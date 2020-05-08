#pragma once
#include <vector>
#include <glm/glm/glm.hpp>
#include <glm/glm/ext.hpp>

class line
{
public:
	glm::vec4 vector;
private:
	int X1;
	int Y1;
	int Z1;
	int X2;
	int Y2;
	int Z2;
public:
	line();
	line(int x1, int y1, int x2, int y2);
	line(int x1, int y1, int z1, int x2, int y2, int z2);
	
	int getX1();
	void setX1(int x);
	int getX2();
	void setX2(int x);

	int getY1();
	void setY1(int y);
	int getY2();
	void setY2(int y);

	int getZ1();
	void setZ1(int z);
	int getZ2();
	void setZ2(int z);
};

