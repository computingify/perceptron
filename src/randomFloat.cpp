#include "randomFloat.h"

randomFloat::randomFloat(float low, float high) {
    std::random_device rd;
    gen = *new std::mt19937(rd());
    dist = std::uniform_real_distribution<float>(low, high);
}
float randomFloat::get() {
    return dist(gen);
}