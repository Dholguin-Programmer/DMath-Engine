#include "Matrix3f.h"
#include <gtest/gtest.h>
#include "GTest_Helper.h"

TEST(Matrix3f, Comparison)
{
    const DME::Matrix3f testVectorOne(4,5,6,
                                1,2,3,
                                7,8,9);

    const DME::Matrix3f testVectorTwo(1,2,3,
                                4,5,6,
                                7,8,9);

    // Test Matrix Equality functional of Matrix3f class
    ASSERT_FALSE(testVectorOne == testVectorTwo);
    GTEST_PASSED << "Equality" << std::endl;

    // Test Matrix Inequality functional of Matrix3f class
    ASSERT_TRUE(testVectorOne != testVectorTwo);
    GTEST_PASSED << "Inequality" << std::endl;
}

TEST(Matrix3f, Addition)
{
    /* Matrix Addition (Matrix Sum) simply states for a matrix of dimensions (NxN)
       that to calculate the Matrix Sum between two or more matrix with 
       (NxN) dimensions, you simply follow the logic defined below:

             Matrix A              Matrix B          Matrix C (Sum Matrix of Matrix A & B)
       -------------------   -------------------   -----------------------------------------
       |  A_A, A_B, A_C  |   |  B_A, B_B, B_C  |   | (A_A + B_A), (A_B + B_B), (A_C + B_C) | 
       |  A_D, A_E, A_F  | + |  B_D, B_E, B_F  | = | (A_D + B_D), (A_E + B_E), (A_F + B_F) | 
       |  A_G, A_H, A_I  |   |  B_G, B_H, B_I  |   | (A_G + B_G), (A_H + B_H), (A_I + B_I) | 
       -------------------   -------------------   -----------------------------------------

       We'll just be testing this functionality for a 3x3 Matrix only.
    */

    const DME::Matrix3f testMatrixOne(1,2,3,
                                      4,5,6,
                                      7,8,9);
    const DME::Matrix3f testMatrixTwo(8,7,6,
                                      5,4,3,
                                      2,1,0);
                                      
    DME::Matrix3f expectedMatrixThusFar(9,9,9,
                                        9,9,9,
                                        9,9,9);

    // Test Matrix Addition functionality of Matrix3f class
    ASSERT_TRUE((testMatrixOne + testMatrixTwo) == expectedMatrixThusFar);
    GTEST_PASSED << "Addition" << std::endl;

    // Now lets test that Matrix Addition and Assigment functionality works as well. 
    const DME::Matrix3f testMatrixThree(1,1,1,
                                        1,1,1,
                                        1,1,1);
    expectedMatrixThusFar += testMatrixThree;
    ASSERT_TRUE((testMatrixOne + testMatrixTwo + testMatrixThree) == expectedMatrixThusFar);
    GTEST_PASSED << "Addition & Assignment" << std::endl;                 
}

TEST(Matrix3f, Subtraction)
{
    /* Matrix Addition (Matrix Difference) simply states for a matrix of dimensions (NxN)
       that to calculate the Matrix Difference between two or more matrix with 
       (NxN) dimensions, you simply follow the logic defined below:

             Matrix A              Matrix B       Matrix C (Difference Matrix of Matrix A & B)
       -------------------   -------------------   -----------------------------------------
       |  A_A, A_B, A_C  |   |  B_A, B_B, B_C  |   | (A_A - B_A), (A_B - B_B), (A_C - B_C) | 
       |  A_D, A_E, A_F  | - |  B_D, B_E, B_F  | = | (A_D - B_D), (A_E - B_E), (A_F - B_F) | 
       |  A_G, A_H, A_I  |   |  B_G, B_H, B_I  |   | (A_G - B_G), (A_H - B_H), (A_I - B_I) | 
       -------------------   -------------------   -----------------------------------------

       We'll just be testing this functionality for a 3x3 Matrix only.
    */

    const DME::Matrix3f testMatrixOne(9,9,9,
                                      9,9,9,
                                      9,9,9);
    const DME::Matrix3f testMatrixTwo(9,8,7,
                                      6,5,4,
                                      3,2,1);

    DME::Matrix3f expectedMatrixThusFar(0,1,2,
                                        3,4,5,
                                        6,7,8);

    // Test Matrix Subtraction functionality of Matrix3f class
    ASSERT_TRUE((testMatrixOne - testMatrixTwo) == expectedMatrixThusFar);
    GTEST_PASSED << "Subtraction" << std::endl;


    // Now lets test that the Subtraction and Assigment functionality as well. 
    const DME::Matrix3f testMatrixThree(0,1,1,
                                        1,1,1,
                                        1,1,1);
    expectedMatrixThusFar -= testMatrixThree;
    ASSERT_TRUE((testMatrixOne - testMatrixTwo - testMatrixThree) == expectedMatrixThusFar);
    GTEST_PASSED << "Subtraction & Assignment" << std::endl;    
}

