#pragma once

#include "playerstate.h"
using namespace std;

class PlayingState : public PlayerState {
public:
  PlayingState(MusicPlayer* p);

  void process() override;
  string name() const override;
};
