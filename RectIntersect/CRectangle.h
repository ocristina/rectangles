#pragma once

#include <unordered_map>
#include <vector>

#include "CHashKey.h"

using namespace std;

class CRectangle
{
public:
	CRectangle() { m_bIsEmpty = true; }
	CRectangle(int n_x, int n_y, int n_width, int n_height) : 
		m_nX(n_x), 
		m_nY(n_y), 
		m_nWidth(n_width), 
		m_nHeight(n_height),
	    m_bIsEmpty(false)  {};
	~CRectangle();

	CRectangle intersect(CRectangle& other);
	string GetDescription();
	bool isEmpty() const { return m_bIsEmpty; }

	bool operator==(const CRectangle& other) const
	{
		if (m_bIsEmpty && other.isEmpty())
			return true;
		if (!m_bIsEmpty && !other.isEmpty())
			return m_nX == other.m_nX && 
			       m_nY == other.m_nY && 
			       m_nWidth == other.m_nWidth && 
			       m_nHeight == other.m_nHeight;
		return false;
	}

private:
	int m_nX;
	int m_nY;
	int m_nWidth;
	int m_nHeight;
	bool m_bIsEmpty;
};



typedef vector<CRectangle> VEC_RECTANGLES;
typedef vector<CRectangle>::iterator VEC_IT_RECTANGLES;

typedef unordered_map<CHashKey, CRectangle> MAP_RECTANGLES;
typedef unordered_map<CHashKey, CRectangle>::iterator MAP_IT_RECTANGLES;
