#ifndef _TEST_ARITHMETICAL_OPERATIONS_HPP_
#define _TEST_ARITHMETICAL_OPERATIONS_HPP_

#include <gtest/gtest.h>

#include "Vector.h"

#pragma region Sum
TEST(Sum, VecSum)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4, -5};

    Vector<int> res(a + b);

    int tmp_a[3] = {-100, 0, 6};
    int tmp[3] = {100, 4, 1};

    size_t i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(Sum, VecSumAnyTypes)
{
    Vector<double> a = {-100.5, 0.5, 6.5};
    Vector<int> b = {200, 4, -5};

    Vector<double> res(a + b);

    double tmp_a[3] = {-100.5, 0.5, 6.5};
    double tmp[3] = {99.5, 4.5, 1.5};

    size_t i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(Sum, ByNumSum)
{
    Vector<int> a = {-100, 0, 6};
    int k = 10;

    Vector<int> res(a + k);

    int tmp_a[3] = {-100, 0, 6};
    int tmp[3] = {-90, 10, 16};

    size_t i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(Sum, ByNumSumAnyTypes)
{
    Vector<double> a = {-100.5, 0.5, 6.5};
    int k = 10;

    Vector<double> res(a + k);

    double tmp_a[3] = {-100.5, 0.5, 6.5};
    double tmp[3] = {-90.5, 10.5, 16.5};

    size_t i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(Sum, EqVecSum)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4, -5};

    Vector<int> res(a += b);

    int tmp[3] = {100, 4, 1};

    size_t i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(Sum, EqVecSumAnyTypes)
{
    Vector<double> a = {-100.5, 0.5, 6.5};
    Vector<int> b = {200, 4, -5};

    Vector<double> res(a += b);

    double tmp[3] = {99.5, 4.5, 1.5};

    size_t i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(Sum, EqByNumSum)
{
    Vector<int> a = {-100, 0, 6};
    int k = 10;

    Vector<int> res(a += k);

    int tmp[3] = {-90, 10, 16};

    size_t i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(Sum, EqByNumSumAnyTypes)
{
    Vector<double> a = {-100.5, 0.5, 6.5};
    int k = 10;

    Vector<double> res(a += k);

    double tmp[3] = {-90.5, 10.5, 16.5};

    size_t i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(Sum, BadVecSum)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4};

    EXPECT_ANY_THROW(a + b);
}

TEST(Sum, BadEqVecSum)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4};

    EXPECT_ANY_THROW(a += b);
}
#pragma endregion Sum

#pragma region Diff
TEST(Diff, VecDiff)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4, -5};

    Vector<int> res(a - b);

    int tmp_a[3] = {-100, 0, 6};
    int tmp[3] = {-300, -4, 11};

    size_t i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(Diff, VecDiffAnyTypes)
{
    Vector<long double> a = {-100.5, 0.5, 6.5};
    Vector<int> b = {200, 4, -5};

    Vector<long double> res(a - b);

    long double tmp_a[3] = {-100.5, 0.5, 6.5};
    long double tmp[3] = {-300.5, -3.5, 11.5};

    size_t i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(Diff, ByNumDiff)
{
    Vector<int> a = {-100, 0, 6};
    int k = 10;

    Vector<int> res(a - k);

    int tmp_a[3] = {-100, 0, 6};
    int tmp[3] = {-110, -10, -4};

    size_t i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(Diff, ByNumDiffAnyTypes)
{
    Vector<size_t> a = {100, 15, 36};
    size_t k = 10;

    Vector<size_t> res(a - k);

    size_t tmp_a[3] = {100, 15, 36};
    size_t tmp[3] = {90, 5, 26};

    size_t i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(Diff, EqVecDiff)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4, -5};

    Vector<int> res(a -= b);

    int tmp[3] = {-300, -4, 11};

    size_t i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(Diff, EqVecDiffAnyTypes)
{
    Vector<long double> a = {-100.5, 0.5, 6.5};
    Vector<int> b = {200, 4, -5};

    Vector<long double> res(a -= b);

    long double tmp[3] = {-300.5, -3.5, 11.5};

    size_t i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(Diff, EqByNumDiff)
{
    Vector<int> a = {-100, 0, 6};
    int k = 10;

    Vector<int> res(a -= k);

    int tmp[3] = {-110, -10, -4};

    size_t i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(Diff, EqByNumDiffAnyTypes)
{
    Vector<size_t> a = {100, 15, 36};
    size_t k = 10;

    Vector<size_t> res(a -= k);

    size_t tmp[3] = {90, 5, 26};

    size_t i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(Diff, BadVecDiff)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4};

    EXPECT_ANY_THROW(a - b);
}

TEST(Diff, BadEqVecDiff)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4};

    EXPECT_ANY_THROW(a -= b);
}
#pragma endregion Diff



#endif
