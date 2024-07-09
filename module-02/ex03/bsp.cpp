#include "Point.hpp"

Fixed	fixedAbs(const Fixed a) {
	if (a < 0)
		return (a * -1);
	return (a);
}

Fixed	triangleArea(const Point a, const Point b, const Point c) {
	Point	AB = Point(b.get_x() - a.get_x(), b.get_y() - a.get_y());
	Point	AC = Point(c.get_x() - a.get_x(), c.get_y() - a.get_y());
	Fixed	crossProduct = (AB.get_x() * AC.get_y()) - (AB.get_y() * AC.get_x());
	return (fixedAbs(crossProduct) / 2);
}

bool	insideTriangle(const Point p, const Point a, const Point b, const Point c) {
	Fixed	abcArea = triangleArea(a, b, c);
	Fixed	sumArea(0);
	sumArea = sumArea + triangleArea(a, b, p);
	sumArea = sumArea + triangleArea(a, c, p);
	sumArea = sumArea + triangleArea(b, c, p);
	return (abcArea == sumArea);
}


