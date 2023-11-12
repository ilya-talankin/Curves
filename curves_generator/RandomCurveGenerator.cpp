#include <random>
#include <memory>

#include "RandomCurveGenerator.h"

using namespace geometry::curves;
using namespace curves_generator::settings;


CurvePtr RandomCurveGenerator::GenRandomCurve() {
	CurveType type = GenRandomCurveType();

	switch (type) {
	case CurveType::CIRCLE:
		return GenRandomCircle();
	case CurveType::ELLIPS:
		return GenRandomEllips();
	case CurveType::HELIX:
		return GenRandomHelix();
	}
}

CurveType RandomCurveGenerator::GenRandomCurveType() {
    std::uniform_int_distribution<CurveType> unif(CurveType::CIRCLE, CurveType::HELIX);
    std::random_device r;
    std::default_random_engine re(r());

    return unif(re);
}

CirclePtr RandomCurveGenerator::GenRandomCircle() {
	const double rad = GenRandomDouble(0.0, settings::max_circle_rad);
    return std::make_shared<Circle>(rad);
}

EllipsPtr RandomCurveGenerator::GenRandomEllips() {
	const double rad_x = GenRandomDouble(0.0, max_ellips_rad_x);
	const double rad_y = GenRandomDouble(0.0, max_ellips_rad_y);
	return std::make_shared<Ellips>(rad_x, rad_y);
}

HelixPtr RandomCurveGenerator::GenRandomHelix() {
	const double rad = GenRandomDouble(0.0, max_helix_rad);
	const double step = GenRandomDouble(min_helix_step, max_helix_step);
	return std::make_shared<Helix>(rad, step);
}

double RandomCurveGenerator::GenRandomDouble(double lower_bound, double upper_bound) {
    std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
    std::random_device r;
    std::default_random_engine re(r());

    return unif(re);
}