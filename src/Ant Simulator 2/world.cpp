#include "world.h"

world::world(size_t _width, size_t _height) {
	this->setWidth(_width);
	this->setHeight(_height);


}

bool world::tick(float _delta) {
	this->trailTick(_delta);


	this->antsTick(_delta);
	//for (size_t i = 0; i < this->getAnts().size(); i++) {
	//	this->getAnts()[i]->tick(_delta);
	//	if (this->getAnts()[i]->getX() > WINDOW_RES_X) {
	//		this->getAnts()[i]->setX(0.f);
	//	} else if (this->getAnts()[i]->getX() < 0) {
	//		this->getAnts()[i]->setX(WINDOW_RES_X);
	//	}
	//	if (this->getAnts()[i]->getY() > WINDOW_RES_Y) {
	//		this->getAnts()[i]->setY(0.f);
	//	} else if (this->getAnts()[i]->getY() < 0) {
	//		this->getAnts()[i]->setY(WINDOW_RES_Y);
	//	}
	//}
	return true;
}

bool world::antsTick(float _delta) {
	ant* current;
	for (size_t i = 0; i < this->getAnts().size(); i++) {
		current = this->getAnts()[i];
		if (current->getFoodStatus()) {
			// Ant is carrying food and looks for to home trail or home



		} else {
			// Ant is not carrying food and looks for to food trail or wanders
			if (current->getTrailTickCounter() <= 0) {
				this->addTrail(new trail(current->getX(), current->getY(), trailType::ToHome, TRAIL_LIFETIME, true));
				current->resetTrailTickCounter();
			}

		}
		this->getAnts()[i]->tick(_delta);

		// Handle ants that go off the screen
		if (current->getX() > WINDOW_RES_X)
			current->setX(0.f);
		else if (current->getX() < 0)
			current->setX(WINDOW_RES_X);
		if (current->getY() > WINDOW_RES_Y)
			current->setY(0.f);
		else if (current->getY() < 0)
			current->setY(WINDOW_RES_Y);
	}
	return true;
}

bool world::trailTick(float _delta) {
	for (int i = 0; i < this->getTrails().size(); i++) {
		// If trail intensity is greater than zero, tick and decrease intensity
		// or if it is <= 0 release the object and remove it from the world
		if (this->getTrails()[i]->getTicksRemaining() > 0)
			this->getTrails()[i]->tick(_delta);
		else 
			this->eraseTrail(i);
	}
	return true;
}

// World size methods
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

// Ant methods
std::vector<ant*> world::getAnts() {
	return this->ants;
}
void world::addAnt(ant* _a) {
	this->ants.push_back(_a);
}
void world::eraseAnt(int _index) {
	delete this->ants[_index];
	this->ants.erase(this->ants.begin() + _index);
}

// Food methods
std::vector<food*> world::getFoods() {
	return this->foods;
}
void world::addFood(food* _f) {
	this->foods.push_back(_f);
}
void world::eraseFood(int _index) {
	delete this->foods[_index];
	this->foods.erase(this->foods.begin() + _index);
}

// Home methods
std::vector<home*> world::getHomes() {
	return this->homes;
}
void world::addHome(home* _h) {
	this->homes.push_back(_h);
}
void world::eraseHome(int _index) {
	delete this->homes[_index];
	this->homes.erase(this->homes.begin() + _index);
}

// Trail methods
std::vector<trail*> world::getTrails() {
	return this->trails;
}
void world::addTrail(trail* _h) {
	this->trails.push_back(_h);
}
void world::eraseTrail(int _index) {
	delete this->trails[_index];
	this->trails.erase(this->trails.begin() + _index);
}
