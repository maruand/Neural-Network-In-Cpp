#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <LinearLayer.h>

namespace py = pybind11;

void bind_layers(py::module_& m) {
    py::class_<LinearLayer>(m, "LinearLayer")
        .def(py::init<int, int>())
        .def("forward", &LinearLayer::forward)
        .def("backward", &LinearLayer::backward);
    
}