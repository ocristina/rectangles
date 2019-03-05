#include "stdafx.h"
#include "CRectangleMap.h"


CRectangleMap::CRectangleMap()
{
}


CRectangleMap::~CRectangleMap()
{
}



bool CRectangleMap::Exists(CHashKey& set_key)
{
	return  m_mapStorage.find(set_key) != m_mapStorage.end();
}


void CRectangleMap::AddNewResultRectangle(CHashKey& rc_orig, CRectangle& rc_rect)
{
	m_mapStorage[rc_orig] = rc_rect;
}

int CRectangleMap::Count()
{
	MAP_IT_RECTANGLES it;
	int nReturnVal = 0;

	if (!m_mapStorage.empty())
	{
		for (it = m_mapStorage.begin(); it != m_mapStorage.end(); it++)
			if (!it->second.isEmpty())
				++nReturnVal;
	}
	return nReturnVal;
}

CRectangleMap CRectangleMap::GenerateIntersectionSet()
{
	MAP_IT_RECTANGLES it1, it2, aux,last = m_mapStorage.end();
	CRectangle cIntersect;
	CRectangleMap cmapResult;
	

	if (Count() < 2) return cmapResult;  // not enough triangles to intersect
	--last;
	for(it1 = m_mapStorage.begin();it1 != last;it1++)
		for (aux = it1, it2 = ++aux; it2 != m_mapStorage.end(); it2++)
		{

			CHashKey cKey = it1->first.merge(it2->first);
	        
			if (cmapResult.m_mapStorage.find(cKey) != cmapResult.m_mapStorage.end())
				continue;
			cIntersect = (it1->second).intersect(it2->second);
			cmapResult.AddNewResultRectangle(cKey, cIntersect);
		}
	cmapResult.filterOutEmptyRects();
	return cmapResult;
}



void CRectangleMap::PrintContents()
{
	MAP_IT_RECTANGLES it;
	int nCount = 0;

	for (it = m_mapStorage.begin(); it != m_mapStorage.end(); ++it)
		cout << "\t" << ++nCount << " : " << "Between Rectangle " << it->first.getDesc().c_str() << " " << (it->second).GetDescription().c_str() << endl;
}

void CRectangleMap::filterOutEmptyRects()
{
	vector<CHashKey>   vecKeysToRemove;

	for (MAP_IT_RECTANGLES it = m_mapStorage.begin(); it != m_mapStorage.end(); it++)
		if (it->second.isEmpty())
			vecKeysToRemove.push_back(it->first);
	for (vector<CHashKey>::iterator it = vecKeysToRemove.begin(); it != vecKeysToRemove.end(); it++)
		m_mapStorage.erase(*it);
}