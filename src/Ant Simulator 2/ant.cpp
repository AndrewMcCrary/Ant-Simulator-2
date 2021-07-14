#include "ant.h"

ant::ant(float _x, float _y, float _angle) {
    srand((unsigned)time(NULL)); // init random
    this->_turnRate = 0;

    // Build asset
	sf::ConvexShape* temp = new sf::ConvexShape();
    temp->setPointCount(3);
    temp->setPoint(0, sf::Vector2f(0.f, -5.f));
    temp->setPoint(1, sf::Vector2f(3.75f, 5.f));
    temp->setPoint(2, sf::Vector2f(-3.75f, 5.f));
    temp->setFillColor(ANT_COLOR);

    temp->setPosition(_x, _y);
    temp->setRotation(_angle);

    this->setAsset(temp);
    this->setSpeed(SPEED);  // May change in the future
}

void ant::tick(float _delta) {
    this->wander(ANT_WANDER_COEFF, _delta);
    this->_turnRate /= TURN_RATE_DIVISOR_PER_TICK;
    this->getAsset()->move(cosf((90.f - this->getRotation()) * (float)M_PI / 180.f) * this->getSpeed() * _delta,
                           -sinf((90.f - this->getRotation()) * (float)M_PI / 180.f) * this->getSpeed() * _delta);


    

    // Check if there is food
    // Check if there is a to food trail
    // 
}

void ant::setRotationLimited(float _a, float _delta) {
    float _back; // Retrograde angle of the ant
    if (this->getRotation() > 180) {
        _back = this->getRotation() - 180.f;
    } else {
        _back = this->getRotation() + 180.f;
    }


    // Since the ant is turning relative to time, it needs to turn in the correct direction
    // before it has achieved the desired direction
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

void ant::setRotationLimited(float _dx, float _dy, float _delta) {
    if (_dx < 0)
        this->setRotation(atan(_dy / _dx) * 180.f / (float)M_PI - 90.f, _delta);
    else
        this->setRotation(atan(_dy / _dx) * 180.f / (float)M_PI + 90.f, _delta);
}


void ant::wander(float _coeff, float _delta) {
    float _r = (float)rand() / RAND_MAX;
    if (_r > _coeff) {
        _r = 2*(_r - 1 + ((1 - ANT_WANDER_COEFF) / 2))/(1-ANT_WANDER_COEFF);
        this->_turnRate += _r*ANT_WANDER_COEFF;

        this->setRotation(this->getRotation() + (this->_turnRate * MAX_TURN_PER_TICK));
    }
}

bool ant::getFoodStatus() {
    return this->_hasFood;
}

void ant::setFoodStatus(bool _f) {
    this->_hasFood = _f;
}
