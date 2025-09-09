#include <Eigen/Dense>
#include <cmath>
#include "../include/ActivationFun.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;


// VectorXd ReLU::operator()(VectorXd &input){
//     return input.unaryExpr([this](double x){return this->forward(x); }).eval();
// };

// VectorXd ReLU::operator()(const VectorXd& input) {
//     // Apply ReLU activation
//     return input.unaryExpr([this](double x){return this->forward(x); }).eval();
// }
ReLU::ReLU(){};
VectorXd ReLU::operator()(const VectorXd& input) {
    VectorXd output = input;
    for (int i = 0; i < output.size(); ++i) {
        output[i] = std::max(0.0, output[i]);
    }
    return output;
}
double ReLU::forward_prime(double x){
    int y;
    if (x <= 0){
        y = 0;
    }
    else{
        y = 1;
    };

    return y;
};

VectorXd ReLU::derivative(VectorXd &input){
    return input.unaryExpr([this](double x) {return this->forward_prime(x);}).eval();
};

Sigmoid::Sigmoid(){};
VectorXd Sigmoid::operator()(VectorXd &input){
    return input.unaryExpr([this](double x) {return this->forward(x);});
};

VectorXd Sigmoid::derivative(VectorXd &input){
    return input.unaryExpr([this](double x) {return this->forward_prime(x);});
};

double Sigmoid::forward_prime(double x){
    return forward(x)*(1-forward(x));
};