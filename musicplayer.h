#pragma once

#include "playerstate.h"
#include <map>
using namespace std;

class MusicPlayer {
public:
	MusicPlayer();
	~MusicPlayer();

	void run();
	void close();
	void changeState(const PlayerState::Type);

private:
	map<PlayerState::Type, PlayerState*> states_;
	PlayerState* currentState_;
};
