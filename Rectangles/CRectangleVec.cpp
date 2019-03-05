#include "stdafx.h"
#include "CRectangleVec.h"



CRectangleVec::CRectangleVec()
{
}



CRectangleVec::~CRectangleVec()
{
}

void CRectangleVec::AddNewRectangle(int n_x, int n_y, int n_width, int n_height)
{
	m_vecRects.push_back(CRectangle(n_x, n_y, n_width, n_height));
}

CRectangleMap CRectangleVec::GenerateIntersectionSet()
{
	VEC_IT_RECTANGLES it1, it2;
	CRectangle cResultRect;
	CRectangleMap cmapRetVal;

	int nIndex1, nIndex2;


	nIndex1 = 1;  // One-based

	for (it1 = m_vecRects.begin(); it1 != m_vecRects.end() - 1; it1++,nIndex1++)
		for (nIndex2 = nIndex1 + 1,it2 = it1 + 1; it2 != m_vecRects.end(); it2++, nIndex2++)
		{
			set<int> set_key;
		
			cResultRect = it1->intersect(*it2);
			if (cResultRect.isEmpty())
				continue;
			set_key.insert(nIndex1);
			set_key.insert(nIndex2);
			cmapRetVal.AddNewResultRectangle(set_key, cResultRect);
		}
	return cmapRetVal;
}

int CRectangleVec::Count()
{
	return (int)(m_vecRects.size());
}

void CRectangleVec::PrintContents()
{
	int nIndex = 1;

	for (VEC_IT_RECTANGLES it = m_vecRects.begin(); it != m_vecRects.end(); it++)
		cout << "\t" << nIndex++ << ": Rectangle " << (it->GetDescription()).c_str() << endl;
}