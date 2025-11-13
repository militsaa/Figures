#include "RandomGenerator.h"

RandomGenerator::RandomGenerator()
{
    std::random_device rd;
    gen.seed(rd());
}

int RandomGenerator::getRandInt(int beg, int end)
{
    std::uniform_int_distribution<int>dist(beg, end);
    return dist(gen);
}

double RandomGenerator::getRandDouble(double beg, double end)
{
    std::uniform_real_distribution<int>dist(beg, end);
    return dist(gen);
}
