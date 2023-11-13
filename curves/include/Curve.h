#pragma once

#include <memory>
#include <string_view>

#include "Vector.h"
#include "Point.h"

namespace geometry {

namespace curves {

enum class CurveType {
    CIRCLE,
    ELLIPSE,
    HELIX
};

typedef double parameter_t;

class Curve {
public:
    virtual Point GetPoint(parameter_t t) const = 0;
    virtual Vector GetDerivative(parameter_t t) const = 0;
    virtual CurveType GetType() const = 0;
    virtual std::string_view GetTypeName() const = 0;
};

typedef std::shared_ptr<Curve> CurvePtr;

} // namespace curves

} // namespace geometry
