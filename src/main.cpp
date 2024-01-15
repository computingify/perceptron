#include <iostream>
#include "perceptron.h"
#include "matplotlibcpp.h"
#include "randomFloat.h"
#include "trainer.h"

namespace plt = matplotlibcpp;

int errorProcessing(int answer, int expectation) {
    return expectation - answer;
}

int argumentGetInt(const std::string& argv) {
    // Convert the argument to an integer
    int intValue(0);
    try {
        intValue = std::stoi(argv);
        std::cout << "Converted integer value: " << intValue << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }

    return intValue;
}

int main(int argc, char* argv[]) {
    unsigned int numberOfEntry(2);  // perceptron input number
    double width(200);              // the width of the plot => the maximum input value for X, Y
    float errorCoef(0.1);           // the learning rate
    // std::vector<float> inputs;

    int numberOfElement(argumentGetInt(argv[1]));       // dot number in my experience
    std::cout << "NumberOfElement " << ": " << numberOfElement << std::endl;

    perceptron p(numberOfEntry, errorCoef);

    // Draw a line to separate positive and negative value
    plt::plot({ 0, width }, { 0, width }, "b-");

    // My perceptron in trainning
    for (int i = 0; i < numberOfElement; i++) {
        p.print();

        trainer t(-width, width);
        // build a vector with X and Y as input for my perceptron
        std::vector<float> coordinate(t.getX(), t.getY());
        // run my perceptron
        int answer = p.guess(coordinate);
        // Calculate the error according to perceptron result
        int error = errorProcessing(answer, t.getLabel());
        std::cout << __func__ << " X = " << t.getX() << " | Y = " << t.getY() << std::endl;
        std::cout << __func__ << " answer = " << answer << " | label = " << t.getLabel() << " | error value : " << error << std::endl;

        // Finally train the perceptron
        p.tune(coordinate, error);

        std::string dotColor("og");
        if (0 != error) {
            dotColor = "or";
        }
        plt::plot({ t.getX() }, { t.getY() }, dotColor);
    }
    plt::save("../result.pdf"); // save the figure
    plt::show();

    return 0;
}
