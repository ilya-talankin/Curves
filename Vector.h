#pragma once

#include <sstream>

namespace geometry {

class Vector {
public:
	Vector() = default;

    Vector(double dx, double dy, double dz = 0.0)
        : m_dx(dx), m_dy(dy), m_dz(dz) {}

    double dx() const {
    	return m_dx;
    }

    double dy() const {
    	return m_dy;
    }

    double dz() const {
    	return m_dz;
    }
private:
	const double m_dx = 0.0;
	const double m_dy = 0.0;
	const double m_dz = 0.0;
};

} // namespace geometry

std::ostream& operator<<(std::ostream& os, const geometry::Vector& v) {
	return os << '{' << v.dx() << ", " << v.dy() << ", " << v.dz() << '}';
}
