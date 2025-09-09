#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <ActivationFun.h>

namespace py = pybind11;

void bind_activations(py::module_& m) {
    py::class_<ReLU>(m, "ReLU")
        .def(py::init<>())
        .def("__call__", &ReLU::operator())
        .def("derivative", &ReLU::derivative)
        .def("forward_prime", &ReLU::forward_prime);

    py::class_<Sigmoid>(m, "Sigmoid")
        .def(py::init<>())
        .def("__call__", &Sigmoid::operator())
        .def("derivative", &Sigmoid::derivative)
        .def("forward", &Sigmoid::forward)
        .def("forward_prime", &Sigmoid::forward_prime);
}