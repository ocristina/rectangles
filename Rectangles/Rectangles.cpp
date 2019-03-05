// Rectangles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "CRectangleVec.h"
#include "CRectanglesFactory.h"

using namespace std;

int main(int argc, char* argv[])
{
	CRectanglesFactory cFactory;
	CRectangleVec cInitialRectangles;
	VEC_CONTAINERS vecContainers;
	CRectangleMap cLatestIntersectionSet;

	cInitialRectangles = cFactory.CreateRectangles(argv[1]);

	cout << "Beginning of program" << endl;
	cout << "Input:" << endl;
	cInitialRectangles.PrintContents();
	cout << "Intersections" << endl;

	cLatestIntersectionSet = cInitialRectangles.GenerateIntersectionSet();
	vecContainers.push_back(cLatestIntersectionSet);
	cLatestIntersectionSet.PrintContents();
	while (cLatestIntersectionSet.Count() > 1)
	{
		cLatestIntersectionSet = cLatestIntersectionSet.GenerateIntersectionSet();
		vecContainers.push_back(cLatestIntersectionSet);
		cLatestIntersectionSet.PrintContents();
	}
	if (!(cLatestIntersectionSet.Count()))
		vecContainers.pop_back();
	for (VEC_IT_CONTAINERS it = vecContainers.begin(); it != vecContainers.end(); it++)
		it -> PrintContents();

	cout << "End of Program" << endl;
    return 0;
}

