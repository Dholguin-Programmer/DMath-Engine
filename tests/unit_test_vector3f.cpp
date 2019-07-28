#include "Vector3f.h"
#include "Vector3f_Statics.h"
#include <gtest/gtest.h>
#include "GTest_Helper.h"

TEST(Vector3f, Comparison)
{
    const DME::Vector3f testVectorOne(4,5,6);
    const DME::Vector3f testVectorTwo(6,5,4);
    const DME::Vector3f copyVectorOne(testVectorOne);

    // Test Vector3f Equality functionality of Vector3f class
    ASSERT_TRUE(testVectorOne == copyVectorOne);
    GTEST_PASSED << "Equality" << std::endl;

    // Test Vector3f Inequality functionality of Vector3f class
    ASSERT_TRUE(testVectorOne != testVectorTwo);
    GTEST_PASSED << "Inequality" << std::endl;
}

TEST(Vector3f, Addition)
{
    /* Vector Addition (Vector Sum) simply states for a vector of dimension N
       that to calculate the Vector Sum between two or more vector, you simply 
       follow the logic defined below:

        Vector A    Vector B     Vector C (Sum Vector of Vectors A & B) 
       ---------    ---------    ---------------
       |  A_X  |    |  B_X  |    |  A_X + B_X  |
       |  A_Y  | +  |  B_Y  |    |  A_Y + B_Y  |
       |  A_Z  |    |  B_Z  |    |  A_Z + B_Z  |
       ---------    ---------    ---------------

       We'll just be testing this functionality for a 3-D Vector only.
    */

    const DME::Vector3f testVectorOne(4,5,6);
    const DME::Vector3f testVectorTwo(6,5,4);
    DME::Vector3f expectedVectorThusFar(10, 10, 10);

    // Test Vector3f Addition functionality of Vector3f class
    ASSERT_TRUE((testVectorOne + testVectorTwo) == expectedVectorThusFar);
    GTEST_PASSED << "Addition" << std::endl;

    // Test Vector3f Addition & Assignment functionality of Vector3f class
    const DME::Vector3f testVectorThree(1,3,5);
    expectedVectorThusFar += testVectorThree;
    ASSERT_TRUE((testVectorOne + testVectorTwo + testVectorThree) == expectedVectorThusFar);
    GTEST_PASSED << "Addition & Assignment" << std::endl;
}

TEST(Vector3f, Subtraction)
{
    /* Vector Subtraction (Vector Difference) simply states for a vector of dimension N
       that to calculate the Vector Sum between two or more vector, you simply 
       follow the logic defined below:

        Vector A    Vector B     Vector C (Sum Vector of Vectors A & B) 
       ---------    ---------    ---------------
       |  A_X  |    |  B_X  |    |  A_X - B_X  |
       |  A_Y  |    |  B_Y  |  = |  A_Y - B_Y  |
       |  A_Z  |    |  B_Z  |    |  A_Z - B_Z  |
       ---------    ---------    ---------------

       We'll just be testing this functionality for a 3-D Vector only.
    */

    const DME::Vector3f testVectorOne(5,10,15);
    const DME::Vector3f testVectorTwo(1,6,11);
    DME::Vector3f expectedVectorThusFar((testVectorOne - testVectorTwo));

    // Test Vector3f Subtraction functionality of Vector3f class
    ASSERT_TRUE((testVectorOne - testVectorTwo) == expectedVectorThusFar);
    GTEST_PASSED << "Subtraction" << std::endl;

    // Test Vector3f Subtraction & Assignment functionality of Vector3f class
    DME::Vector3f testVectorThree(3,2,1);
    expectedVectorThusFar -= testVectorThree;
    ASSERT_TRUE((testVectorOne - testVectorTwo - testVectorThree) == expectedVectorThusFar);
    GTEST_PASSED << "Subtraction & Assignment" << std::endl;
}

TEST(Vector3f, Scalar_Multiplcation)
{
    /* Scalar Multiplication simply states for a vector of dimension N
       that to calculate it's vector multiplid by some scalar X, you simply 
       follow the logic defined below:

        Vector A    Scalar X     Vector C (Vector A multiplied by Scalar X) 
       ---------    ---------    --------------
       |  A_X  |                 |   A_X * X  |
       |  A_Y  | *      X        |   A_Y * X  |
       |  A_Z  |                 |   A_Z * X  |
       ---------                 --------------

       We'll just be testing this functionality for a 3-D Vector only.
    */

    const DME::Vector3f testVectorOne(5,10,20);
    const float scalar = 5;
    DME::Vector3f expectedVectorThusFar((testVectorOne * scalar));

    // Test Vector3f Scalar Multiplication functionality of Vector3f class
    ASSERT_TRUE((testVectorOne * scalar) == expectedVectorThusFar);
    GTEST_PASSED << "Scalar Multiplication" << std::endl;

    // Test Vector3f Scalar Multiplication & Assignment functionality of Vector3f class
    expectedVectorThusFar *= scalar;
    ASSERT_TRUE((testVectorOne * scalar * scalar) == expectedVectorThusFar);
    GTEST_PASSED << "Scalar Multiplication & Assignment" << std::endl;
}

