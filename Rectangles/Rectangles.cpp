// Rectangles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\RectIntersect\CRectangleVec.h"
#include "..\RectIntersect\CRectanglesFactory.h"

using namespace std;

int main(int argc, char* argv[])
{
	int nInitialSize;
	CRectanglesFactory cFactory;
	CRectangleVec cInitialRectangles;
	CRectangleMap cLatestIntersectionSet;

	if (argc == 1)
	{
		cout << "Usage:" << endl
			<< argv[0] << " <json file with the triangle description data>" << endl;
		return 1;
	}
	try
	{
		cInitialRectangles = cFactory.CreateRectangles(argv[1]);
	}
	catch (const char *pchErrorDesc)
	{
		cout << pchErrorDesc << endl;
		return 3;
	}
	catch (string xception)
	{
		cout << xception << endl;
		return 3;
	}
	catch (runtime_error xception)
	{
		cout << "Error...failure to read triangle data from file" << endl << xception.what() << endl;
		return 2;
	}
	catch (...)
	{
		cout << "unknown error";
		return 4;
	}

	nInitialSize = cInitialRectangles.Count();
	cout << "Input:" << endl;
	if (!nInitialSize)
		cout << "None" << endl;
	else
	    cInitialRectangles.PrintContents();
	cout << "Intersections" << endl;
	if (2 > nInitialSize)
	{
		cout << "N/A" << endl;
		return 0;
	}
	cLatestIntersectionSet = cInitialRectangles.GenerateIntersectionSet();
	cLatestIntersectionSet.PrintContents();
	while (cLatestIntersectionSet.Count() > 1)
	{
		cLatestIntersectionSet = cLatestIntersectionSet.GenerateIntersectionSet();
		cLatestIntersectionSet.PrintContents();
	}


    return 0;
}

