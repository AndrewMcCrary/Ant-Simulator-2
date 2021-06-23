#ifndef OBJ_H
#define OBJ_H

#include <SFML/Graphics.hpp>

class obj {
	
private:
	sf::ConvexShape asset;

protected:
	sf::ConvexShape getAsset();
	void setAsset(sf::ConvexShape _asset);

public:
	obj();
	obj(float _x, float _y, sf::ConvexShape _asset);


	float getRotation();
	void setRotation(float _a);

	float getX();
	void setX(float _x);

	float getY();
	void setY(float _y);
};

#endif // !OBJ_H
