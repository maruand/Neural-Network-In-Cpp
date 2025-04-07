#include <vector>
#include <cmath>
#include <cstdlib>
#include <numeric>
#include <random>


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
        float* input;
        float* output;
        std::vector<float> weights;
        std::vector<float> bias;
        std::vector<float> gradWeights;
        std::vector<float> gradBias;

    
};

LinearLayer::LinearLayer(int nInputs, int nOutputs) {
    this->nInputs = nInputs;
    this->nOutputs = nOutputs;
    input = new float[nInputs]; // Dynamically allocate memory for input
    output = new float[nOutputs]; // Dynamically allocate memory for output

};
LinearLayer::~LinearLayer() {
    delete[] input; // Free allocated memory for input
    delete[] output; // Free allocated memory for output
};

void LinearLayer::initWeights(){
    std::random_device rd{};
    std::mt19937 gen{rd()};

    std::normal_distribution d{0.0, sqrt(nInputs)}; // Normal distribution with mean=0, std=sqrt(nInputs)

    auto random_float = [&d, &gen]{return d(gen);}; // Function to draw a random float from the normal dist

    // Populate the wegihts matrix with random floats
    for (int i = 0; i < nInputs; i++ ){
        for (int j = 0; j < nOutputs; j++){
            weights[i,j] = random_float();
        };
        
    };
};

void LinearLayer::initBias(){
    for (int i; i < nOutputs; i++){
        bias[i] = 0;
    };
};
void LinearLayer::forward(float* input){


}