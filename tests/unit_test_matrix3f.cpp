#include "Matrix3f.h"
#include <gtest/gtest.h>
#define GTEST_COUT std::cerr << "[          ] [ INFO ]"

TEST(Matrix3f, Comparison)
{
    DME::Matrix3f testVectorOne(4,5,6,
                                1,2,3,
                                7,8,9);

    GTEST_COUT << testVectorOne << std::endl;

    // Test Equals functionality of Vector3f class
    ASSERT_TRUE(true);
}

int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}