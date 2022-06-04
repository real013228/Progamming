//
// Created by real0 on 30.04.2022.
//
#include <gtest/gtest.h>
#include "Polynomial.h"

TEST(TestSuiteSample, TestSample){
    int s = Polynomial<2, 1, 1>::answer;
    ASSERT_EQ(3, s);
}
TEST(TestSuiteSample1, TestSample){
    int s = Polynomial<3, 1, 1>::answer;
    ASSERT_EQ(4, s);
}
TEST(TestSuiteSample2, TestSample){
    int s = Polynomial<4, 1, 1>::answer;
    ASSERT_EQ(5, s);
}
TEST(TestSuiteSample3, TestSample){
    int s = Polynomial<5, 1, 1>::answer;
    ASSERT_EQ(6, s);
}
int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}