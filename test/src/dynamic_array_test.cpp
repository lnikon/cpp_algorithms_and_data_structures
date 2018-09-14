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

        dynamic_array<int> darr_int{};

        std::size_t darr_string_cap{8};
        dynamic_array<std::string> darr_string{darr_string_cap};
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

TEST_F(dynamic_array_test, test_ctor_with_cap)
{
    EXPECT_EQ(darr_string.capacity(), darr_string_cap);
}

TEST_F(dynamic_array_test, test_size_3)
{
    EXPECT_EQ(darr_string.size(), 0);
}

TEST_F(dynamic_array_test, test_push_back_6)
{
    darr_string.push_back("Hello");
    darr_string.push_back(" world!");

    EXPECT_EQ(darr_string.size(), 2);
}

TEST_F(dynamic_array_test, test_push_back_7)
{
    darr_string.push_back("Hello");
    darr_string.push_back(" world!");

    EXPECT_EQ(darr_string.size(), 2);
}

TEST_F(dynamic_array_test, test_pop_front_1)
{
    darr_string.push_back("Hello");
    darr_string.push_back(" world!");

    EXPECT_EQ(darr_string.pop_front(), "Hello");
}

TEST_F(dynamic_array_test, test_pop_front_2)
{
    darr_string.push_back("Hello");
    darr_string.push_back(" world!");

    darr_string.pop_front();

    EXPECT_EQ(darr_string.size(), 1);
}

TEST_F(dynamic_array_test, test_pop_front_3)
{
    darr_string.push_back("Hello");
    darr_string.push_back(" world!");

    darr_string.pop_front();

    EXPECT_EQ(darr_string.size(), 1);
}

TEST_F(dynamic_array_test, test_push_front_1)
{
    darr_int.push_front(3);
    
    EXPECT_EQ(darr_int.pop_front(), 3);
}

TEST_F(dynamic_array_test, test_push_front_2)
{
    darr_int.push_front(3);
    
    EXPECT_EQ(darr_int.pop_back(), 3);
}

TEST_F(dynamic_array_test, test_push_front_3)
{
    darr_int.push_front(3);
    darr_int.push_front(3);

    darr_int.pop_back();
    
    EXPECT_EQ(darr_int.size(), 1);
}

TEST_F(dynamic_array_test, test_pop_front_4)
{
    darr_int.push_back(3);
    darr_int.push_back(3);

    darr_int.pop_front();
    
    EXPECT_EQ(darr_int.size(), 1);
}

TEST_F(dynamic_array_test, test_pop_front_5)
{
    darr_int.push_back(3);
    darr_int.push_back(9);
    darr_int.push_back(-1);

    
    EXPECT_EQ(darr_int.pop_front(), 3);
}

TEST_F(dynamic_array_test, test_pop_front_6)
{
    darr_int.push_back(3);
    darr_int.push_back(9);
    darr_int.push_back(-1);

    darr_int.pop_front();
    EXPECT_EQ(darr_int.pop_front(), 9);
}

TEST_F(dynamic_array_test, test_pop_front_7)
{
    darr_int.push_back(3);
    darr_int.push_back(9);
    darr_int.push_back(-1);

    darr_int.pop_front();
    darr_int.pop_front();
    EXPECT_EQ(darr_int.size(), 1);
}

TEST_F(dynamic_array_test, test_resize_1)
{
    darr_int.push_back(5);
    darr_int.push_back(0);
    darr_int.push_back(-8);
    darr_int.push_back(51);
    darr_int.push_back(4);

    EXPECT_EQ(darr_int.size(), 5);
}

TEST_F(dynamic_array_test, test_resize_2)
{
    darr_int.push_back(5);
    darr_int.push_back(0);
    darr_int.push_back(-8);
    darr_int.push_back(51);
    darr_int.push_back(4);

    EXPECT_EQ(darr_int.capacity(), 8);
}
