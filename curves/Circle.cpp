#include "Circle.h"
#include <cmath>

using namespace geometry::curves;

Circle::Circle(double rad) {
	SetRad(rad);
}

Point Circle::GetPoint(parameter_t t) const {
	return Point(m_rad * std::cos(t), m_rad * std::sin(t));
}

Vector Circle::GetDerivative(parameter_t t) const {
	return Vector(m_rad * (- std::sin(t)), m_rad * std::cos(t));
}

CurveType Circle::GetType() const {
    return CurveType::CIRCLE;
}

std::string_view Circle::GetTypeName() const {
	return std::string_view("Circle");
}

double Circle::Rad() const {
	return m_rad;
}

void Circle::SetRad(double rad) {
	if (rad < 0.0)
		throw std::logic_error("Radius of the circle must be positive");
	m_rad = rad;
}

bool Circle::operator<(const Circle& other) {
	return m_rad < other.m_rad;
}
