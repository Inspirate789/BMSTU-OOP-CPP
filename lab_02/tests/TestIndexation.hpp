#ifndef _TEST_INDEXATION_HPP_
#define _TEST_INDEXATION_HPP_

#include <gtest/gtest.h>

#include "Vector.h"

TEST(Indexation, Variable)
{
    size_t size = 5;
    double arr_1[] = {-0.5, -2, 0, 1, -1};
    int arr_2[] = {1, 0, 0, 0, 0};
    char arr_3[] = {'a', 'b', 'c', 'd', 'e'};
    Vector<double> vector_1{-0.5, -2, 0, 1, -1};
    Vector<int> vector_2{1, 0, 0, 0, 0};
    Vector<char> vector_3{'a', 'b', 'c', 'd', 'e'};

    for (size_t i = 0; i < size; ++i)
    {
        EXPECT_DOUBLE_EQ(vector_1[i], arr_1[i]);
        EXPECT_EQ(vector_2[i], arr_2[i]);
        EXPECT_EQ(vector_3[i], arr_3[i]);
    }
}

TEST(Indexation, Constant)
{
    Vector<double> vector{-0.5, -2, 0, 1, -1};
    const double a = vector[0], b = vector[1], c = vector[2],
                 d = vector[3], e = vector[4];
    
    EXPECT_DOUBLE_EQ(a, vector[0]);
    EXPECT_DOUBLE_EQ(b, vector[1]);
    EXPECT_DOUBLE_EQ(c, vector[2]);
    EXPECT_DOUBLE_EQ(d, vector[3]);
    EXPECT_DOUBLE_EQ(e, vector[4]);
}

#endif
