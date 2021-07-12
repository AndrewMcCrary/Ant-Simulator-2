#include "obj.h"

obj::obj() {
	this->asset = (sf::Shape*)nullptr;
}

obj::obj(sf::Shape* _asset) {
	this->asset = _asset;
}

sf::Shape* obj::getAsset() {
	return this->asset;
}

void obj::setAsset(sf::Shape* _asset) {
	this->asset = _asset;
}

float obj::getRotation() {
	return this->getAsset()->getRotation();
}

void obj::setRotation(float _a) {
	this->getAsset()->setRotation(_a);
}

void obj::setRotation(float _dx, float _dy) {
	if (_dx < 0)
		this->setRotation((atan(_dy / _dx) * 180.f / (float)M_PI - 90.f));
	else
		this->setRotation(atan(_dy / _dx) * 180.f / (float)M_PI + 90.f);
}

float obj::getX() {
	return this->getAsset()->getPosition().x;
}

void obj::setX(float _x) {
	this->getAsset()->setPosition(_x, this->getY());
}

float obj::getY() {
	return this->getAsset()->getPosition().y;
}

void obj::setY(float _y) {
	this->getAsset()->setPosition(this->getX(), _y);
}
