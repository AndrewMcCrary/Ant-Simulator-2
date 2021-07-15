#include "trail.h"

trail::trail(float _x, float _y, trailType _t, float _ticks, bool _isVisible) {
	sf::CircleShape* temp = new sf::CircleShape(15.f);
	temp->setPosition(_x, _y);
	this->t = _t;
	if (_t == trailType::ToHome)
		temp->setFillColor(sf::Color(50, 50, 50, 255));
	else
		temp->setFillColor(sf::Color(200, 200, 200, 255));

	this->setAsset(temp);
	this->_ticksRemaining = _ticks;
	this->setVisibility(_isVisible);
}

void trail::tick(float _delta) {
	this->_ticksRemaining--;
	// seconds * 10, max ~15
	if (this->isVisible()) {
		((sf::CircleShape*)this->getAsset())->setRadius(std::max(15.f, this->getTicksRemaining() * 10.f));

	}

}

trailType trail::getTrailType() {
	return this->t;
}

float trail::getTicksRemaining() {
	return this->_ticksRemaining;
}
void trail::setTicksRemaining(float _i) {
	this->_ticksRemaining = _i;
}

bool trail::isVisible() {
	return this->_isVisible;
}
void trail::setVisibility(bool _v) {
	this->_isVisible = _v;
}
