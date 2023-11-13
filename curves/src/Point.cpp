#include "../include/Point.h"

std::ostream& operator<<(std::ostream& os, const geometry::Point& p) {
	os << '(' << p.x() << ", " << p.y();
	if (p.z() != 0.0)
	   os << ", " << p.z() << ')';
	else
		os << ')';
	return os;
}