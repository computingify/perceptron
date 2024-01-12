#include "randomFloat.h"

randomFloat::randomFloat(float low, float high) {
    dist = std::uniform_real_distribution<float>(low, high);
}
float randomFloat::get() {
    std::mt19937 gen(rd());
    return dist(gen);
}