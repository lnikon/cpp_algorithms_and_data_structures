#include <string>

#include "gtest/gtest.h"
#include "dynamic_array.hpp"

class dynamic_array_test : public ::testing::Test
{
    protected:
        void SetUp() override
        { }

        void TearDown() override
        { }

        dynamic_array<int> darr_int;
        dynamic_array<std::string> darr_string;
};

TEST_F(dynamic_array_test, test_default_capacity)
{
    EXPECT_EQ(darr_int.default_capacity(), 4);
}

TEST_F(dynamic_array_test, test_default_ctor)
{
    EXPECT_EQ(darr_int.capacity(), darr_int.default_capacity());
}

TEST_F(dynamic_array_test, test_empty_push_back)
{
    darr_int.push_back(5);
    EXPECT_EQ(darr_int.pop_back(), 5);
}
