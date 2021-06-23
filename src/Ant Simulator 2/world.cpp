#include "world.h"

world::world(size_t _width, size_t _height) {

}

bool world::tick(float _delta) {

}

size_t world::getWidth() {
	return this->width;
}

void world::setWidth(size_t _width) {
	this->width = _width;
}

size_t world::getHeight() {
	return this->height;
}

void world::setHeight(size_t _height) {
	this->height = _height;
}

std::vector<ant*> world::getAnts() {
	return this->ants;
}

void world::addAnt(ant* _a) {
	this->ants.push_back(_a);
}
