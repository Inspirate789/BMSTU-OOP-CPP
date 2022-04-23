#ifndef _REVERSE_ITERATOR_HPP_
#define _REVERSE_ITERATOR_HPP_

#include "ReverseIterator.h"
#include "Exceptions.h"

#pragma region Constructors
template <typename Type>
ReverseIterator<Type>::ReverseIterator(const Vector<Type> &vector) noexcept
{
    ptr = vector.data;
    size = vector.size;
    index = 0;
}

template <typename Type>
ReverseIterator<Type>::ReverseIterator(const ReverseIterator<Type> &iterator) noexcept: BaseIterator(iterator)
{
    ptr = iterator.ptr;
}
#pragma endregion Constructors

template <typename Type>
ReverseIterator<Type>::~ReverseIterator() = default;

#pragma region Operators
template <typename Type>
ReverseIterator<Type>::operator bool() const
{
    expiredCheck(__LINE__);

    return size && index < size;
}

template <typename Type>
ReverseIterator<Type> &ReverseIterator<Type>::operator=(const ReverseIterator<Type> &iterator) noexcept
{
    ptr.reset(iterator.ptr);
    size = iterator.size;
    index = iterator.index;
}

template <typename Type>
Type &ReverseIterator<Type>::operator*()
{
    expiredCheck(__LINE__);
    indexCheck(__LINE__);

    return *getCurPtr();
}

template <typename Type>
const Type &ReverseIterator<Type>::operator*() const
{
    expiredCheck(__LINE__);
    indexCheck(__LINE__);

    return *getCurPtr();
}

template <typename Type>
Type *ReverseIterator<Type>::operator->()
{
    expiredCheck(__LINE__);
    indexCheck(__LINE__);

    return getCurPtr();
}

template <typename Type>
const Type *ReverseIterator<Type>::operator->() const
{
    expiredCheck(__LINE__);
    indexCheck(__LINE__);

    return getCurPtr();
}

template <typename Type>
Type &ReverseIterator<Type>::operator[](const size_t offset)
{
    expiredCheck(__LINE__);
    indexCheck(__LINE__, offset);

    return *(getCurPtr() + offset);
}

template <typename Type>
const Type &ReverseIterator<Type>::operator[](const size_t offset) const
{
    expiredCheck(__LINE__);
    indexCheck(__LINE__, offset);

    return *(getCurPtr() + offset);
}

template <typename Type>
template <typename OtherType>
ReverseIterator<Type> ReverseIterator<Type>::operator+(const OtherType diff) const
{
    expiredCheck(__LINE__);

    ReverseIterator<Type> res(*this);
    res.index -= diff;
    return res;
}

template <typename Type>
template <typename OtherType>
ReverseIterator<Type> ReverseIterator<Type>::operator-(const OtherType diff) const
{
    expiredCheck(__LINE__);

    ReverseIterator<Type> res(*this);
    res.index += diff;
    return res;
}

template <typename Type>
template <typename OtherType>
ReverseIterator<Type> &ReverseIterator<Type>::operator+=(const OtherType diff)
{
    expiredCheck(__LINE__);

    index -= diff;
    return this;
}

template <typename Type>
template <typename OtherType>
ReverseIterator<Type> &ReverseIterator<Type>::operator-=(const OtherType diff)
{
    expiredCheck(__LINE__);

    index += diff;
    return this;
}

template <typename Type>
ReverseIterator<Type> & ReverseIterator<Type>::operator++()
{
    expiredCheck(__LINE__);

    --index;
    return *this;
}

template <typename Type>
ReverseIterator<Type> ReverseIterator<Type>::operator++(int)
{
    expiredCheck(__LINE__);

    ReverseIterator<Type> tmp(*this);
    --(*this);
    return tmp;
}

template <typename Type>
ReverseIterator<Type> & ReverseIterator<Type>::operator--()
{
    expiredCheck(__LINE__);

    ++index;
    return *this;
}

template <typename Type>
ReverseIterator<Type> ReverseIterator<Type>::operator--(int)
{
    expiredCheck(__LINE__);

    ReverseIterator<Type> tmp(*this);
    ++(*this);
    return tmp;
}

template <typename Type>
bool ReverseIterator<Type>::operator==(const ReverseIterator<Type> &iterator) const
{
    expiredCheck(__LINE__);
    iterator.expiredCheck(__LINE__);

    return getCurPtr() == iterator.getCurPtr();
}

template <typename Type>
bool ReverseIterator<Type>::operator!=(const ReverseIterator<Type> &iterator) const
{
    expiredCheck(__LINE__);
    iterator.expiredCheck(__LINE__);

    return getCurPtr() != iterator.getCurPtr();
}

template <typename Type>
bool ReverseIterator<Type>::operator>(const ReverseIterator<Type> &iterator) const
{
    expiredCheck(__LINE__);
    iterator.expiredCheck(__LINE__);

    return getCurPtr() < iterator.getCurPtr();
}

template <typename Type>
bool ReverseIterator<Type>::operator>=(const ReverseIterator<Type> &iterator) const
{
    expiredCheck(__LINE__);
    iterator.expiredCheck(__LINE__);

    return getCurPtr() <= iterator.getCurPtr();
}

template <typename Type>
bool ReverseIterator<Type>::operator<(const ReverseIterator<Type> &iterator) const
{
    expiredCheck(__LINE__);
    iterator.expiredCheck(__LINE__);

    return getCurPtr() > iterator.getCurPtr();
}

template <typename Type>
bool ReverseIterator<Type>::operator<=(const ReverseIterator<Type> &iterator) const
{
    expiredCheck(__LINE__);
    iterator.expiredCheck(__LINE__);

    return getCurPtr() >= iterator.getCurPtr();
}
#pragma endregion Operators

#pragma region ProtectedMethods
template <typename Type>
Type *ReverseIterator<Type>::getCurPtr() const
{
    std::shared_ptr<Type[]> tmp = ptr.lock();
    return tmp.get() + index;
}

template <typename Type>
void ReverseIterator<Type>::expiredCheck(const size_t line) const
{
    if (ptr.expired())
    {
        time_t cur_time = time(NULL);
        throw ExpiredException(ctime(&cur_time), __FILE__, line,
                               typeid(*this).name(), __FUNCTION__);
    }
}

template <typename Type>
void ReverseIterator<Type>::indexCheck(const size_t line, const size_t offset) const
{
    if (index + offset >= size)
    {
        time_t cur_time = time(NULL);
        throw OutOfRangeException(ctime(&cur_time), __FILE__, line,
                                  typeid(*this).name(), __FUNCTION__);
    }
}
#pragma endregion ProtectedMethods

#endif
