#define BOOST_TEST_MODULE RectanglesTests

#include <set>

//#include <boost/test/included/unit_test.hpp>
#include "..\UTIncludes\boost\test\included\unit_test.hpp"

#include "..\RectIntersect\CRectangle.h"
#include "..\RectIntersect\CRectangleVec.h"

using namespace std;

BOOST_AUTO_TEST_CASE(TC_NON_INTERSECTING)
{
	CRectangle cFirst(10, 10, 20, 20),cSecond(140,140,10,10);
	CRectangle cResult,cReversedResult;

	cResult = cFirst.intersect(cSecond);
	cReversedResult = cSecond.intersect(cFirst);

	bool bIsEmpty = cResult.isEmpty();
	bool bIsReverseEmpty = cReversedResult.isEmpty();

    BOOST_TEST(bIsEmpty);
	BOOST_TEST(bIsReverseEmpty);
}

BOOST_AUTO_TEST_CASE(TC_UPPER_RIGHT)
{
	CRectangle cFirst(40, 40, 20, 20), cSecond(50, 30, 15, 15);
	CRectangle cResult, cReversedResult;

	cResult = cFirst.intersect(cSecond);
	cReversedResult = cSecond.intersect(cFirst);

	bool bIsCorrect = cResult == CRectangle(50, 40, 10, 5);
	bool bIsTheSame = cReversedResult == cResult;

	BOOST_TEST(bIsCorrect);
	BOOST_TEST(bIsTheSame);
}

BOOST_AUTO_TEST_CASE(TC_UPPER_LEFT)
{
	CRectangle cFirst(40, 40, 20, 20), cSecond(30, 30, 15, 15);
	CRectangle cResult, cReversedResult;

	cResult = cFirst.intersect(cSecond);
	cReversedResult = cSecond.intersect(cFirst);

	bool bIsCorrect = cResult == CRectangle(40, 40, 5, 5);
	bool bIsTheSame = cReversedResult == cResult;

	BOOST_TEST(bIsCorrect);
	BOOST_TEST(bIsTheSame);
}

BOOST_AUTO_TEST_CASE(TC_LOWER_LEFT)
{
	CRectangle cFirst(40, 40, 20, 20), cSecond(30, 50, 15, 15);
	CRectangle cResult, cReversedResult;

	cResult = cFirst.intersect(cSecond);
	cReversedResult = cSecond.intersect(cFirst);

	bool bIsCorrect = cResult == CRectangle(40, 50, 5, 10);
	bool bIsTheSame = cReversedResult == cResult;

	BOOST_TEST(bIsCorrect);
	BOOST_TEST(bIsTheSame);
}

BOOST_AUTO_TEST_CASE(TC_LOWER_RIGHT)
{
	CRectangle cFirst(40, 40, 20, 20), cSecond(30, 50, 15, 15);
	CRectangle cResult, cReversedResult;

	cResult = cFirst.intersect(cSecond);
	cReversedResult = cSecond.intersect(cFirst);

	bool bIsCorrect = cResult == CRectangle(40, 50, 5, 10);
	bool bIsTheSame = cReversedResult == cResult;

	BOOST_TEST(bIsCorrect);
	BOOST_TEST(bIsTheSame);
}


BOOST_AUTO_TEST_CASE(TC_RIGHT_SIDE)
{
	CRectangle cFirst(40, 40, 20, 20), cSecond(50, 30, 15, 50);
	CRectangle cResult, cReversedResult;

	cResult = cFirst.intersect(cSecond);
	cReversedResult = cSecond.intersect(cFirst);

	bool bIsCorrect = cResult == CRectangle(50, 40, 10, 20);
	bool bIsTheSame = cReversedResult == cResult;

	BOOST_TEST(bIsCorrect);
	BOOST_TEST(bIsTheSame);
}

BOOST_AUTO_TEST_CASE(TC_UPPER_SIDE)
{
	CRectangle cFirst(40, 40, 20, 20), cSecond(30, 30, 50, 15);
	CRectangle cResult, cReversedResult;

	cResult = cFirst.intersect(cSecond);
	cReversedResult = cSecond.intersect(cFirst);

	bool bIsCorrect = cResult == CRectangle(40, 40, 20, 5);
	bool bIsTheSame = cReversedResult == cResult;

	BOOST_TEST(bIsCorrect);
	BOOST_TEST(bIsTheSame);
}


BOOST_AUTO_TEST_CASE(TC_CONTAINS)
{
	CRectangle cFirst(40, 40, 20, 20), cSecond(30, 30, 50, 50);
	CRectangle cResult, cReversedResult;

	cResult = cFirst.intersect(cSecond);
	cReversedResult = cSecond.intersect(cFirst);

	bool bIsCorrect = cResult == CRectangle(40, 40, 20, 20);
	bool bIsTheSame = cReversedResult == cResult;

	BOOST_TEST(bIsCorrect);
	BOOST_TEST(bIsTheSame);
}

/******************************************************************************************************************************/

BOOST_AUTO_TEST_CASE(TC_VEC_ADD)
{
	CRectangleVec vecRectangles;
	
	vecRectangles.AddNewRectangle(100, 100, 250, 80);
	vecRectangles.AddNewRectangle(120, 200, 250, 150);
	vecRectangles.AddNewRectangle(140, 160, 250, 100);
	vecRectangles.AddNewRectangle(160, 140, 350, 190);

	BOOST_TEST(vecRectangles.Count() == 4);
}

