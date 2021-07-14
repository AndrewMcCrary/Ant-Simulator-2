#ifndef ANT_H
#define ANT_H

#define MAX_TURN_PER_TICK 2.f
#define MAX_TURN_DELTA .01f
#define TURN_RATE_DIVISOR_PER_TICK 1.015f
#define SPEED 1.f
#define VIEW_DISTANCE 15.f
#define ANT_COLOR sf::Color(255, 65, 30)

// Percentage likelyhood to not change direction per tick
#define ANT_WANDER_COEFF 0.15f

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <random>

#include "moveable.h"

class ant : public moveable {

private:
	/// <summary>
	/// [-1,1], % of max turn rate per tick
	/// </summary>
	float _turnRate;

	/// <summary>
	/// True if ant has food
	/// </summary>
	bool _hasFood;

public:
	/// <summary>
	/// Creates ant object
	/// </summary>
	/// <param name="_x">X position relative to leftmost side of the window</param>
	/// <param name="_y">Y position relative to topmost side of the window</param>
	/// <param name="_angle">Starting angle</param>
	ant(float _x, float _y, float _angle);

	/// <summary>
	/// Method to update ant each tick
	/// </summary>
	/// <param name="_delta">Relation between framerate and tickrate</param>
	void tick(float _delta);

	/// <summary>
	/// Changes the turnrate of the ant a random amount
	/// </summary>
	/// <param name="_coeff">Wandering coefficient, [0,1], percentage likelyhood to not turn</param>
	/// <param name="_delta">Relation between framerate and tickrate</param>
	void wander(float _coeff, float _delta);

	/// <summary>
	/// Sets rotation and takes tickrate and max turnrate into account
	/// </summary>
	/// <param name="_a">Angle to work towards</param>
	/// <param name="_delta">Relation between framerate and tickrate</param>
	void setRotationLimited(float _a, float _delta);

	/// <summary>
	/// Sets rotation and takes tickrate into account
	/// </summary>
	/// <param name="_dx">X offset from ant</param>
	/// <param name="_dy">Y offset from ant</param>
	/// <param name="_delta">Relation between framerate and tickrate</param>
	void setRotationLimited(float _dx, float _dy, float _delta);

	/// <returns>True if ant has food</returns>
	bool getFoodStatus();

	/// <param name="_f">New food status</param>
	void setFoodStatus(bool _f);
};

#endif // !ANT_H
