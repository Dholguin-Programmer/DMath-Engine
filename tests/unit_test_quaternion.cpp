#include "Quaternion.h"
#include "Vector3f.h"
#include <gtest/gtest.h>
#include "GTest_Helper.h"

TEST(Quaternion, Comparison)
{
    DME::Vector3f testVectorOne(1,2,3);
    DME::Vector3f testVectorTwo(4,5,6);

    const DME::Quaternion testQuaternionOne(1, testVectorOne);
    const DME::Quaternion testQuaternionTwo(2, testVectorTwo);
    const DME::Quaternion copyQuaternionOne(testQuaternionOne);

    // Test Vector3f Equality functionality of Vector3f class
    ASSERT_TRUE(testQuaternionOne == copyQuaternionOne);
    GTEST_PASSED << "Equality" << std::endl;

    // Test Vector3f Inequality functionality of Vector3f class
    ASSERT_TRUE(testQuaternionOne != testQuaternionTwo);
    GTEST_PASSED << "Inequality" << std::endl;
}

int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}