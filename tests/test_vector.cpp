#include <iostream>
#include "kalo_algebra.hpp"

void testVectorMagnitude()
{
    // Create a vector
    Vector vec(std::vector<double>{3.0, 4.0});

    // Calculate its magnitude
    double result = vec.magnitude();

    // Expected magnitude
    double expected = 5.0;

    // Compare results
    if (std::fabs(result - expected) < 1e-9) // Allow small tolerance
    {
        std::cout << "testVectorMagnitude PASSED\n";
    }
    else
    {
        std::cout << "testVectorMagnitude FAILED\n";
    }
}

void testVectorNormalize()
{
    // Create a vector
    Vector vec(std::vector<double>{3.0, 4.0});

    // Normalize the vector
    Vector result = vec.normalize();

    // Expected normalized vector
    Vector expected(std::vector<double>{0.6, 0.8}); // Divide each element by magnitude (5.0)

    // Compare results
    if (result == expected)
    {
        std::cout << "testVectorNormalize PASSED\n";
    }
    else
    {
        std::cout << "testVectorNormalize FAILED\n";
    }
}

void testVectorDotProduct()
{
    // Create two vectors
    Vector vec1(std::vector<double>{1.0, 2.0, 3.0});
    Vector vec2(std::vector<double>{4.0, 5.0, 6.0});

    // Calculate dot product
    double result = vec1.dot(vec2);

    // Expected dot product
    double expected = 1.0 * 4.0 + 2.0 * 5.0 + 3.0 * 6.0; // 32.0

    // Compare results
    if (std::fabs(result - expected) < 1e-9)
    {
        std::cout << "testVectorDotProduct PASSED\n";
    }
    else
    {
        std::cout << "testVectorDotProduct FAILED\n";
    }
}

void testVectorCrossProduct()
{
    // Create two 3D vectors
    Vector vec1(std::vector<double>{1.0, 0.0, 0.0});
    Vector vec2(std::vector<double>{0.0, 1.0, 0.0});

    // Calculate cross product
    Vector result = vec1.cross(vec2);

    // Expected cross product
    Vector expected(std::vector<double>{0.0, 0.0, 1.0});

    // Compare results
    if (result == expected)
    {
        std::cout << "testVectorCrossProduct PASSED\n";
    }
    else
    {
        std::cout << "testVectorCrossProduct FAILED\n";
    }
}

void testVectorAddition()
{
    Vector vec1(std::vector<double>{1.0, 2.0, 3.0});
    Vector vec2(std::vector<double>{4.0, 5.0, 6.0});

    // Perform addition
    Vector result = vec1 + vec2;

    // Expected result
    Vector expected(std::vector<double>{5.0, 7.0, 9.0});

    // Check equality
    if (result == expected)
    {
        std::cout << "testVectorAddition PASSED\n";
    }
    else
    {
        std::cout << "testVectorAddition FAILED\n";
    }
}

void testVectorSubtraction()
{
    Vector vec1(std::vector<double>{7.0, 8.0, 9.0});
    Vector vec2(std::vector<double>{4.0, 5.0, 6.0});

    // Perform subtraction
    Vector result = vec1 - vec2;

    // Expected result
    Vector expected(std::vector<double>{3.0, 3.0, 3.0});

    // Check equality
    if (result == expected)
    {
        std::cout << "testVectorSubtraction PASSED\n";
    }
    else
    {
        std::cout << "testVectorSubtraction FAILED\n";
    }
}

void testVectorScalarMultiplication()
{
    Vector vec(std::vector<double>{1.0, 2.0, 3.0});
    double scalar = 2.0;

    // Perform scalar multiplication
    Vector result = vec * scalar;

    // Expected result
    Vector expected(std::vector<double>{2.0, 4.0, 6.0});

    // Check equality
    if (result == expected)
    {
        std::cout << "testVectorScalarMultiplication PASSED\n";
    }
    else
    {
        std::cout << "testVectorScalarMultiplication FAILED\n";
    }
}

void testVectorDotProduct2()
{
    Vector vec1(std::vector<double>{1.0, 2.0, 3.0});
    Vector vec2(std::vector<double>{4.0, 5.0, 6.0});

    // Perform dot product
    double result = vec1 * vec2;

    // Expected result
    double expected = 1.0 * 4.0 + 2.0 * 5.0 + 3.0 * 6.0;

    // Check equality with a tolerance
    if (std::fabs(result - expected) < 1e-9)
    {
        std::cout << "testVectorDotProduct2 PASSED\n";
    }
    else
    {
        std::cout << "testVectorDotProduct2 FAILED\n";
    }
}

