#ifndef ANT_H
#define ANT_H

#define LIMIT_TURN_SPEED true
#define MAX_TURN_PER_FRAME 2.f
#define SPEED 3.f
#define ANT_COLOR sf::Color(255, 65, 30)

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

#include "obj.h"
#include "moveable.h"

class ant : public moveable {

private:

public:
	ant(float _x, float _y, float _angle);

	void tick(float _delta);


};

#endif // !ANT_H