BOOST_AUTO_TEST_CASE(TC_VEC_INTERSECT)
{
	CRectangleVec vecRectangles;
	CRectangleMap mapResult;

	vecRectangles.AddNewRectangle(100, 100, 250, 80);
	vecRectangles.AddNewRectangle(120, 200, 250, 150);
	vecRectangles.AddNewRectangle(140, 160, 250, 100);
	vecRectangles.AddNewRectangle(160, 140, 350, 190);

	mapResult = vecRectangles.GenerateIntersectionSet();

	BOOST_TEST(mapResult.Count() == 5);
}

BOOST_AUTO_TEST_CASE(TC_VEC_INTERSECT_CORRECT_RESULT)
{
	CRectangleVec vecRectangles;
	CRectangleMap mapResult;
	set<int> setKey;

	vecRectangles.AddNewRectangle(100, 100, 250, 80);
	vecRectangles.AddNewRectangle(120, 200, 250, 150);
	vecRectangles.AddNewRectangle(140, 160, 250, 100);
	vecRectangles.AddNewRectangle(160, 140, 350, 190);

	mapResult = vecRectangles.GenerateIntersectionSet();

	BOOST_TEST(mapResult.Count() == 5);
	setKey = { 1,3 };
	BOOST_TEST(mapResult.Exists(setKey));
	setKey = { 1,4 };
	BOOST_TEST(mapResult.Exists(setKey));
	setKey = { 2,3 };
	BOOST_TEST(mapResult.Exists(setKey));
	setKey = { 2,4 };
	BOOST_TEST(mapResult.Exists(setKey));
	setKey = { 4,3 };
	BOOST_TEST(mapResult.Exists(setKey));
}

/*****************************************************************************************************************************/

BOOST_AUTO_TEST_CASE(TC_MAP_ADD)
{
	CRectangleMap mapRectangles;
	set<int> setKey;
	CRectangle cRect1(140, 160, 210, 20),
		cRect2(160, 140, 190, 40),
		cRect3(140, 200, 230, 60),
		cRect4(160, 200, 210, 130),
		cRect5(160, 160, 230, 100);

	setKey = { 1,3 };
	mapRectangles.AddNewResultRectangle(setKey, cRect1);
	setKey = { 1,4 };
	mapRectangles.AddNewResultRectangle(setKey, cRect2);
	setKey = { 2,3 };
	mapRectangles.AddNewResultRectangle(setKey, cRect3);
	setKey = { 2,4 };
	mapRectangles.AddNewResultRectangle(setKey, cRect4);
	setKey = { 4,3 };
	mapRectangles.AddNewResultRectangle(setKey, cRect5);

	BOOST_TEST(mapRectangles.Count() == 5);
}

BOOST_AUTO_TEST_CASE(TC_MAP_INTERSECT)
{
	CRectangleMap mapRectangles,mapResult;
	set<int> setKey;
	CRectangle cRect1(140, 160, 210, 20),
		cRect2(160, 140, 190, 40),
		cRect3(140, 200, 230, 60),
		cRect4(160, 200, 210, 130),
		cRect5(160, 160, 230, 100);

	setKey = { 1,3 };
	mapRectangles.AddNewResultRectangle(setKey, cRect1);
	setKey = { 1,4 };
	mapRectangles.AddNewResultRectangle(setKey, cRect2);
	setKey = { 2,3 };
	mapRectangles.AddNewResultRectangle(setKey, cRect3);
	setKey = { 2,4 };
	mapRectangles.AddNewResultRectangle(setKey, cRect4);
	setKey = { 4,3 };
	mapRectangles.AddNewResultRectangle(setKey, cRect5);

	mapResult = mapRectangles.GenerateIntersectionSet();

	BOOST_TEST(mapResult.Count() == 2);
}

BOOST_AUTO_TEST_CASE(TC_MAP_INTERSECT_CORRECT_RESULT)
{
	CRectangleMap mapRectangles, mapResult;
	set<int> setKey;
	CRectangle cRect1(140, 160, 210, 20),
		cRect2(160, 140, 190, 40),
		cRect3(140, 200, 230, 60),
		cRect4(160, 200, 210, 130),
		cRect5(160, 160, 230, 100);

	setKey = { 1,3 };
	mapRectangles.AddNewResultRectangle(setKey, cRect1);
	setKey = { 1,4 };
	mapRectangles.AddNewResultRectangle(setKey, cRect2);
	setKey = { 2,3 };
	mapRectangles.AddNewResultRectangle(setKey, cRect3);
	setKey = { 2,4 };
	mapRectangles.AddNewResultRectangle(setKey, cRect4);
	setKey = { 4,3 };
	mapRectangles.AddNewResultRectangle(setKey, cRect5);

	mapResult = mapRectangles.GenerateIntersectionSet();

	BOOST_TEST(mapResult.Count() == 2);

	setKey = { 1,3,4 };
	BOOST_TEST(mapResult.Exists(setKey));

	setKey = { 2,3,4 };
	BOOST_TEST(mapResult.Exists(setKey));
}
