#include <Eigen/Dense>
#include <cmath>
#include <iostream>
#include "../include/LossFun.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;



MSELoss::MSELoss(){};
float MSELoss::forward(VectorXd prediction, VectorXd &target){
    return calculateLoss(prediction, target);
};

float MSELoss::calculateLoss(VectorXd prediction, VectorXd &target){
    //std::cout << prediction << std::endl;
    //std::cout << target << std::endl;
    VectorXd residuals = prediction - target;
    VectorXd residualsSquared = residuals.array().square();
    return residualsSquared.sum();

};

VectorXd MSELoss::lossDerivative(VectorXd prediction, VectorXd &target){
    return 2*(prediction-target);
};

class BinaryMAELoss
{
private:
    /* data */
public:
    BinaryMAELoss(/* args */);
    
};

BinaryMAELoss::BinaryMAELoss(/* args */)
{
}

