#pragma once

#include <string>
using namespace std;

class MusicPlayer;

/** Abstract class for music player state
 */
class PlayerState {
public:
	enum class Type { STOPPED, PLAYING, PAUSED };

	PlayerState(MusicPlayer* p): player_{ p } {}
	virtual ~PlayerState() = default;

	virtual void process() = 0;
	virtual string name() const = 0;

protected:
	MusicPlayer* player_;
};