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
	float _intensity;

public:

	trail(float _x, float _y, trailType _t, float _seconds);

	/// <summary>
	/// Method to update trail each tick
	/// </summary>
	/// <param name="_delta">Relation between framerate and tickrate</param>
	void tick(float _delta);

	/// <returns>Returns trail type</returns>
	trailType getTrailType();

	/// <returns>Intensity; seconds remaining on trail</returns>
	float getIntensity();
	
	/// <param name="_i">New intensity for the trail in seconds</param>
	void setIntensity(float _i);
};

#endif // !TRAIL_H
