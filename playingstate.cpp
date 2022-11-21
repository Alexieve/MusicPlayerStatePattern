#include "playingstate.h"
#include "musicplayer.h"

#include <iostream>
using namespace std;

PlayingState::PlayingState(MusicPlayer* p): PlayerState{ p } {}

void PlayingState::process() {
	cout << "Player is " << name() << "...\n";
	cout << "-----------------------------\n";

	char c = ' ';
	while ( c == ' ' ) {
		cout << "  Pause [P]  Stop [S]  Quit [Q]\n";
		cout << "  Choice: ";
		cin >> c;

		switch ( toupper(c) ) {
			case 'P':
				player_->changeState(PlayerState::Type::PAUSED);
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

string PlayingState::name() const {
  return string{ "PLAYING" };
}
