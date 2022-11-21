#pragma once

#include "playerstate.h"
using namespace std;

class StoppedState : public PlayerState{
public:
  StoppedState(MusicPlayer* p);

  void process() override;
  string name() const override;
};
