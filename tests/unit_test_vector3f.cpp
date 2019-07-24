#include "Vector3f.h"
#include <gtest/gtest.h>
// #define GTEST_COUT std::cerr << "[          ] [ INFO ]"

TEST(Vector3f, Comparison)
{
    DME::Vector3f testVectorOne(4,5,6);
    DME::Vector3f testVectorTwo(6,5,4);
    DME::Vector3f copyVectorOne(testVectorOne);

    // Test Equals functionality of Vector3f class
    ASSERT_TRUE(testVectorOne == copyVectorOne);

    // Test Not Equals functionality of Vector3f class
    ASSERT_TRUE(testVectorOne != testVectorTwo);
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

    DME::Vector3f testVectorOne(4,5,6);
    DME::Vector3f testVectorTwo(6,5,4);
    DME::Vector3f expectedVectorThusFar((testVectorOne + testVectorTwo));

    // Test Addition functionality of Vector3f class
    ASSERT_TRUE((testVectorOne + testVectorTwo) == expectedVectorThusFar);

    DME::Vector3f testVectorThree(1,3,5);
    expectedVectorThusFar += testVectorThree;

    // Now lets test that the Addition and Assigment functionality as well. 
    ASSERT_TRUE((testVectorOne + testVectorTwo + testVectorThree) == expectedVectorThusFar);
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

    DME::Vector3f testVectorOne(5,10,15);
    DME::Vector3f testVectorTwo(1,6,11);
    DME::Vector3f expectedVectorThusFar((testVectorOne - testVectorTwo));

    // Now lets test that the Subtraction and Assigment functionality works as well. 
    ASSERT_TRUE((testVectorOne - testVectorTwo) == expectedVectorThusFar);

    DME::Vector3f testVectorThree(3,2,1);
    expectedVectorThusFar -= testVectorThree;

    // Now lets test that the Subtraction and Assigment functionality works as well. 
    ASSERT_TRUE((testVectorOne - testVectorTwo - testVectorThree) == expectedVectorThusFar);
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

    DME::Vector3f testVectorOne(5,10,20);
    float scalar = 5;
    DME::Vector3f expectedVectorThusFar((testVectorOne * scalar));

    // Now lets test that the Scalar Multiplication functionality works.
    ASSERT_TRUE((testVectorOne * scalar) == expectedVectorThusFar);

    expectedVectorThusFar *= scalar;

    // Now lets test that the Scalar Multilication and Assigment functionality works as well. 
    ASSERT_TRUE((testVectorOne * scalar * scalar) == expectedVectorThusFar);
}

TEST(Vector3f, Scalar_Division)
{
    /* Scalar Division simply states for a vector of dimension N
       that to calculate it's vector divided by some scalar X, you simply 
       follow the logic defined below:

        Vector A    Scalar X     Vector C (Vector A multiplied by Scalar X) 
       ---------    ---------    --------------
       |  A_X  |                 |   A_X / X  |
       |  A_Y  | /      x        |   A_Y / X  |
       |  A_Z  |                 |   A_Z / X  |
       ---------                 --------------

       We'll just be testing this functionality for a 3-D Vector only.
    */

    DME::Vector3f testVectorOne(125,250,500);
    float divisor = 5;
    DME::Vector3f expectedVectorThusFar((testVectorOne / divisor));

    // Now lets test that the Scalar Multiplication functionality works.
    ASSERT_TRUE((testVectorOne / divisor) == expectedVectorThusFar);

    expectedVectorThusFar /= divisor;

    // Now lets test that the Scalar Multilication and Assigment functionality works as well. 
    ASSERT_TRUE((testVectorOne / (divisor * divisor)) == expectedVectorThusFar);
}

TEST(Vector3f, Dot_Product)
{
    /* The Dot Product simply states for two vectors of the same dimenstion (say 3-dimensions)
       (Vector A and Vector B), that to calculate the Dot Product returned as a value (Value X),
       you must follow the logic defined below:

        Vector A       Scalar B     Value X (Vector A dot producted with Vector B) 
       ---------       ---------    ----------------------------------------------
       |  A_X  |       |  B_X  |                      
       |  A_Y  |       |  B_Y  |  =    (A_X + B_X) + (A_Y + B_Y) + (A_Z + B_Z)                      
       |  A_Z  |       |  B_Z  |                                         
       ---------       ---------

       We'll just be testing this functionality for a 3-D Vector only.
       Note that a dot product any of these values defined below, tells us 
       meainingful information with respect to the direction of both vectors 
       (Vector A and Vector B) :
            value = -1 --> Vector A and Vector B are heading in opposite directions.
            value =  0 --> Both Vector A and Vector B are perpendicular of eachother.
            value =  1 --> Both Vector A and Vector B are heading in the same direction.
    */

    DME::Vector3f perpenicularVectorOne(5,0,15);
    DME::Vector3f perpenicularVectorTwo(0,10,0);
    float expectedDotProduct = 0; // Assume we both vectors are perpendicular

    // Now lets test that the Scalar Multiplication functionality works.
    ASSERT_TRUE(DME::Vector3f::Dot(perpenicularVectorOne, perpenicularVectorTwo) == expectedDotProduct);
}

TEST(Vector3f, Cross_Product)
{
    /* The Cross Product simply states for two vectors of the same dimenstion (say 3-dimensions)
       (Vector A and Vector B), that to calculate the Cross Product which returns a new 
       vector (Vector C), you must follow the logic defined below:

        Vector A          Scalar B     Value X (Vector A dot producted with Vector B) 
       ---------         ---------     -----------------------------
       |  A_X  |         |  B_X  |     | (A_Y * B_Z) - (A_Z * B_Y) |               
       |  A_Y  |         |  B_Y  |  =  | (A_Z * B_X) - (A_X * B_Z) |               
       |  A_Z  |         |  B_Z  |     | (A_X * B_Y) - (A_Y * B_X) |                
       ---------         ---------     -----------------------------                  

       We'll just be testing this functionality for a 3-D Vector only.
    */

    DME::Vector3f perpenicularVectorOne(2,5,4);
    DME::Vector3f perpenicularVectorTwo(2,5,3);
    DME::Vector3f expectedDotProduct(-5, 2, 0);

    // Now lets test that the Scalar Multiplication functionality works.
    ASSERT_TRUE(DME::Vector3f::Cross(perpenicularVectorOne, perpenicularVectorTwo) == expectedDotProduct);
}

int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}