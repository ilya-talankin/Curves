#pragma once

#include "../Curve.h"

namespace geometry::curves {

class Helix : public Curve {
public:
	Helix() = default;
	Helix(double rad, double step);

    virtual Point GetPoint(parametr_t t) const override;
    virtual Vector GetDerivative(parametr_t t) const override;
    virtual CurvesType GetType() const override;
    virtual std::string_view GetTypeName() const override;

    double Rad() const;
    double Step() const;

    void SetRad(double rad);
    void SetStep(double step);

private:
	double m_rad = 0.0;
	double m_step = 0.0;
};

typedef std::shared_ptr<Helix> HelixPtr;

} // namespace geometry::curves
