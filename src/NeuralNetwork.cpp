#include "ActivationFun.cpp"
#include "LinearLayer.cpp"
#include "LossFun.cpp"
#include "Optimizer.cpp"
#include "Utilities.cpp"
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class NeuralNetwork {
private:
    LinearLayer inputLayer;
    LinearLayer hiddenLayer;
    LinearLayer outputLayer;
    ReLU activationFunction;
    MSELoss lossFunction;
    SGD optimizer;

public:
    NeuralNetwork()
        : inputLayer(10, 30), hiddenLayer(30, 30), outputLayer(30, 1), optimizer(0.001) {
        // Initialize layers and optimizer
    }

    VectorXd forward (VectorXd& input) {
        //std::cout << input << std::endl;
        VectorXd hiddenOutput = activationFunction(inputLayer.forward(input));
        //std::cout << hiddenOutput << std::endl;
        VectorXd hiddenOutput2 = activationFunction(hiddenLayer.forward(hiddenOutput));
        //std::cout << hiddenOutput2 << std::endl;
        return outputLayer.forward(hiddenOutput2);
    }

    void train( std::vector<VectorXd>& inputs,  std::vector<VectorXd>& targets, int epochs) {
        for (int epoch = 0; epoch < epochs; ++epoch) {
            double totalLoss = 0.0;

            for (size_t i = 0; i < inputs.size(); ++i) {
                // Forward pass
                
                VectorXd predictions = forward(inputs[i]);
                //std::cout << 4 << std::endl;
                // Compute loss
                Eigen::VectorXd targetCopy = targets[i];
                //std::cout << 5 << std::endl;
                //std::cout <<"predictions: " << predictions << std::endl;
                //std::cout << targetCopy << std::endl;
                double loss = lossFunction.forward(predictions, targetCopy);
                //std::cout << 6 << std::endl;
                totalLoss += loss;
                //std::cout << 7 << std::endl;
                // Backward pass
                VectorXd gradLoss = lossFunction.lossDerivative(predictions, targetCopy);
                //std::cout << 8 << std::endl;
                VectorXd hiddenOutput = inputLayer.forward(inputs[i]);
                //std::cout << 9 << std::endl;
                VectorXd hiddenOutput2 = hiddenLayer.forward(hiddenOutput);
                //std::cout << 10 << std::endl;
                VectorXd gradOutput = outputLayer.backward(hiddenOutput2, gradLoss);
                //std::cout << 11 << std::endl;
                optimizer.step(outputLayer.weights, outputLayer.bias, outputLayer.gradWeights, outputLayer.gradBias);
                //std::cout << 12 << std::endl;
            }

            std::cout << "Epoch " << epoch + 1 << ": Loss = " << totalLoss / inputs.size() << std::endl;
        }
    }
};

