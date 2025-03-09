#include "kalo_algebra.hpp"
#include <iostream>
#include "tests/test_vector.cpp"

int main() {
    // Create a 3x3 matrix and set elements
    KaloAlgebra::Matrix mat(3, 3, 1.0);
    mat.setElement(1, 1, 5.0);
    std::cout << "Matrix:\n";
    mat.print();

    // Transpose the matrix
    auto transposed = mat.transpose();
    std::cout << "\nTransposed Matrix:\n";
    transposed.print();

    // Create a vector and calculate its magnitude
    KaloAlgebra::Vector vec(3, 2.0);
    std::cout << "\nVector Magnitude: " << vec.magnitude() << "\n";

    // test hadamard and test projection
    testhadamard(); 
    std::cout<<"\n"; 
    testProjectOnto(); 
     
    return 0;
}
