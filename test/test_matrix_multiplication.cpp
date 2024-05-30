#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

/*
    1x1 matrix times 1x1 matrix. This tests the element-wise product
 */
TEST(MatrixMultiplicationTest, TestMultiplyScalars)
{

    std::vector<std::vector<int>> A = {
        {5}};
    std::vector<std::vector<int>> B = {
        {5}};
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));
    multiplyMatrices(A, B, C, 1, 1, 1);

    std::vector<std::vector<int>> expected = {
        {25}};

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/*
    1x1 matrix times 1x1 matrix with big values. This tests the element-wise product and overflow
 */
TEST(MatrixMultiplicationTest, TestMultiplyBigScalars)
{

    std::vector<std::vector<int>> A = {
        {20000}};
    std::vector<std::vector<int>> B = {
        {30000}};
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));
    multiplyMatrices(A, B, C, 1, 1, 1);

    std::vector<std::vector<int>> expected = {
        {20000 * 30000}};

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/*
    1x10 matrix times 10x1 matrix. This tests the sum of the products
*/
TEST(MatrixMultiplicationTest, TestSumColRow)
{

    std::vector<std::vector<int>> A = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}};
    std::vector<std::vector<int>> B = {
        {0}, {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}};
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));
    multiplyMatrices(A, B, C, 1, 10, 1);

    std::vector<std::vector<int>> expected = {
        {285}};

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/*
    Left and right product by the identity matrix. This tests correct indexing of the loops
*/
TEST(MatrixMultiplicationTest, TestMultiplyIdentity)
{

    std::vector<std::vector<int>> A = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}

    };
    std::vector<std::vector<int>> B = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));
    multiplyMatrices(A, B, C, 3, 3, 3);

    EXPECT_EQ(C, B) << "Matrix multiplication test failed! :(((()";

    multiplyMatrices(B, A, C, 3, 3, 3);
    ASSERT_EQ(C, B) << "Matrix multiplication test failed! :(((()";
}

/*
    Left and right product by the zero matrix. This tests products by zero
*/
TEST(MatrixMultiplicationTest, TestMultiplyZero)
{

    std::vector<std::vector<int>> A = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}

    };
    std::vector<std::vector<int>> B = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));
    multiplyMatrices(A, B, C, 3, 3, 3);

    EXPECT_EQ(C, A) << "Matrix multiplication test failed! :(((()";

    multiplyMatrices(B, A, C, 3, 3, 3);
    ASSERT_EQ(C, A) << "Matrix multiplication test failed! :(((()";
}

/*
    20x20 matrix multiplication to test big inputs
*/
TEST(MatrixMultiplicationTest, TestMultiplyBig)
{

    std::vector<std::vector<int>> A(20, std::vector<int>(20, 0));
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            A[i][j] = (i * 10) + j;
        }
    }
    std::vector<std::vector<int>> B(20, std::vector<int>(20, 0));
    for (int i = 0; i < 20; i++)
    {
        B[i][i] = 1;
    }

    std::vector<std::vector<int>> C(20, std::vector<int>(20, 0));
    multiplyMatrices(A, B, C, 20, 20, 20);
    EXPECT_EQ(C, A) << "Matrix multiplication test failed! :(((()";

    multiplyMatrices(B, A, C, 20, 20, 20);
    ASSERT_EQ(C, A) << "Matrix multiplication test failed! :(((()";
}

/*
    Test negative entries for the matrices, possible sign errors
*/
TEST(MatrixMultiplicationTest, TestMultiplyNegative)
{
    std::vector<std::vector<int>> A = {
        {-1, -2}, {3, 4}};

    std::vector<std::vector<int>> B = {
        {1, 1}, {1, 1}};

    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    std::vector<std::vector<int>> expected = {
        {-3, -3}, {7, 7}};
    multiplyMatrices(A, B, C, 2, 2, 2);
    EXPECT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";

    expected = {
        {2, 2}, {2, 2}};
    multiplyMatrices(B, A, C, 2, 2, 2);
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}