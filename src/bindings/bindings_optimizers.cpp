#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <Optimizer.h>

namespace py = pybind11;

void bind_optimizers(py::module_& m) {
    py::class_<SGD>(m, "SGD")
        .def(py::init<float>())
        .def("step", &SGD::step);
}