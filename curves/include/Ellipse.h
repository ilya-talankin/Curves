#pragma once

#include "Curve.h"

namespace geometry::curves {

class Ellipse : public Curve {
public:
	Ellipse() = default;
	Ellipse(double rx, double ry);

    virtual Point GetPoint(parameter_t t) const override;
    virtual Vector GetDerivative(parameter_t t) const override;
    virtual CurveType GetType() const override;
    virtual std::string_view GetTypeName() const override;

    double Rx() const;
    double Ry() const;

    void SetRx(double rx);
    void SetRy(double ry);

private:
	double m_rx = 0.0;
	double m_ry = 0.0;
};

typedef std::shared_ptr<Ellipse> EllipsePtr;

} // namespace geometry::curves