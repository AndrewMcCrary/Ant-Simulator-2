#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>

#include "ant.h"

#define BACK_COLOR sf::Color(25, 16, 6)

class world {

private:
	size_t width;
	size_t height;

	std::vector<ant*> ants;

public:
	world(size_t _width, size_t _height);

	bool tick(float _delta);

	size_t getWidth();
	void setWidth(size_t _w);

	size_t getHeight();
	void setHeight(size_t _height);

	std::vector<ant*> getAnts();
	void addAnt(ant* _a);

};

#endif // !WORLD_H
