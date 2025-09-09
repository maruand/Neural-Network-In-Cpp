# Neural Network

## Project Description
This project is a modular neural network implementation in C++ designed for educational, experimental, and practical machine learning tasks. It provides core components for building, training, and evaluating neural networks, with a focus on extensibility and clarity. The codebase demonstrates how to implement and train a simple feedforward neural network for regression tasks, such as predicting housing prices.

## Features
- Customizable feedforward neural network architecture
- Support for various activation functions (ReLU, Sigmoid)
- Mean Squared Error (MSE) loss function
- Stochastic Gradient Descent (SGD) optimizer
- Example demonstration with synthetic data
- Integration with Eigen for efficient matrix operations

## Getting Started
### Prerequisites
- C++20 compatible compiler (e.g., clang++, g++)
- Eigen library (install via Homebrew: `brew install eigen`)

### Build and Run
1. Clone the repository:
	```sh
	git clone <repo-url>
	cd neural_network
	```
2. Build the demo:
	```sh
	clang++ -g -std=c++20 src/main.cpp -I/opt/homebrew/include/eigen3 -o neural_network
	```
3. Run the demo:
	```sh
	./neural_network
	```

## Project Structure

- `src/` — Source code for neural network layers, activations, loss functions, optimizer, and main demo
	 - `NeuralNetwork.cpp` — Main neural network class
	 - `LinearLayer.cpp` — Linear layer implementation
	 - `ActivationFun.cpp` — Activation functions (ReLU, Sigmoid)
	 - `LossFun.cpp` — Loss functions (MSE)
	 - `Optimizer.cpp` — Optimizer (SGD)
	 - `main.cpp` — Demonstration and entry point
- `include/` — Header files for all components
- `data/` — Example datasets (CSV files)
- `build/` — Build artifacts
- `NN.so` — Python bindings (if applicable)
- `README.md` — Project documentation

## Example Demo
The demo in `main.cpp` generates synthetic data with a known linear relationship, trains the neural network, and prints predictions before and after training to show learning progress.




