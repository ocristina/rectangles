#include "stdafx.h"
#include "CHashKey.h"
#include <math.h>

CHashKey::CHashKey(int n_first, int n_second)
{
	int nMax = n_first > n_second ? n_first : n_second;
	unsigned int nArrayLen ;


	nArrayLen = nMax / 32 + 1;
	m_pnStorage = new unsigned int[nArrayLen];
	memset(m_pnStorage, 0, sizeof(unsigned int) * nArrayLen);

	SetBit(n_first);
	SetBit(n_second);
}

CHashKey CHashKey::merge(const CHashKey& rc_second)
{
	CHashKey cReturnVal;
	unsigned int nMax, nMin, nIndex,*pnBiggerArray;
	

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

void CHashKey::SetBit(int n_triangle_num)
{
	unsigned int nOrMask;

	nOrMask = 1 << (n_triangle_num % 32);
	m_pnStorage[n_triangle_num / 32] |= nOrMask;
}


CHashKey::~CHashKey()
{
}
