#include "trail.h"

trail::trail(float _x, float _y, trailType _t, float _milSeconds) {
	sf::CircleShape* temp = new sf::CircleShape((float)_milSeconds / 10.f);
	temp->setPosition(_x, _y);
	this->t = _t;
	if (_t == trailType::ToHome)
		temp->setFillColor(sf::Color(10, 255, 50, 255));
	else
		temp->setFillColor(sf::Color(255, 50, 10, 255));

	this->setAsset(temp);
}

void trail::tick(float _delta) {

}

trailType trail::getTrailType() {
	return this->t;
}