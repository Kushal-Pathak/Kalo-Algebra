#include <iostream>
#include "kalo_algebra.hpp"

// Function to check if two matrices are equal
bool areMatricesEqual(const KaloAlgebra::Matrix &mat1, const KaloAlgebra::Matrix &mat2)
{
    if (mat1.getRows() != mat2.getRows() || mat1.getCols() != mat2.getCols())
    {
        return false;
    }
    for (int i = 0; i < mat1.getRows(); i++)
    {
        for (int j = 0; j < mat1.getCols(); j++)
        {
            if (mat1.getElement(i, j) != mat2.getElement(i, j))
            {
                return false;
            }
        }
    }
    return true;
}

void testMatrixTranspose()
{
    // Create a 2x3 matrix
    Matrix mat(2, 3, 0.0);
    mat.setElement(0, 0, 1.0);
    mat.setElement(0, 1, 2.0);
    mat.setElement(0, 2, 3.0);
    mat.setElement(1, 0, 4.0);
    mat.setElement(1, 1, 5.0);
    mat.setElement(1, 2, 6.0);

    // Transpose the matrix
    Matrix transposed = mat.transpose();

    // Expected transposed matrix (3x2)
    Matrix expected(3, 2, 0.0);
    expected.setElement(0, 0, 1.0);
    expected.setElement(0, 1, 4.0);
    expected.setElement(1, 0, 2.0);
    expected.setElement(1, 1, 5.0);
    expected.setElement(2, 0, 3.0);
    expected.setElement(2, 1, 6.0);

    // Compare the result with the expected matrix
    if (areMatricesEqual(transposed, expected))
    {
        std::cout << "testMatrixTranspose PASSED\n";
    }
    else
    {
        std::cout << "testMatrixTranspose FAILED\n";
    }
}

void testMatrixSubMatrix()
{
    // Create a 4x4 matrix with sequential elements
    Matrix mat(4, 4, 0.0);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            mat.setElement(i, j, i * 4 + j + 1); // Fill with 1, 2, ..., 16
        }
    }

    // Extract a sub-matrix (2x2 sub-matrix from (1, 1) to (2, 2))
    Matrix subMat = mat.subMatrix(1, 1, 2, 2);

    // Expected sub-matrix
    Matrix expected(2, 2, 0.0);
    expected.setElement(0, 0, 6.0);  // mat(1, 1)
    expected.setElement(0, 1, 7.0);  // mat(1, 2)
    expected.setElement(1, 0, 10.0); // mat(2, 1)
    expected.setElement(1, 1, 11.0); // mat(2, 2)

    // Compare the result with the expected matrix
    if (areMatricesEqual(subMat, expected))
    {
        std::cout << "testMatrixSubMatrix PASSED\n";
    }
    else
    {
        std::cout << "testMatrixSubMatrix FAILED\n";
    }
}

void testMatrixAddition()
{
    // Create two 2x2 matrices
    Matrix mat1(2, 2, 1.0); // All elements are 1.0
    Matrix mat2(2, 2, 2.0); // All elements are 2.0

    // Add the matrices
    Matrix result = mat1 + mat2;

    // Expected result
    Matrix expected(2, 2, 3.0); // All elements are 3.0

    // Verify the result
    if (areMatricesEqual(result, expected))
    {
        std::cout << "testMatrixAddition PASSED\n";
    }
    else
    {
        std::cout << "testMatrixAddition FAILED\n";
    }
}

void testMatrixSubtraction()
{
    // Create two 2x2 matrices
    Matrix mat1(2, 2, 5.0); // All elements are 5.0
    Matrix mat2(2, 2, 3.0); // All elements are 3.0

    // Subtract the matrices
    Matrix result = mat1 - mat2;

    // Expected result
    Matrix expected(2, 2, 2.0); // All elements are 2.0

    // Verify the result
    if (areMatricesEqual(result, expected))
    {
        std::cout << "testMatrixSubtraction PASSED\n";
    }
    else
    {
        std::cout << "testMatrixSubtraction FAILED\n";
    }
}

