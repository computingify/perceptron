#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>

class perceptron {
public:
    perceptron(size_t entrySize);

    void print() const;

    int guess(std::vector<float>& inputs);

protected:

    int sign(float n);

private:
    std::vector<float> mWeights;

};
#endif // PERCEPTRON_H