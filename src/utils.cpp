#include "utils.hpp"
#include <random>
#include <iomanip>

namespace KaloAlgebraUtils
{
    // Calculate the Euclidean norm of a vector
    double euclideanNorm(const std::vector<double> &vec)
    {
        double sumOfSquares = 0.0;
        for (double value : vec)
        {
            sumOfSquares += value * value;
        }
        return std::sqrt(sumOfSquares);
    }

    // approximately equal
    bool approximatelyEquals(double a, double b, double epsilon)
    {
        return std::fabs(a - b) <= epsilon;
    }

    // print std::vector<std::vector<double>>
    void print2DVector(const std::vector<std::vector<double>> &mat)
    {
        for (const auto &row : mat)
        {
            for (double value : row)
            {
                std::cout << std::setw(8) << value << " ";
            }
            std::cout << std::endl;
        }
    }

    double randomDouble(double min, double max)
    {
        if (min > max)
            throw std::invalid_argument("Min must be less or equal to max!");
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dist(min, max);
        return dist(gen);
    }
}