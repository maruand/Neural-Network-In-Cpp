cmake_minimum_required(VERSION 3.14)
project(NN)

set(CMAKE_CXX_STANDARD 17)

# Get pybind11 cmake path
execute_process(
    COMMAND python3 -m pybind11 --cmakedir
    OUTPUT_VARIABLE pybind11_dir
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
list(APPEND CMAKE_PREFIX_PATH ${pybind11_dir})

# Packages
find_package(pybind11 REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(include)

# Add bindings from subcomponents
file(GLOB BINDINGS "src/bindings/*.cpp")

# Build the pybind11 module
pybind11_add_module(NN
    ${BINDINGS}
    src/ActivationFun.cpp
    src/LinearLayer.cpp
    src/LossFun.cpp
    src/Optimizer.cpp
)

target_link_libraries(NN PRIVATE Eigen3::Eigen)