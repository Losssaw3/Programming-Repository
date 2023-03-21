#include "Point.h"
using namespace PointClass;
Point::Point(const double x, const  double y)
	:abscissa(x), ordinate(y)
{
}

ostream& PointClass::operator<<(ostream& out, const Point& point)
{
	out << "Point(" << point.abscissa << ", " << point.ordinate << ')';
	return out;
}

