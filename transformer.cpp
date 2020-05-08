#include "transformer.h"
// Send to Screen Functions //
void transformer::sendToDisplay(ridgidShape shape, display* ptr, bool fill)
{
	for (int i = 0; i < shape.sides; i++)
	{
		if (shape.poly[i].getX1() == shape.poly[i].getX2())
		{
			// draw vertical line
			if (shape.poly[i].getY1() <= shape.poly[i].getY2())
			{
				for (int j = shape.poly[i].getY1(); j <= shape.poly[i].getY2(); j++)
				{
					ptr->updatePixel(shape.poly[i].getX1(), j, 255, 0, 0, 255);
				}
			}
			else
			{
				for (int j = shape.poly[i].getY1(); j >= shape.poly[i].getY2(); j--)
				{
					ptr->updatePixel(shape.poly[i].getX1(), j, 255, 0, 0, 255);
				}
			}
			
		}
		else if (shape.poly[i].getY1() == shape.poly[i].getY2())
		{
			// draw horizontal line
			if (shape.poly[i].getX1() <= shape.poly[i].getX2())
			{
				for (int j = shape.poly[i].getX1(); j <= shape.poly[i].getX2(); j++)
				{
					//ptr->screen[j][shape.poly[i].getY1()];
					ptr->updatePixel(j, shape.poly[i].getY1(), 255, 0, 0, 255);
				}
			}
			else
			{
				for (int j = shape.poly[i].getX1(); j >= shape.poly[i].getX2(); j--)
				{
					//ptr->screen[j][shape.poly[i].getY1()];
					ptr->updatePixel(j, shape.poly[i].getY1(), 255, 0, 0, 255);
				}
			}
		}
		else if (getSlope(shape.poly[i]).x / getSlope(shape.poly[i]).y == 1 || getSlope(shape.poly[i]).x / getSlope(shape.poly[i]).y == -1)
		{
			if (getSlope(shape.poly[i]).x / getSlope(shape.poly[i]).y == 1)
			{
				if (shape.poly[i].getX1() < shape.poly[i].getX2())
				{
					int cntY = shape.poly[i].getY1();
					for (int j = shape.poly[i].getX1(); j < shape.poly[i].getX2(); j++)
					{
						ptr->updatePixel(j, cntY, 255, 0, 0, 255);
						cntY++;
					}
				}
				else
				{
					int cntY = shape.poly[i].getY2();
					for (int j = shape.poly[i].getX2(); j < shape.poly[i].getX1(); j++)
					{
						ptr->updatePixel(j, cntY, 255, 0, 0, 255);
						cntY++;
					}
				}
			}
			else
			{
				if (shape.poly[i].getX1() < shape.poly[i].getX2())
				{
					int cntY = shape.poly[i].getY1();
					int cntX = shape.poly[i].getX1();
					for (int j = shape.poly[i].getX1(); j < shape.poly[i].getX2(); j++)
					{
						ptr->updatePixel(cntX, cntY, 255, 0, 0, 255);
						cntY--;
						cntX--;
					}
				}
				else
				{
					int cntY = shape.poly[i].getY2();
					int cntX = shape.poly[i].getX2();
					for (int j = shape.poly[i].getX2(); j < shape.poly[i].getX1(); j++)
					{
						ptr->updatePixel(cntX, cntY, 255, 0, 0, 255);
						cntY--;
						cntX--;
					}
				}
			}
		}
		else if (hasPositiveSlope(shape.poly[i]))
		{
			
			
			if (xIsGreater(shape.poly[i]))
			{
				if (shape.poly[i].getX1() <= shape.poly[i].getX2())
				{
					float y = 1; 
					float x = getSlope(shape.poly[i]).x / getSlope(shape.poly[i]).y;
					float slopeErr = x - ((float)((int)(x)));
					int rlx = (((int)(x)));
					int k = shape.poly[i].getY1();
					float errAdd = 0;
					int cntr = 0;
					for (int j = shape.poly[i].getX1(); j <= shape.poly[i].getX2(); j++)
					{
						if (errAdd >= 1.0f)
						{
							rlx++;
							errAdd = 0;
						}
						ptr->updatePixel(j, k, 255, 0, 0, 255);
						if (cntr == rlx)
						{
							k++;
							rlx = (((int)(x)));
							errAdd += slopeErr;
							cntr = 0;
						}
						cntr++;
					}
				}
				else
				{
					float y = 1;
					float x = getSlope(shape.poly[i]).x / getSlope(shape.poly[i]).y;
					float slopeErr = x - ((float)((int)(x)));
					int rlx = (((int)(x)));
					int k = shape.poly[i].getY1();
					float errAdd = 0;
					int cntr = 0;
					for (int j = shape.poly[i].getX1(); j >= shape.poly[i].getX2(); j--)
					{
						if (errAdd >= 1.0f)
						{
							rlx++;
							errAdd = 0;
						}
						ptr->updatePixel(j, k, 255, 0, 0, 255);
						if (cntr == rlx)
						{
							k--;
							rlx = (((int)(x)));
							errAdd += slopeErr;
							cntr = 0;
						}
						cntr++;
					}
				}
			}
			else
			{
				if (shape.poly[i].getX1() <= shape.poly[i].getX2())
				{
					float x = 1;
					float y = getSlope(shape.poly[i]).y / getSlope(shape.poly[i]).x;
					float slopeErr = y - ((float)((int)(y)));
					int rly = ((int)(y));
					int k = shape.poly[i].getX1();
					float errAdd = 0;
					int cntr = 0;
					for (int j = shape.poly[i].getY1(); j <= shape.poly[i].getY2(); j++)
					{
						if (errAdd >= 1.0f)
						{
							rly++;
							errAdd = 0;
						}
						ptr->updatePixel(k, j, 255, 0, 0, 255);
						if (cntr == rly)
						{
							k++;
							rly = (((int)(y)));
							errAdd += slopeErr;
							cntr = 0;
						}
						cntr++;
					}
				}
				else
				{
					float x = 1;
					float y = getSlope(shape.poly[i]).y / getSlope(shape.poly[i]).x;
					float slopeErr = y - ((float)((int)(y)));
					int rly = (((int)(y)));
					int k = shape.poly[i].getX1();
					float errAdd = 0;
					int cntr = 0;
					for (int j = shape.poly[i].getY1(); j >= shape.poly[i].getY2(); j--)
					{
						if (errAdd >= 1.0f)
						{
							rly++;
							errAdd = 0;
						}
						ptr->updatePixel(k, j, 255, 0, 0, 255);
						if (cntr == rly)
						{
							k--;
							rly = (((int)(y)));
							errAdd += slopeErr;
							cntr = 0;
						}
						cntr++;
					}
				}
			}
		
		
		
		}
		else
		{
				// NEGATIVE SLOPES


			if (xIsGreater(shape.poly[i]))
			{
				if (shape.poly[i].getX1() <= shape.poly[i].getX2())
				{
					float y = 1;
					float x = abs(getSlope(shape.poly[i]).x / getSlope(shape.poly[i]).y);
					float slopeErr = x - ((float)((int)(x)));
					int rlx = (((int)(x)));
					int k = shape.poly[i].getY1();
					float errAdd = 0;
					int cntr = 0;
					for (int j = shape.poly[i].getX1(); j <= shape.poly[i].getX2(); j++)
					{
						if (errAdd >= 1.0f)
						{
							rlx++;
							errAdd = 0;
						}
						ptr->updatePixel(j, k, 255, 0, 0, 255);
						if (cntr == rlx)
						{
							k--;
							rlx = (((int)(x)));
							errAdd += slopeErr;
							cntr = 0;
						}
						cntr++;
					}
				
				}
				else
				{
					float y = 1;
					float x = abs(getSlope(shape.poly[i]).x / getSlope(shape.poly[i]).y);
					float slopeErr = x - ((float)((int)(x)));
					int rlx = (((int)(x)));
					int k = shape.poly[i].getY1();
					float errAdd = 0;
					int cntr = 0;
					for (int j = shape.poly[i].getX1(); j >= shape.poly[i].getX2(); j--)
					{
						if (errAdd >= 1.0f)
						{
							rlx++;
							errAdd = 0;
						}
						ptr->updatePixel(j, k, 255, 0, 0, 255);
						if (cntr == rlx)
						{
							k++;
							rlx = (((int)(x)));
							errAdd += slopeErr;
							cntr = 0;
						}
						cntr++;
					}
					
				}

			}
			else
			{
				if (shape.poly[i].getX1() <= shape.poly[i].getX2())
				{
					float x = 1;
					float y = abs(getSlope(shape.poly[i]).y / getSlope(shape.poly[i]).x);
					float slopeErr = y - ((float)((int)(y)));
					int rly = ((int)(y));
					int k = shape.poly[i].getX1();
					float errAdd = 0;
					int cntr = 0;
					for (int j = shape.poly[i].getY1(); j >= shape.poly[i].getY2(); j--)
					{
						if (errAdd >= 1.0f)
						{
							rly++;
							errAdd = 0;
						}
						ptr->updatePixel(k, j, 255, 0, 0, 255);
						if (cntr == rly)
						{
							k++;
							rly = (((int)(y)));
							errAdd += slopeErr;
							cntr = 0;
						}
						cntr++;
					}
				}
				else
				{
					float x = 1;
					float y = abs(getSlope(shape.poly[i]).y / getSlope(shape.poly[i]).x);
					float slopeErr = y - ((float)((int)(y)));
					int rly = ((int)(y));
					int k = shape.poly[i].getX1();
					float errAdd = 0;
					int cntr = 0;
					for (int j = shape.poly[i].getY1(); j <= shape.poly[i].getY2(); j++)
					{
						if (errAdd >= 1.0f)
						{
							rly++;
							errAdd = 0;
						}
						ptr->updatePixel(k, j, 255, 0, 0, 255);
						if (cntr == rly)
						{
							k--;
							rly = (((int)(y)));
							errAdd += slopeErr;
							cntr = 0;
						}
						cntr++;
					}
					
				}
				
			}


		}

	}
}
void transformer::sendToDisplay(circle shape, display* ptr)
{
	int x = 0;
	int y = shape.getRadius();
	int d = 3 - (2 * shape.getRadius());
	drawCirclePoint(ptr, shape.getOriginX(), shape.getOriginY(), x, y);
	while (y >= x)
	{
		x++;

		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
		{
			d = d + 4 * x + 6;
		}
		drawCirclePoint(ptr, shape.getOriginX(), shape.getOriginY(), x, y);
	}
}
// ------------------------ //


