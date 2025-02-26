#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath> //For math operations

class Vector
{
private:
    std::vector<double> data; // data storage for vector
    int size;                 // vector size

public:
    // constructors
    Vector() : size(0), data() {} // Default constructor
    Vector(int size, double initialValue = 0.0);  // with size and initial value
    Vector(const std::vector<double> &inputData); // with std::vector instance
    Vector(const Vector &other);                  // copy constructor
    Vector(Vector &&other) noexcept;              // move constructor

    // Destructor
    ~Vector();

    // Accessors
    int getSize() const;                      // get vector size
    double getElement(int index) const;       // get an element
    void setElement(int index, double value); // set value
    void print() const;

    // Vector operations
    double magnitude() const;                // returns magnitude
    Vector normalize() const;                // returns normalized vector
    double dot(const Vector &other) const;   // dot product
    Vector cross(const Vector &other) const; // cross product (only for 3d vectors)
    Vector projectOnto(const Vector &other) const; // useful in physics for collision resolution and neural network for weight adjustment
    Vector hadamard(const Vector &other) const; // Essential in NN for element-wise weight updates 

    // Arithmetic Operators
    Vector operator+(const Vector &other) const; // vector addition
    Vector operator-(const Vector &other) const; // vector subtraction
    Vector operator*(double scalar) const;       // scalar multiplication
    double operator*(const Vector &other) const; // dot product

    // Assignment operators
    Vector &operator=(const Vector &other); // copy assignment
    Vector &operator=(Vector &&other) noexcept;      // move assignment

    // Comparision operators
    bool operator==(const Vector &other) const; // equality check
    bool operator!=(const Vector &other) const; // inequality check

    // Static methods
    static Vector zero(int size);                           // create a zero vector
    static Vector random(int size, double min, double max); // create a random vector
};