void testMatrixMultiplication()
{
    // Create two matrices for multiplication
    Matrix mat1(2, 3, 0.0);
    mat1.setElement(0, 0, 1.0);
    mat1.setElement(0, 1, 2.0);
    mat1.setElement(0, 2, 3.0);
    mat1.setElement(1, 0, 4.0);
    mat1.setElement(1, 1, 5.0);
    mat1.setElement(1, 2, 6.0);

    Matrix mat2(3, 2, 0.0);
    mat2.setElement(0, 0, 7.0);
    mat2.setElement(0, 1, 8.0);
    mat2.setElement(1, 0, 9.0);
    mat2.setElement(1, 1, 10.0);
    mat2.setElement(2, 0, 11.0);
    mat2.setElement(2, 1, 12.0);

    // Multiply the matrices
    Matrix result = mat1 * mat2;

    // Expected result
    Matrix expected(2, 2, 0.0);
    expected.setElement(0, 0, 58.0);  // 1*7 + 2*9 + 3*11
    expected.setElement(0, 1, 64.0);  // 1*8 + 2*10 + 3*12
    expected.setElement(1, 0, 139.0); // 4*7 + 5*9 + 6*11
    expected.setElement(1, 1, 154.0); // 4*8 + 5*10 + 6*12

    // Verify the result
    if (areMatricesEqual(result, expected))
    {
        std::cout << "testMatrixMultiplication PASSED\n";
    }
    else
    {
        std::cout << "testMatrixMultiplication FAILED\n";
    }
}

void testMatrixScalarMultiplication()
{
    // Create a 2x2 matrix
    Matrix mat(2, 2, 1.0); // All elements are 1.0

    // Multiply by a scalar
    double scalar = 5.0;
    Matrix result = mat * scalar;

    // Expected result
    Matrix expected(2, 2, 5.0); // All elements are 5.0

    // Verify the result
    if (areMatricesEqual(result, expected))
    {
        std::cout << "testMatrixScalarMultiplication PASSED\n";
    }
    else
    {
        std::cout << "testMatrixScalarMultiplication FAILED\n";
    }
}

void testMatrixCopyAssignment()
{
    // Create an initial matrix
    Matrix mat1(2, 2, 1.0); // All elements are 1.0

    // Create another matrix and assign mat1 to it
    Matrix mat2(2, 2, 0.0); // All elements are 0.0
    mat2 = mat1;            // Copy assignment

    // Expected result: mat2 should be identical to mat1
    if (areMatricesEqual(mat1, mat2))
    {
        std::cout << "testMatrixCopyAssignment PASSED\n";
    }
    else
    {
        std::cout << "testMatrixCopyAssignment FAILED\n";
    }
}

void testMatrixMoveAssignment()
{
    // Create a matrix to be moved
    Matrix mat1(2, 2, 5.0); // All elements are 5.0

    // Move mat1 to mat2
    Matrix mat2(2, 2, 0.0); // All elements are 0.0
    mat2 = std::move(mat1); // Move assignment

    // Expected result:
    // 1. mat2 should now contain the data from mat1
    // 2. mat1 should be in a valid but unspecified state (rows and cols reset to 0 in your implementation)

    // Verify mat2's contents
    Matrix expected(2, 2, 5.0); // All elements should be 5.0
    if (areMatricesEqual(mat2, expected))
    {
        std::cout << "testMatrixMoveAssignment PASSED\n";
    }
    else
    {
        std::cout << "testMatrixMoveAssignment FAILED (mat2 contents incorrect)\n";
    }

    // Verify mat1's state (optional; you can choose how to handle moved-from objects)
    if (mat1.getRows() == 0 && mat1.getCols() == 0)
    {
        std::cout << "testMatrixMoveAssignment PASSED (mat1 state after move is valid)\n";
    }
    else
    {
        std::cout << "testMatrixMoveAssignment FAILED (mat1 state after move is invalid)\n";
    }
}

