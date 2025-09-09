#include "NeuralNetwork.cpp"
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

    // Create a true weight vector for generating targets
    VectorXd true_weights = VectorXd::LinSpaced(10, 1.0, 2.0); // weights from 1.0 to 2.0
    double true_bias = 0.5;
    std::default_random_engine generator;
    std::normal_distribution<double> noise_dist(0.0, 0.1); // small Gaussian noise

    for (int i = 0; i < 100; ++i) {
        VectorXd input = VectorXd::Random(10); // Random input vector of size 10
        double noise = noise_dist(generator);
        double target_value = input.dot(true_weights) + true_bias + noise;
        VectorXd target(1);
        target(0) = target_value;
        inputs.push_back(input);
        targets.push_back(target);
    }

    // Show predictions before training
    std::cout << "Predictions before training:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        VectorXd pred = nn.forward(inputs[i]);
        
        std::cout << "Prediction: " << pred.transpose() << ", Target: " << targets[i].transpose() << "\n";
    }

    // Train the neural network
    int epochs = 200;
    nn.train(inputs, targets, epochs);

    // Show predictions after training
    std::cout << "\nPredictions after training:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        VectorXd pred = nn.forward(inputs[i]);
        
        std::cout << "Prediction: " << pred.transpose() << ", Target: " << targets[i].transpose() << "\n";
    }

    return 0;
}