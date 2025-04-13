#include <Eigen/Dense>
#include <cmath>


using Eigen::MatrixXd;
using Eigen::VectorXd;

class SGD{
    public:
        float learningRate;

        void step(MatrixXd &weigths, VectorXd &bias, MatrixXd &weightsGrad, VectorXd &biasGrad){
            weigths -= learningRate*weightsGrad;
            bias -= learningRate*biasGrad;
        };
};