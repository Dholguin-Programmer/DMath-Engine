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

TEST(Quaternion, Addition)
{
    /* Quaternion Addition (Quaternion Sum) simply states for a quaternion,
       that to calculate the Quaternion Sum between two or more quaternions with ,
       you simply follow the logic defined below:

        Let S_X = Scalar X, where X is some number denoting the specific scalar
        Let V_X = Vector X, where X is some number denoting the specific vector

          Quaternion A          Quaternion B     Quaternion C (Quaternion Sum of Quaternion A & B)
       -------------------   -------------------   -----------------------------------------
       |       S_A       |   |       S_B       |   |            S_C = S_A + S_B            | 
       |       V_A       | + |       V_B       | = |            V_C = V_A + V_B            | 
       -------------------   -------------------   -----------------------------------------
    */

    DME::Vector3f testVectorOne(1,2,3);
    DME::Vector3f testVectorTwo(2,4,6);
    DME::Vector3f testVectorThree(3,6,9);


    const DME::Quaternion testQuaternionOne(3, testVectorOne);
    const DME::Quaternion testQuaternionTwo(testQuaternionOne);                                
    DME::Quaternion expectedQuaternionThusFar(6, testVectorTwo);

    // Test Quaternion Addition functionality of Quaternion class
    ASSERT_TRUE((testQuaternionOne + testQuaternionTwo) == expectedQuaternionThusFar);
    GTEST_PASSED << "Addition" << std::endl;

    // Now lets test that Quaternion Addition and Assigment functionality works as well. 
    const DME::Quaternion testQuaternionThree(3, testVectorOne);

    expectedQuaternionThusFar += testQuaternionThree;
    ASSERT_TRUE((testQuaternionOne + testQuaternionTwo + testQuaternionTwo) == expectedQuaternionThusFar);
    GTEST_PASSED << "Addition & Assignment" << std::endl;   
}

int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}