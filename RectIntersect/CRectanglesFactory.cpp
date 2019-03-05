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
	ifstream inputStream; 
	json j,arrayOfRects, rect;
	
	try
	{
		inputStream.open(pszFileName);
	}
	catch (...)
	{
		throw std::runtime_error("could not open the file for reading");
	}
	if (inputStream.fail())
	{
		throw std::runtime_error("could not open the file for reading");
	}
	
	try
	{
		inputStream >> j;
	}
	catch (json::parse_error xception)
	{
		throw runtime_error(string("parse error, failed to parse the input .json file, error : ") + xception.what()); //sprintf_s(buffer, "failed to parse the input .json file, error : %s", xception.what());
	}
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