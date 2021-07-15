//	NOTES:
//	May try to do chunking in the future if performace is an issue
//
//
//
//
//
//


#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>

#include "ant.h"
#include "food.h"
#include "home.h"
#include "trail.h"
#include "window.h"

#define BACK_COLOR sf::Color(25, 16, 6)

class world {

private:
	size_t width;
	size_t height;

	std::vector<ant*> ants;
	std::vector<food*> foods;
	std::vector<home*> homes;
	std::vector<trail*> trails;

	/// <summary>
	/// Method containing ant behavior in relation to external objects
	/// </summary>
	/// <param name="_delta">Relation between framerate and tickrate</param>
	/// <returns>True if successful</returns>
	bool antsTick(float _delta);
	/// <summary>
	/// Method containing trail behavior in relation to external objects
	/// </summary>
	/// <param name="_delta">Relation between framerate and tickrate</param>
	/// <returns>True if successful</returns>
	bool trailTick(float _delta);

public:
	world(size_t _width, size_t _height);

	/// <summary>
	///	Occurs every tick, calls the tick of each object in the world
	/// </summary>
	/// <param name="_delta">Relation between framerate and tickrate</param>
	/// <returns>True if successful</returns>
	bool tick(float _delta);

	/// <returns>Width of the world in pixels</returns>
	size_t getWidth();
	/// <param name="_w">New width of the world in pixels</param>
	void setWidth(size_t _w);

	/// <returns>Height of the world in pixels</returns>
	size_t getHeight();
	/// <param name="_w">New height of the world in pixels</param>
	void setHeight(size_t _height);

	/// <returns>Vector of pointers to ants within the world</returns>
	std::vector<ant*> getAnts();
	/// <param name="_a">Ant to add to the world</param>
	void addAnt(ant* _a);
	/// <param name="_index">Index in the vector to remove</param>
	void eraseAnt(int _index);

	/// <returns>Vector of pointers to food within the world</returns>
	std::vector<food*> getFoods();
	/// <param name="_a">Food to add to the world</param>
	void addFood(food* _f);
	/// <param name="_index">Index in the vector to remove</param>
	void eraseFood(int _index);

	/// <returns>Vector of pointers to homes within the world</returns>
	std::vector<home*> getHomes();
	/// <param name="_a">Home to add to the world</param>
	void addHome(home* _h);
	/// <param name="_index">Index in the vector to remove</param>
	void eraseHome(int _index);

	/// <returns>Vector of pointers to trails within the world</returns>
	std::vector<trail*> getTrails();
	/// <param name="_a">Trail to add to the world</param>
	void addTrail(trail* _t);
	/// <param name="_index">Index in the vector to remove</param>
	void eraseTrail(int _index);

};

#endif // !WORLD_H
