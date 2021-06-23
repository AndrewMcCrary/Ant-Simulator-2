#ifndef MOVEBEHAVIOR_H
#define MOVEBEHAVIOR_H

#include <SFML/Graphics.hpp>

class moveable {

private:
	float speed;
	sf::ConvexShape asset;

public:
	virtual void tick(float _delta) = 0;

	float getSpeed();
	void setSpeed();

};

#endif // !MOVEBEHAVIOR_H
