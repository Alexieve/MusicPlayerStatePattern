#include "pausedstate.h"
#include "musicplayer.h"

#include <iostream>
using namespace std;

PausedState::PausedState(MusicPlayer* p): PlayerState{ p } {}

void PausedState::process() {
	cout << "Player is " << name() << "...\n";
	cout << "-----------------------------\n";

	char c = ' ';
	while ( c == ' ' ) {
		cout << "  Play [P]  Stop [S]  Quit [Q]\n";
		cout << "  Choice: ";
		cin >> c;

		switch ( toupper(c) ) {
			case 'P':
				player_->changeState(PlayerState::Type::PLAYING);
				break;
			case 'S':
				player_->changeState(PlayerState::Type::STOPPED);
				break;
			case 'Q':
				player_->close();
				break;
			default:
				c = ' ';
				break;
		}
	}
	cout << "\n\n";
}

string PausedState::name() const {
	return string{ "PAUSED" };
}
