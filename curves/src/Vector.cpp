#include "../include/Vector.h"

std::ostream& operator<<(std::ostream& os, const geometry::Vector& v) {
	os << '{' << v.dx() << ", " << v.dy();
	if (v.dz() != 0.0)
	    os << ", " << v.dz() << '}';
	else
		os << '}';
	return os;
}
