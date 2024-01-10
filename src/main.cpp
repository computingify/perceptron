#include <iostream>
#include "perceptron.h"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main() {
    std::cout << "Hello, World!" << std::endl;

    perceptron p(2);
    p.print();

    std::vector<float> inputs({ 1.5, 2.3 });
    int output = p.guess(inputs);

    std::cout << "guess value : " << output << std::endl;

    plt::plot({ 1,3,2,4 });
    plt::show();

    return 0;
}