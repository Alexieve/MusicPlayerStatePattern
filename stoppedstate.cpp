#include "stoppedstate.h"
#include "musicplayer.h"

#include <iostream>
using namespace std;

StoppedState::StoppedState(MusicPlayer* p): PlayerState{ p } {}

void StoppedState::process() {
	cout << "Player is " << name() << "...\n";
	cout << "-----------------------------\n";

	char c = ' ';
	while ( c == ' ' ) {
		cout << "  Play [P]  Quit [Q]\n";
		cout << "  Choice: ";
		cin >> c;

		switch ( toupper(c) ) {
			case 'P':
				player_->changeState(PlayerState::Type::PLAYING);
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

string StoppedState::name() const {
	return string{ "STOPPED" };
}
