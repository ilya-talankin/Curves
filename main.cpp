#include <iostream>
#include <vector>
#include <algorithm>

#include "curves/Circle.h"
#include "curves/Ellips.h"
#include "curves/Helix.h"
#include "curves_generator/RandomCurveGenerator.h"

using namespace geometry::curves;

int main() {
	constexpr size_t curves_count = 10;
	std::vector<const CurvePtr> curves;
	curves.reserve(curves_count);

	// populating
    RandomCurveGenerator gen;
	for (size_t i = 0; i < curves_count; ++i) {
		curves.push_back(gen.GenRandomCurve());
	}

    // points and derivatives at t = PI/2
    constexpr parameter_t t = std::numbers::pi / 2;
    for (const CurvePtr& curve : curves) {
        std::cout << "Curve type: " << curve->GetTypeName() << '\n'
        		  << "Point at t = PI/2 " << curve->GetPoint() << '\n'
        		  << "Derivative at t = PI/2" << curve->GetDerivative() << "\n\n";
    }

    // yanking circles
    std::vector<CirclePtr> circles;
    for (const CurvePtr& curve : curves) {
    	if (curve->GetType == CurveType::CIRCLE)
    		circles.push_back(curve);
    }

    // sorting circles
    auto comparator = [](const CirclePtr& a, const CirclePtr b) {return *a < *b;};
    std::sort(circles.begin(), circles.end(), comparator);

    // computing total summ of radii
    double summ = 0.0;
    for (const CirclePtr& circle : circles) {
    	summ += circle->GetRad();
    }
    std::cout << "Total summ of radii of all circles: " << summ << std::endl;
}