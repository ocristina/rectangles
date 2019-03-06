#include "stdafx.h"
#include "CHashKey.h"

#include <vector>

using namespace std;

CHashKey::CHashKey(int n_first, int n_second)
{
	int nMax = n_first > n_second ? n_first : n_second;
	unsigned int nArrayLen ;


	nArrayLen = nMax / 32 + 1;
	m_pnStorage = new unsigned int[nArrayLen];
	memset(m_pnStorage, 0, sizeof(unsigned int) * nArrayLen);

	SetBit(n_first);
	SetBit(n_second);
	m_nLen = nArrayLen;
}

CHashKey::CHashKey(const CHashKey& rc_other)
{
	m_nLen = rc_other.m_nLen;

	m_pnStorage = new unsigned int[m_nLen];
	for (unsigned int i = 0; i < m_nLen; ++i)
		m_pnStorage[i] = rc_other.m_pnStorage[i];
}

CHashKey CHashKey::merge(const CHashKey& rc_second) const
{
	CHashKey cReturnVal;
	unsigned int nMax, nMin, nIndex,*pnBiggerArray ;


	if (m_nLen > rc_second.m_nLen)
	{
		nMax = m_nLen;
		nMin = rc_second.m_nLen;
		pnBiggerArray = m_pnStorage;
	}
	else
	{
		nMin = m_nLen;
		nMax = rc_second.m_nLen;
		pnBiggerArray = rc_second.m_pnStorage;
	}
	cReturnVal.m_nLen = nMax;
	cReturnVal.m_pnStorage = new unsigned int[nMax];
	for (nIndex = 0; nIndex < nMin; nIndex++)
		cReturnVal.m_pnStorage[nIndex] = m_pnStorage[nIndex] | rc_second.m_pnStorage[nIndex];
	for (; nIndex < nMax; nIndex++)
		cReturnVal.m_pnStorage[nIndex] = pnBiggerArray[nIndex];
	return cReturnVal;
}

std::string CHashKey::getDesc() const
{
	unsigned int nBit ;
	vector<int> vecOrigRects;
	char szBuffer[16];

	for (unsigned int nX = 0; nX < m_nLen; ++nX)
	{
		nBit = 1;
		for (int nY = 0; nY < 32; ++nY, nBit <<= 1)
			if (nBit & m_pnStorage[nX])
				vecOrigRects.push_back(32 * nX + nY + 1);
	}
	vector<int>::iterator last = vecOrigRects.end(),it = vecOrigRects.begin();
	
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

void CHashKey::SetBit(int n_triangle_num)
{
	unsigned int nOrMask;

	--n_triangle_num;
	nOrMask = 1 << (n_triangle_num % 32);
	m_pnStorage[n_triangle_num / 32] |= nOrMask;
}

bool CHashKey::operator==(const CHashKey& other) const
{
	if (m_nLen != other.m_nLen)
		return false;
	for (unsigned int nI = 0; nI < m_nLen; ++nI)
		if (m_pnStorage[nI] != other.m_pnStorage[nI])
			return false;
	return true;
}

CHashKey::~CHashKey()
{
	delete m_pnStorage;
}
