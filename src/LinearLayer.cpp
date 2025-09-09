#include <vector>
#include <Eigen/Dense>
#include <cmath>
#include <cstdlib>
#include <numeric>
#include <random>
#include <iostream>
#include "../include/LinearLayer.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;

// Constructor
LinearLayer::LinearLayer(int nInputs, int nOutputs) {
    this->nInputs = nInputs;
    this->nOutputs = nOutputs;
    initWeights();
    initBias();
    
};



void LinearLayer::initWeights(){

    std::random_device rd{};
    std::mt19937 gen{rd()};

        // Use smaller stddev for weights to avoid exploding values
        std::normal_distribution d{0.0, 1.0 / sqrt(nInputs)}; // Normal distribution with mean=0, std=1/sqrt(nInputs)

    auto normal = [&](){return d(gen);}; // Function to draw a random float from the normal dist (lambda exoressin that captures d and gen by reference)

    weights = MatrixXd::NullaryExpr(nOutputs, nInputs, normal); // Initialize the weight matrix with normally distributed floats
    
};

void LinearLayer::initBias(){
    bias = VectorXd::Ones(nOutputs);
};

VectorXd LinearLayer::forward(VectorXd &input) {
    if (input.size() != nInputs) {
        //std::cout << input.size()<<std::endl;
        //std::cout << nInputs<<std::endl;
        throw std::invalid_argument("Input size does not match the number of inputs for the layer.");
    }
    output = (weights * input).colwise() + bias; // Corrected matrix multiplication
    //std::cout << output.size() << std::endl;
    return output;
}

VectorXd LinearLayer::backward(VectorXd &input, VectorXd &gradOutput) {
    // Compute gradient of weights
    gradWeights = gradOutput * input.transpose();

    // Compute gradient of biases
    gradBias = gradOutput;

    // Compute gradient of input to propagate to the previous layer
    return weights.transpose() * gradOutput;
}





