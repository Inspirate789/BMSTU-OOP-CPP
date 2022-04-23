#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_

#include "Iterator.h"
#include "Exceptions.h"

#pragma region Constructors
template <typename Type>
Iterator<Type>::Iterator(const Vector<Type> &vector) noexcept: BaseIterator()
{
    ptr = vector.data;
    size = vector.size;
}

template <typename Type>
Iterator<Type>::Iterator(const Iterator<Type> &iterator) noexcept: BaseIterator(iterator)
{
    ptr = iterator.ptr;
}
#pragma endregion Constructors

template <typename Type>
Iterator<Type>::~Iterator() = default;

#pragma region Operators
template <typename Type>
Iterator<Type>::operator bool() const
{
    expiredCheck(__LINE__);

    return size && index < size;
}

template <typename Type>
Iterator<Type> &Iterator<Type>::operator=(const Iterator<Type> &iterator) noexcept
{
    ptr.reset(iterator.ptr);
    size = iterator.size;
    index = iterator.index;
}

template <typename Type>
Type &Iterator<Type>::operator*()
{
    expiredCheck(__LINE__);
    indexCheck(__LINE__);

    return *getCurPtr();
}

template <typename Type>
const Type &Iterator<Type>::operator*() const
{
    expiredCheck(__LINE__);
    indexCheck(__LINE__);

    return *getCurPtr();
}

template <typename Type>
Type *Iterator<Type>::operator->()
{
    expiredCheck(__LINE__);
    indexCheck(__LINE__);

    return getCurPtr();
}

template <typename Type>
const Type *Iterator<Type>::operator->() const
{
    expiredCheck(__LINE__);
    indexCheck(__LINE__);

    return getCurPtr();
}

template <typename Type>
Type &Iterator<Type>::operator[](const size_t offset)
{
    expiredCheck(__LINE__);
    indexCheck(__LINE__, offset);

    return *(getCurPtr() + offset);
}

template <typename Type>
const Type &Iterator<Type>::operator[](const size_t offset) const
{
    expiredCheck(__LINE__);
    indexCheck(__LINE__, offset);

    return *(getCurPtr() + offset);
}

template <typename Type>
template <typename OtherType>
Iterator<Type> Iterator<Type>::operator+(const OtherType diff) const
{
    expiredCheck(__LINE__);

    Iterator<Type> res(*this);
    res.index += diff;
    return res;
}

template <typename Type>
template <typename OtherType>
Iterator<Type> Iterator<Type>::operator-(const OtherType diff) const
{
    expiredCheck(__LINE__);

    Iterator<Type> res(*this);
    res.index -= diff;
    return res;
}

template <typename Type>
template <typename OtherType>
Iterator<Type> &Iterator<Type>::operator+=(const OtherType diff)
{
    expiredCheck(__LINE__);

    index += diff;
    return this;
}

template <typename Type>
template <typename OtherType>
Iterator<Type> &Iterator<Type>::operator-=(const OtherType diff)
{
    expiredCheck(__LINE__);

    index -= diff;
    return this;
}

template <typename Type>
Iterator<Type> & Iterator<Type>::operator++()
{
    expiredCheck(__LINE__);

    ++index;
    return *this;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator++(int)
{
    expiredCheck(__LINE__);

    Iterator<Type> tmp(*this);
    ++(*this);
    return tmp;
}

template <typename Type>
Iterator<Type> & Iterator<Type>::operator--()
{
    expiredCheck(__LINE__);

    --index;
    return *this;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator--(int)
{
    expiredCheck(__LINE__);

    Iterator<Type> tmp(*this);
    --(*this);
    return tmp;
}

template <typename Type>
bool Iterator<Type>::operator==(const Iterator<Type> &iterator) const
{
    expiredCheck(__LINE__);
    iterator.expiredCheck(__LINE__);

    return getCurPtr() == iterator.getCurPtr();
}

template <typename Type>
bool Iterator<Type>::operator!=(const Iterator<Type> &iterator) const
{
    expiredCheck(__LINE__);
    iterator.expiredCheck(__LINE__);

    return getCurPtr() != iterator.getCurPtr();
}

template <typename Type>
bool Iterator<Type>::operator>(const Iterator<Type> &iterator) const
{
    expiredCheck(__LINE__);
    iterator.expiredCheck(__LINE__);

    return getCurPtr() > iterator.getCurPtr();
}

template <typename Type>
bool Iterator<Type>::operator>=(const Iterator<Type> &iterator) const
{
    expiredCheck(__LINE__);
    iterator.expiredCheck(__LINE__);

    return getCurPtr() >= iterator.getCurPtr();
}

template <typename Type>
bool Iterator<Type>::operator<(const Iterator<Type> &iterator) const
{
    expiredCheck(__LINE__);
    iterator.expiredCheck(__LINE__);

    return getCurPtr() < iterator.getCurPtr();
}

template <typename Type>
bool Iterator<Type>::operator<=(const Iterator<Type> &iterator) const
{
    expiredCheck(__LINE__);
    iterator.expiredCheck(__LINE__);

    return getCurPtr() <= iterator.getCurPtr();
}
#pragma endregion Operators

#pragma region ProtectedMethods
template <typename Type>
Type *Iterator<Type>::getCurPtr() const
{
    std::shared_ptr<Type[]> tmp = ptr.lock();
    return tmp.get() + index;
}

template <typename Type>
void Iterator<Type>::expiredCheck(const size_t line) const
{
    if (ptr.expired())
    {
        time_t cur_time = time(NULL);
        throw ExpiredException(ctime(&cur_time), __FILE__, line,
                               typeid(*this).name(), __FUNCTION__);
    }
}

template <typename Type>
void Iterator<Type>::indexCheck(const size_t line, const size_t offset) const
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
