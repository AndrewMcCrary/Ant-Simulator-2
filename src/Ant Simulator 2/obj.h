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
	obj(sf::ConvexShape _asset);


	float getRotation();
	virtual void setRotation(float _a);

	float getX();
	virtual void setX(float _x);

	float getY();
	virtual void setY(float _y);
};

#endif // !OBJ_H
