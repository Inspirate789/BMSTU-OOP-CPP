#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <memory>

#include "Vector.h"
#include "Exceptions.h"

#define EPS __DBL_EPSILON__
#define DIMS_COUNT_OF_3D_VECTOR 3

#pragma region Constructors
template <typename Type>
Vector<Type>::Vector(size_t size_value)
{
    allocate(size);
    size = size_value;
}

template <typename Type>
Vector<Type>::Vector(const Vector<Type> &vector)
{
    allocate(vector.size);
    size = vector.size;

    ConstIterator<Type> src = vector.cbegin();
    Iterator<Type> dst = begin();

    for (; src; ++src, ++dst)
        *dst = *src;
}

template <typename Type>
Vector<Type>::Vector(size_t sizeValue, const Type &filler)
{
    allocate(sizeValue);
    size = sizeValue;

    for (Iterator<Type> iter = begin(); iter; ++iter)
        *iter = filler;
}

template <typename Type>
Vector<Type>::Vector(size_t sizeValue, const Type *arr)
{
    allocate(sizeValue);
    size = sizeValue;

    size_t i = 0;
    for (Iterator<Type> iter = begin(); iter; ++iter, ++i)
        *iter = arr[i];
}

template <typename Type>
Vector<Type>::Vector(std::initializer_list<Type> elements)
{
    allocate(elements.size());
    size = elements.size();

    Iterator<Type> iter = begin();

    for (auto elem : elements)
        *(iter++) = elem;
}

template <typename Type>
Vector<Type>::Vector(Vector<Type> &&vector) noexcept // Передача по правосторонней ссылке (вызывается конструктор перемещения) (~передача владения~)
{
    size = vector.size;
    data = vector.data;
    vector.data.reset();
}

template <typename Type>
template <typename IterType>
Vector<Type>::Vector(IterType begin, IterType end)
{
    size_t len = 0;
    for (auto iter = begin; iter != end; ++iter, ++len)
        ;

    allocate(len);
    size = len;

    len = 0;
    for (auto iter = begin; iter != end; ++iter, ++len)
        data[len] = *iter;
}
#pragma endregion Constructors

#pragma region Iterators
template <typename Type>
Iterator<Type> Vector<Type>::begin() noexcept
{
    return Iterator<Type>(*this);
}

template <typename Type>
Iterator<Type> Vector<Type>::end() noexcept
{
    return Iterator<Type>(*this) + size;
}

template <typename Type>
ConstIterator<Type> Vector<Type>::begin() const noexcept // а зачем это, если есть cbegin и cend?
{
    return ConstIterator<Type>(*this);
}

template <typename Type>
ConstIterator<Type> Vector<Type>::end() const noexcept
{
    return ConstIterator<Type>(*this) + size;
}

template <typename Type>
ConstIterator<Type> Vector<Type>::cbegin() const noexcept
{
    return ConstIterator<Type>(*this);
}

template <typename Type>
ConstIterator<Type> Vector<Type>::cend() const noexcept
{
    return ConstIterator<Type>(*this) + size;
}
#pragma endregion Iterators

