#ifndef _TEST_CONSTRUCTORS_HPP_
#define _TEST_CONSTRUCTORS_HPP_

#include <gtest/gtest.h>

#include "Vector.h"

TEST(Contructors, DefaultInt)
{
    Vector<int> vector;
    EXPECT_EQ(vector.IsEmpty(), true);
}

TEST(Contructors, SizeInt)
{
    Vector<int> vector(3);
    EXPECT_EQ(vector.IsEmpty(), false);
}

TEST(Contructors, SizeDouble)
{
    Vector<double> vector(3);
    EXPECT_EQ(vector.IsEmpty(), false);
}

TEST(Contructors, FillerInt)
{
    size_t size = 3;
    int filler = -1;
    Vector<int> vector(size, filler);
    EXPECT_EQ(vector.IsEmpty(), false);

    for (auto elem : vector)
        EXPECT_EQ(elem, -1);
}

TEST(Contructors, ArrDouble)
{
    size_t size = 5;
    double a[5] = {1.2, -2.0, 0.000001, 3.7, -4.5};
    double *arr = a;
    Vector<double> vector(size, arr);

    EXPECT_EQ(vector.IsEmpty(), false);

    size_t i = 0;
    for (auto elem : vector)
        EXPECT_EQ(elem, arr[i++]);
}

TEST(Contructors, InitListInt)
{
    Vector<int> vector{1, -2, 0, 3, -4};
    EXPECT_EQ(vector.IsEmpty(), false);
    int arr[5] = {1, -2, 0, 3, -4};

    size_t i = 0;
    for (auto elem : vector)
        EXPECT_EQ(elem, arr[i++]);
}

TEST(Contructors, InitListChar)
{
    Vector<char> vector{'T', 'R', 'Y'};
    EXPECT_EQ(vector.IsEmpty(), false);

    int arr[3] = {'T', 'R', 'Y'};

    size_t i = 0;
    for (auto elem : vector)
        EXPECT_EQ(elem, arr[i++]);
}

TEST(Contructors, IterChar)
{
    size_t size = 5;
    const char *str = "abcdef";
    Vector<char> vector_1(size, str);
    Vector<char> vector_2(vector_1.cbegin() + 1, vector_1.cend() - 1);
    
    EXPECT_EQ(vector_2.IsEmpty(), false);

    size_t i = 1;
    for (auto elem : vector_2)
        EXPECT_EQ(elem, vector_1[i++]);
}

TEST(Contructors, RevIterChar)
{
    size_t size = 5;
    const char *str = "abcdef";
    Vector<char> vector_1(size, str);

    EXPECT_EQ(vector_1.IsEmpty(), false);

    Vector<char> vector_2(vector_1.crbegin() + 1, vector_1.crend() - 1);
    
    EXPECT_EQ(vector_2.IsEmpty(), false);

    size_t i = 3;
    for (auto elem : vector_2)
        EXPECT_EQ(elem, vector_1[i--]);
}

class A
{
    private:
        int a;
        size_t b;
    public:
    A() {a = 0; b = 0; };
    explicit A(int x, size_t y) {a = x; b = y; };
    bool operator==(const A &other) const { return (a == other.a) && (b == other.b); }
    ~A() = default;
};

TEST(Contructors, FillerClass)
{
    size_t size = 3;
    A filler(1, 2);
    Vector<A> vector(size, filler);
    EXPECT_EQ(vector.IsEmpty(), false);

    for (auto elem : vector)
        EXPECT_EQ(elem, filler);
}

TEST(Contructors, FillerClassWithDynAlloc)
{
    size_t size = 3;
    A filler(1, 2);
    Vector<A> *vector_ptr = new Vector<A>(size, filler);
    EXPECT_EQ(vector_ptr->IsEmpty(), false);

    for (auto elem : *vector_ptr)
        EXPECT_EQ(elem, filler);

    delete vector_ptr;
}

#endif
