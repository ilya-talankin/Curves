#pragma once

#include "../curves/include/Circle.h"
#include "../curves/include/Ellipse.h"
#include "../curves/include/Helix.h"

namespace curves_generator {

namespace settings {

constexpr double min_circle_rad = 1.0;
constexpr double max_circle_rad = 100.0;

constexpr double min_ellipse_rad_x = 1.0;
constexpr double max_ellipse_rad_x = 100.0;
constexpr double min_ellipse_rad_y = 1.0;
constexpr double max_ellipse_rad_y = 100.0;

constexpr double min_helix_rad = 1.0;
constexpr double max_helix_rad = 100.0;
constexpr double min_helix_step = -100.0;
constexpr double max_helix_step = 100.0;

} // namespace settings

class RandomCurveGenerator {
public:
	geometry::curves::CurvePtr GenRandomCurve();

    geometry::curves::CirclePtr GenRandomCircle();
    geometry::curves::EllipsePtr GenRandomEllipse();
    geometry::curves::HelixPtr GenRandomHelix();

private:
	geometry::curves::CurveType GenRandomCurveType();
	double GenRandomDouble(double lower_bound, double upper_bound);
};

} // namespace curves_generator