bool transformer::hasPositiveSlope(line tmp)
{
	//tmpPoint slope = getSlope(tmp);
	float posneg = ((float)(tmp.getY2()) - ((float)tmp.getY1())) / (((float)(tmp.getX2()) - ((float)tmp.getX1())));
	if ( posneg >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool transformer::xIsGreater(line tmp)
{
	
	tmpPoint slope = getSlope(tmp);
	if (abs(slope.x) > abs(slope.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}
tmpPoint transformer::getSlope(line tmp)
{
	tmpPoint rtrn;
	rtrn.x = (tmp.getX2() - tmp.getX1());
	rtrn.y = (tmp.getY2() - tmp.getY1());

	return rtrn;
}
void transformer::drawCirclePoint(display* ptr, int origX, int origY, int _x, int _y)
{
	ptr->updatePixel(origX + _x, origY + _y, 255, 0, 0, 255);
	ptr->updatePixel(origX - _x, origY + _y, 255, 0, 0, 255);
	ptr->updatePixel(origX + _x, origY - _y, 255, 0, 0, 255);
	ptr->updatePixel(origX - _x, origY - _y, 255, 0, 0, 255);
	ptr->updatePixel(origX + _y, origY + _x, 255, 0, 0, 255);
	ptr->updatePixel(origX - _y, origY + _x, 255, 0, 0, 255);
	ptr->updatePixel(origX + _y, origY - _x, 255, 0, 0, 255);
	ptr->updatePixel(origX - _y, origY - _x, 255, 0, 0, 255);
}



void transformer::translate(ridgidShape *shape, int dirX, int dirY)
{
	if (dirX != 0)
	{
		for (int i = 0; i < shape->sides; i++)
		{
			shape->poly[i].setX1(shape->poly[i].getX1() + dirX);
			shape->poly[i].setX2(shape->poly[i].getX2() + dirX);
		}
	}
	if (dirY != 0)
	{
		for (int i = 0; i < shape->sides; i++)
		{
			shape->poly[i].setY1(shape->poly[i].getY1() + dirY);
			shape->poly[i].setY2(shape->poly[i].getY2() + dirY);
		}
	}
}
void transformer::translate(circle *shape, int dirX, int dirY)
{
	if (dirX != 0)
	{
		shape->setOriginX(shape->getOriginX() + dirX);
	}
	if (dirY != 0)
	{
		shape->setOriginY(shape->getOriginY() + dirY);
	}
}

void transformer::scale(ridgidShape *shape, float _mx, float _my)
{
	if (_mx != 0)
	{
		for (int i = 0; i < shape->sides; i++)
		{
			shape->poly[i].setX1((int)((float)(shape->poly[i].getX1()) * _mx));
			shape->poly[i].setX2((int)((float)(shape->poly[i].getX2()) * _mx));
			shape->poly[i].vector.x = shape->poly[i].vector.x * _mx;
		}
	}
	if (_my != 0)
	{
		for (int i = 0; i < shape->sides; i++)
		{
			shape->poly[i].setY1((int)((float)(shape->poly[i].getY1()) * _my));
			shape->poly[i].setY2((int)((float)(shape->poly[i].getY2()) * _my));
			shape->poly[i].vector.y = shape->poly[i].vector.y * _my;
		}
	}
}
void transformer::scale(circle *shape, int _m)
{
	shape->setRadius(shape->getRadius() * _m);
}

void transformer::reflect(ridgidShape *shape, int _ri, bool _xoy)
{
	if (_xoy == true) // reflect over y = line 
	{
		for (int i = 0; i < shape->sides; i++)
		{
			int dif1;
			int dif2;
			if (_ri > shape->poly[i].getY1())
			{
				dif1 = _ri - shape->poly[i].getY1();
				shape->poly[i].setY1(_ri + dif1);
			}
			else if (_ri < shape->poly[i].getY1())
			{
				dif1 = shape->poly[i].getY1() - _ri;
				shape->poly[i].setY1(_ri - dif1);
			}
			else
			{
				// the point lies on the line of reflection so dont do anything
			}

			if (_ri > shape->poly[i].getY2())
			{
				dif2 = _ri - shape->poly[i].getY2();
				shape->poly[i].setY2(_ri + dif2);
			}
			else if (_ri < shape->poly[i].getY2())
			{
				dif2 = shape->poly[i].getY2() - _ri;
				shape->poly[i].setY2(_ri - dif2);
			}
			else
			{
				// the point lies on the line of reflection so dont do anything
			}
		}
	}
	else if (_xoy == false) // reflect over x = line
	{
		for (int i = 0; i < shape->sides; i++)
		{
			int dif1;
			int dif2;
			if (_ri > shape->poly[i].getX1())
			{
				dif1 = _ri - shape->poly[i].getX1();
				shape->poly[i].setX1(_ri + dif1);
			}
			else if (_ri < shape->poly[i].getX1())
			{
				dif1 = shape->poly[i].getX1() - _ri;
				shape->poly[i].setX1(_ri - dif1);
			}
			else
			{
				// the point lies on the line of reflection so dont do anything
			}

			if (_ri > shape->poly[i].getX2())
			{
				dif2 = _ri - shape->poly[i].getX2();
				shape->poly[i].setX2(_ri + dif2);
			}
			else if (_ri < shape->poly[i].getX2())
			{
				dif2 = shape->poly[i].getX2() - _ri;
				shape->poly[i].setX2(_ri - dif2);
			}
			else
			{
				// the point lies on the line of reflection so dont do anything
			}
		}
	}
}
void transformer::reflect(circle *shape, int _ri, bool _xoy)
{
	if (_xoy == true) // reflect over y = line
	{
		int dif;
		if (_ri > shape->getOriginY())
		{
			dif = _ri - shape->getOriginY();
			shape->setOriginY(_ri + dif);
		}
		else if (_ri < shape->getOriginY())
		{
			dif = shape->getOriginY() - _ri;
			shape->setOriginY(_ri - dif);
		}
		else
		{
			// the point lies on the line of reflection so dont do anything
		}
	}
	else if (_xoy == false) // reflect over x = line
	{
		int dif;
		if (_ri > shape->getOriginX())
		{
			dif = _ri - shape->getOriginX();
			shape->setOriginX(_ri + dif);
		}
		else if (_ri < shape->getOriginX())
		{
			dif = shape->getOriginX() - _ri;
			shape->setOriginX(_ri - dif);
		}
		else
		{
			// the point lies on the line of reflection so dont do anything
		}
	}
	

}

void transformer::rotate(ridgidShape *shape, int _x, int _y, int _deg)
{
	float s = sin(_deg);
	float c = cos(_deg);
	for (int i = 0; i < shape->sides; i++)
	{
		shape->poly[i].setX1(shape->poly[i].getX1() - _x);
		shape->poly[i].setY1(shape->poly[i].getY1() - _y);
		float xp1 = shape->poly[i].getX1() * c - shape->poly[i].getY1() * s;
		float yp1 = shape->poly[i].getX1() * s + shape->poly[i].getY1() * c;
		shape->poly[i].setX1((int)(xp1) + _x);
		shape->poly[i].setY1((int)(yp1)+_y);


		shape->poly[i].setX2(shape->poly[i].getX2() - _x);
		shape->poly[i].setY2(shape->poly[i].getY2() - _y);
		float xp2 = shape->poly[i].getX2() * c - shape->poly[i].getY2() * s;
		float yp2 = shape->poly[i].getX2() * s + shape->poly[i].getY2() * c;
		shape->poly[i].setX2((int)(xp2)+_x);
		shape->poly[i].setY2((int)(yp2)+_y);
	}
}
void transformer::rotate(ridgidShape *shape, int _deg)
{
	int _x = 0;
	int _y = 0;
	for (int i = 0; i < shape->sides; i++)
	{
		_x += shape->poly[i].getX1();
		_y += shape->poly[i].getY1();
	}
	_x /= shape->sides;
	_y /= shape->sides;
	
	
	float s = sin(_deg);
	float c = cos(_deg);
	for (int i = 0; i < shape->sides; i++)
	{
		shape->poly[i].setX1(shape->poly[i].getX1() - _x);
		shape->poly[i].setY1(shape->poly[i].getY1() - _y);
		float xp1 = shape->poly[i].getX1() * c - shape->poly[i].getY1() * s;
		float yp1 = shape->poly[i].getX1() * s + shape->poly[i].getY1() * c;
		shape->poly[i].setX1((int)(xp1)+_x);
		shape->poly[i].setY1((int)(yp1)+_y);


		shape->poly[i].setX2(shape->poly[i].getX2() - _x);
		shape->poly[i].setY2(shape->poly[i].getY2() - _y);
		float xp2 = shape->poly[i].getX2() * c - shape->poly[i].getY2() * s;
		float yp2 = shape->poly[i].getX2() * s + shape->poly[i].getY2() * c;
		shape->poly[i].setX2((int)(xp2)+_x);
		shape->poly[i].setY2((int)(yp2)+_y);
	}
}
void transformer::rotate(circle *shape, int _x, int _y, int _deg)
{
	float s = sin(_deg);
	float c = cos(_deg);
	shape->setOriginX(shape->getOriginX() - _x);
	shape->setOriginY(shape->getOriginY() - _y);
	float xp1 = shape->getOriginX() * c - shape->getOriginY() * s;
	float yp1 = shape->getOriginX() * s + shape->getOriginY() * c;
	shape->setOriginX((int)(xp1)+_x);
	shape->setOriginY((int)(yp1)+_y);
}
void transformer::rotate(circle *shape, int _deg)
{
	int _x = shape->getOriginX();
	int _y = shape->getOriginY();

	float s = sin(_deg);
	float c = cos(_deg);
	shape->setOriginX(shape->getOriginX() - _x);
	shape->setOriginY(shape->getOriginY() - _y);
	float xp1 = shape->getOriginX() * c - shape->getOriginY() * s;
	float yp1 = shape->getOriginX() * s + shape->getOriginY() * c;
	shape->setOriginX((int)(xp1)+_x);
	shape->setOriginY((int)(yp1)+_y);
}

void transformer::matrixTranslate(ridgidShape* shape, int dirX, int dirY)
{
	glm::mat4 translateMatrix = {{1 , 0 , 0 , dirX},
								 {0 , 1 , 0 , dirY },
								 {0 , 0 , 1 , 0},
								 {0 , 0 , 0 , 1} };

	for (int i = 0; i < shape->sides; i++)
	{
		glm::vec4 tempP1;
		tempP1.x = shape->poly[i].getX1();
		tempP1.y = shape->poly[i].getY1();
		tempP1.z = 0;
		tempP1.w = 1;

		glm::vec4 tempP2;
		tempP1.x = shape->poly[i].getX2();
		tempP1.y = shape->poly[i].getY2();
		tempP1.z = 0;
		tempP1.w = 1;

		tempP1 = translateMatrix * tempP1;
		tempP2 = translateMatrix * tempP2;

		shape->poly[i].setX1(tempP1.x);
		shape->poly[i].setY1(tempP1.y);
		shape->poly[i].setX2(tempP2.x);
		shape->poly[i].setY2(tempP2.y);
	}
}
void transformer::matrixScale(ridgidShape* shape, int dirX, int dirY)
{
	glm::mat4 scaleMatrix = { {dirX , 0    , 0 , 0},
							  {0    , dirY , 0 , 0 },
							  {0    , 0    , 0 , 0},
							  {0    , 0    , 0 , 1} };
	for (int i = 0; i < shape->sides; i++)
	{
		glm::vec4 tempP1;
		tempP1.x = shape->poly[i].getX1();
		tempP1.y = shape->poly[i].getY1();
		tempP1.z = 0;
		tempP1.w = 1;

		glm::vec4 tempP2;
		tempP1.x = shape->poly[i].getX2();
		tempP1.y = shape->poly[i].getY2();
		tempP1.z = 0;
		tempP1.w = 1;

		tempP1 = scaleMatrix * tempP1;
		tempP2 = scaleMatrix * tempP1;

		shape->poly[i].setX1(tempP1.x);
		shape->poly[i].setY1(tempP1.y);
		shape->poly[i].setX2(tempP2.x);
		shape->poly[i].setY2(tempP2.y);
	}
}