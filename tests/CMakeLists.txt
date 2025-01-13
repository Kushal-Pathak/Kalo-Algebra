# Enable testing
enable_testing()

# Add test executable for Matrix tests
add_executable(test_matrix test_matrix.cpp)
target_link_libraries(test_matrix KaloAlgebra)

# Add test executable for Vector tests
add_executable(test_vector test_vector.cpp)
target_link_libraries(test_vector KaloAlgebra)

# Register the tests with CTest
add_test(NAME MatrixTests COMMAND test_matrix)
add_test(NAME VectorTests COMMAND test_vector)