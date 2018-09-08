#include <string>

#include "gtest/gtest.h"
#include "dynamic_array.hpp"

class dynamic_array_test : public ::testing::Test
{
    protected:
        void SetUp() override
        {
            darr_int.push_back(12);
            darr_int.push_back(-32);
            darr_int.push_back(0);

            darr_string.push_back("Hello");
            darr_string.push_back(std::string(std::string(" world!")));
        }

        void TearDown() override
        {
            // Nothing to do here yet
        }

        dynamic_array<int> darr_int{4};
        dynamic_array<std::string> darr_string{4};

};

TEST_F(dynamic_array_test, is_last_eq_zero)
{
    EXPECT_EQ(darr_int.pop_back(), 0);
}
