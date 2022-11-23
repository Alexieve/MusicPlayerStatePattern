#include "playingstate.h"
#include "musicplayer.h"

#include <iostream>
using namespace std;

PlayingState::PlayingState(MusicPlayer* p): PlayerState{p} {}

void PlayingState::process() {
	cout << "Player is " << name() << "...\n";
	cout << "-----------------------------\n";

	char choice = ' ';
	while (choice == ' ') {
		cout << "  Pause [P]  Stop [S]  Quit [Q]\n";
		cout << "  Choice: ";
		cin >> choice;
		switch (toupper(choice)) {
			case 'P':
				player->changeState(PlayerState::Type::PAUSED);
				break;
			case 'S':
				player->changeState(PlayerState::Type::STOPPED);
				break;
			case 'Q':
				player->close();
				break;
			default:
				choice = ' ';
				break;
		}
	}
	cout << "\n\n";
}

string PlayingState::name() const {
  return string{"PLAYING"};
}
