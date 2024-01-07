#include <iostream>
#include "perceptron.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    perceptron p(2);
    p.print();

    std::vector<float> inputs({ 1.5, 2.3 });
    int output = p.guess(inputs);

    std::cout << "guess value : " << output << std::endl;

    return 0;
}