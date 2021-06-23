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

void ant::setRotation(float _a, float _delta) {
    while (_a < 0)
        _a += 360;

    float _back = fmodf(this->getRotation() + 180, 360.f);
    if (abs(_a - this->getRotation()) > MAX_TURN_PER_TICK * _delta) {

        if (this->getRotation() < 180) {
            if (_a > this->getRotation() && _a < _back)
                this->setRotation(this->getRotation() + MAX_TURN_PER_TICK);
            else
                this->setRotation(this->getRotation() - MAX_TURN_PER_TICK);
        } else {
            if (_a < this->getRotation() && _a > _back)
                this->setRotation(this->getRotation() - MAX_TURN_PER_TICK);
            else
                this->setRotation(this->getRotation() + MAX_TURN_PER_TICK);
        }
    } else {
        this->setRotation(_a);
    }



}

void ant::setRotation(float _dx, float _dy, float _delta) {
    if (_dx < 0)
        this->setRotation(atan(_dy / _dx) * 180.f / M_PI - 90.f, _delta);
    else
        this->setRotation(atan(_dy / _dx) * 180.f / M_PI + 90.f, _delta);
}
