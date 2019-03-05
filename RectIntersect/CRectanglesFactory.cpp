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
	int nCounter = 1;
	
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
		throw runtime_error(string("parse error, failed to parse the input .json file, error : ") + xception.what()); 
	}

	try 
	{
		arrayOfRects = j["rects"];
	}
	catch (...)
	{
		throw runtime_error(string("Failed to read full array"));
	}

	for (json::iterator it = arrayOfRects.begin(); it != arrayOfRects.end(); it++,nCounter++)
	{
		int nX, nY, nWidth, nHeight ;
		char chCurrentKey;

		rect = *it;
		try
		{
			chCurrentKey = 'x';
			nX = rect["x"].get<int>();
			chCurrentKey = 'y';
			nY = rect["y"].get<int>();
			chCurrentKey = 'w';
			nWidth = rect["w"].get<int>();
			chCurrentKey = 'h';
			nHeight = rect["h"].get<int>();
		}
		catch (json::type_error xception)
		{
			char buf[256];

			cout << "Exception;";
			sprintf_s(buf, "Failed to obtain coordinates for rectangle %d\nTrouble reading key '%c'\nProblem description : ", 
				nCounter,
				chCurrentKey);
			throw runtime_error(string(buf) +  xception.what());
		}
		cvecReturnVal.AddNewRectangle(nX, nY, nWidth, nHeight);
	}
	return cvecReturnVal;
}