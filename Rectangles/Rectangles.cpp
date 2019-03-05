// Rectangles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "..\RectIntersect\CRectangleVec.h"
#include "..\RectIntersect\CRectanglesFactory.h"

using namespace std;

int main(int argc, char* argv[])
{
	CRectanglesFactory cFactory;
	CRectangleVec cInitialRectangles;
	CRectangleMap cLatestIntersectionSet;

	cInitialRectangles = cFactory.CreateRectangles(argv[1]);

	cout << "Beginning of program" << endl;
	cout << "Input:" << endl;
	cInitialRectangles.PrintContents();
	cout << "Intersections" << endl;

	cLatestIntersectionSet = cInitialRectangles.GenerateIntersectionSet();
	cLatestIntersectionSet.PrintContents();
	while (cLatestIntersectionSet.Count() > 1)
	{
		cLatestIntersectionSet = cLatestIntersectionSet.GenerateIntersectionSet();
		cLatestIntersectionSet.PrintContents();
	}

	cout << "End of Program" << endl;
    return 0;
}

