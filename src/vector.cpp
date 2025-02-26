#include "vector.hpp"
#include <random>

// constructors
// Initialize with size and an initial value
Vector::Vector(int size, double initialValue) : size(size), data(size, initialValue)
{
    if (size <= 0)
        throw std::invalid_argument("Size must be greater than 0!");
}

// Initialize with an existing std::vector
Vector::Vector(const std::vector<double> &inputData) : size(inputData.size()), data(inputData)
{
    if (size == 0)
        throw std::invalid_argument("Input vector must not be empty!");
}

// copy constructor
Vector::Vector(const Vector &other) : size(other.size), data(other.data)
{
}

// move constructor
Vector::Vector(Vector &&other) noexcept : size(other.size), data(std::move(other.data))
{
    other.size = 0;
}

// destructor
Vector::~Vector()
{
}

// Accessors
int Vector::getSize() const
{
    return size;
}

double Vector::getElement(int index) const
{
    if (index < 0 || index >= size)
        throw std::invalid_argument("Index out of range!");
    return data[index];
}

void Vector::setElement(int index, double value)
{
    if (index < 0 || index >= size)
        throw std::invalid_argument("Index out of range!");
    data[index] = value;
}

void Vector::print() const {
    std::cout << "[ ";
    for (double value : data) {
        std::cout << value << " ";
    }
    std::cout << "]" << std::endl;  
}


// vector operations
double Vector::magnitude() const
{
    double sumOfSquares = 0.0;
    for (double value : data)
    {
        sumOfSquares += value * value;
    }
    return std::sqrt(sumOfSquares);
}

Vector Vector::normalize() const
{

    double mag = magnitude();
    if (mag == 0)
        throw std::invalid_argument("Can't normalize a zero vector!");
    Vector result(size);
    for (int i = 0; i < size; i++)

        result.data[i] = data[i] / mag;
    return result;
}

double Vector::dot(const Vector &other) const
{
    if (size != other.size)
        throw std::invalid_argument("Vector size must match to perform dot product!");
    double result = 0.0;
    for (int i = 0; i < size; i++)
        result += data[i] * other.data[i];
    return result;
}

Vector Vector::cross(const Vector &other) const
{
    if (size != 3 || other.size != 3)
        throw std::invalid_argument("Cross product is only possible dor 3d vector!");
    return Vector({data[1] * other.data[2] - data[2] * other.data[1],
                   data[2] * other.data[0] - data[0] * other.data[2],
                   data[0] * other.data[1] - data[1] * other.data[0]

    });
}

Vector Vector::projectOnto(const Vector &other) const {
    double denominator = other.dot(other); 
    if(denominator == 0) throw std::invalid_argument("Cannot project onto a zero vector!");
    return other * (this->dot(other) / denominator); 
}

Vector Vector::hadamard(const Vector &other) const {
    if (size != other.size) 
        throw std::invalid_argument("Vectors must be of the same size!");
    
    Vector result(size); 
    for (int i = 0; i < size; i++) 
        result.data[i] = data[i] * other.data[i];
    
    return result; 
}


// Arithmetic operators
Vector Vector::operator+(const Vector &other) const
{
    if (size != other.size)
    {
        throw std::invalid_argument("Vectors must be the same size for addition.");
    }
    Vector result(size);
    for (int i = 0; i < size; i++)
        result.data[i] = data[i] + other.data[i];
    return result;
}

Vector Vector::operator-(const Vector &other) const
{
    if (size != other.size)
    {
        throw std::invalid_argument("Vectors must be the same size for subtraction.");
    }
    Vector result(size);
    for (int i = 0; i < size; i++)
        result.data[i] = data[i] - other.data[i];
    return result;
}

Vector Vector::operator*(double scalar) const
{
    Vector result(size);
    for (int i = 0; i < size; i++)
        result.data[i] = data[i] * scalar;
    return result;
}

double Vector::operator*(const Vector &other) const
{
    if (size != other.size)
        throw std::invalid_argument("Vector size must match to perform dot product!");
    double result = 0.0;
    for (int i = 0; i < size; i++)
        result += data[i] * other.data[i];
    return result;
}

// Assignment operators
Vector &Vector::operator=(const Vector &other)
{
    if (this != &other)
    {
        size = other.size;
        data = other.data;
    }

    return *this;
}

Vector &Vector::operator=(Vector &&other) noexcept
{
    if (this != &other)
    {
        size = other.size;
        data = std::move(other.data);
        other.size = 0;
    }
    return *this;
}

// Comparision operators
bool Vector::operator==(const Vector &other) const
{
    return size == other.size && data == other.data;
}

bool Vector::operator!=(const Vector &other) const
{
    return !(*this == other);
}

// static methods
Vector Vector::zero(int size)
{
    if (size <= 0)
        throw std::invalid_argument("Vector size must be greater than 0!");
    return Vector(size, 0.0);
}

Vector Vector::random(int size, double min, double max)
{
    if (size <= 0 || min > max)
        throw std::invalid_argument("Invalid size or range!");
    Vector result(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(min, max);
    for (int i = 0; i < size; i++)
    {
        result.data[i] = dist(gen);
    }
    return result;
}
