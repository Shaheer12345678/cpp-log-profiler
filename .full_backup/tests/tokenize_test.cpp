#include "tokenize.hpp"
#include <gtest/gtest.h>
using namespace logprof;
TEST(Tokenize, Basic) {
    auto v = split_sv("a,b,c", ',');
    ASSERT_EQ(v.size(), 3);
    EXPECT_EQ(v[1], "b");
}


