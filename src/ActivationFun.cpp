#include <Eigen/Dense>
#include <cmath>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class ReLU{
    public:
        VectorXd operator()(VectorXd &input);
        VectorXd derivative(VectorXd &input);
        ReLU();
        float forward(float x){return fmax(0.0,x);};
        float forward_prime(float x);
};

VectorXd ReLU::operator()(VectorXd &input){
    return input.unaryExpr(&forward);
};

float ReLU::forward_prime(float x){
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
    return input.unaryExpr(&forward_prime);
};

class Sigmoid{
    public:
        VectorXd operator()(VectorXd &input);
        VectorXd derivative(VectorXd &input);
        Sigmoid();
        float forward(float x){return 1/(1+expf(-x));};
        float forward_prime(float x);
};

VectorXd Sigmoid::operator()(VectorXd &input){
    return input.unaryExpr(&forward);
};

VectorXd Sigmoid::derivative(VectorXd &input){
    return input.unaryExpr(&forward);
};

float Sigmoid::forward_prime(float x){
    return forward(x)*(1-forward(x));
};