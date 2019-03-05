#pragma once

#include "CRectangle.h"
#include "CRectangleMap.h"

class CRectangleVec 
{
public:
	CRectangleVec();
	~CRectangleVec();

	void AddNewRectangle(int n_x, int n_y, int n_width, int n_height);
	CRectangleMap GenerateIntersectionSet();
	int Count();
	void PrintContents();

private:
	VEC_RECTANGLES m_vecRects;
};

