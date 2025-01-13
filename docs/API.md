### **API.md**

# Kalo Algebra API Documentation

This document provides a detailed explanation of the classes, methods, and utility functions available in the **Kalo Algebra**. Use this document as a reference while integrating the library into your projects.

---

## **1. Matrix Class**

### **Header File**

`matrix.hpp`

### **Description**

The `Matrix` class provides functionality for creating, manipulating, and performing operations on matrices.

### **Public Methods**

| **Method**                                                             | **Description**                                                                            |
| ---------------------------------------------------------------------- | ------------------------------------------------------------------------------------------ |
| `Matrix(int rows, int cols, double value)`                             | Constructs a matrix with specified rows, columns, and initializes all elements to `value`. |
| `Matrix(const std::vector<std::vector<double>>& inputData)`            | Constructs a matrix from a 2D vector.                                                      |
| `Matrix(const Matrix& other)`                                          | Copy constructor.                                                                          |
| `Matrix(Matrix&& other) noexcept`                                      | Move constructor.                                                                          |
| `~Matrix()`                                                            | Destructor.                                                                                |
| `int getRows() const`                                                  | Returns the number of rows in the matrix.                                                  |
| `int getCols() const`                                                  | Returns the number of columns in the matrix.                                               |
| `double getElement(int row, int col) const`                            | Retrieves the element at position `(row, col)`.                                            |
| `void setElement(int row, int col, double value)`                      | Sets the element at position `(row, col)` to `value`.                                      |
| `Matrix transpose() const`                                             | Returns the transpose of the matrix.                                                       |
| `Matrix subMatrix(int startRow, int startCol, int endRow, int endCol)` | Extracts a submatrix from the matrix.                                                      |
| `Matrix operator+(const Matrix& other) const`                          | Adds two matrices element-wise.                                                            |
| `Matrix operator-(const Matrix& other) const`                          | Subtracts two matrices element-wise.                                                       |
| `Matrix operator*(const Matrix& other) const`                          | Multiplies two matrices.                                                                   |
| `Matrix operator*(double scalar) const`                                | Multiplies all elements of the matrix by a scalar.                                         |
| `bool operator==(const Matrix& other) const`                           | Checks if two matrices are equal.                                                          |
| `bool operator!=(const Matrix& other) const`                           | Checks if two matrices are not equal.                                                      |
| `static Matrix identity(int size)`                                     | Creates an identity matrix of size `size x size`.                                          |
| `static Matrix zero(int rows, int cols)`                               | Creates a zero matrix with specified rows and columns.                                     |
| `static Matrix random(int rows, int cols, double min, double max)`     | Creates a matrix with random elements between `min` and `max`.                             |

---

## **2. Vector Class**

### **Header File**

`vector.hpp`

### **Description**

The `Vector` class provides functionality for creating, manipulating, and performing operations on vectors.

### **Public Methods**

| **Method**                                               | **Description**                                                                           |
| -------------------------------------------------------- | ----------------------------------------------------------------------------------------- |
| `Vector(int size, double initialValue)`                  | Constructs a vector with a specified size and initializes all elements to `initialValue`. |
| `Vector(const std::vector<double>& inputData)`           | Constructs a vector from an existing `std::vector`.                                       |
| `Vector(const Vector& other)`                            | Copy constructor.                                                                         |
| `Vector(Vector&& other) noexcept`                        | Move constructor.                                                                         |
| `~Vector()`                                              | Destructor.                                                                               |
| `int getSize() const`                                    | Returns the size of the vector.                                                           |
| `double getElement(int index) const`                     | Retrieves the element at the specified index.                                             |
| `void setElement(int index, double value)`               | Sets the element at the specified index to `value`.                                       |
| `double magnitude() const`                               | Calculates the magnitude (length) of the vector.                                          |
| `Vector normalize() const`                               | Returns a normalized version of the vector.                                               |
| `double dot(const Vector& other) const`                  | Calculates the dot product of two vectors.                                                |
| `Vector cross(const Vector& other) const`                | Calculates the cross product of two 3D vectors.                                           |
| `Vector operator+(const Vector& other) const`            | Adds two vectors element-wise.                                                            |
| `Vector operator-(const Vector& other) const`            | Subtracts two vectors element-wise.                                                       |
| `Vector operator*(double scalar) const`                  | Multiplies all elements of the vector by a scalar.                                        |
| `double operator*(const Vector& other) const`            | Calculates the dot product of two vectors using the `*` operator.                         |
| `bool operator==(const Vector& other) const`             | Checks if two vectors are equal.                                                          |
| `bool operator!=(const Vector& other) const`             | Checks if two vectors are not equal.                                                      |
| `static Vector zero(int size)`                           | Creates a zero vector of the specified size.                                              |
| `static Vector random(int size, double min, double max)` | Creates a vector with random elements between `min` and `max`.                            |

---

## **3. Utility Functions**

### **Header File**

`utils.hpp`

### **Description**

Contains general utility functions for linear algebra operations and debugging.

### **Functions**

| **Function**                                                         | **Description**                                                                             |
| -------------------------------------------------------------------- | ------------------------------------------------------------------------------------------- |
| `double euclideanNorm(const std::vector<double>& vec)`               | Calculates the Euclidean norm of a 1D `std::vector`.                                        |
| `bool approximatelyEqual(double a, double b, double epsilon = 1e-9)` | Checks if two floating-point numbers are approximately equal with a tolerance of `epsilon`. |
| `void print2DVector(const std::vector<std::vector<double>>& mat)`    | Prints a 2D vector (matrix-like structure) for debugging purposes.                          |
| `double randomDouble(double min, double max)`                        | Generates a random double between `min` and `max`.                                          |

---

## **4. Public API**

### **Header File**

`kalo_algebra.hpp`

### **Description**

The **`kalo_algebra.hpp`** header combines the `Matrix`, `Vector`, and utility functions into a single public API for the library.

### **How to Include the API**

To use the library in your project, simply include this file:

```cpp
#include "kalo_algebra.hpp"
```

---

## Example Usage

```cpp
#include "kalo_algebra.hpp"
#include <iostream>

int main() {
    // Create a matrix
    KaloAlgebra::Matrix mat(3, 3, 1.0);
    mat.setElement(1, 1, 5.0);
    std::cout << "Matrix:\n";
    mat.print();

    // Transpose the matrix
    auto transposed = mat.transpose();
    std::cout << "\nTransposed Matrix:\n";
    transposed.print();

    // Create a vector
    KaloAlgebra::Vector vec(3, 2.0);
    std::cout << "\nVector Magnitude: " << vec.magnitude() << "\n";

    return 0;
}
```

---

## Notes

1. Ensure that the library is built with C++17 or later.
2. Use the provided `CMakeLists.txt` file to build and link the library in your projects.

---

This API documentation gives a clear and detailed explanation of the features and functions available in the Kalo Algebra Library. For more information, feel free to explore the source code and test cases.

---
