#include <iostream>
#include "perceptron.h"
#include "matplotlibcpp.h"
#include "randomFloat.h"
#include "trainer.h"

namespace plt = matplotlibcpp;

int main() {
    unsigned int numberOfDot(100);
    double width(200);
    double height(200);
    std::vector<float> inputs;

    perceptron p(2);
    p.print();

    // Trainer
    std::vector < std::tuple<float, float, std::string>> trainerResults;  // Will contains all the valide result that should be output by my perceptron
    std::vector< float> tainerResultsX;
    std::vector< float> tainerResultsY;
    std::vector< std::string> tainerResultsDotColor;
    int numberOfElement(100);
    for (int i = 0; i < numberOfElement; i++) {
        trainer t(0, width);
        std::string dotColor("or");
        if (t.getLabel() >= 0) {
            dotColor = "og";
        }
        trainerResults.emplace_back(t.getX(), t.getY(), dotColor);
        tainerResultsX.push_back(t.getX());
        tainerResultsY.push_back(t.getY());
        tainerResultsDotColor.push_back(dotColor);
        plt::plot({ t.getX() }, { t.getY() }, dotColor);
    }

    // Draw a line to separate positive and negative value
    plt::plot({ 0, width }, { 0, height }, "b-");

    // plt::plot(tainerResultsX, tainerResultsY, "og");
    /*
        randomFloat r(-1.0, 1.0);
        // Initialize the vector with random values
        for (size_t i = 0; i < numberOfDot; ++i) {
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
        */ plt::show();
        plt::save("../result.pdf"); // save the figure

        return 0;
}