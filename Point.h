#pragma once

#include <sstream>
#include "Vector.h"

namespace geometry {

class Point {
public:
	Point() = default;

	Point(double x, double y, double z = 0.0)
		: m_x(x), m_y(y), m_z(z) {}

	double x() const {
		return m_x;
	}

	double y() const {
		return m_y;
	}

	double z() const {
		return m_z;
	}

private:
	const double m_x = 0.0;
	const double m_y = 0.0;
	const double m_z = 0.0;
};

} // namespace geometry

std::ostream& operator<<(std::ostream& os, const geometry::Point& p) {
	return os << '(' << p.x() << ", " << p.y() << ", " << p.z() << ')';
}