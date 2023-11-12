#include "Ellips.h"
#include <cmath>

using namespace geometry::curves;

Ellips::Ellips(double rx, double ry) {
	SetRx(rx);
	SetRy(ry);
}

Point Ellips::GetPoint(parameter_t t) const {
	return Point(m_rx * std::cos(t), m_ry * std::sin(t));
}

Vector Ellips::GetDerivative(parameter_t t) const {
	return Vector(m_rx * (-std::sin(t)), m_ry * std::cos(t))
}

CurveType Ellips::GetType() const {
	return CurveType::ELLIPS;
}

std::string_view Ellips::GetTypeName() const {
	return std::string_view("Ellips");
}

double Ellips::Rx() const {
	return m_rx;
}

double Ellips::Ry() const {
	return m_ry;
}

void Ellips::SetRx(double rx) {
	if (rx < 0.0)
		throw std::logic_error("Radius along X axis of the ellips must be positive");
}

void Ellips::SetRy(double ry) {
	if (ry < 0.0)
		throw std::logic_error("Radius along Y axis of the ellips must be positive");
}