#pragma region Operators
#pragma region Assignments
template <typename Type>
Vector<Type> &Vector<Type>::operator=(std::initializer_list<Type> elements)
{
    allocate(elements.size());
    size = elements.size();

    Iterator<Type> iter = begin();
    for (auto &cur : elements)
        *(iter++) = cur;

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator=(const Vector<Type> &vector)
{
    allocate(vector.size);
    size = vector.size;

    Iterator<Type> iter = begin();
    for (auto &cur : vector)
        *(iter++) = cur;

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator=(Vector<Type> &&vector) noexcept // Передача по правосторонней ссылке (перемещение) (~передача владения~)
{
    size = vector.size;
    data = vector.data;
    vector.data.reset();

    return *this;
}
#pragma endregion Assignments

#pragma region Comparsions
template <typename Type>
bool Vector<Type>::operator==(const Vector<Type> &vector) const
{
    ConstIterator<Type> first = cbegin();
    ConstIterator<Type> second = vector.cbegin();

    bool are_equal = (size && size == vector.size);
    for (; are_equal && (first != cend()) && (second != vector.cend());
         ++first, ++second)
        are_equal = (*first == *second);

    return are_equal || !size;
}

template <typename Type>
bool Vector<Type>::operator!=(const Vector<Type> &vector) const
{
    return !(*this == vector);
}
#pragma endregion Comparsions

#pragma region Indexations
template <typename Type>
Type & Vector<Type>::operator[](const size_t index)
{
    indexCheck(index, __LINE__);
    return data[index];
}

template <typename Type>
const Type & Vector<Type>::operator[](const size_t index) const
{
    indexCheck(index, __LINE__);
    return data[index];
}
#pragma endregion Indexations

#pragma region ArithmeticalOperations
template <typename Type>
Vector<Type> Vector<Type>::operator+(const Vector<Type> &vector) const
{
    sizesCheck(vector, __LINE__);

    Vector<Type> res(*this);
    Iterator<Type> res_iter = res.begin();
    ConstIterator<Type> vec_iter = vector.cbegin();

    for (; res_iter; ++res_iter)
        *res_iter += *(vec_iter++);

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator+(const Type &num) const
{
    Vector<Type> res(*this);
    Iterator<Type> res_iter = res.begin();

    for (; res_iter; ++res_iter)
        *res_iter += num;

    return res;
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::operator+(const Vector<OtherType> &vector) const
{
    sizesCheck(vector, __LINE__);

    Vector<decltype((*this)[0] + vector[0])> res(size); // *this ??????
    ConstIterator<OtherType> vec_iter = vector.cbegin();

    size_t i = 0;
    for (; vec_iter; ++vec_iter, ++i)
        res[i] = (*this)[i] + *vec_iter;

    return res;
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::operator+(const OtherType &num) const
{
    Vector<decltype((*this)[0] + num)> res(size);

    size_t i = 0;
    for (ConstIterator<Type> iter = cbegin(); iter; ++iter, ++i)
        res[i] = *iter + num;

    return res;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator+=(const Vector<Type> &vector)
{
    sizesCheck(vector, __LINE__);

    Iterator<Type> res_iter = begin();
    ConstIterator<Type> vec_iter = vector.cbegin();

    for (; res_iter; ++res_iter)
        *res_iter += *(vec_iter++);

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator+=(const Type &num)
{
    Iterator<Type> res_iter = begin();

    for (; res_iter; ++res_iter)
        *res_iter += num;

    return *this;
}

template <typename Type>
template <typename OtherType>
Vector<Type> &Vector<Type>::operator+=(const Vector<OtherType> &vector)
{
    sizesCheck(vector, __LINE__);

    Iterator<Type> res_iter = begin();
    ConstIterator<OtherType> vec_iter = vector.cbegin();

    for (; res_iter; ++res_iter)
        *res_iter += *(vec_iter++);

    return *this;
}

template <typename Type>
template <typename OtherType>
Vector<Type> &Vector<Type>::operator+=(const OtherType &num)
{
    Iterator<Type> res_iter = begin();

    for (; res_iter; ++res_iter)
        *res_iter += num;

    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::operator-(const Vector<Type> &vector) const
{
    sizesCheck(vector, __LINE__);

    Vector<Type> res(*this);
    Iterator<Type> res_iter = res.begin();
    ConstIterator<Type> vec_iter = vector.cbegin();

    for (; res_iter; ++res_iter)
        *res_iter -= *(vec_iter++);

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator-(const Type &num) const
{
    Vector<Type> res(*this);
    Iterator<Type> res_iter = res.begin();

    for (; res_iter; ++res_iter)
        *res_iter -= num;

    return res;
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::operator-(const Vector<OtherType> &vector) const
{
    sizesCheck(vector, __LINE__);

    Vector<decltype((*this)[0] - vector[0])> res(size); // *this ??????
    ConstIterator<OtherType> vec_iter = vector.cbegin();

    size_t i = 0;
    for (; vec_iter; ++vec_iter, ++i)
        res[i] = (*this)[i] - *vec_iter;

    return res;
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::operator-(const OtherType &num) const
{
    Vector<decltype((*this)[0] - num)> res(size);

    size_t i = 0;
    for (ConstIterator<Type> iter = cbegin(); iter; ++iter, ++i)
        res[i] = *iter - num;

    return res;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator-=(const Vector<Type> &vector)
{
    sizesCheck(vector, __LINE__);

    Iterator<Type> res_iter = begin();
    ConstIterator<Type> vec_iter = vector.cbegin();

    for (; res_iter; ++res_iter)
        *res_iter -= *(vec_iter++);

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator-=(const Type &num)
{
    Iterator<Type> res_iter = begin();

    for (; res_iter; ++res_iter)
        *res_iter -= num;

    return *this;
}

template <typename Type>
template <typename OtherType>
Vector<Type> &Vector<Type>::operator-=(const Vector<OtherType> &vector)
{
    sizesCheck(vector, __LINE__);

    Iterator<Type> res_iter = begin();
    ConstIterator<OtherType> vec_iter = vector.cbegin();

    for (; res_iter; ++res_iter)
        *res_iter -= *(vec_iter++);

    return *this;
}

template <typename Type>
template <typename OtherType>
Vector<Type> &Vector<Type>::operator-=(const OtherType &num)
{
    Iterator<Type> res_iter = begin();

    for (; res_iter; ++res_iter)
        *res_iter -= num;

    return *this;
}
#pragma endregion ArithmeticalOperations
#pragma endregion Operators

#pragma region OtherPublicMethods
template <typename Type>
template <typename OutType>
OutType Vector<Type>::length() const
{
    zeroSizeCheck(__LINE__);

    Type len = 0;
    ConstIterator<Type> iter = cbegin();
    for (; iter; ++iter)
        len += *iter * *iter;

    return sqrt(len);
}

template <typename Type>
template <typename OutType>
Vector<OutType> Vector<Type>::getUnit() const
{
    zeroSizeCheck(__LINE__);
    Vector<OutType> res(size);

    OutType len = length<OutType>();
    Iterator<OutType> res_iter = res.begin();

    ConstIterator<Type> srcIt = cbegin();
    for (; srcIt; ++srcIt, ++res_iter)
        *res_iter = *srcIt / len;

    return res;
}
#pragma endregion OtherPublicMethods

#pragma region ProtectedMethods
#pragma region Allocate
template <typename Type>
void Vector<Type>::allocate(size_t size_value)
{
    try
    {
        data.reset(new Type[size_value]);
    }
    catch (std::bad_alloc &error)
    {
        time_t cur_time = time(NULL);
        throw MemoryException(ctime(&cur_time), __FILE__, __LINE__,
                              typeid(*this).name(), __FUNCTION__);
    }
}
#pragma endregion Allocate

#pragma region Checks
template <typename Type>
void Vector<Type>::zeroSizeCheck(const size_t line)
{
    if (IsEmpty())
    {
        time_t cur_time = time(NULL);
        throw EmptyVectorException(ctime(&cur_time), __FILE__, line,
                                   typeid(*this).name(), __FUNCTION__);
    }
}

template <typename Type>
void Vector<Type>::indexCheck(const size_t index, const size_t line) const
{
    if (index >= GetSize())
    {
        time_t cur_time = time(NULL);
        throw OutOfRangeException(ctime(&cur_time), __FILE__, line,
                                  typeid(*this).name(), __FUNCTION__);
    }
}

template <typename Type>
template <typename OtherType>
void Vector<Type>::sizesCheck(const Vector<OtherType> &vector, const size_t line) const
{
    if (GetSize() != vector.GetSize())
    {
        time_t cur_time = time(NULL);
        throw NotEqualSizesException(ctime(&cur_time), __FILE__, line,
                                     typeid(*this).name(), __FUNCTION__);
    }
}

template <typename Type>
template <typename OtherType>
void Vector<Type>::vector3DSizesCheck(const Vector<OtherType> &vector, const size_t line) const
{
    if (GetSize() != DIMS_COUNT_OF_3D_VECTOR || vector.GetSize() != DIMS_COUNT_OF_3D_VECTOR)
    {
        time_t cur_time = time(NULL);
        throw Not3DException(ctime(&cur_time), __FILE__, line,
                             typeid(*this).name(), __FUNCTION__);
    }
}

template <typename Type>
template <typename OtherType>
void Vector<Type>::divisionByZeroCheck(const OtherType &num, const size_t line) const
{
    if (abs(num) < EPS)
    {
        time_t cur_time = time(NULL);
        throw DivisionByZeroException(ctime(&cur_time), __FILE__, line,
                                      typeid(*this).name(), __FUNCTION__);
    }
}
#pragma endregion Checks
#pragma endregion ProtectedMethods
#endif
