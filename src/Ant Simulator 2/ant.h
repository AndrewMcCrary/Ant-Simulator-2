#ifndef ANT_H
#define ANT_H

// Max turn rate per tick
#define MAX_TURN_RATE 2.f
// Max turn acceleration per tick
#define MAX_TURN_ACCEL .01f
#define SPEED 1.f
#define VIEW_DISTANCE 25.f
#define PICKUP_DISTANCE 3.f
#define TRAIL_DROP_RATE 60
#define TURN_RATE_DIVISOR_PER_TICK 1.015f
#define ANT_COLOR sf::Color(255, 65, 30)

// Percentage likelyhood to not change direction per tick
#define ANT_WANDER_COEFF 0.15f

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <random>

#include "moveable.h"

// TODO Recreate object where it inherits from sf::shape

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

	/// <summary>
	/// Number of ticks until trail is dropped
	/// </summary>
	int _ticksUntilTrail;

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

	/// <returns>Ticks until trail is dropped</returns>
	int getTrailTickCounter();
	/// <param name="_t">New number of ticks until trail</param>
	void setTrailTickCounter(int _t);
	/// <summary>
	/// Resets tick counter
	/// </summary>
	void resetTrailTickCounter();
};

#endif // !ANT_H
