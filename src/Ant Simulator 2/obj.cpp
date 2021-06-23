#include "obj.h"

obj::obj() {

}

obj::obj(float _x, float _y, sf::ConvexShape _asset) {

}

sf::ConvexShape obj::getAsset() {
	return this->asset;
}

void obj::setAsset(sf::ConvexShape _asset) {
	this->asset = _asset;
}

float obj::getRotation() {
	return this->getAsset().getRotation();
}

void obj::setRotation(float _a) {
	this->getAsset().setRotation(_a);
}

float obj::getX() {
	return this->getAsset().getPosition().x;
}

void obj::setX(float _x) {
	this->getAsset().setPosition(_x, this->getY());
}

float obj::getY() {
	return this->getAsset().getPosition().y;
}

void obj::setY(float _y) {
	this->getAsset().setPosition(this->getX(), _y);
}
