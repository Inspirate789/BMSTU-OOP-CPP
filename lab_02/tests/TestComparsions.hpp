#ifndef _TEST_COMPARSIONS_HPP_
#define _TEST_COMPARSIONS_HPP_

#include <gtest/gtest.h>

#include "Vector.h"

TEST(comparison_operators, equal)
{
    Vector<int> a = {5, -3, 1, 0, -7};
    Vector<int> b = {5, -3, 1, 0, -7};

    EXPECT_EQ((a == b), true);
    EXPECT_EQ((a != b), false);
}

TEST(comparison_operators, emptyEqual)
{
    Vector<int> a(0);
    Vector<int> b(0);

    EXPECT_EQ((a == b), true);
    EXPECT_EQ((a != b), false);
}

TEST(comparison_operators, notEqual)
{
    Vector<int> a = {5, -3, 1, 0, -7};
    Vector<int> b = {5, 10, 1, 0, -7};

    EXPECT_EQ((a == b), false);
    EXPECT_EQ((a != b), true);
}

TEST(comparison_operators, notEqualBySizes)
{
    Vector<int> a = {5, -3, 1, 0, -7};
    Vector<int> b = {5, -3, 1};

    EXPECT_EQ((a == b), false);
    EXPECT_EQ((a != b), true);
}

#endif