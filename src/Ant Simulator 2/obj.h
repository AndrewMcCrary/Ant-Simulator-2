#ifndef OBJ_H
#define OBJ_H

#define _USE_MATH_DEFINES

#include <cmath>

#include <SFML/Graphics.hpp>

// TODO Insert comments

class obj {
	
private:
	sf::Shape* asset;

protected:
	void setAsset(sf::Shape* _asset);

public:
	obj();
	obj(sf::Shape* _asset);
	~obj();
	sf::Shape* getAsset();

	float getRotation();
	virtual void setRotation(float _a);
	virtual void setRotation(float _dx, float _dy);

	virtual void move(float _x, float _y);

	float getX();
	void setX(float _x);

	float getY();
	void setY(float _y);
};

#endif // !OBJ_H
