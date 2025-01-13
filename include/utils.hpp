#pragma once

#include <vector>
#include <cmath>
#include <numeric>
#include <iostream>

namespace KaloAlgebraUtils
{
    // euclidean norm of a std::vector<double>
    double euclideanNorm(const std::vector<double> &vec);

    // approximately equals
    bool approximatelyEquals(double a, double b, double epsilon = 1e-9);

    // print 2d std::vector<std::vetctor<double>>
    void print2DVector(const std::vector<std::vector<double>> &mat);

    // generate random double value
    double randomDouble(double min, double max);
}