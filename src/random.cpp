#include <random>

int gen_rnd(int gen_min = 0,int gen_max = 36)
{
    std::random_device rnd;
    std::mt19937 mt_rnd(rnd());
    std::uniform_int_distribution<int> distribution(gen_min, gen_max);
    return distribution(mt_rnd);
}