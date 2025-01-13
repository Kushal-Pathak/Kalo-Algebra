#include "matrix.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <random> //For random number generation

// Constructor: Initialized with dimensions and initial value
Matrix::Matrix(int rows, int cols, double initialValue) : rows(rows), cols(cols)
{
    data = std::vector<std::vector<double>>(rows, std::vector<double>(cols, initialValue));
}

// Constructor: Initialized with a 2d vector
Matrix::Matrix(const std::vector<std::vector<double>> &inputData) : data(inputData)
{
    rows = data.size();
    cols = data.empty() ? 0 : data[0].size();

    // Check if all rows have same number of columns
    for (const auto &row : data)
    {
        if (row.size() != cols)
        {
            throw std::invalid_argument("All rows must have same number of column!");
        }
    }
}

// Constructor: Initialize with copy constructor
Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols), data(other.data)
{
}

// Constructor: Move
Matrix::Matrix(Matrix &&other) noexcept : rows(other.rows), cols(other.cols), data(std::move(other.data))
{
    other.rows = 0;
    other.cols = 0;
}

// Destructor
Matrix::~Matrix()
{
}

// Accessors
int Matrix::getRows() const
{
    return rows;
}

int Matrix::getCols() const
{
    return cols;
}

double Matrix::getElement(int row, int col) const
{
    if (row < 0 || row >= rows || col < 0 || col >= cols)
    {
        throw std::invalid_argument("Index out of range!");
    }
    return data[row][col];
}

void Matrix::setElement(int row, int col, double value)
{
    if (row < 0 || row >= rows || col < 0 || col >= cols)
    {
        throw std::invalid_argument("Index out of range!");
    }
    data[row][col] = value;
}

// Matrix Operations
Matrix Matrix::transpose() const
{
    Matrix result(cols, rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}

// Sub matrix
Matrix Matrix::subMatrix(int startRow, int startCol, int endRow, int endCol) const
{
    if (startRow < 0 || startRow >= rows || startCol < 0 || startCol >= cols || endRow < 0 || endRow >= rows || endCol < 0 || endCol >= cols)
    {
        throw std::invalid_argument("Index out of bound!");
    }
    Matrix result(endRow - startRow + 1, endCol - startCol + 1);
    for (int i = startRow; i <= endRow; i++)
    {
        for (int j = startCol; j <= endCol; j++)
        {
            result.data[i - startRow][j - startCol] = data[i][j];
        }
    }
    return result;
}

void Matrix::print() const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << data[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}

// Arithmetic Operators
// Matrix addition
Matrix Matrix::operator+(const Matrix &other) const
{
    if (other.rows != rows || other.cols != cols)
    {
        throw std::invalid_argument("Matrix dimensions must match in order to perform addition!");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Matrix subtraction
Matrix Matrix::operator-(const Matrix &other) const
{
    if (other.rows != rows || other.cols != cols)
    {
        throw std::invalid_argument("Matrix dimensions must match in order to perform subtraction!");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

// Matrix multiplication
Matrix Matrix::operator*(const Matrix &other) const
{
    if (cols != other.rows)
    {
        throw std::invalid_argument("Columns of first matrix must match rows of second matrix in order to perform multiplication!");
    }
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < other.cols; j++)
        {
            for (int k = 0; k < cols; k++)
            {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

// Scalar multiplication
Matrix Matrix::operator*(double scalar) const
{
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.data[i][j] = scalar * data[i][j];
        }
    }
    return result;
}

// Assignment Operators
// Copy assignment
Matrix &Matrix::operator=(const Matrix &other)
{
    if (this != &other)
    {
        rows = other.rows;
        cols = other.cols;
        data = other.data;
    }
    return *this;
}
// Move assignment
Matrix &Matrix::operator=(Matrix &&other) noexcept
{
    if (this != &other)
    {
        rows = other.rows;
        cols = other.cols;
        data = std::move(other.data);
        other.rows = 0;
        other.cols = 0;
    }
    return *this;
}

// Comparison Operators
// Check equality
bool Matrix::operator==(const Matrix &other) const
{
    return rows == other.rows && cols == other.cols && data == other.data;
}
// Check inequality
bool Matrix::operator!=(const Matrix &other) const
{
    return !(*this == other);
}

// Static Methods
// Create an identity matrix
Matrix Matrix::identity(int size)
{
    Matrix result(size, size, 0.0);
    for (int i = 0; i < size; i++)
    {
        result.data[i][i] = 1.0;
    }
    return result;
}
// Create a zero matrix
Matrix Matrix::zero(int rows, int cols)
{
    return Matrix(rows, cols, 0.0);
}
// Create a random matrix
Matrix Matrix::random(int rows, int cols, double min, double max)
{
    Matrix result(rows, cols);
    std::random_device rd;                                 // seed
    std::mt19937 gen(rd());                                // generator
    std::uniform_real_distribution<double> dist(min, max); // range
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.data[i][j] = dist(gen); // generate random number
        }
    }
    return result;
}