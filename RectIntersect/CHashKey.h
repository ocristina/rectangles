#pragma once
class CHashKey
{
	friend std::hash<CHashKey>;
public:
	CHashKey(int n_first,int n_second);
	CHashKey(const CHashKey&);

	~CHashKey();

	CHashKey merge(const CHashKey&) const;
	std::string getDesc() const;
	bool operator==(const CHashKey&) const;
private:
	CHashKey() {}

	unsigned int *m_pnStorage;
	unsigned int m_nLen;

	void SetBit(int);
};


namespace std {

	template <>
	struct hash<CHashKey>
	{
		std::size_t operator()(const CHashKey& k) const
		{
			using std::size_t;
			using std::hash;
			using std::string;

			// Compute individual hash values for first,
			// second and third and combine them using XOR
			// and bit shifting:
			size_t returnVal = 0;

			for (int i = 0; i != k.m_nLen; i++)
				returnVal ^= hash<unsigned int>()(k.m_pnStorage[i]);
			
			return returnVal;
		}
	};

}
