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
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        exit(1);
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
        exit(1);
    }

    return intValue;
}

int main(int argc, char* argv[]) {
    unsigned int numberOfEntry(2);  // perceptron input number
    double width(100);              // the width of the plot => the maximum input value for X, Y
    float errorCoef(0.01);           // the learning rate
    // std::vector<float> inputs;

    int numberOfElement(argumentGetInt(argv[1]));       // dot number in my experience

    perceptron p(numberOfEntry, errorCoef);

    // Draw a line to separate positive and negative value
    plt::plot({ -width, width }, { -width, width }, "b-");

    // Prepare raw input value
    std::vector<std::pair<float, float>> coordinates;
    std::vector<int> label;
    for (int i = 0; i < numberOfElement; i++) {
        trainer t(-width, width);
        coordinates.push_back(std::make_pair(t.getX(), t.getY()));
        label.push_back(t.getLabel());
    }

    // My perceptron in trainning
    for (int i = 0; i < numberOfElement; i++) {
        p.print();

        // build a vector with X and Y as input for my perceptron
        std::vector<float> coordinate{ coordinates[i].first, coordinates[i].second };
        // run my perceptron
        int answer = p.guess(coordinate);
        // Calculate the error according to perceptron result
        int error = errorProcessing(answer, label[i]);
        std::cout << __func__ << " X = " << coordinates[i].first << " | Y = " << coordinates[i].second << std::endl;
        std::cout << __func__ << " answer = " << answer << " | label = " << label[i] << " | error value : " << error << std::endl;

        // Finally train the perceptron
        p.tune(coordinate, error);

        std::string dotColor("og");
        if (answer > 0) {
            dotColor = "or";
        }
        plt::plot({ coordinates[i].first }, { coordinates[i].second }, dotColor);
    }
    plt::save("../result.pdf"); // save the figure
    plt::show();

    return 0;
}