TEST(Vector3f, Scalar_Division)
{
    /* Scalar Division simply states for a vector of dimension N
       that to calculate it's vector divided by some scalar X, you simply 
       follow the logic defined below:

        Vector A    Scalar X     Vector C (Vector A multiplied by Scalar X) 
       ---------    ---------    --------------
       |  A_X  |                 |   A_X / X  |
       |  A_Y  | /      X        |   A_Y / X  |
       |  A_Z  |                 |   A_Z / X  |
       ---------                 --------------

       We'll just be testing this functionality for a 3-D Vector only.
    */

    const DME::Vector3f testVectorOne(125,250,500);
    const float divisor = 5;
    DME::Vector3f expectedVectorThusFar(25, 50, 100);

    // Test Vector3f Scalar Division functionality of Vector3f class
    ASSERT_TRUE((testVectorOne / divisor) == expectedVectorThusFar);
    GTEST_PASSED << "Scalar Division" << std::endl;

    // Test Vector3f Scalar Division & Assignment functionality of Vector3f class
    expectedVectorThusFar /= divisor;
    ASSERT_TRUE((testVectorOne / (divisor * divisor)) == expectedVectorThusFar);
    GTEST_PASSED << "Scalar Division & Assignment" << std::endl;
}

TEST(Vector3f, Dot_Product)
{
    /* The Dot Product simply states for two vectors of the same dimenstion (say 3-dimensions)
       (Vector A and Vector B), that to calculate the Dot Product returned as a value (Value X),
       you must follow the logic defined below:

        Vector A       Scalar B     Value X (Vector A dot producted with Vector B) 
       ---------       ---------    ----------------------------------------------
       |  A_X  |       |  B_X  |                      
       |  A_Y  |  dot  |  B_Y  |  =    (A_X + B_X) + (A_Y + B_Y) + (A_Z + B_Z)                      
       |  A_Z  |       |  B_Z  |                                         
       ---------       ---------

       We'll just be testing this functionality for a 3-D Vector only.
       Note that a dot product that returns any of these values defined below, tells us 
       meainingful information with respect to the direction of both vectors 
       (Vector A and Vector B) :
            value = -1 --> Vector A and Vector B are heading in opposite directions.
            value =  0 --> Both Vector A and Vector B are perpendicular of eachother.
            value =  1 --> Both Vector A and Vector B are heading in the same direction.
    */

    const DME::Vector3f perpenicularVectorOne(5,0,15);
    const DME::Vector3f perpenicularVectorTwo(0,10,0);
    const float expectedDotProduct = 0; // Assume we both vectors are perpendicular

    // Test Vector3f static Dot function
    ASSERT_TRUE(DME::Vector3f_Statics::Dot(perpenicularVectorOne, perpenicularVectorTwo) == expectedDotProduct);
    GTEST_PASSED << "Dot Product" << std::endl;
}

TEST(Vector3f, Cross_Product)
{
    /* The Cross Product simply states for two vectors of the same dimenstion (say 3-dimensions)
       (Vector A and Vector B), that to calculate the Cross Product which returns a new 
       vector (Vector C), you must follow the logic defined below:

        Vector A          Scalar B     Value X (Vector A dot producted with Vector B) 
       ---------         ---------     -----------------------------
       |  A_X  |         |  B_X  |     | (A_Y * B_Z) - (A_Z * B_Y) |               
       |  A_Y  |  cross  |  B_Y  |  =  | (A_Z * B_X) - (A_X * B_Z) |               
       |  A_Z  |         |  B_Z  |     | (A_X * B_Y) - (A_Y * B_X) |                
       ---------         ---------     -----------------------------                  

       We'll just be testing this functionality for a 3-D Vector only.
    */

    const DME::Vector3f perpenicularVectorOne(2,5,4);
    const DME::Vector3f perpenicularVectorTwo(2,5,3);
    const DME::Vector3f expectedDotProduct(-5, 2, 0);

    // Test Vector3f static Cross function
    ASSERT_TRUE(DME::Vector3f_Statics::Cross(perpenicularVectorOne, perpenicularVectorTwo) == expectedDotProduct);
    GTEST_PASSED << "Cross Product" << std::endl;
}

int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}