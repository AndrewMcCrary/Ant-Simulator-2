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
	/// <summary>
	/// Trail type (tohome, tofood)
	/// </summary>
	trailType t;
	/// <summary>
	/// Seconds remaining
	/// </summary>
	float _ticksRemaining;
	/// <summary>
	/// Visibility of the trail
	/// </summary>
	bool _isVisible;



public:

	trail(float _x, float _y, trailType _t, float _ticks, bool _isVisible);

	/// <summary>
	/// Method to update trail each tick
	/// </summary>
	/// <param name="_delta">Relation between framerate and tickrate</param>
	void tick(float _delta);

	/// <returns>Returns trail type</returns>
	trailType getTrailType();

	/// <returns>Intensity; seconds remaining on trail</returns>
	float getTicksRemaining();
	/// <param name="_i">New intensity for the trail in seconds</param>
	void setTicksRemaining(float _t);

	/// <returns>Visibility of the trail</returns>
	bool isVisible();
	/// <param name="_v">New visibility</param>
	void setVisibility(bool _v);
};

#endif // !TRAIL_H
