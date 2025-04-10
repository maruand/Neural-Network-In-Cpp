#include <Eigen/Dense>
#include <cmath>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class ReLU{
    public:
        VectorXd operator()(VectorXd &input);
        ReLU();
        float forward(float x){return fmax(0.0,x);};
};

VectorXd ReLU::operator()(VectorXd& input){
    return input.unaryExpr(&forward);
};