#include "stdafx.h"
#include "CRectangleMap.h"


CRectangleMap::CRectangleMap()
{
}


CRectangleMap::~CRectangleMap()
{
}


bool CRectangleMap::Exists(set<int> set_key)
{
	return  m_mapStorage.find(set_key) != m_mapStorage.end();
}

void CRectangleMap::AddNewResultRectangle(set<int>& rset_orig, CRectangle& rc_rect)
{
	m_mapStorage[rset_orig] = rc_rect;
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

	--last;
	for(it1 = m_mapStorage.begin();it1 != last;it1++)
		for (aux = it1, it2 = ++aux; it2 != m_mapStorage.end(); it2++)
		{
			set<int> setOrig = merge(it1 -> first, it2->first);
	        
			if (cmapResult.m_mapStorage.find(setOrig) != cmapResult.m_mapStorage.end())
				continue;
			cIntersect = (it1->second).intersect(it2->second);
			cmapResult.AddNewResultRectangle(setOrig, cIntersect);
		}
	cmapResult.filterOutEmptyRects();
	return cmapResult;
}

set<int> CRectangleMap::merge(set<int> set_tgt,const set<int>& rset_src)
{
	for (set<int>::iterator it = rset_src.begin(); it != rset_src.end(); it++)
		set_tgt.insert(*it);
	return set_tgt;
}

string CRectangleMap::getIntersectionOperands(const set<int>& rset_key)
{
	char szBuffer[16];
	set<int>::iterator last = rset_key.end(),it = rset_key.begin();

	last--;
	sprintf_s(szBuffer, "%d", *it++ );
	string strRetVal(szBuffer);
	for (; it != last; it++)
	{
		sprintf_s(szBuffer, ", %d", *it);
		strRetVal += szBuffer;
	}
	sprintf_s(szBuffer, " and %d", *last);
	strRetVal += szBuffer;
	return strRetVal;
}

void CRectangleMap::PrintContents()
{
	MAP_IT_RECTANGLES it;
	int nCount = 0;

	for (it = m_mapStorage.begin(); it != m_mapStorage.end(); ++it)
		cout << "\t" << ++nCount << " : " << "Between Rectangle " << getIntersectionOperands(it->first).c_str() << " " << (it->second).GetDescription().c_str() << endl;
}

void CRectangleMap::filterOutEmptyRects()
{
	vector<set<int>> vecKeysToRemove;

	for (MAP_IT_RECTANGLES it = m_mapStorage.begin(); it != m_mapStorage.end(); it++)
		if (it->second.isEmpty())
			vecKeysToRemove.push_back(it->first);
	for (vector<set<int>>::iterator it = vecKeysToRemove.begin(); it != vecKeysToRemove.end(); it++)
		m_mapStorage.erase(*it);
}