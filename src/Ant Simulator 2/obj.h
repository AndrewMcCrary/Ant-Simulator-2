#ifndef OBJ_H
#define OBJ_H

#define _USE_MATH_DEFINES

#include <cmath>

#include <SFML/Graphics.hpp>

class obj {
	
private:
	sf::ConvexShape* asset;

protected:
	void setAsset(sf::ConvexShape* _asset);

public:
	obj();
	obj(sf::ConvexShape* _asset);
	sf::ConvexShape* getAsset();

	float getRotation();
	virtual void setRotation(float _a);
	virtual void setRotation(float _dx, float _dy);

	float getX();
	virtual void setX(float _x);

	float getY();
	virtual void setY(float _y);
};

#endif // !OBJ_H
