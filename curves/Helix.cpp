#include "Helix.h"
#include <cmath>
#include <numbers>

using namespace geometry::curves;

Helix::Helix(double rad, double step) {
	SetRad(rad);
	SetStep(step);
}

Point Helix::GetPoint(parameter_t t) const {
	return Point(m_rad * std::cos(t), m_rad * std::sin(t), m_step * t / std::numbers::pi);
}

Vector Helix::GetDerivative(parameter_t t) const {
	return Vector(m_rad * (-std::sin(t)), m_rad * std::cos(t), m_step / std::numbers::pi);
}

CurveType Helix::GetType() const {
	return CurveType::HELIX;
}

std::string_view Helix::GetTypeName() const {
	return std::string_view("Helix");
}

double Helix::Rad() const {
	return m_rad();
}

double Helix::Step() const {
	return m_step;
}

void Helix::SetRad(double rad) {
	if (rad < 0.0)
		throw std::logic_error("Radius of the helix must be positive");
	m_rad = rad;
}

void Helix::SetStep(double step) {
	m_step = step;
}