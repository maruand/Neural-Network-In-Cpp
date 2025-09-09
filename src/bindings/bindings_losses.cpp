#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <LossFun.h>

namespace py = pybind11;

void bind_losses(py::module_& m) {
    py::class_<MSELoss>(m, "MSELoss")
        .def(py::init<>())
        .def("calculateLoss", &MSELoss::calculateLoss)
        .def("lossDerivative", &MSELoss::lossDerivative);
    
}