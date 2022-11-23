#pragma once

#include <string>
using namespace std;

class MusicPlayer;

/** Abstract class for music player state
 */
class PlayerState {
protected:
	MusicPlayer* player;
public:
	enum class Type {STOPPED, PLAYING, PAUSED };

	PlayerState(MusicPlayer* p): player{p} {}
	virtual ~PlayerState() = default;

	virtual void process() = 0;
	virtual string name() const = 0;
};