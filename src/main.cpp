#include <iostream>
#include "perceptron.h"
#include "matplotlibcpp.h"
#include "randomFloat.h"
#include "trainer.h"

namespace plt = matplotlibcpp;

int main() {
    std::cout << "Hello, World!" << std::endl;
    unsigned int numberOfDot(500);
    std::vector<float> inputs;

    perceptron p(2);
    p.print();

    randomFloat r(-1.0, 1.0);
    // Initialize the vector with random values
    for (size_t i = 0; i < numberOfDot; ++i) {
        inputs.push_back(r.get());
    }

    // TODO: for the moment the large input isn't correctly handle
    int output = p.guess(inputs);

    std::cout << "guess value : " << output << std::endl;

    // Test build trainer
    trainer t(0, 400);

    // plt::plot({ 1,3,2,4 });
    std::string dotColor("or");
    if (output >= 0) {
        dotColor = "og";
    }
    plt::plot({ inputs.at(0) }, { inputs.at(1) }, dotColor);
    // plt::show();
    plt::save("standard.pdf"); // save the figure

    return 0;
}