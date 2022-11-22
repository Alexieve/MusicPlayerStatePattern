#include "musicplayer.h"
#include "pausedstate.h"
#include "playingstate.h"
#include "stoppedstate.h"

#include <iostream>
#include <stdexcept>
using namespace std;

MusicPlayer::MusicPlayer() {
	cout << "MusicPlayer is started. Hello!\n";
	changeState(PlayerState::Type::STOPPED);
}

MusicPlayer::~MusicPlayer() {
	cout << "MusicPlayer is closed. Bye!\n";
	for (auto& s : states_) {
		cout << "  delete state " << s.second->name() << "\n";
		delete s.second;
	}
}

void MusicPlayer::run() {
	while ( currentState_ ) {
		currentState_->process();
	}
}

void MusicPlayer::close() {
	currentState_ = nullptr;
}

/** Change current state to a state specified by type
 */
void MusicPlayer::changeState(const PlayerState::Type type) {
	try {
		currentState_ = states_.at(type);
		return;
	} catch (const out_of_range&) {
		switch (type) {
			case PlayerState::Type::PAUSED:
				states_[type] = new PausedState(this);
				break;
			case PlayerState::Type::PLAYING:
				states_[type] = new PlayingState(this);
				break;
			case PlayerState::Type::STOPPED:
				states_[type] = new StoppedState(this);
				break;
		}
	}
	currentState_ = states_[type];
}