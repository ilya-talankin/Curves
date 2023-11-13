#include <random>
#include <memory>

#include "RandomCurveGenerator.h"

using namespace geometry::curves;
using namespace curves_generator;
using namespace curves_generator::settings;


CurvePtr RandomCurveGenerator::GenRandomCurve() {
	CurveType type = GenRandomCurveType();

	switch (type) {
	case CurveType::CIRCLE:
		return GenRandomCircle();
	case CurveType::ELLIPSE:
		return GenRandomEllipse();
	case CurveType::HELIX:
		return GenRandomHelix();
	default:
		return GenRandomCircle();
	}
}

CurveType RandomCurveGenerator::GenRandomCurveType() {
	const int lower_type = static_cast<int>(CurveType::CIRCLE);
	const int upper_type = static_cast<int>(CurveType::HELIX);
    std::uniform_int_distribution<int> unif(lower_type, upper_type);
    std::random_device r;
    std::default_random_engine re(r());

    return static_cast<CurveType>(unif(re));
}

CirclePtr RandomCurveGenerator::GenRandomCircle() {
	const double rad = GenRandomDouble(min_circle_rad, max_circle_rad);
    return std::make_shared<Circle>(rad);
}

EllipsePtr RandomCurveGenerator::GenRandomEllipse() {
	const double rad_x = GenRandomDouble(min_ellipse_rad_x, max_ellipse_rad_x);
	const double rad_y = GenRandomDouble(min_ellipse_rad_y, max_ellipse_rad_y);
	return std::make_shared<Ellipse>(rad_x, rad_y);
}

HelixPtr RandomCurveGenerator::GenRandomHelix() {
	const double rad = GenRandomDouble(min_helix_rad, max_helix_rad);
	const double step = GenRandomDouble(min_helix_step, max_helix_step);
	return std::make_shared<Helix>(rad, step);
}

double RandomCurveGenerator::GenRandomDouble(double lower_bound, double upper_bound) {
    std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
    std::random_device r;
    std::default_random_engine re(r());

    return unif(re);
}