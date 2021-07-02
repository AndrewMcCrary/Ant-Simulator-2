#include "ant.h"

ant::ant(float _x, float _y, float _angle) {
    srand((unsigned)time(NULL));
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
    this->wander(ANT_WANDER_COEFF, _delta);
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

void ant::wander(float _coeff, float _delta) {
    float _r = (float)rand() / RAND_MAX;
    if (_r > _coeff) {
        _r = 2*(_r - 1 + ((1 - ANT_WANDER_COEFF) / 2))/(1-ANT_WANDER_COEFF);
        this->_turnRate += _r*ANT_WANDER_COEFF;

        if (this->_turnRate > 1) {
            this->_turnRate = 1;
            this->_turnRate = pow(this->_turnRate, 1.1);
        } else if (this->_turnRate < -1) {
            this->_turnRate = -1;
            this->_turnRate = -pow(abs(this->_turnRate), 1.1);
        }

        this->setRotation(this->getRotation() + (this->_turnRate * MAX_TURN_PER_TICK));
    }
}
