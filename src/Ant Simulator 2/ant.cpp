#include "ant.h"

ant::ant(float _x, float _y, float _angle = 0.f) {
	sf::ConvexShape temp;

    temp.setPointCount(3);
    temp.setPoint(0, sf::Vector2f(0.f, -10.f));
    temp.setPoint(1, sf::Vector2f(7.5f, 10.f));
    temp.setPoint(2, sf::Vector2f(-7.5f, 10.f));
    temp.setFillColor(ANT_COLOR);

    temp.setPosition(_x, _y);
    temp.setRotation(_angle);


    this->setAsset(temp);
}

void ant::tick(float _delta) {
	
}

