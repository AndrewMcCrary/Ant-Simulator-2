#ifndef MOVEABLE_H
#define MOVEABLE_H

#include <SFML/Graphics.hpp>

#include "obj.h"

// TODO Insert comments

class moveable : public obj {

private:
	float speed = 0;

public:
	virtual void tick(float _delta) = 0;

	float getSpeed();
	void setSpeed(float _s);
};

#endif // !MOVEABLE_H
