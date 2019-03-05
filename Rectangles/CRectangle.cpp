#include "stdafx.h"
#include "CRectangle.h"


CRectangle CRectangle::intersect(CRectangle& other)
{
	CRectangle intersectResult;

	if ((m_nX < other.m_nX + other.m_nWidth) &&
		(m_nX + m_nWidth > other.m_nX) &&
		(m_nY < other.m_nY + other.m_nHeight) &&
		(m_nY + m_nHeight > other.m_nY))
	{
		intersectResult.m_bIsEmpty = false;
		if (m_nX > other.m_nX)
		{
			intersectResult.m_nX = m_nX;
			intersectResult.m_nWidth = (other.m_nX + other.m_nWidth > m_nX + m_nWidth) ? m_nWidth :other.m_nX + other.m_nWidth - m_nX;
		}
		else
		{
			intersectResult.m_nX = other.m_nX;
			intersectResult.m_nWidth = (m_nX + m_nWidth > other.m_nX + other.m_nWidth) ? other.m_nWidth : m_nX + m_nWidth - other.m_nX;
		}
		if (m_nY > other.m_nY)
		{
			intersectResult.m_nY = m_nY;
			intersectResult.m_nHeight = (other.m_nY + other.m_nHeight > m_nY + m_nHeight) ? m_nHeight : other.m_nY + other.m_nHeight - m_nY;
		}
		else
		{
			intersectResult.m_nY = other.m_nY;
			intersectResult.m_nHeight = (m_nY + m_nHeight > other.m_nY + other.m_nHeight) ? other.m_nHeight : m_nY + m_nHeight - other.m_nY;
		}
	}

	return intersectResult;
}

string CRectangle::GetDescription()
{
	char pszBuffer[256];
	string strReturnVal;
	
	sprintf_s(pszBuffer, "at (%d,%d), w=%d, h=%d.", m_nX, m_nY, m_nWidth, m_nHeight);
	strReturnVal = pszBuffer;

	return strReturnVal;
}


CRectangle::~CRectangle()
{
}
