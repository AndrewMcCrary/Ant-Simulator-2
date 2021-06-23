#include "ant.h"

ant::ant(float _x, float _y, float _angle) {
	sf::ConvexShape* temp = new sf::ConvexShape();

    temp->setPointCount(3);
    temp->setPoint(0, sf::Vector2f(0.f, -10.f));
    temp->setPoint(1, sf::Vector2f(7.5f, 10.f));
    temp->setPoint(2, sf::Vector2f(-7.5f, 10.f));
    temp->setFillColor(ANT_COLOR);

    temp->setPosition(_x, _y);
    temp->setRotation(_angle);


    this->setAsset(temp);
    this->setSpeed(SPEED);
}

void ant::tick(float _delta) {
    this->getAsset()->move(cosf((90.f - this->getRotation()) * M_PI / 180.f) * this->getSpeed() * _delta,
                          -sinf((90.f - this->getRotation()) * M_PI / 180.f) * this->getSpeed() * _delta);

}

