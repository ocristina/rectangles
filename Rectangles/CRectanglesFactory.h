#pragma once

#include "json.hpp"
#include "CRectangleVec.h"

class CRectanglesFactory
{
public:
	CRectanglesFactory();
	~CRectanglesFactory();

	CRectangleVec CreateRectangles(const char *);
};

