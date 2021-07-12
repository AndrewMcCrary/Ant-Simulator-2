#ifndef TRAIL_H
#define TRAIL_H

#define INTENSITY_DECREASE_PER_TICK .5f

#include "moveable.h"

enum class trailType {
	ToHome,
	ToFood
};

class trail : public moveable {

private:
	trailType t;

public:

	trail(float _x, float _y, trailType _t, float _milSeconds);

	void tick(float _delta);

	trailType getTrailType();
};

#endif // !TRAIL_H
