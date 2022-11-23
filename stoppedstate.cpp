#include "stoppedstate.h"
#include "musicplayer.h"

#include <iostream>
using namespace std;

StoppedState::StoppedState(MusicPlayer* p): PlayerState{p} {}

void StoppedState::process() {
	cout << "Player is " << name() << "...\n";
	cout << "-----------------------------\n";

	char choice = ' ';
	while (choice == ' ') {
		cout << "  Play [P]  Quit [Q]\n";
		cout << "  Choice: ";
		cin >> choice;
		switch (toupper(choice)) {
			case 'P':
				player->changeState(PlayerState::Type::PLAYING);
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

string StoppedState::name() const {
	return string{"STOPPED"};
}
