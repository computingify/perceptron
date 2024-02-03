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

void training(double width, int numberOfElement, perceptron& p) {
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
        // p.print();

        // build a vector with X and Y as input for my perceptron
        std::vector<float> coordinate{ coordinates[i].first, coordinates[i].second };
        // run my perceptron
        int answer = p.guess(coordinate);
        // Calculate the error according to perceptron result
        int error = errorProcessing(answer, label[i]);
        // std::cout << __func__ << " X = " << coordinates[i].first << " | Y = " << coordinates[i].second << std::endl;
        // std::cout << __func__ << " answer = " << answer << " | label = " << label[i] << " | error value : " << error << std::endl;

        // Finally train the perceptron
        p.tune(coordinate, error);

        std::string dotColor("og");
        if (answer > 0) {
            dotColor = "or";
        }
        plt::plot({ coordinates[i].first }, { coordinates[i].second }, dotColor);
    }
}

void run(double width, int numberOfElement, perceptron& p) {
    for (int i = 0; i < numberOfElement * 2; i++) {
        randomFloat r(-width, width);
        // build a vector with X and Y as input for my perceptron
        std::vector<float> coordinate{ r.get(), r.get() };
        // run my perceptron
        int answer = p.guess(coordinate);

        std::string dotColor("og");
        if (answer > 0) {
            dotColor = "or";
        }
        plt::plot({ coordinate[0] }, { coordinate[1] }, dotColor);
    }
}

int main(int argc, char* argv[]) {
    unsigned int numberOfEntry(2);  // perceptron input number
    double width(100);              // the width of the plot => the maximum input value for X, Y
    float errorCoef(0.01);           // the learning rate

    int numberOfElement(argumentGetInt(argv[1]));       // dot number in my experience

    perceptron p(numberOfEntry, errorCoef);

    // My perceptron in trainning
    // Draw a line to separate both value (all green should be over the line and red under)
    plt::title("Training Resutl");
    plt::plot({ -width, width }, { -width, width }, "b-");
    training(width, numberOfElement, p);

    plt::save("../training.png"); // save the figure
    plt::show();

    // My perceptron in ACTION
    plt::plot({ -width, width }, { -width, width }, "b-");
    run(width, numberOfElement, p);

    plt::title("Run on random data Resutl");
    plt::save("../result.png"); // save the figure
    plt::show();

    return 0;
}
