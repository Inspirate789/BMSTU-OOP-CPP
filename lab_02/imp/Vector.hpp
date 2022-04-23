#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <memory>
#include <cmath>

#include "Vector.h"
#include "Exceptions.h"

#define EPS __DBL_EPSILON__
#define NULL_FILLER 0.0

#pragma region Constructors
template <typename Type>
Vector<Type>::Vector(size_t sizeValue): BaseContainer(sizeValue)
{
    allocate(size);
}

template <typename Type>
Vector<Type>::Vector(const Vector<Type> &vector): BaseContainer(vector.size)
{
    allocate(size);

    ConstIterator<Type> src_iter = vector.cbegin();
    Iterator<Type> dst_iter = begin();

    for (; src_iter; ++src_iter, ++dst_iter)
        *dst_iter = *src_iter;
}

template <typename Type>
Vector<Type>::Vector(size_t sizeValue, const Type &filler): BaseContainer(sizeValue)
{
    allocate(sizeValue);

    for (Iterator<Type> iter = begin(); iter; ++iter)
        *iter = filler;
}

template <typename Type>
Vector<Type>::Vector(size_t sizeValue, const Type *arr): BaseContainer(sizeValue)
{
    allocate(sizeValue);

    size_t i = 0;
    for (Iterator<Type> iter = begin(); iter; ++iter, ++i)
        *iter = arr[i];
}

template <typename Type>
Vector<Type>::Vector(std::initializer_list<Type> elements): BaseContainer(elements.size())
{
    allocate(size);

    Iterator<Type> iter = begin();

    for (auto elem : elements)
        *(iter++) = elem;
}

template <typename Type>
Vector<Type>::Vector(Vector<Type> &&vector) noexcept: BaseContainer(vector.size) // Передача по правосторонней ссылке (вызывается конструктор перемещения) (~передача владения~)
{
    data = vector.data;
    vector.data.reset();
}

template <typename Type>
template <typename IterType>
Vector<Type>::Vector(IterType begin, IterType end): BaseContainer()
{
    size_t len = 0;
    for (auto iter = begin; iter < end; ++iter, ++len);

    allocate(len);
    size = len;

    len = 0;
    for (auto iter = begin; iter < end; ++iter, ++len)
        data[len] = *iter;
}
#pragma endregion Constructors

#pragma region Iterators
template <typename Type>
Iterator<Type> Vector<Type>::begin() const noexcept
{
    return Iterator<Type>(*this);
}

template <typename Type>
Iterator<Type> Vector<Type>::end() const noexcept
{
    if (IsEmpty())
        return begin();
        
    return Iterator<Type>(*this) + size;
}

template <typename Type>
ConstIterator<Type> Vector<Type>::cbegin() const noexcept
{
    return ConstIterator<Type>(*this);
}

template <typename Type>
ConstIterator<Type> Vector<Type>::cend() const noexcept
{
    if (IsEmpty())
        return cbegin();
        
    return ConstIterator<Type>(*this) + size;
}

template <typename Type>
ReverseIterator<Type> Vector<Type>::rbegin() const noexcept
{
    if (IsEmpty())
        return rend();
        
    return ReverseIterator<Type>(*this) - (size - 1);
}

template <typename Type>
ReverseIterator<Type> Vector<Type>::rend() const noexcept
{
    return ReverseIterator<Type>(*this) - 1;
}

template <typename Type>
ConstReverseIterator<Type> Vector<Type>::crbegin() const noexcept
{
    if (IsEmpty())
        return crend();
        
    return ConstReverseIterator<Type>(*this) - (size - 1);
}

template <typename Type>
ConstReverseIterator<Type> Vector<Type>::crend() const noexcept
{
    return ConstReverseIterator<Type>(*this) - 1;
}
#pragma endregion Iterators

