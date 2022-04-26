#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <memory>
#include <cmath>

#include "Vector.h"
#include "Exceptions.h"

#define EPS __DBL_EPSILON__

#pragma region Constructors
template <typename Type>
Vector<Type>::Vector(): BaseContainer(), data() {}

template <typename Type>
Vector<Type>::Vector(const size_t sizeValue): BaseContainer(sizeValue)
{
    allocate(size);
}

template <typename Type>
Vector<Type>::Vector(const Vector<Type> &vector): BaseContainer(vector.size)
{
    allocate(size);

    for (size_t i = 0; i < size; ++i)
        (*this)[i] = vector[i];
}

template <typename Type>
Vector<Type>::Vector(const size_t sizeValue, const Type &filler): BaseContainer(sizeValue)
{
    allocate(sizeValue);

    for (size_t i = 0; i < size; ++i)
        (*this)[i] = filler;
}

template <typename Type>
Vector<Type>::Vector(const size_t sizeValue, const Type *arr): BaseContainer(sizeValue)
{
    allocate(sizeValue);

    for (size_t i = 0; i < size; ++i)
        (*this)[i] = arr[i];
}

template <typename Type>
Vector<Type>::Vector(const std::initializer_list<Type> elements): BaseContainer(elements.size())
{
    allocate(size);

    size_t i = 0;
    for (auto elem : elements)
        (*this)[i++] = elem;
}

template <typename Type>
Vector<Type>::Vector(Vector<Type> &&vector) noexcept: BaseContainer(vector.size)
{
    data = vector.data;
    vector.data.reset();
}

template <typename Type>
template <typename IterType>
Vector<Type>::Vector(const IterType begin, const IterType end): BaseContainer()
{
    size_t len = 0;
    for (auto iter = begin; iter < end; ++iter, ++len);

    size = len;
    allocate(size);

    len = 0;
    for (auto iter = begin; iter < end; ++iter, ++len)
        data[len] = *iter;
}
#pragma endregion Constructors

template <typename Type>
Vector<Type>::~Vector() = default;

#pragma region Iterators
template <typename Type>
Iterator<Type> Vector<Type>::begin() noexcept
{
    return Iterator<Type>(*this);
}

template <typename Type>
Iterator<Type> Vector<Type>::end() noexcept
{
    if (IsEmpty())
        return begin();
        
    return Iterator<Type>(*this) + size;
}

template <typename Type>
ConstIterator<Type> Vector<Type>::begin() const noexcept
{
    return ConstIterator<Type>(*this);
}

template <typename Type>
ConstIterator<Type> Vector<Type>::end() const noexcept
{
    if (IsEmpty())
        return cbegin();
        
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
    if (IsEmpty())
        return cbegin();
        
    return ConstIterator<Type>(*this) + size;
}

template <typename Type>
ReverseIterator<Type> Vector<Type>::rbegin() noexcept
{
    if (IsEmpty())
        return rend();
        
    return ReverseIterator<Type>(*this) - (size - 1);
}

template <typename Type>
ReverseIterator<Type> Vector<Type>::rend() noexcept
{
    return ReverseIterator<Type>(*this) + 1;
}

template <typename Type>
ConstReverseIterator<Type> Vector<Type>::rbegin() const noexcept
{
    if (IsEmpty())
        return crend();
        
    return ConstReverseIterator<Type>(*this) - (size - 1);
}

template <typename Type>
ConstReverseIterator<Type> Vector<Type>::rend() const noexcept
{
    return ConstReverseIterator<Type>(*this) + 1;
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
    return ConstReverseIterator<Type>(*this) + 1;
}
#pragma endregion Iterators

#pragma region Operations
#pragma region UnaryOperations
template <typename Type>
Vector<Type> Vector<Type>::neg() const
{
    Vector<Type> res(*this);

    for (size_t i = 0; i < size; ++i)
        res[i] = -res[i];

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
    for (size_t i = 0; i < size; ++i)
        len += (*this)[i] * (*this)[i];

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

    OutType len = length<OutType>();
    divisionByZeroCheck(len, __LINE__);
    
    Vector<OutType> res(size);
    
    for (size_t i = 0; i < size; ++i)
        res[i] = (*this)[i] / len;

    return res;
}
#pragma endregion UnaryOperations

