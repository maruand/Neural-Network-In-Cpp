#pragma once
#include <Eigen/Dense>
#include <cmath>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class ReLU{
    public:
        VectorXd operator()(const VectorXd &input);
        VectorXd derivative(VectorXd &input);
        ReLU();
        double forward(double x){return fmax(0.0,x);};
        double forward_prime(double x);
};

class Sigmoid{
    public:
        VectorXd operator()(VectorXd &input);
        VectorXd derivative(VectorXd &input);
        Sigmoid();
        double forward(double x){return 1/(1+exp(-x));};
        double forward_prime(double x);
};
