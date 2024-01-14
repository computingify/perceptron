#include "perceptron.h"
#include <iostream>
#include "randomFloat.h"

perceptron::perceptron(size_t entrySize, float errorPonderation) :
    mWeights(entrySize),
    mErrorPonderation(errorPonderation)
{
    randomFloat r(-1.0, 1.0);

    // Initialize the vector with random values
    for (size_t i = 0; i < entrySize; ++i) {
        mWeights[i] = r.get();
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
        std::cout << __func__ << " Wrong data size" << std::endl;
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

void perceptron::tune(const std::vector<float>& inputs, const int error) {
    if (inputs.size() < mWeights.size()) {
        std::cout << __func__ << " Wrong data size" << std::endl;
        return;
    }

    // Compute the error to tune each input weight
    for (unsigned int i = 0; i < mWeights.size(); i++) {
        // Apply error formula
        mWeights[i] += inputs[i] * error * mErrorPonderation;
    }
}