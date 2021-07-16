#ifndef TRAIL_H
#define TRAIL_H

#define RADIUS_DIVISOR 10.f
#define MAX_RADIUS 15.f
#define TRAIL_LIFETIME 300
#define VISIBLE_TRAILS true

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
	int _ticksRemaining;
	/// <summary>
	/// Visibility of the trail
	/// </summary>
	bool _isVisible;



public:

	trail(float _x, float _y, trailType _t, int _ticks, bool _isVisible);

	/// <summary>
	/// Method to update trail each tick
	/// </summary>
	/// <param name="_delta">Relation between framerate and tickrate</param>
	void tick(float _delta);

	/// <returns>Returns trail type</returns>
	trailType getTrailType();

	/// <returns>Intensity; seconds remaining on trail</returns>
	int getTicksRemaining();
	/// <param name="_i">New intensity for the trail in seconds</param>
	void setTicksRemaining(int _t);

	/// <returns>Visibility of the trail</returns>
	bool isVisible();
	/// <param name="_v">New visibility</param>
	void setVisibility(bool _v);
};

#endif // !TRAIL_H
