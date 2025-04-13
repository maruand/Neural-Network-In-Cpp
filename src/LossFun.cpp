#include <Eigen/Dense>
#include <cmath>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class MSELoss{
    public:
        MSELoss();
        float operator()(VectorXd prdiction, VectorXd &target);
        float calculateLoss(VectorXd prediction, VectorXd &target);
        VectorXd lossDerivative(VectorXd prediction, VectorXd &target);

};

float MSELoss::operator()(VectorXd prediction, VectorXd &target){
    return calculateLoss(prediction, target);
};

float MSELoss::calculateLoss(VectorXd prediction, VectorXd &target){
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

