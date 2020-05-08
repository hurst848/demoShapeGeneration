#include "ridgidShape.h"


ridgidShape::ridgidShape()
{
	vertexNum = 0;
	sides = 0;
	for (int i = 0; i < 3; i++)
	{
		points temp;
		temp.x = i * 5;
		temp.y = i * 5;
		verticies.push_back(temp);
		vertexNum++;
	}
	for (int i = 0; i < vertexNum; i++)
	{
		int tmpX1;
		int tmpY1;
		int tmpY2;
		int tmpX2;
		if (i = (vertexNum - 1))
		{
			tmpX1 = verticies[i].x;
			tmpY1 = verticies[i].y;
			tmpX2 = verticies[0].x;
			tmpY2 = verticies[0].y;
		}
		else
		{
			tmpX1 = verticies[i].x;
			tmpY1 = verticies[i].y;
			tmpX2 = verticies[i+1].x;
			tmpY2 = verticies[i+1].y;
		}
		line tmp(tmpX1,tmpY1, tmpX2,tmpY2);
		poly.push_back(tmp);
		sides++;
	}
}

ridgidShape::ridgidShape(int numSides)
{

	
	for (int i = 0; i < numSides; i++)
	{
		points temp; 
		std::cout << "enter X coord: " << std::endl;								
		temp.x = readInt();
		std::cout << "enter Y coord: " << std::endl;
		temp.y = readInt();
		verticies.push_back(temp);
	
		
	}
	
	
	for (int i = 0; i < numSides; i++)
	{
		int tmpX1 = 0;
		int tmpY1 = 0;
		int tmpY2 = 0;
		int tmpX2 = 0;
		if (i == (numSides - 1))
		{
			tmpX1 = verticies[i].x;
			tmpY1 = verticies[i].y;
			tmpX2 = verticies[0].x;
			tmpY2 = verticies[0].y;
		}
		else
		{
			tmpX1 = verticies[i].x;
			tmpY1 = verticies[i].y;
			tmpX2 = verticies[i + 1].x;
			tmpY2 = verticies[i + 1].y;
		}
		line tmp(tmpX1, tmpY1, tmpX2, tmpY2);
		
		poly.push_back(tmp);
		
		
	}
	sides = numSides;
	vertexNum = numSides;


}