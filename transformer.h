#pragma once
#include <cmath>
#include "ridgidShape.h"
#include "circle.h"
#include "display.h"
struct tmpPoint
{
	float x;
	float y;
};

class transformer
{
public:
	
	void sendToDisplay(ridgidShape shape, display* ptr, bool fill);
	void sendToDisplay(circle shape, display* ptr);
	
	
	void translate(ridgidShape *shape, int dirX, int dirY);
	void translate(circle *shape, int dirX, int dirY);
	

	void scale(ridgidShape *shape, float _mx, float _my);
	void scale(circle *shape, int _m);


	void reflect(ridgidShape *shape, int _ri, bool _xoy);
	void reflect(circle *shape, int _ri, bool _xoy);
	// if _xoy == true, reflect over y = line, if_xoy == false, reflect over x = line 

	void rotate(ridgidShape *shape, int _x, int _y, int _deg);
	void rotate(ridgidShape *shape, int _deg);
	void rotate(circle *shape, int _x, int _y, int _deg);
	void rotate(circle *shape, int _deg);
	
	void matrixTranslate(ridgidShape* shape, int dirX, int dirY);
	void matrixScale(ridgidShape* shape, int dirX, int dirY);


private:
	bool hasPositiveSlope(line tmp);
	bool xIsGreater(line tmp);
	tmpPoint getSlope(line tmp);
	void drawCirclePoint(display* ptr, int origX, int origY, int _x, int _y);

};

