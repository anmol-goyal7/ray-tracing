#pragma once

#include <random>

// Uniform random double in [0, 1). Fixed seed, so renders are reproducible.
inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

// Uniform random double in [min, max).
inline double random_double(double min, double max) {
    return min + (max - min) * random_double();
}
