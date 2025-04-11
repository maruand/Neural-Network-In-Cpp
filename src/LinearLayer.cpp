#include <vector>
#include <Eigen/Dense>
#include <cmath>
#include <cstdlib>
#include <numeric>
#include <random>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class LinearLayer {
    public:
        LinearLayer(int nInputs, int nOutputs);
        
        VectorXd operator()(VectorXd& input);
        void backward(float* input, float* output);
        void updateWeights(float learningRate);
        void initWeights();
        void initBias();


    private:
        int nInputs;
        int nOutputs;
        VectorXd input;
        VectorXd output;
        MatrixXd weights;
        VectorXd bias;
        MatrixXd gradWeights;
        VectorXd gradBias;

    
};

// Constructor
LinearLayer::LinearLayer(int nInputs, int nOutputs) {
    this->nInputs = nInputs;
    this->nOutputs = nOutputs;
    initWeights();
    initBias();
    
};



void LinearLayer::initWeights(){

    std::random_device rd{};
    std::mt19937 gen{rd()};

    std::normal_distribution d{0.0, sqrt(nInputs)}; // Normal distribution with mean=0, std=sqrt(nInputs)

    auto normal = [&](){return d(gen);}; // Function to draw a random float from the normal dist (lambda exoressin that captures d and gen by reference)

    weights = MatrixXd::NullaryExpr(nOutputs, nInputs, normal); // Initialize the weight matrix with normally distributed floats
    
};

void LinearLayer::initBias(){
    bias = VectorXd::Ones(nOutputs);
};

VectorXd LinearLayer::operator()(VectorXd& input){
    output = input * weights + bias;
    return output;
};






