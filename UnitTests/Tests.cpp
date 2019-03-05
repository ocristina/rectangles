#define BOOST_TEST_MODULE RectanglesTests
#include <boost/test/included/unit_test.hpp>
#include "..\Rectangles\CRectangle.h"

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