#pragma region Operations
#pragma region UnaryOperations
template <typename Type>
Vector<Type> Vector<Type>::neg() const
{
    Vector<Type> res(*this);

    for (auto &elem : res)
        elem = -elem;

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator-() const
{
    return neg();
}

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
bool Vector<Type>::isZero() const
{
    return abs(length<double>()) < EPS;
}

template <typename Type>
bool Vector<Type>::isUnit() const
{
    return abs(length<double>() - 1) < EPS;
}

template <typename Type>
template <typename OutType>
Vector<OutType> Vector<Type>::getUnit() const
{
    zeroSizeCheck(__LINE__);
    Vector<OutType> res(size, NULL_FILLER);

    OutType len = length<OutType>();
    divisionByZeroCheck(len, __LINE__);
    
    Iterator<OutType> res_iter = res.begin();
    ConstIterator<Type> src_iter = cbegin();
    while (src_iter && res_iter)
        *(res_iter++) = *(src_iter++) / len;

    return res;
}
#pragma endregion UnaryOperations

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
template <typename OtherType>
bool Vector<Type>::isEqual(const Vector<OtherType> &vector) const
{
    ConstIterator<Type> first = cbegin();
    ConstIterator<OtherType> second = vector.cbegin();

    bool are_equal = (size && size == vector.GetSize());
    for (; are_equal && (first < cend()) && (second < vector.cend());
         ++first, ++second)
        are_equal = abs(*first - *second) < EPS;

    return are_equal || !size;
}

template <typename Type>
template <typename OtherType>
bool Vector<Type>::isNotEqual(const Vector<OtherType> &vector) const
{
    return !isEqual(vector);
}

template <typename Type>
template <typename OtherType>
bool Vector<Type>::operator==(const Vector<OtherType> &vector) const
{
    return isEqual(vector);
}

template <typename Type>
template <typename OtherType>
bool Vector<Type>::operator!=(const Vector<OtherType> &vector) const
{
    return !isEqual(vector);
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

#pragma region Sum
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

// template <typename Type>
// template <typename OtherType>
// decltype(auto) Vector<Type>::operator+(const Vector<OtherType> &vector) const
// {
//     sizesCheck(vector, __LINE__);

//     Vector<decltype((*this)[0] + vector[0])> res(size);
//     ConstIterator<OtherType> vec_iter = vector.cbegin();

//     size_t i = 0;
//     for (; vec_iter; ++vec_iter, ++i)
//         res[i] = (*this)[i] + *vec_iter;

//     return res;
// }

// template <typename Type>
// template <typename OtherType>
// decltype(auto) Vector<Type>::operator+(const OtherType &num) const
// {
//     Vector<decltype((*this)[0] + num)> res(size);

//     size_t i = 0;
//     for (ConstIterator<Type> iter = cbegin(); iter; ++iter, ++i)
//         res[i] = *iter + num;

//     return res;
// }

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

// template <typename Type>
// template <typename OtherType>
// Vector<Type> &Vector<Type>::operator+=(const Vector<OtherType> &vector)
// {
//     sizesCheck(vector, __LINE__);

//     Iterator<Type> res_iter = begin();
//     ConstIterator<OtherType> vec_iter = vector.cbegin();

//     for (; res_iter; ++res_iter)
//         *res_iter += *(vec_iter++);

//     return *this;
// }

// template <typename Type>
// template <typename OtherType>
// Vector<Type> &Vector<Type>::operator+=(const OtherType &num)
// {
//     Iterator<Type> res_iter = begin();

//     for (; res_iter; ++res_iter)
//         *res_iter += num;

//     return *this;
// }
#pragma endregion Sum

#pragma region Diff
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

// template <typename Type>
// template <typename OtherType>
// decltype(auto) Vector<Type>::operator-(const Vector<OtherType> &vector) const
// {
//     sizesCheck(vector, __LINE__);

//     Vector<decltype((*this)[0] + vector[0])> res(size);
//     ConstIterator<OtherType> vec_iter = vector.cbegin();

//     size_t i = 0;
//     for (; vec_iter; ++vec_iter, ++i)
//         res[i] = (*this)[i] - *vec_iter;

//     return res;
// }

// template <typename Type>
// template <typename OtherType>
// decltype(auto) Vector<Type>::operator-(const OtherType &num) const
// {
//     Vector<decltype((*this)[0] - num)> res(size);

//     size_t i = 0;
//     for (ConstIterator<Type> iter = cbegin(); iter; ++iter, ++i)
//         res[i] = *iter - num;

//     return res;
// }

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

// template <typename Type>
// template <typename OtherType>
// Vector<Type> &Vector<Type>::operator-=(const Vector<OtherType> &vector)
// {
//     sizesCheck(vector, __LINE__);

//     Iterator<Type> res_iter = begin();
//     ConstIterator<OtherType> vec_iter = vector.cbegin();

//     for (; res_iter; ++res_iter)
//         *res_iter -= *(vec_iter++);

//     return *this;
// }

// template <typename Type>
// template <typename OtherType>
// Vector<Type> &Vector<Type>::operator-=(const OtherType &num)
// {
//     Iterator<Type> res_iter = begin();

//     for (; res_iter; ++res_iter)
//         *res_iter -= num;

//     return *this;
// }
#pragma endregion Diff

#pragma region Mul
template <typename Type>
Vector<Type> Vector<Type>::operator*(const Type &num) const
{
    Vector<Type> res(*this);
    Iterator<Type> res_iter = res.begin();

    for (; res_iter; ++res_iter)
        *res_iter *= num;

    return res;
}

// template <typename Type>
// template <typename OtherType>
// decltype(auto) Vector<Type>::operator*(const OtherType &num) const
// {
//     Vector<decltype((*this)[0] * num)> res(size);

//     size_t i = 0;
//     for (ConstIterator<Type> iter = cbegin(); iter; ++iter, ++i)
//         res[i] = *iter * num;

//     return res;
// }

template <typename Type>
Vector<Type> &Vector<Type>::operator*=(const Type &num)
{
    Iterator<Type> res_iter = begin();

    for (; res_iter; ++res_iter)
        *res_iter *= num;

    return *this;
}

// template <typename Type>
// template <typename OtherType>
// Vector<Type> &Vector<Type>::operator*=(const OtherType &num)
// {
//     Iterator<Type> res_iter = begin();

//     for (; res_iter; ++res_iter)
//         *res_iter *= num;

//     return *this;
// }
#pragma endregion Mul

#pragma region Div
template <typename Type>
Vector<Type> Vector<Type>::operator/(const Type &num) const
{
    divisionByZeroCheck(num, __LINE__);

    Vector<Type> res(*this);
    Iterator<Type> res_iter = res.begin();

    for (; res_iter; ++res_iter)
        *res_iter /= num;

    return res;
}

// template <typename Type>
// template <typename OtherType>
// decltype(auto) Vector<Type>::operator/(const OtherType &num) const
// {
//     divisionByZeroCheck(num, __LINE__);
    
//     Vector<decltype((*this)[0] / num)> res(size);

//     size_t i = 0;
//     for (ConstIterator<Type> iter = cbegin(); iter; ++iter, ++i)
//         res[i] = *iter / num;

//     return res;
// }

template <typename Type>
Vector<Type> &Vector<Type>::operator/=(const Type &num)
{
    divisionByZeroCheck(num, __LINE__);
    
    Iterator<Type> res_iter = begin();

    for (; res_iter; ++res_iter)
        *res_iter /= num;

    return *this;
}

// template <typename Type>
// template <typename OtherType>
// Vector<Type> &Vector<Type>::operator/=(const OtherType &num)
// {
//     divisionByZeroCheck(num, __LINE__);
    
//     Iterator<Type> res_iter = begin();

//     for (; res_iter; ++res_iter)
//         *res_iter /= num;

//     return *this;
// }
#pragma endregion Div

#pragma region ScalarProd
template <typename Type>
Type Vector<Type>::scalarProd(const Vector<Type> &vector) const
{
    sizesCheck(vector, __LINE__);

    ConstIterator<Type> iter_1 = cbegin();
    ConstIterator<Type> iter_2 = vector.cbegin();

    Type sum = 0;
    for (; iter_1; ++iter_1, ++iter_2)
        sum += *iter_1 * *iter_2;

    return sum;
}

template <typename Type>
Type Vector<Type>::operator&(const Vector<Type> &vector) const
{
    return scalarProd(vector);
}

// template <typename Type>
// template <typename OtherType>
// decltype(auto) Vector<Type>::scalarProd(const Vector<OtherType> &vector) const
// {
//     sizesCheck(vector, __LINE__);

//     ConstIterator<Type> iter_1 = cbegin();
//     ConstIterator<OtherType> iter_2 = vector.cbegin();

//     decltype(*iter_1 * *iter_2) sum = 0;
//     for (; iter_1; ++iter_1, ++iter_2)
//         sum += *iter_1 * *iter_2;

//     return sum;
// }

// template <typename Type>
// template <typename OtherType>
// decltype(auto) Vector<Type>::operator&(const Vector<OtherType> &vector) const
// {
//     return scalarProd(vector);
// }
#pragma endregion ScalarProd

#pragma region VectorProd
template <typename Type>
Vector<Type> Vector<Type>::vectorProd(const Vector<Type> &vector) const
{
    sizesCheck(vector, __LINE__);

    Vector<Type> res(size);

    for (size_t i = 0; i < size; ++i)
        res[i] = (*this)[(i + 1) % size] * vector[(i + 2) % size] - 
                 (*this)[(i + 2) % size] * vector[(i + 1) % size];

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator^(const Vector<Type> &vector) const
{
    return vectorProd(vector);
}

// template <typename Type>
// template <typename OtherType>
// decltype(auto) Vector<Type>::vectorProd(const Vector<OtherType> &vector) const
// {
//     sizesCheck(vector, __LINE__);

//     Vector<decltype((*this)[0] * vector[0])> res(size);

//     for (size_t i = 0; i < size; ++i)
//         res[i] = (*this)[(i + 1) % size] * vector[(i + 2) % size] - 
//                  (*this)[(i + 2) % size] * vector[(i + 1) % size];

//     return res;
// }

// template <typename Type>
// template <typename OtherType>
// decltype(auto) Vector<Type>::operator^(const Vector<OtherType> &vector) const
// {
//     return vectorProd(vector);
// }

template <typename Type>
Vector<Type> &Vector<Type>::eqVectorProd(const Vector<Type> &vector)
{
    sizesCheck(vector, __LINE__);

    Vector<Type> tmp(*this);

    for (size_t i = 0; i < size; ++i)
        (*this)[i] = tmp[(i + 1) % size] * vector[(i + 2) % size] - 
                     tmp[(i + 2) % size] * vector[(i + 1) % size];

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator^=(const Vector<Type> &vector)
{
    return eqVectorProd(vector);
}

// template <typename Type>
// template <typename OtherType>
// Vector<Type> &Vector<Type>::eqVectorProd(const Vector<OtherType> &vector)
// {
//     sizesCheck(vector, __LINE__);

//     Vector<Type> tmp(*this);

//     for (size_t i = 0; i < size; ++i)
//         (*this)[i] = tmp[(i + 1) % size] * vector[(i + 2) % size] - 
//                      tmp[(i + 2) % size] * vector[(i + 1) % size];

//     return *this;
// }

// template <typename Type>
// template <typename OtherType>
// Vector<Type> &Vector<Type>::operator^=(const Vector<OtherType> &vector)
// {
//     return eqVectorProd(vector);
// }
#pragma endregion VectorProd

#pragma region OtherBinaryOperations
template <typename Type>
double Vector<Type>::angle(const Vector<Type> &vector) const
{
    double res = 0;

    if (abs(length<double>()) > EPS && abs(vector.length<double>()) > EPS)
        res = acos(scalarProd(vector) / (length<double>() * vector.length<double>()));

    return res;
}

template <typename Type>
template <typename OtherType>
double Vector<Type>::angle(const Vector<OtherType> &vector) const
{
    double res = 0;

    if (abs(this->template length<double>()) > EPS &&
        abs(vector.template length<double>()) > EPS)
        res = acos(scalarProd(vector) /
            (this->template length<double>() * 
            vector.template length<double>()));

    return res;
}

template <typename Type>
bool Vector<Type>::isCollinear(const Vector<Type> &vector) const
{
    sizesCheck(vector, __LINE__);

    double ang = angle(vector);
    return abs(ang) < EPS || abs(ang - M_PI) < EPS;
}

template <typename Type>
template <typename OtherType>
bool Vector<Type>::isCollinear(const Vector<OtherType> &vector) const
{
    sizesCheck(vector, __LINE__);

    double ang = angle(vector);
    return abs(ang) < EPS || abs(ang - M_PI) < EPS;
}

template <typename Type>
bool Vector<Type>::isOrthogonal(const Vector<Type> &vector) const
{
    sizesCheck(vector, __LINE__);

    return abs(angle(vector) - M_PI / 2) < EPS;
}

template <typename Type>
template <typename OtherType>
bool Vector<Type>::isOrthogonal(const Vector<OtherType> &vector) const
{
    sizesCheck(vector, __LINE__);

    return abs(angle(vector) - M_PI / 2) < EPS;
}
#pragma endregion OtherBinaryOperations
#pragma endregion Operations

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
void Vector<Type>::zeroSizeCheck(const size_t line) const
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

// template <typename Type>
// template <typename OtherType>
// void Vector<Type>::vector3DimsCheck(const Vector<OtherType> &vector, const size_t line) const
// {
//     if (GetSize() != DIMS_COUNT_OF_3D_VECTOR || vector.GetSize() != DIMS_COUNT_OF_3D_VECTOR)
//     {
//         time_t cur_time = time(NULL);
//         throw Not3DException(ctime(&cur_time), __FILE__, line,
//                              typeid(*this).name(), __FUNCTION__);
//     }
// }

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
