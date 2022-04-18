#ifndef _TEST_CONSTRUCTORS_HPP_
#define _TEST_CONSTRUCTORS_HPP_

#include <gtest/gtest.h>

#include "Vector.h"

TEST(contructors, defaultInt)
{
    Vector<int> vector;
    EXPECT_EQ(vector.IsEmpty(), true);
}

TEST(contructors, sizeInt)
{
    Vector<int> vector(3);
    EXPECT_EQ(vector.IsEmpty(), false);
}

TEST(contructors, sizeDouble)
{
    Vector<double> vector(3);
    EXPECT_EQ(vector.IsEmpty(), false);
}

TEST(contructors, fillerInt)
{
    size_t size = 3;
    int filler = -1;
    Vector<int> vector(size, filler);
    EXPECT_EQ(vector.IsEmpty(), false);

    for (auto elem : vector)
        EXPECT_EQ(elem, -1);
}

TEST(contructors, initListInt)
{
    Vector<int> vector{1, -2, 0, 3, -4};
    EXPECT_EQ(vector.IsEmpty(), false);
    int arr[5] = {1, -2, 0, 3, -4};

    int i = 0;
    for (auto elem : vector)
        EXPECT_EQ(elem, arr[i++]);
}

TEST(contructors, initListChar)
{
    Vector<char> vector{'T', 'R', 'Y'};
    EXPECT_EQ(vector.IsEmpty(), false);

    int arr[3] = {'T', 'R', 'Y'};

    int i = 0;
    for (auto elem : vector)
        EXPECT_EQ(elem, arr[i++]);
}

#endif