# Kalo Algebra

A lightweight and efficient **C++ library** for performing linear algebra operations, including matrix and vector manipulations. This library is designed for use in various applications such as **machine learning**, **computer graphics**, **physics simulations**, and more.

---

## Features

- **Matrix Operations**:

  - Addition, subtraction, and multiplication.
  - Transpose and submatrix extraction.
  - Identity matrix, zero matrix, and random matrix generation.

- **Vector Operations**:

  - Dot product and cross product.
  - Magnitude and normalization.
  - Scalar multiplication.

- **Utility Functions**:
  - Euclidean norm for `std::vector`.
  - Floating-point number comparison with a tolerance.
  - Debugging tools like printing 2D vectors.

---

## Project Structure

```plaintext
kalo-algebra/
├── include/                 # Header files (interface)
│   ├── matrix.hpp           # Matrix class declarations
│   ├── vector.hpp           # Vector class declarations
│   ├── utils.hpp            # Utility functions
│   └── kalo_algebra.hpp     # Public API
│
├── src/                     # Source files (implementation)
│   ├── matrix.cpp           # Matrix methods
│   ├── vector.cpp           # Vector methods
│   ├── utils.cpp            # Utility function definitions
│
├── main.cpp                 # Main entry point
│
├── tests/                   # Unit tests for the library
│   ├── test_matrix.cpp      # Tests for matrix operations
│   ├── test_vector.cpp      # Tests for vector operations
│   └── CMakeLists.txt       # Build configuration for tests
│
├── docs/                    # Documentation
│   ├── README.md            # Overview of the library
│   └── API.md               # Detailed API documentation
│
├── build/                   # Build directory (ignored in source control)
│
├── CMakeLists.txt           # Build configuration for the project
└── LICENSE                  # License file
```

---

## Getting Started

### Prerequisites

- A **C++ Compiler** supporting C++17 or later.
- **CMake** (version 3.10 or higher).
- A development environment or terminal-based setup.

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/kushal-pathak/Kalo-Algebra.git
   cd Kalo-Algebra
   ```

2. Create a `build` directory and configure the project:

   ```bash
   mkdir build
   cd build
   cmake .. # For default systems (Make sure build folder is empty) or
   cmake -G "MinGW Makefiles" .. # On Windows with MinGW (Make sure build folder is empty)
   ```

3. Build the project:

   ```bash
   make # On Linux/Mac or
   mingw32-make # On Windows with MinGW
   ```

4. Run the program:
   ```bash
   ./main
   ```

---

**Another way to build main.cpp**

Build the main project using CMake Preset:

```bash
cd Kalo-Algebra
cmake --preset build_main #configure
cmake --build build #compile
./build/main.exe #execute
```

## Usage Example

```cpp
#include "kalo_algebra.hpp"
#include <iostream>

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

    return 0;
}
```

Compile and run the above example after building the library.

---

## Testing

Unit tests are provided to verify the correctness of the library. To run the tests:

```bash
cd Kalo-Algebra

cmake --preset build_tests #configure for tests

cmake --build build/tests #build tests

./build/tests/test_matrix.exe #run tests

./build/tests/test_vector.exe
```

---

## Contributing

Everyone is welcome to help out with this project! Follow these steps to contribute:

1. Fork the repository.
2. Create a new branch for your feature or bug fix:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add feature-name"
   ```
4. Push your branch and open a pull request:
   ```bash
   git push origin feature-name
   ```

---

## License

This project is licensed under the **MIT License**. See the [LICENSE](../LICENSE) file for details.

---

## Acknowledgements

- Inspired by the amazing work of [The Coding Train](https://thecodingtrain.com).
- Special thanks to Mahesh Khanal, for his invaluable guidance in mathematics.
- Grateful to the open-source community for tools and resources that made this project possible.

---
