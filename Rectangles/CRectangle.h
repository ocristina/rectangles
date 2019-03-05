#pragma once

#include <map>
#include <set>
#include <vector>


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
	    m_bIsEmpty(false) {};
	~CRectangle();

	CRectangle intersect(CRectangle& other);
	string GetDescription();
	bool isEmpty() { return m_bIsEmpty; }

private:
	int m_nX;
	int m_nY;
	int m_nWidth;
	int m_nHeight;
	bool m_bIsEmpty;
};


namespace std {

	template <>
	struct hash<set<int>>
	{
		std::size_t operator()(const set<int>& k) const
		{
			using std::size_t;
			using std::hash;
			using std::string;

			// Compute individual hash values for first,
			// second and third and combine them using XOR
			// and bit shifting:
			size_t returnVal = 0;

			for (set<int>::iterator it = k.begin(); it != k.end(); it++)
				returnVal ^= hash<int>()(*it);
		/*	return ((hash<string>()(k.first)
				^ (hash<string>()(k.second) << 1)) >> 1)
				^ (hash<int>()(k.third) << 1);*/
			return returnVal;
		}
	};

}

typedef vector<CRectangle> VEC_RECTANGLES;
typedef vector<CRectangle>::iterator VEC_IT_RECTANGLES;
typedef map<set<int>, CRectangle> MAP_RECTANGLES;
typedef map<set<int>, CRectangle>::iterator MAP_IT_RECTANGLES;
