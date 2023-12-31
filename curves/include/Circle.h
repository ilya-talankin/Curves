#pragma once

#include "Curve.h"

namespace geometry::curves {

class Circle : public Curve {
public:
	Circle() = default;
	Circle(double rad);

    virtual Point GetPoint(parameter_t t) const override;
    virtual Vector GetDerivative(parameter_t t) const override;
    virtual CurveType GetType() const override;
    virtual std::string_view GetTypeName() const override;

    double Rad() const;
    void SetRad(double rad);

    bool operator<(const Circle& other);

private:
	double m_rad = 0.0;
};

typedef std::shared_ptr<Circle> CirclePtr;

} // namespace geometry::curves
