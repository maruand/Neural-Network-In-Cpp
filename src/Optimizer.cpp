#include <Eigen/Dense>
#include <cmath>
#include "Optimizer.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;


SGD::SGD(float lr){learningRate=lr;};

void SGD::step(MatrixXd &weigths, VectorXd &bias, MatrixXd &weightsGrad, VectorXd &biasGrad){
    weigths -= learningRate*weightsGrad;
    bias -= learningRate*biasGrad;
};