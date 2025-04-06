#include <vector>
#include <cmath>
#include <numeric>

class LinearLayer {
    public:
        LinearLayer(int nInputs, int nOutputs);
        ~LinearLayer();
        void forward(float* input);
        void backward(float* input, float* output);
        void updateWeights(float learningRate);
        void initWeights();
        void initBias();

    private:
        int nInputs;
        int nOutputs;
        float* weights;
        float* bias;
        float* gradWeights;
        float* gradBias;
        float* input;
        float* output;
    
};

LinearLayer::LinearLayer(int nInputs, int nOutputs) {
    this->nInputs = nInputs;
    this->nOutputs = nOutputs;
    weights = new float[nInputs * nOutputs]; // Dynamically allocate memory for weights
    bias = new float[nOutputs]; // Dynamically allocate memory for bias
    gradWeights = new float[nInputs * nOutputs]; // Dynamically allocate memory for gradient of weights
    gradBias = new float[nOutputs]; // Dynamically allocate memory for gradient of bias
    input = new float[nInputs]; // Dynamically allocate memory for input
    output = new float[nOutputs]; // Dynamically allocate memory for output

};
LinearLayer::~LinearLayer() {
    delete[] weights; // Free allocated memory for weights
    delete[] bias; // Free allocated memory for bias
    delete[] gradWeights; // Free allocated memory for gradient of weights
    delete[] gradBias; // Free allocated memory for gradient of bias
    delete[] input; // Free allocated memory for input
    delete[] output; // Free allocated memory for output
};
void LinearLayer::forward(float* input){


}