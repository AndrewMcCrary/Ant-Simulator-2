#include "world.h"

world::world(size_t _width, size_t _height) {
	this->setWidth(_width);
	this->setHeight(_height);


}

bool world::tick(float _delta) {
	for (size_t i = 0; i < this->getAnts().size(); i++) {
		this->getAnts()[i]->tick(_delta);
		if (this->getAnts()[i]->getX() > WINDOW_RES_X) {
			this->getAnts()[i]->setX(0.f);
		} else if (this->getAnts()[i]->getX() < 0) {
			this->getAnts()[i]->setX(WINDOW_RES_X);
		}
		if (this->getAnts()[i]->getY() > WINDOW_RES_Y) {
			this->getAnts()[i]->setY(0.f);
		} else if (this->getAnts()[i]->getY() < 0) {
			this->getAnts()[i]->setY(WINDOW_RES_Y);
		}
	}
	return true;
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
