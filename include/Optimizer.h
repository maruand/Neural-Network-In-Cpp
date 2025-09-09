#pragma once
#include <Eigen/Dense>
#include <cmath>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class SGD{
    public:
        float learningRate;
        SGD(float lr);
        void step(MatrixXd &weigths, VectorXd &bias, MatrixXd &weightsGrad, VectorXd &biasGrad);
};