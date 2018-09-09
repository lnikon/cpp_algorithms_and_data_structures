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

TEST_F(dynamic_array_test, test_empty_push_back_1)
{
    darr_int.push_back(5);

    EXPECT_EQ(darr_int.pop_back(), 5);
}

TEST_F(dynamic_array_test, test_empty_push_back_2)
{
    darr_int.push_back(5);
    darr_int.push_back(-99);

    EXPECT_EQ(darr_int.pop_back(), -99);
}

TEST_F(dynamic_array_test, test_empty_push_back_3)
{
    darr_int.push_back(5);
    darr_int.push_back(-99);

    EXPECT_EQ(darr_int.size(), 2);
}

TEST_F(dynamic_array_test, test_is_empty)
{
    EXPECT_EQ(darr_int.empty(), true);
}

TEST_F(dynamic_array_test, test_size_1)
{
    darr_int.push_back(5);
    darr_int.push_back(0);
    darr_int.push_back(-3);

    EXPECT_EQ(darr_int.size(), 3);
}

TEST_F(dynamic_array_test, test_size_2)
{
    darr_int.push_back(5);
    darr_int.push_back(0);
    darr_int.push_back(-3);

    darr_int.pop_back();

    EXPECT_EQ(darr_int.size(), 2);
}

TEST_F(dynamic_array_test, test_pop_back_1)
{
    darr_int.push_back(4);
    darr_int.push_back(-2);

    EXPECT_EQ(darr_int.pop_back(), -2);

}

TEST_F(dynamic_array_test, test_pop_back_2)
{
    darr_int.push_back(4);
    darr_int.push_back(-2);

    darr_int.pop_back();

    EXPECT_EQ(darr_int.pop_back(), 4);

}

TEST_F(dynamic_array_test, test_pop_back_3)
{
    darr_int.push_back(4);
    darr_int.push_back(-2);

    darr_int.pop_back();
    darr_int.pop_back();

    EXPECT_EQ(darr_int.size(), 0);
}

TEST_F(dynamic_array_test, test_pop_back_4)
{
    darr_int.push_back(4);
    darr_int.push_back(-2);

    darr_int.pop_back();

    EXPECT_EQ(darr_int.size(), 1);
}

TEST_F(dynamic_array_test, test_pop_back_5)
{
    darr_int.push_back(4);
    darr_int.push_back(-2);

    darr_int.pop_back();

    EXPECT_NE(darr_int.size(), 0);
}
