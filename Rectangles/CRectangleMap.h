#pragma once

#include "CRectangle.h"


class CRectangleMap 
{
public:
	CRectangleMap();
	~CRectangleMap();

	bool Exists(set<int>);
	void AddNewResultRectangle(set<int>& rset_orig, CRectangle& rc_rect);
	CRectangleMap GenerateIntersectionSet();
	int  Count();
	void PrintContents();

private:
	MAP_RECTANGLES m_mapStorage;

	set<int> merge(set<int> set_tgt,const set<int> & rset_src);
	string getIntersectionOperands(const set<int>&);
	void filterOutEmptyRects();
};

typedef vector<CRectangleMap> VEC_CONTAINERS;
typedef vector<CRectangleMap>::iterator VEC_IT_CONTAINERS;