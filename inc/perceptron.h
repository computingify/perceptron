#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>
#include <cstddef>  // Include this header for size_t

class perceptron {
public:
    perceptron(std::size_t entrySize, float errorPonderation);

    virtual ~perceptron() = default;

    void print() const;

    int guess(std::vector<float>& inputs);

    void tune(const std::vector<float>& inputs, const int error);

protected:

    int sign(float n);

private:
    std::vector<float> mWeights;
    float mErrorPonderation;

};
#endif // PERCEPTRON_H