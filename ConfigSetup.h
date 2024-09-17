#include "emp/config/ArgManager.hpp"

EMP_BUILD_CONFIG(MyConfigType,
    VALUE(SEED, int, 10, "What value should the random seed be?"), 
    VALUE(START_NUM, int, 5, "How many organisms should we start with?"),
    VALUE(MUTATION_RATE_NUM, double, 0.02, "What is the percent probability that each bit in the binary representation of the offprings' genome is going to be flipped?")
)