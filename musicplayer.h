#pragma once

#include "playerstate.h"
#include <map>
using namespace std;

class MusicPlayer {
private:
	map<PlayerState::Type, PlayerState*> states;
	PlayerState* currentState;
public:
	MusicPlayer();
	~MusicPlayer();

	void run();
	void close();
	void changeState(const PlayerState::Type);
};
