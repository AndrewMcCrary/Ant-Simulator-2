#ifndef MOVEBEHAVIOR_H
#define MOVEBEHAVIOR_H

#include <SFML/Graphics.hpp>

#include "obj.h"

class moveable : public obj {

private:
	float speed;

public:
	virtual void tick(float _delta) = 0;

	float getSpeed();
	void setSpeed(float _s);
};

#endif // !MOVEBEHAVIOR_H
