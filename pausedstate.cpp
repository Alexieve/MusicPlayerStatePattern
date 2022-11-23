#include "pausedstate.h"
#include "musicplayer.h"

#include <iostream>
using namespace std;

PausedState::PausedState(MusicPlayer* p): PlayerState{p} {}

void PausedState::process() {
	cout << "Player is " << name() << "...\n";
	cout << "-----------------------------\n";

	char choice = ' ';
	while (choice == ' ') {
		cout << "  Play [P]  Stop [S]  Quit [Q]\n";
		cout << "  Choice: ";
		cin >> choice;
		switch (toupper(choice)) {
			case 'P':
				player->changeState(PlayerState::Type::PLAYING);
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

string PausedState::name() const {
	return string{ "PAUSED" };
}
