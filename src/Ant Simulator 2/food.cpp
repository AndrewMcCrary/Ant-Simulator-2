#include "food.h"

food::food(float _x, float _y, float _radius, bool _I) {
	sf::CircleShape* temp = new sf::CircleShape(_radius);
	temp->setPosition(_x, _y);
	this->setAsset(temp);
	this->_isInfinite = _I;
}

bool food::isInfinite() {
	return this->_isInfinite;
}
