#include <iostream>
#include "perceptron.h"
#include "matplotlibcpp.h"
#include "randomFloat.h"
#include "trainer.h"

namespace plt = matplotlibcpp;

int errorProcessing(int answer, int expectation) {
    return answer - expectation;
}

int main() {
    unsigned int numberOfEntry(2);  // perceptron input number
    int numberOfElement(5);       // dot number in my experience
    double width(200);              // the width of the plot => the maximum input value for X, Y
    float errorCoef(0.1);           // the learning rate
    // std::vector<float> inputs;

    perceptron p(numberOfEntry, errorCoef);

    // Trainer computation
    std::vector<float> tainerResultsX;
    std::vector<float> tainerResultsY;
    std::vector<int> tainerAnswer;
    std::vector<std::string> tainerResultsDotColor;
    for (int i = 0; i < numberOfElement; i++) {
        trainer t(0, width);
        tainerResultsX.push_back(t.getX());
        tainerResultsY.push_back(t.getY());
        tainerAnswer.push_back(t.getLabel());
        tainerResultsDotColor.push_back(dotColor);
    }

    // Draw a line to separate positive and negative value
    plt::plot({ 0, width }, { 0, width }, "b-");

    // My perceptron in trainning
    for (int i = 0; i < numberOfElement; i++) {
        p.print();

        // build a vector with X and Y as input for my perceptron
        std::vector<float> coordinate(tainerResultsX[i], tainerResultsY[i]);
        // run my perceptron
        int answer = p.guess(coordinate);
        // Calculate the error according to perceptron result
        int error = errorProcessing(answer, tainerAnswer[i]);
        std::cout << __func__ << " error value : " << error << std::endl;

        // Finally train the perceptron
        p.tune(coordinate, error);

        std::string dotColor("og");
        if (0 < error) {
            dotColor = "or";
        }
        plt::plot({ tainerResultsX[i] }, { tainerResultsY[i] }, dotColor);
    }
    /*
        randomFloat r(-1.0, 1.0);
        // Initialize the vector with random values
        for (size_t i = 0; i < numberOfEntry; ++i) {
            inputs.push_back(r.get());
        }

        // TODO: for the moment the large input isn't correctly handle
        int output = p.guess(inputs);

        std::cout << "guess value : " << output << std::endl;

        // plt::plot({ 1,3,2,4 });
        std::string dotColor("or");
        if (output >= 0) {
            dotColor = "og";
        }
        plt::plot({ inputs.at(0) }, { inputs.at(1) }, dotColor);
        */
    plt::show();
    plt::save("../result.pdf"); // save the figure

    return 0;
}
