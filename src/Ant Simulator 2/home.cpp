#include "home.h"

home::home(float _x, float _y, float _r) {
	sf::CircleShape* temp = new sf::CircleShape(_r);



	this->setAsset(temp);
}