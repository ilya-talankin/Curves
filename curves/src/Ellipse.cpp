#include "../include/Ellipse.h"
#include <cmath>

using namespace geometry;
using namespace geometry::curves;

Ellipse::Ellipse(double rx, double ry) {
	SetRx(rx);
	SetRy(ry);
}

Point Ellipse::GetPoint(parameter_t t) const {
	return Point(m_rx * std::cos(t), m_ry * std::sin(t));
}

Vector Ellipse::GetDerivative(parameter_t t) const {
	return Vector(m_rx * (-std::sin(t)), m_ry * std::cos(t));
}

CurveType Ellipse::GetType() const {
	return CurveType::ELLIPSE;
}

std::string_view Ellipse::GetTypeName() const {
	return std::string_view("Ellipse");
}

double Ellipse::Rx() const {
	return m_rx;
}

double Ellipse::Ry() const {
	return m_ry;
}

void Ellipse::SetRx(double rx) {
	if (rx < 0.0)
		throw std::logic_error("Radius along X axis of the ellips must be positive");
	m_rx = rx;
}

void Ellipse::SetRy(double ry) {
	if (ry < 0.0)
		throw std::logic_error("Radius along Y axis of the ellips must be positive");
	m_ry = ry;
}
