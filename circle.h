#pragma once
class circle
{
private:
	int originX;
	int originY;
	int radius;
public:
	int getOriginX();
	int getOriginY();
	int getRadius();
	void setOriginX(int _x);
	void setOriginY(int _y);
	void setRadius(int _r);

	circle();
	circle(int _x, int _y, int _r);


};

