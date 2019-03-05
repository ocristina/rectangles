#include "stdafx.h"

#include <iostream>
#include <fstream>
#include "CRectanglesFactory.h"

using namespace std;
using json = nlohmann::json;

CRectanglesFactory::CRectanglesFactory()
{
}


CRectanglesFactory::~CRectanglesFactory()
{
}

CRectangleVec CRectanglesFactory::CreateRectangles(const char *pszFileName)
{
	CRectangleVec cvecReturnVal;
	ifstream inputStream(pszFileName); 
	json j,arrayOfRects, rect;
	
	inputStream >> j;

	arrayOfRects = j["rects"];
	for (json::iterator it = arrayOfRects.begin(); it != arrayOfRects.end(); it++)
	{
		int nX, nY, nWidth, nHeight;

		rect = *it;
		nX = rect["x"].get<int>();
		nY = rect["y"].get<int>();
		nWidth = rect["w"].get<int>();
		nHeight = rect["h"].get<int>();
		cvecReturnVal.AddNewRectangle(nX, nY, nWidth, nHeight);
	}
	return cvecReturnVal;
}