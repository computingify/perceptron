#include "perceptron.h"
#include <iostream>
#include <random>

perceptron::perceptron(size_t entrySize) :
    mWeights(entrySize)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(-1.0, 1.0);

    // Initialize the vector with random values
    for (size_t i = 0; i < entrySize; ++i) {
        mWeights[i] = dist(gen);
    }
}

// Function to access and print elements of the vector
void perceptron::print() const {
    std::cout << "Weight vector contains: " << std::endl;
    std::cout << "-----------------" << std::endl;
    for (auto weight : mWeights) {
        std::cout << "| " << weight << "\t|" << std::endl;
    }
    std::cout << "-----------------" << std::endl;
}

int perceptron::guess(std::vector<float>& inputs) {
    float sum(0);

    if (inputs.size() < mWeights.size()) {
        std::cout << "Wrong data size" << std::endl;
        return 0;
    }

    for (unsigned int i = 0; i < mWeights.size(); i++) {
        sum += mWeights[i] * inputs[i];
    }

    return sign(sum);
}

// Activation method
int perceptron::sign(float n) {
    if (n >= 0) {
        return 1;
    }
    return -1;
}