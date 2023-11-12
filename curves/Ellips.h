#pragma once

#include "../Curve.h"

namespace geometry::curves {

class Ellips : public Curve {
public:
	Ellips() = default;
	Ellips(double rx, double ry);

    virtual Point GetPoint(parametr_t t) const override;
    virtual Vector GetDerivative(parametr_t t) const override;
    virtual CurvesType GetType() const override;
    virtual std::string_view GetTypeName() const override;

    double Rx() const;
    double Ry() const;

    void SetRx(double rx);
    void SetRy(double ry);

private:
	double m_rx = 0.0;
	double m_ry = 0.0;
};

typedef std::shared_ptr<Ellips> EllipsPtr;

} // namespace geometry::curves