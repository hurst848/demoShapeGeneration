#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "line.h"
#include "D:\CPP Projects\SDL2Project_GOOP\util.h"
class ridgidShape
{
public:

	struct points
	{
		int x;
		int y;
	};


	std::vector<line> poly;
	std::vector<points> verticies;
	int sides;
	int vertexNum;

	ridgidShape();
	ridgidShape(int numSides);
};