#pragma region Assignments
template <typename Type>
Vector<Type> &Vector<Type>::operator=(std::initializer_list<Type> elements)
{
    size = elements.size();
    allocate(size);
    
    size_t i = 0;
    for (auto &cur : elements)
        (*this)[i++] = cur;

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator=(const Vector<Type> &vector)
{
    size = vector.size;
    allocate(size);
    
    size_t i = 0;
    for (auto &cur : vector)
        (*this)[i++] = cur;
 
    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator=(Vector<Type> &&vector) noexcept
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
    if (size != vector.GetSize())
    return false;

    for (size_t i = 0; i < size; ++i)
        if (abs((*this)[i] - vector[i]) > EPS)
            return false;

    return true;
}

template <typename Type>
template <typename OtherType>
bool Vector<Type>::operator==(const Vector<OtherType> &vector) const
{
    return isEqual(vector);
}

template <typename Type>
template <typename OtherType>
bool Vector<Type>::isNotEqual(const Vector<OtherType> &vector) const
{
    return !isEqual(vector);
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
Type &Vector<Type>::operator[](const size_t index)
{
    indexCheck(index, __LINE__);

    return data[index];
}

template <typename Type>
const Type &Vector<Type>::operator[](const size_t index) const
{
    indexCheck(index, __LINE__);

    return data[index];
}
#pragma endregion Indexations

#pragma region Sum
template <typename Type>
Vector<Type> Vector<Type>::VecSum(const Vector<Type> &vector) const
{
    sizesCheck(vector, __LINE__);

    Vector<Type> res(*this);

    for (size_t i = 0; i < size; ++i)
        res[i] += vector[i];

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator+(const Vector<Type> &vector) const
{
    return VecSum(vector);
}

template <typename Type>
Vector<Type> Vector<Type>::ByNumSum(const Type &num) const
{
    Vector<Type> res(*this);
    
    for (size_t i = 0; i < size; ++i)
        res[i] += num;

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator+(const Type &num) const
{
    return ByNumSum(num);
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::VecSum(const Vector<OtherType> &vector) const
{
    sizesCheck(vector, __LINE__);
    Vector<decltype((*this)[0] + vector[0])> res(size);
    
    for (size_t i = 0; i < size; ++i)
        res[i] = (*this)[i] + vector[i];

    return res;
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::operator+(const Vector<OtherType> &vector) const
{
    return VecSum(vector);
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::ByNumSum(const OtherType &num) const
{
    Vector<decltype((*this)[0] + num)> res(size);
    
    for (size_t i = 0; i < size; ++i)
        res[i] = (*this)[i] + num;

    return res;
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::operator+(const OtherType &num) const
{
    return ByNumSum(num);
}

template <typename Type>
Vector<Type> &Vector<Type>::EqVecSum(const Vector<Type> &vector)
{
    sizesCheck(vector, __LINE__);

    for (size_t i = 0; i < size; ++i)
        (*this)[i] += vector[i];

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator+=(const Vector<Type> &vector)
{
    return EqVecSum(vector);
}

template <typename Type>
Vector<Type> &Vector<Type>::EqByNumSum(const Type &num)
{
    for (size_t i = 0; i < size; ++i)
        (*this)[i] += num;

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator+=(const Type &num)
{
    return EqByNumSum(num);
}

template <typename Type>
template <typename OtherType>
Vector<Type> &Vector<Type>::EqVecSum(const Vector<OtherType> &vector)
{
    sizesCheck(vector, __LINE__);

    for (size_t i = 0; i < size; ++i)
        (*this)[i] += vector[i];
    
    return *this;
}

template <typename Type>
template <typename OtherType>
Vector<Type> &Vector<Type>::operator+=(const Vector<OtherType> &vector)
{
    return EqVecSum(vector);
}

template <typename Type>
template <typename OtherType>
Vector<Type> &Vector<Type>::EqByNumSum(const OtherType &num)
{
    for (size_t i = 0; i < size; ++i)
        (*this)[i] += num;
    
    return *this;
}

template <typename Type>
template <typename OtherType>
Vector<Type> &Vector<Type>::operator+=(const OtherType &num)
{
    return EqByNumSum(num);
}
#pragma endregion Sum

#pragma region Diff
template <typename Type>
Vector<Type> Vector<Type>::VecDiff(const Vector<Type> &vector) const
{
    sizesCheck(vector, __LINE__);

    Vector<Type> res(*this);
    
    for (size_t i = 0; i < size; ++i)
        res[i] -= vector[i];

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator-(const Vector<Type> &vector) const
{
    return VecDiff(vector);
}

template <typename Type>
Vector<Type> Vector<Type>::ByNumDiff(const Type &num) const
{
    Vector<Type> res(*this);
    
    for (size_t i = 0; i < size; ++i)
        res[i] -= num;

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator-(const Type &num) const
{
    return ByNumDiff(num);
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::VecDiff(const Vector<OtherType> &vector) const
{
    sizesCheck(vector, __LINE__);

    Vector<decltype((*this)[0] - vector[0])> res(size);

    for (size_t i = 0; i < size; ++i)
        res[i] = (*this)[i] - vector[i];

    return res;
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::operator-(const Vector<OtherType> &vector) const
{
    return VecDiff(vector);
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::ByNumDiff(const OtherType &num) const
{
    Vector<decltype((*this)[0] - num)> res(size);

    for (size_t i = 0; i < size; ++i)
        res[i] = (*this)[i] - num;

    return res;
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::operator-(const OtherType &num) const
{
    return ByNumDiff(num);
}

template <typename Type>
Vector<Type> &Vector<Type>::EqVecDiff(const Vector<Type> &vector)
{
    sizesCheck(vector, __LINE__);

    for (size_t i = 0; i < size; ++i)
        (*this)[i] -= vector[i];

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator-=(const Vector<Type> &vector)
{
    return EqVecDiff(vector);
}

template <typename Type>
Vector<Type> &Vector<Type>::EqByNumDiff(const Type &num)
{
    for (size_t i = 0; i < size; ++i)
        (*this)[i] -= num;

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator-=(const Type &num)
{
    return EqByNumDiff(num);
}

template <typename Type>
template <typename OtherType>
Vector<Type> &Vector<Type>::EqVecDiff(const Vector<OtherType> &vector)
{
    sizesCheck(vector, __LINE__);

    for (size_t i = 0; i < size; ++i)
        (*this)[i] -= vector[i];
    
    return *this;
}

template <typename Type>
template <typename OtherType>
Vector<Type> &Vector<Type>::operator-=(const Vector<OtherType> &vector)
{
    return EqVecDiff(vector);
}

template <typename Type>
template <typename OtherType>
Vector<Type> &Vector<Type>::EqByNumDiff(const OtherType &num)
{
    for (size_t i = 0; i < size; ++i)
        (*this)[i] -= num;
    
    return *this;
}

template <typename Type>
template <typename OtherType>
Vector<Type> &Vector<Type>::operator-=(const OtherType &num)
{
    return EqByNumDiff(num);
}
#pragma endregion Diff

#pragma region Mul
template <typename Type>
Vector<Type> Vector<Type>::ByNumMul(const Type &num) const
{
    Vector<Type> res(*this);
    
    for (size_t i = 0; i < size; ++i)
        res[i] *= num;

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator*(const Type &num) const
{
    return ByNumMul(num);
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::ByNumMul(const OtherType &num) const
{
    Vector<decltype((*this)[0] * num)> res(size);

    for (size_t i = 0; i < size; ++i)
        res[i] = (*this)[i] * num;

    return res;
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::operator*(const OtherType &num) const
{
    return ByNumMul(num);
}

template <typename Type>
Vector<Type> &Vector<Type>::EqByNumMul(const Type &num)
{
    Iterator<Type> res_iter = begin();

    for (size_t i = 0; i < size; ++i)
        (*this)[i] *= num;

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator*=(const Type &num)
{
    return EqByNumMul(num);
}

template <typename Type>
template <typename OtherType>
Vector<Type> &Vector<Type>::EqByNumMul(const OtherType &num)
{
    for (size_t i = 0; i < size; ++i)
        (*this)[i] *= num;

    return *this;
}

template <typename Type>
template <typename OtherType>
Vector<Type> &Vector<Type>::operator*=(const OtherType &num)
{
    return EqByNumMul(num);
}
#pragma endregion Mul

#pragma region Div
template <typename Type>
Vector<Type> Vector<Type>::ByNumDiv(const Type &num) const
{
    divisionByZeroCheck(num, __LINE__);

    Vector<Type> res(*this);
    
    for (size_t i = 0; i < size; ++i)
        res[i] /= num;

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator/(const Type &num) const
{
    return ByNumDiv(num);
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::ByNumDiv(const OtherType &num) const
{
    divisionByZeroCheck(num, __LINE__);
    
    Vector<decltype((*this)[0] / num)> res(size);

    for (size_t i = 0; i < size; ++i)
        res[i] = (*this)[i] / num;

    return res;
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::operator/(const OtherType &num) const
{
    return ByNumDiv(num);
}

template <typename Type>
Vector<Type> &Vector<Type>::EqByNumDiv(const Type &num)
{
    divisionByZeroCheck(num, __LINE__);
    
    for (size_t i = 0; i < size; ++i)
        (*this)[i] /= num;

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator/=(const Type &num)
{
    return EqByNumDiv(num);
}

template <typename Type>
template <typename OtherType>
Vector<Type> &Vector<Type>::EqByNumDiv(const OtherType &num)
{
    divisionByZeroCheck(num, __LINE__);
    
    for (size_t i = 0; i < size; ++i)
        (*this)[i] /= num;

    return *this;
}

template <typename Type>
template <typename OtherType>
Vector<Type> &Vector<Type>::operator/=(const OtherType &num)
{
    return EqByNumDiv(num);
}
#pragma endregion Div

#pragma region ScalarProd
template <typename Type>
Type Vector<Type>::scalarProd(const Vector<Type> &vector) const
{
    sizesCheck(vector, __LINE__);

    Type sum = 0;

    for (size_t i = 0; i < size; ++i)
        sum += (*this)[i] * vector[i];

    return sum;
}

template <typename Type>
Type Vector<Type>::operator&(const Vector<Type> &vector) const
{
    return scalarProd(vector);
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::scalarProd(const Vector<OtherType> &vector) const
{
    sizesCheck(vector, __LINE__);

    decltype((*this)[0] * vector[0]) sum = 0;

    for (size_t i = 0; i < size; ++i)
        sum += (*this)[i] * vector[i];

    return sum;
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::operator&(const Vector<OtherType> &vector) const
{
    return scalarProd(vector);
}
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

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::vectorProd(const Vector<OtherType> &vector) const
{
    sizesCheck(vector, __LINE__);

    Vector<decltype((*this)[0] + vector[0])> res(size);

    for (size_t i = 0; i < size; ++i)
        res[i] = (*this)[(i + 1) % size] * vector[(i + 2) % size] - 
                 (*this)[(i + 2) % size] * vector[(i + 1) % size];

    return res;
}

template <typename Type>
template <typename OtherType>
decltype(auto) Vector<Type>::operator^(const Vector<OtherType> &vector) const
{
    return vectorProd(vector);
}

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

template <typename Type>
template <typename OtherType>
Vector<Type> &Vector<Type>::eqVectorProd(const Vector<OtherType> &vector)
{
    sizesCheck(vector, __LINE__);

    Vector<Type> tmp(*this);

    for (size_t i = 0; i < size; ++i)
        (*this)[i] = tmp[(i + 1) % size] * vector[(i + 2) % size] - 
                     tmp[(i + 2) % size] * vector[(i + 1) % size];

    return *this;
}

template <typename Type>
template <typename OtherType>
Vector<Type> &Vector<Type>::operator^=(const Vector<OtherType> &vector)
{
    return eqVectorProd(vector);
}
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
