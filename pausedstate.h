#pragma once

#include "playerstate.h"
using namespace std;

class PausedState : public PlayerState {
public:
	PausedState(MusicPlayer* p);

	void process();
	string name() const;
};