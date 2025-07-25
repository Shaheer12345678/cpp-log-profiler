#include "tokenize.hpp"
#include <gtest/gtest.h>
using namespace logprof;
TEST(Tokenize, Basic) {
    auto v = split_sv("a,b,c", ',');
