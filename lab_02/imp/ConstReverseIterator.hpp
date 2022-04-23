#ifndef _CONST_REVERSE_ITERATOR_HPP_
#define _CONST_REVERSE_ITERATOR_HPP_

#include "ConstReverseIterator.h"
#include "Exceptions.h"

#pragma region Constructors
template <typename Type>
ConstReverseIterator<Type>::ConstReverseIterator(const Vector<Type> &vector) noexcept
{
    ptr = vector.data;
    size = vector.size;
    index = 0;
}

template <typename Type>
ConstReverseIterator<Type>::ConstReverseIterator(const ConstReverseIterator<Type> &iterator) noexcept: BaseIterator(iterator)
{
    ptr = iterator.ptr;
}
#pragma endregion Constructors

template <typename Type>
ConstReverseIterator<Type>::~ConstReverseIterator() = default;

#pragma region Operators
template <typename Type>
ConstReverseIterator<Type>::operator bool() const
{
    expiredCheck(__LINE__);

    return size && index < size;
}

template <typename Type>
ConstReverseIterator<Type> &ConstReverseIterator<Type>::operator=(const ConstReverseIterator<Type> &iterator) noexcept
{
    ptr.reset(iterator.ptr);
    size = iterator.size;
    index = iterator.index;
}

template <typename Type>
const Type &ConstReverseIterator<Type>::operator*() const
{
    expiredCheck(__LINE__);
    indexCheck(__LINE__);

    return *getCurPtr();
}

template <typename Type>
const Type *ConstReverseIterator<Type>::operator->() const
{
    expiredCheck(__LINE__);
    indexCheck(__LINE__);

    return getCurPtr();
}

template <typename Type>
const Type &ConstReverseIterator<Type>::operator[](const size_t offset) const
{
    expiredCheck(__LINE__);
    indexCheck(__LINE__, offset);

    return *(getCurPtr() + offset);
}

template <typename Type>
template <typename OtherType>
ConstReverseIterator<Type> ConstReverseIterator<Type>::operator+(const OtherType diff) const
{
    expiredCheck(__LINE__);

    ConstReverseIterator<Type> res(*this);
    res.index -= diff;
    return res;
}

template <typename Type>
template <typename OtherType>
ConstReverseIterator<Type> ConstReverseIterator<Type>::operator-(const OtherType diff) const
{
    expiredCheck(__LINE__);

    ConstReverseIterator<Type> res(*this);
    res.index += diff;
    return res;
}

template <typename Type>
template <typename OtherType>
ConstReverseIterator<Type> &ConstReverseIterator<Type>::operator+=(const OtherType diff)
{
    expiredCheck(__LINE__);

    index -= diff;
    return this;
}

template <typename Type>
template <typename OtherType>
ConstReverseIterator<Type> &ConstReverseIterator<Type>::operator-=(const OtherType diff)
{
    expiredCheck(__LINE__);

    index += diff;
    return this;
}

template <typename Type>
ConstReverseIterator<Type> & ConstReverseIterator<Type>::operator++()
{
    expiredCheck(__LINE__);

    --index;
    return *this;
}

template <typename Type>
ConstReverseIterator<Type> ConstReverseIterator<Type>::operator++(int)
{
    expiredCheck(__LINE__);

    ConstReverseIterator<Type> tmp(*this);
    --(*this);
    return tmp;
}

template <typename Type>
ConstReverseIterator<Type> & ConstReverseIterator<Type>::operator--()
{
    expiredCheck(__LINE__);

    ++index;
    return *this;
}

template <typename Type>
ConstReverseIterator<Type> ConstReverseIterator<Type>::operator--(int)
{
    expiredCheck(__LINE__);

    ConstReverseIterator<Type> tmp(*this);
    ++(*this);
    return tmp;
}

template <typename Type>
bool ConstReverseIterator<Type>::operator==(const ConstReverseIterator<Type> &iterator) const
{
    expiredCheck(__LINE__);
    iterator.expiredCheck(__LINE__);

    return getCurPtr() == iterator.getCurPtr();
}

template <typename Type>
bool ConstReverseIterator<Type>::operator!=(const ConstReverseIterator<Type> &iterator) const
{
    expiredCheck(__LINE__);
    iterator.expiredCheck(__LINE__);

    return getCurPtr() != iterator.getCurPtr();
}

template <typename Type>
bool ConstReverseIterator<Type>::operator>(const ConstReverseIterator<Type> &iterator) const
{
    expiredCheck(__LINE__);
    iterator.expiredCheck(__LINE__);

    return getCurPtr() < iterator.getCurPtr();
}

template <typename Type>
bool ConstReverseIterator<Type>::operator>=(const ConstReverseIterator<Type> &iterator) const
{
    expiredCheck(__LINE__);
    iterator.expiredCheck(__LINE__);

    return getCurPtr() <= iterator.getCurPtr();
}

template <typename Type>
bool ConstReverseIterator<Type>::operator<(const ConstReverseIterator<Type> &iterator) const
{
    expiredCheck(__LINE__);
    iterator.expiredCheck(__LINE__);

    return getCurPtr() > iterator.getCurPtr();
}

template <typename Type>
bool ConstReverseIterator<Type>::operator<=(const ConstReverseIterator<Type> &iterator) const
{
    expiredCheck(__LINE__);
    iterator.expiredCheck(__LINE__);

    return getCurPtr() >= iterator.getCurPtr();
}
#pragma endregion Operators

#pragma region ProtectedMethods
template <typename Type>
Type *ConstReverseIterator<Type>::getCurPtr() const
{
    std::shared_ptr<Type[]> tmp = ptr.lock();
    return tmp.get() + index;
}

template <typename Type>
void ConstReverseIterator<Type>::expiredCheck(const size_t line) const
{
    if (ptr.expired())
    {
        time_t cur_time = time(NULL);
        throw ExpiredException(ctime(&cur_time), __FILE__, line,
                               typeid(*this).name(), __FUNCTION__);
    }
}

template <typename Type>
void ConstReverseIterator<Type>::indexCheck(const size_t line, const size_t offset) const
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
