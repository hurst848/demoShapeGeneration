#include "circle.h"


int circle::getOriginX()
{
	return originX;
}
int circle::getOriginY()
{
	return originY;
}
int circle::getRadius()
{
	return radius;
}
void circle::setOriginX(int _x)
{
	originX = _x;
}
void circle::setOriginY(int _y)
{
	originY = _y;
}
void circle::setRadius(int _r)
{
	radius = _r;
}


circle::circle()
{
	radius = 100;
	originX = 100;
	originY = 100;
}
circle::circle(int _x, int _y, int _r)
{
	radius = _r;
	originX = _x;
	originY = _y;
}