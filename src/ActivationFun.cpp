#include <Eigen/Dense>
#include <cmath>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class ReLU{
    public:
        VectorXd operator()(VectorXd &input);
        VectorXd derivative(VectorXd &input);
        ReLU();
        double forward(double x){return fmax(0.0,x);};
        double forward_prime(double x);
};

VectorXd ReLU::operator()(VectorXd &input){
    return input.unaryExpr([this](double x){return this->forward(x); }).eval();
};

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

class Sigmoid{
    public:
        VectorXd operator()(VectorXd &input);
        VectorXd derivative(VectorXd &input);
        Sigmoid();
        double forward(double x){return 1/(1+exp(-x));};
        double forward_prime(double x);
};

VectorXd Sigmoid::operator()(VectorXd &input){
    return input.unaryExpr([this](double x) {return this->forward(x);});
};

VectorXd Sigmoid::derivative(VectorXd &input){
    return input.unaryExpr([this](double x) {return this->forward_prime(x);});
};

double Sigmoid::forward_prime(double x){
    return forward(x)*(1-forward(x));
};