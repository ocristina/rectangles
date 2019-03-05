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

void CHashKey::SetBit(int n_triangle_num)
{
	unsigned int nOrMask;

	nOrMask = 1 << (n_triangle_num % 32);
	m_pnStorage[n_triangle_num / 32] |= nOrMask;
}


CHashKey::~CHashKey()
{
}
