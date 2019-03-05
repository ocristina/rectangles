#pragma once

#include "CRectangle.h"


class CRectangleMap 
{
public:
	CRectangleMap();
	~CRectangleMap();

	bool Exists(CHashKey&);

	void AddNewResultRectangle(CHashKey& rset_orig, CRectangle& rc_rect);
	CRectangleMap GenerateIntersectionSet();
	int  Count();
	void PrintContents();

private:
	MAP_RECTANGLES m_mapStorage;


	string getIntersectionOperands(const CHashKey&);
	void filterOutEmptyRects();
};

typedef vector<CRectangleMap> VEC_CONTAINERS;
typedef vector<CRectangleMap>::iterator VEC_IT_CONTAINERS;