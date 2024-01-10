#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>
#include <cstddef>  // Include this header for size_t

class perceptron {
public:
    perceptron(std::size_t entrySize);

    void print() const;

    int guess(std::vector<float>& inputs);

protected:

    int sign(float n);

private:
    std::vector<float> mWeights;

};
#endif // PERCEPTRON_H