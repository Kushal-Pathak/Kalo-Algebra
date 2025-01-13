#pragma once // Ensure this header file is included only once during compilation

#include <iostream>  // For functions like std::cout
#include <vector>    // For std::vector usage
#include <stdexcept> // For exceptions like std::invalid_argument

class Matrix
{
private:
    std::vector<std::vector<double>> data; // 2D vector to store matrix elements
    int rows, cols;                        // Dimensions of the matrix

public:
    // Constructors
    Matrix(int rows, int cols, double initialValue = 0.0);     // Initialize with dimensions and a default value
    Matrix(const std::vector<std::vector<double>> &inputData); // Initialize with 2D vector
    Matrix(const Matrix &other);                               // Copy constructor
    Matrix(Matrix &&other) noexcept;                           // Move constructor

    // Destructor
    ~Matrix(); // Clean up resources if necessary

    // Accessors
    int getRows() const;                             // Get the number of rows
    int getCols() const;                             // Get the number of columns
    double getElement(int row, int col) const;       // Get the element at (row, col)
    void setElement(int row, int col, double value); // Set the element at (row, col)

    // Matrix Operations
    Matrix transpose() const;                                                   // Transpose the matrix
    Matrix subMatrix(int startRow, int startCol, int endRow, int endCol) const; // Extract a sub-matrix
    void print() const;                                                         // Print the matrix

    // Arithmetic Operators
    Matrix operator+(const Matrix &other) const; // Matrix addition
    Matrix operator-(const Matrix &other) const; // Matrix subtraction
    Matrix operator*(const Matrix &other) const; // Matrix multiplication
    Matrix operator*(double scalar) const;       // Scalar multiplication

    // Assignment Operators
    Matrix &operator=(const Matrix &other);     // Copy assignment
    Matrix &operator=(Matrix &&other) noexcept; // Move assignment

    // Comparison Operators
    bool operator==(const Matrix &other) const; // Check equality
    bool operator!=(const Matrix &other) const; // Check inequality

    // Static Methods
    static Matrix identity(int size);                                 // Create an identity matrix
    static Matrix zero(int rows, int cols);                           // Create a zero matrix
    static Matrix random(int rows, int cols, double min, double max); // Create a random matrix
};
