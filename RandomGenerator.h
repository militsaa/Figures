#include <random>

class RandomGenerator {
    std::mt19937 gen;
public:
    RandomGenerator();
    int getRandInt(int beg, int end);
    double getRandDouble(double beg, double end);
};