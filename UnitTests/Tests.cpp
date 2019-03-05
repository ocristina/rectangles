#define BOOST_TEST_MODULE RectanglesTests
#include <boost/test/included/unit_test.hpp>
#include "..\Rectangles\CRectangle.h"

BOOST_AUTO_TEST_CASE(RectangleTestCase)
{
	CRectangle first(10, 10, 120, 120),second(40,40,10,10);
	bool bIsEmpty = first.intersect(second).isEmpty();
  BOOST_TEST(1 == 1);
  BOOST_TEST(bIsEmpty);
}