#pragma once
#include <vector>
#include <Eigen/Dense>
#include <cmath>
#include <cstdlib>
#include <numeric>
#include <random>
#include <iostream>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class LinearLayer {
    public:
        LinearLayer(int nInputs, int nOutputs);
        
        VectorXd forward(VectorXd &input);
        VectorXd backward( VectorXd &input, VectorXd &gradOutput);
        void updateWeights(float learningRate);
        void initWeights();
        void initBias();
        VectorXd input;
        VectorXd output;
        MatrixXd weights;
        VectorXd bias;
        MatrixXd gradWeights;
        VectorXd gradBias;


    private:
        int nInputs;
        int nOutputs;
        

    
};