void testMatrixEquality()
{
    // Create two identical matrices
    Matrix mat1(2, 2, 1.0); // All elements are 1.0
    Matrix mat2(2, 2, 1.0); // All elements are 1.0

    // Create a different matrix
    Matrix mat3(2, 2, 2.0); // All elements are 2.0

    // Test equality
    if (mat1 == mat2)
    {
        std::cout << "testMatrixEquality PASSED (mat1 == mat2)\n";
    }
    else
    {
        std::cout << "testMatrixEquality FAILED (mat1 == mat2)\n";
    }

    // Test inequality
    if (!(mat1 == mat3))
    {
        std::cout << "testMatrixEquality PASSED (mat1 != mat3)\n";
    }
    else
    {
        std::cout << "testMatrixEquality FAILED (mat1 != mat3)\n";
    }
}

void testMatrixInequality()
{
    // Create two identical matrices
    Matrix mat1(3, 3, 0.0); // All elements are 0.0
    Matrix mat2(3, 3, 0.0); // All elements are 0.0

    // Create a different matrix
    Matrix mat3(3, 3, 1.0); // All elements are 1.0

    // Test inequality
    if (!(mat1 != mat2))
    {
        std::cout << "testMatrixInequality PASSED (mat1 == mat2)\n";
    }
    else
    {
        std::cout << "testMatrixInequality FAILED (mat1 == mat2)\n";
    }

    // Test equality
    if (mat1 != mat3)
    {
        std::cout << "testMatrixInequality PASSED (mat1 != mat3)\n";
    }
    else
    {
        std::cout << "testMatrixInequality FAILED (mat1 != mat3)\n";
    }
}

void testIdentityMatrix()
{
    KaloAlgebra::Matrix identity = KaloAlgebra::Matrix::identity(3);

    // Expected result
    KaloAlgebra::Matrix expected(3, 3, 0.0);
    for (int i = 0; i < 3; i++)
    {
        expected.setElement(i, i, 1.0);
    }

    if (areMatricesEqual(identity, expected))
    {
        std::cout << "testIdentityMatrix PASSED\n";
    }
    else
    {
        std::cout << "testIdentityMatrix FAILED\n";
    }
}

void testMatrixZero()
{
    // Create a 3x2 zero matrix
    Matrix zeroMatrix = Matrix::zero(3, 2);

    // Expected result: All elements should be 0.0
    Matrix expected(3, 2, 0.0);

    // Check if the generated zero matrix matches the expected result
    if (areMatricesEqual(zeroMatrix, expected))
    {
        std::cout << "testMatrixZero PASSED\n";
    }
    else
    {
        std::cout << "testMatrixZero FAILED\n";
    }
}

void testMatrixRandom()
{
    // Generate a random 3x3 matrix with values between 1.0 and 5.0
    Matrix randomMatrix = Matrix::random(3, 3, 1.0, 5.0);

    // Validate the size of the matrix
    if (randomMatrix.getRows() != 3 || randomMatrix.getCols() != 3)
    {
        std::cout << "testMatrixRandom FAILED (incorrect size)\n";
        return;
    }

    // Check if the generated values are within the range
    bool withinRange = true;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            double value = randomMatrix.getElement(i, j);
            if (value < 1.0 || value > 5.0)
            {
                withinRange = false;
                break;
            }
        }
    }

    if (withinRange)
    {
        std::cout << "testMatrixRandom PASSED\n";
    }
    else
    {
        std::cout << "testMatrixRandom FAILED (values out of range)\n";
    }
}

int main()
{
    testMatrixTranspose();
    testMatrixSubMatrix();
    testMatrixAddition();
    testMatrixSubtraction();
    testMatrixMultiplication();
    testMatrixScalarMultiplication();
    testMatrixCopyAssignment();
    testMatrixMoveAssignment();
    testIdentityMatrix();
    testMatrixEquality();
    testMatrixInequality();
    testMatrixZero();
    testMatrixRandom();
    return 0;
}
