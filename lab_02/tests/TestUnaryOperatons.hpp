#ifndef _TEST_UNARY_OPERATIONS_HPP_
#define _TEST_UNARY_OPERATIONS_HPP_

#include <gtest/gtest.h>

#include "Vector.h"

TEST(UnaryOperations, Neg)
{
    Vector<int> vector{1, -2, 0, 3, -4};
    int arr[5] = {1, -2, 0, 3, -4};

    size_t i = 0;
    for (auto elem : vector.neg())
        EXPECT_EQ(elem, -arr[i++]);
}

TEST(UnaryOperations, Operator_minus)
{
    Vector<int> vector{1, -2, 0, 3, -4};
    int arr[5] = {1, -2, 0, 3, -4};

    size_t i = 0;
    for (auto elem : -vector)
        EXPECT_EQ(elem, -arr[i++]);
}

TEST(UnaryOperations, Length)
{
    Vector<double> vector_1{-0.5, -2, 0, 1, -1};
    Vector<int> vector_2{0, 0, 0, 0, 0};
    Vector<int> vector_3{1, 0, 0, 0, 0};

    EXPECT_DOUBLE_EQ(vector_1.length<double>(), 2.5);
    EXPECT_DOUBLE_EQ(vector_2.length<double>(), 0.0);
    EXPECT_DOUBLE_EQ(vector_3.length<double>(), 1.0);
}

TEST(UnaryOperations, IsZero)
{
    Vector<double> vector_1{-0.5, -2, 0, 1, -1};
    Vector<int> vector_2{0, 0, 0, 0, 0};
    Vector<int> vector_3{1, 0, 0, 0, 0};

    EXPECT_EQ(vector_1.isZero(), false);
    EXPECT_EQ(vector_2.isZero(), true);
    EXPECT_EQ(vector_3.isZero(), false);
}

TEST(UnaryOperations, IsUnit)
{
    Vector<double> vector_1{-0.5, -2, 0, 1, -1};
    Vector<int> vector_2{0, 0, 0, 0, 0};
    Vector<int> vector_3{1, 0, 0, 0, 0};

    EXPECT_EQ(vector_1.isUnit(), false);
    EXPECT_EQ(vector_2.isUnit(), false);
    EXPECT_EQ(vector_3.isUnit(), true);
}

TEST(UnaryOperations, GetUnit)
{
    Vector<double> vector_1{-0.5, -2, 0, 1, -1};
    Vector<double> vector_1u{-0.2, -0.8, 0, 0.4, -0.4};
    Vector<double> vector_2{1, 0, 0, 0, 0};

    Vector<double> vector_3 = vector_1.getUnit<double>();
    ConstIterator<double> iter_1 = vector_3.cbegin();
    ConstIterator<double> iter_2 = vector_1u.cbegin();

    for (; (iter_1 < vector_1.cend()) && (iter_2 < vector_1u.cend());
         ++iter_1, ++iter_2)
        EXPECT_DOUBLE_EQ(*iter_1 , *iter_2);

    Vector<double> vector_4 = vector_2.getUnit<double>();
    ConstIterator<double> iter_3 = vector_2.cbegin();
    ConstIterator<double> iter_4 = vector_4.cbegin();

    for (; iter_3 < vector_2.cend() && iter_4 < vector_4.cend();
         ++iter_3, ++iter_4)
        EXPECT_DOUBLE_EQ(*iter_3 , *iter_4);
}

#endif
