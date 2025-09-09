#include "/Users/marcusandersson/Desktop/neural_network/src/NeuralNetwork.cpp"
#include <iostream>
#include <vector>
#include <Eigen/Dense>

using Eigen::VectorXd;

int main() {
    // Create a neural network instance
    NeuralNetwork nn;

    // Generate dummy data for training
    std::vector<VectorXd> inputs;
    std::vector<VectorXd> targets;

    for (int i = 0; i < 100; ++i) {
        VectorXd input = VectorXd::Random(10); // Random input vector of size 10
        VectorXd target = VectorXd::Random(1); // Random target vector of size 1
        inputs.push_back(input);
        targets.push_back(target);
    }

    // Train the neural network
    int epochs = 10;
    nn.train(inputs, targets, epochs);

    return 0;
}