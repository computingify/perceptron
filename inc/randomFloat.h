#ifndef RANDOM_FLOAT_H
#define RANDOM_FLOAT_H

#include <random>

class randomFloat {
public:
    randomFloat(float low, float high);
    virtual ~randomFloat() = default;

    float get();

private:
    std::random_device rd;
    std::uniform_real_distribution<float> dist;
};
#endif // RANDOM_FLOAT_H