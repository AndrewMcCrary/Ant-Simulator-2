#ifndef FOOD_H
#define FOOD_H

#include "obj.h"

class food : public obj {

private:
	bool _isInfinite;


public:

	food(float _x, float _y, float _radius, bool _isInfinite = false);

	/// <returns>True if food source is infinite</returns>
	bool isInfinite();

};

#endif // !FOOD_H
