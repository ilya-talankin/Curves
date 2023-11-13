#include <iostream>
#include <vector>
#include <algorithm>

#include "curves/include/Circle.h"
#include "curves/include/Ellipse.h"
#include "curves/include/Helix.h"

#include "curves_generator/RandomCurveGenerator.h"

#include <chrono>
#include <omp.h>

using namespace geometry::curves;
using std::cout;

int main() {
	constexpr size_t curves_count = 100;
	std::vector<CurvePtr> curves;
	curves.reserve(curves_count); // avoiding reallocation

	// 2. Populating
    curves_generator::RandomCurveGenerator gen;
	for (size_t i = 0; i < curves_count; ++i) {
		curves.push_back(gen.GenRandomCurve());
	}

    // 3. Points and derivatives at t = PI/4
    constexpr parameter_t t = std::numbers::pi / 4;
    for (const CurvePtr& curve : curves) {
        cout << "Curve type: " << curve->GetTypeName() << '\n'
        	 << "Point at t = PI/4: " << curve->GetPoint(t) << '\n'
        	 << "Derivative at t = PI/4: " << curve->GetDerivative(t) << "\n\n";
    }

    // 4. Yanking circles
    std::vector<CirclePtr> circles;
    for (const CurvePtr& curve : curves) {
    	if (curve->GetType() == CurveType::CIRCLE)
    		circles.push_back(std::dynamic_pointer_cast<Circle>(curve));
    }

    // 5. Sorting circles
    // before
    cout << "Unsorted circles array\n";
    for (const CirclePtr& circle : circles) {
        cout << "Radii: " << circle->Rad() << '\n';
    }
    cout << '\n';
    // * sorting *
    auto comparator = [](const CirclePtr& a, const CirclePtr& b) {return *a < *b;};
    std::sort(circles.begin(), circles.end(), comparator);
    // after
    cout << "Sorted circles array\n";
    for (const CirclePtr& circle : circles) {
        cout << "Radii: " << circle->Rad() << '\n';
    }
    cout << '\n';

    // 6. Computing total summ of radii
    double sum = 0.0;
    std::chrono::time_point start = std::chrono::high_resolution_clock::now();
    #pragma omp parallel for reduction(+:sum)
    for (const CirclePtr& circle : circles) {
    	sum += circle->Rad();
    }
    std::chrono::time_point finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration dt = finish - start;
    // report
    cout << "Total summ of radii of all circles: " << sum << '\n'
         << "Elapsed time: " << dt << std::endl;
}
