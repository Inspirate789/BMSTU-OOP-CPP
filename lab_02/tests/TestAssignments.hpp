#ifndef _TEST_ASSIGNMENTS_HPP_
#define _TEST_ASSIGNMENTS_HPP_

#include <gtest/gtest.h>

#include "Vector.h"

TEST(Assignments, initList)
{
    Vector<int> a;
    a = {1, -2, 0, 3, 5};
    int arr[5] = {1, -2, 0, 3, 5};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, arr[i++]);
}

TEST(Assignments, CopyVector)
{
    Vector<int> a = {1, -2, 0, 3, 5};

    Vector<int> b = {1};
    b = a;
    int arr[5] = {1, -2, 0, 3, 5};

    int i = 0;
    for (auto elem : b)
        EXPECT_EQ(elem, arr[i++]);
}

TEST(Assignments, MoveVector)
{
    Vector<int> a = {1, -2, 0, 3, 5};
    Vector<int> b;
    b = -a;                             // "-a" - временный объект, поэтому вызовется оператор переноса
    int arr[5] = {-1, 2, 0, -3, -5};

    int i = 0;
    for (auto elem : b)
        EXPECT_EQ(elem, arr[i++]);
}

#endif
