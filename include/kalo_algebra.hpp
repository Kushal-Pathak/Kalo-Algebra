#pragma once

#include "matrix.hpp"
#include "vector.hpp"
#include "utils.hpp"

namespace KaloAlgebra
{
    // Re-exporting the followings

    using Matrix = ::Matrix;
    using Vector = ::Vector;

    using KaloAlgebraUtils::approximatelyEquals;
    using KaloAlgebraUtils::euclideanNorm;
    using KaloAlgebraUtils::print2DVector;
    using KaloAlgebraUtils::randomDouble;
} // User accesses KaloAlgebra namespace for usage