void testProjectOnto() {
    Vector v1(std::vector<double>{3, 4});
    Vector v2(std::vector<double>{1, 0});

    Vector projected = v1.projectOnto(v2); 
    std::cout<<"Projection of v1 onto v2: "; 
    projected.print(); 
}

void testhadamard() {
    // Create Vector objects v1 and v2
    Vector v1(std::vector<double>{1.0, 2.0, 3.0});
    Vector v2(std::vector<double>{4.0, 5.0, 6.0});

    // Calculate the Hadamard product
    Vector hadamardResult = v1.hadamard(v2); 

    // Print the result
    std::cout << "Hadamard product of v1 and v2: "; 
    hadamardResult.print(); 
}

void testVectorCopyAssignment()
{
    // Create a source vector
    Vector v1(std::vector<double>{1.0, 2.0, 3.0});

    // Create a target vector
    Vector v2;
    v2 = v1; // Copy assignment

    // Check equality
    if (v2 == v1)
    {
        std::cout << "testVectorCopyAssignment PASSED\n";
    }
    else
    {
        std::cout << "testVectorCopyAssignment FAILED\n";
    }
}

void testVectorMoveAssignment()
{
    // Create a source vector
    Vector v1(std::vector<double>{1.0, 2.0, 3.0});

    // Create a target vector
    Vector v2;
    v2 = std::move(v1); // Move assignment

    // Check the state of the target vector
    if (v2 == Vector(std::vector<double>{1.0, 2.0, 3.0}) && v1.getSize() == 0)
    {
        std::cout << "testVectorMoveAssignment PASSED\n";
    }
    else
    {
        std::cout << "testVectorMoveAssignment FAILED\n";
    }
}

void testVectorComparisonOperators()
{
    Vector v1(std::vector<double>{1.0, 2.0, 3.0});
    Vector v2(std::vector<double>{1.0, 2.0, 3.0});
    Vector v3(std::vector<double>{3.0, 2.0, 1.0});

    // Test equality operator
    if (v1 == v2)
    {
        std::cout << "testVectorComparisonOperators: Equality PASSED\n";
    }
    else
    {
        std::cout << "testVectorComparisonOperators: Equality FAILED\n";
    }

    // Test inequality operator
    if (v1 != v3)
    {
        std::cout << "testVectorComparisonOperators: Inequality PASSED\n";
    }
    else
    {
        std::cout << "testVectorComparisonOperators: Inequality FAILED\n";
    }
}

void testVectorZero()
{
    Vector zeroVector = Vector::zero(3);
    Vector expected(std::vector<double>{0.0, 0.0, 0.0});

    if (zeroVector == expected)
    {
        std::cout << "testVectorZero PASSED\n";
    }
    else
    {
        std::cout << "testVectorZero FAILED\n";
    }
}

void testVectorRandom()
{
    Vector randomVector = Vector::random(3, -10.0, 10.0);

    // Verify size
    if (randomVector.getSize() != 3)
    {
        std::cout << "testVectorRandom FAILED: Incorrect size\n";
        return;
    }

    // Verify values are within range
    bool valuesInRange = true;
    for (int i = 0; i < randomVector.getSize(); ++i)
    {
        double value = randomVector.getElement(i);
        if (value < -10.0 || value > 10.0)
        {
            valuesInRange = false;
            break;
        }
    }

    if (valuesInRange)
    {
        std::cout << "testVectorRandom PASSED\n";
    }
    else
    {
        std::cout << "testVectorRandom FAILED: Values out of range\n";
    }
}

// int main()
// {
//     testVectorMagnitude();
//     testVectorNormalize();
//     testVectorDotProduct();
//     testVectorCrossProduct();
//     testVectorAddition();
//     testVectorSubtraction();
//     testVectorScalarMultiplication();
//     testVectorDotProduct2();
//     testProjectOnto(); 
//     testhadamard();
//     testVectorCopyAssignment();
//     testVectorMoveAssignment();
//     testVectorComparisonOperators();
//     testVectorZero();
//     testVectorRandom();
//     return 0;
// }
