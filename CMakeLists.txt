cmake_minimum_required(VERSION 3.18)
project(pacio_test VERSION 1.0.0 LANGUAGES C)

# Set up specifications for the C compiler.
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# Set output directories.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

# Link the LibPacIO shared library, if there is one.
find_library(pacio NAMES pacio REQUIRED)

# Gather the main files.
FILE(GLOB MAIN ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

# Output the executable.
add_executable(pacio_test ${MAIN})
target_include_directories(pacio_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(pacio_test PRIVATE pacio)
install(TARGETS pacio_test DESTINATION bin)
