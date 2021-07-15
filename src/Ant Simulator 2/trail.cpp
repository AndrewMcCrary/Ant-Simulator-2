#include "trail.h"

trail::trail(float _x, float _y, trailType _t, int _ticks, bool _isVisible) {
	sf::CircleShape* temp = new sf::CircleShape(MAX_RADIUS);
	temp->setOrigin(temp->getRadius(), temp->getRadius());
	temp->setPosition(_x, _y);
	this->t = _t;
	if (_t == trailType::ToHome)
		temp->setFillColor(sf::Color(50, 50, 50, 255));
	else
		temp->setFillColor(sf::Color(200, 200, 200, 255));

	//temp->setOrigin(-250, -250);
	this->setAsset(temp);
	this->_ticksRemaining = _ticks;
	this->setVisibility(_isVisible);
}

void trail::tick(float _delta) {
	this->_ticksRemaining--;
	// seconds * 10, max ~15
	if (this->isVisible()) {
		this->getAsset()->setScale((float)this->getTicksRemaining() / LIFETIME, (float)this->getTicksRemaining() / LIFETIME);
	}

}

trailType trail::getTrailType() {
	return this->t;
}

int trail::getTicksRemaining() {
	return this->_ticksRemaining;
}
void trail::setTicksRemaining(int _i) {
	this->_ticksRemaining = _i;
}

bool trail::isVisible() {
	return this->_isVisible;
}
void trail::setVisibility(bool _v) {
	this->_isVisible = _v;
}
