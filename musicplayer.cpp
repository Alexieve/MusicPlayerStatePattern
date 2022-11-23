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
	for (auto& s : states) {
		cout << "  delete state " << s.second->name() << "\n";
		delete s.second;
	}
}

void MusicPlayer::run() {
	while ( currentState )
		currentState->process();
}

void MusicPlayer::close() {
	currentState = nullptr;
}

/** Change current state to a state specified by type
 */
void MusicPlayer::changeState(const PlayerState::Type type) {
	try {
		currentState = states.at(type);
		return;
	} catch (const out_of_range&) {
		switch (type) {
			case PlayerState::Type::PAUSED:
				states[type] = new PausedState(this);
				break;
			case PlayerState::Type::PLAYING:
				states[type] = new PlayingState(this);
				break;
			case PlayerState::Type::STOPPED:
				states[type] = new StoppedState(this);
				break;
		}
	}
	currentState = states[type];
}