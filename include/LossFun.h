#pragma once
#include <Eigen/Dense>
#include <cmath>
#include <iostream>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class MSELoss{
    public:
        MSELoss();
        float forward(VectorXd prdiction, VectorXd &target);
        float calculateLoss(VectorXd prediction, VectorXd &target);
        VectorXd lossDerivative(VectorXd prediction, VectorXd &target);

};