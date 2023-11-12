#pragma once

#include "../curves/circle.h"
#include "../curves/ellips.h"
#include "../curves/helix.h"

namespace curves_generator {

namespace settings {

constexpr double max_circle_rad = 1000.0;
constexpr double max_ellipse_rad_x = 1000.0;
constexpr double max_ellipse_rad_y = 1000.0;
constexpr double max_helix_rad = 1000.0;
constexpr double min_helix_step = -100.0;
constexpr double max_helix_step = 100.0;

} // namespace settings

class RandomCurveGenerator {
public:
	geometry::curves::CurvePtr GenRandomCurve();

    geometry::curves::CirclePtr GenRandomCircle();
    geometry::curves::EllipsPtr GenRandomEllips();
    geometry::curves::HelixPtr GenRandomHelix();

private:
	geometry::curves::CurveType GenRandomCurveType();
	double GenRandomDouble(double lower_bound, double upper_bound);
};

} // namespace curves_generator
