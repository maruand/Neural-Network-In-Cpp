#include <pybind11/pybind11.h>

namespace py = pybind11;

// Forward declarations from submodules
void bind_activations(py::module_& m);
void bind_layers(py::module_& m);
void bind_losses(py::module_& m);
void bind_optimizers(py::module_& m);

PYBIND11_MODULE(NN, m) {
    m.doc() = "Bindings for my neural network";
    // Define submodules and bind their respective functions
    auto activations = m.def_submodule("activations");
    bind_activations(activations);

    auto layers = m.def_submodule("layers");
    bind_layers(layers);

    auto losses = m.def_submodule("losses");
    bind_losses(losses);

    auto optim = m.def_submodule("optim");
    bind_optimizers(optim);
}