TEST(Matrix3f, Scalar_Multiplication)
{
    /* Scalar Multiplication simply states for a matrix of dimensions (3x3)
       that to multiply this matrix by a scalar value of X,, you simply follow the logic defined below:

             Matrix A         Scalar X                   Matrix B
       -------------------   ----------   -------------------------------------
       |  A_A, A_B, A_C  |                |   (A_A * X), (A_B * X), (A_C * X) | 
       |  A_D, A_E, A_F  | *     X      = |   (A_D * X), (A_E * X), (A_F * X) | 
       |  A_G, A_H, A_I  |                |   (A_G * X), (A_H * X), (A_I * X) | 
       -------------------                -------------------------------------

       We'll just be testing this functionality for a 3x3 Matrix only.
    */

    const DME::Matrix3f testMatrixOne(9,9,9,
                                      9,9,9,
                                      9,9,9);
    const float scalar = 10;

    DME::Matrix3f expectedMatrixThusFar(90,90,90,
                                        90,90,90,
                                        90,90,90);

    // Test Scalar Multiplication functionality of Matrix3f class
    ASSERT_TRUE((testMatrixOne * scalar) == expectedMatrixThusFar);
    GTEST_PASSED << "Multiplication" << std::endl;

    // Now lets test that the Scalar Multiplication and Assigment functionality as well. 
    expectedMatrixThusFar *= scalar;
    ASSERT_TRUE((testMatrixOne * (scalar * scalar)) == expectedMatrixThusFar);
    GTEST_PASSED << "Multiplication & Assignment" << std::endl;

}

TEST(Matrix3f, Matrix_Multiplication)
{
    /* Matrix Multiplication between two or more matrixs simply states that this is only 
       allowed based upon specific properties of the two matrixes:
        - The number of rows in Matrix M must be equal to the number of columns in Matrix B
        - The number of columns in Matrix M must be equal to the number of rows in Matrix B
       Note: One of these properties, or both (inclusive) must be met to perform Matrix
             Multiplication

        Example 1: 
            ** Both Matrix A and Matrix B have the same exact number of rows and columns **
            
               3x3 Matrix A           3x3 Matrix B           3x3 Matrix C 
            -------------------   ---------------------   ------------------
            |  A_A, A_B, A_C,  |   |  B_A, B_B, B_C,  |   | C_A, C_B, C_C, | 
            |  A_D, A_E, A_F,  | * |  B_D, B_E, B_F,  | = | C_D, C_E, C_F, | 
            |  A_G, A_H, A_I   |   |  B_G, B_H, B_I   |   | C_G, C_H, C_I  | 
            -------------------   ---------------------    -----------------

            Let C_A = (A_A * B_A) + (A_B * B_D) + (A_C * B_G)
            Let C_B = (A_A * B_B) + (A_B * B_E) + (A_C * B_F)
            Let C_C = (A_A * B_C) + (A_B * B_F) + (A_C * B_I)

            Let C_D = (A_D * B_A) + (A_E * B_D) + (A_F * B_G)
            Let C_E = (A_D * B_B) + (A_E * B_E) + (A_F * B_F)
            Let C_F = (A_D * B_C) + (A_E * B_F) + (A_F * B_I)

            Let C_G = (A_G * B_A) + (A_H * B_D) + (A_I * B_G)
            Let C_H = (A_G * B_B) + (A_H * B_E) + (A_I * B_F)
            Let C_I = (A_G * B_C) + (A_H * B_F) + (A_I * B_I)

        Example 2: 
            ** Matrix A has the same number of columns as Matrix B number of rows **
            
              2x3 Matrix A            3x4 Matrix B             2x4 Matrix C 
            ------------------   ----------------------   ----------------------
            |  A_A, A_B, A_C |   | B_A, B_B, B_C, B_D |   | C_A, C_B, C_C, C_D | 
            |  A_C, A_D, A_E | * | B_E, B_F, B_G, B_H | = | C_E, C_F, C_G, C_H | 
            ------------------   | B_I, B_J, B_K, B_L |   ----------------------
                                 ----------------------

            Let C_A = (A_A * B_A) + (A_B * B_E) + (A_C * B_I)
            Let C_B = (A_A * B_B) + (A_B * B_F) + (A_C * B_J)
            Let C_C = (A_A * B_C) + (A_B * B_G) + (A_C * B_K)
            Let C_D = (A_A * B_D) + (A_B * B_H) + (A_C * B_L)

            Let C_E = (A_C * B_A) + (A_D * B_E) + (A_E * B_I)
            Let C_F = (A_C * B_B) + (A_D * B_F) + (A_E * B_J)
            Let C_G = (A_C * B_C) + (A_D * B_G) + (A_E * B_K)
            Let C_H = (A_C * B_D) + (A_D * B_H) + (A_E * B_L)
            

       We'll just be testing this functionality for a 3x3 Matrix only 
       (i.e Matrix3f * Matrix3f only).
    */

    const DME::Matrix3f testMatrixOne (0,3,5,
                                       1,4,7,
                                       2,5,8);
    const DME::Matrix3f testMatrixTwo (10,10,10,
                                       10,10,10,
                                       10,10,10);
    DME::Matrix3f expectedMatrixThusFar( 80, 80, 80,
                                        120,120,120,
                                        150,150,150);
    
    // Test Matrix Multiplication functionality of Matrix3f class
    ASSERT_TRUE((testMatrixOne * testMatrixTwo) == expectedMatrixThusFar);
    GTEST_PASSED << "Multiplication" << std::endl;

    //Now lets test that the Matrix Multiplication and Assigment functionality as well. 
    expectedMatrixThusFar *= testMatrixOne;
    ASSERT_TRUE((testMatrixOne * testMatrixTwo) * testMatrixOne == expectedMatrixThusFar);
    GTEST_PASSED << "Multiplication & Assignment" << std::endl;
}

int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}