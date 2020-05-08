#include "line.h"


line::line(int x1, int y1, int x2, int y2)
{
	X1 = x1;
	Y1 = y1;
	Z1 = 0;
	X2 = x2;
	Y2 = y2;
	Z2 = 0;

	int deltX = x2 - x1;
	int deltY = y2 - y1;

	vector.x = deltX;
	vector.y = deltY;
	vector.z = 0;
	vector.w = 1;
}

line::line(int x1, int y1, int z1, int x2, int y2, int z2)
{
	X1 = x1;
	Y1 = y1;
	Z1 = z1;
	X2 = x2;
	Y2 = y2;
	Z2 = z2;

	int deltX = x2 - x1;
	int deltY = y2 - y1;
	int deltZ = z2 - z1;

	vector.x = deltX;
	vector.y = deltY;
	vector.z = deltZ;
	vector.w = 1;
}

line::line()
{
	X1 = 0;
	Y1 = 0;
	Z1 = 0;
	X2 = 0;
	Y2 = 0;
	Z2 = 0;
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	vector.w = 1;
}

int line::getX1()
{
	return X1;
}
void line::setX1(int x)
{
	X1 = x;
}
int line::getX2()
{
	return X2;
}
void line::setX2(int x)
{
	X2 = x;
}

int line::getY1()
{
	return Y1;
}
void line::setY1(int y)
{
	Y1 = y;
}
int line::getY2()
{
	return Y2;
}
void line::setY2(int y)
{
	Y2 = y;
}

int line::getZ1()
{
	return Z1;
}
void line::setZ1(int z)
{
	Z1 = z;
}
int line::getZ2()
{
	return Z2;
}
void line::setZ2(int z)
{
	Z2 = z;
}