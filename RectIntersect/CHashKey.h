#pragma once
class CHashKey
{
public:
	CHashKey(int n_first,int n_second);
	~CHashKey();


private:
	unsigned int *m_pnStorage;
	unsigned int m_nLen;

	void SetBit(int);
};

