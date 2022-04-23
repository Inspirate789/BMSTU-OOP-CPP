#ifndef _REVERSE_ITERATOR_H_
#define _REVERSE_ITERATOR_H_

#include <memory>

#include "BaseIterator.h"

template <typename Type>
class Vector;

template <typename Type>
class ReverseIterator : public BaseIterator, public std::iterator<std::random_access_iterator_tag, Type>
{
    friend class Vector<Type>;

public:
    ReverseIterator(const Vector<Type> &vector) noexcept;
    ReverseIterator(const ReverseIterator<Type> &iterator) noexcept;

    ~ReverseIterator();

    operator bool() const;
    ReverseIterator<Type> &operator=(const ReverseIterator<Type> &iterator) noexcept;

    Type &operator*();
    const Type &operator*() const;

    Type *operator->();
    const Type *operator->() const;

    Type &operator[](const size_t offset);
    const Type &operator[](const size_t offset) const;

    template <typename OtherType>
    ReverseIterator<Type> operator+(const OtherType diff) const;
    template <typename OtherType>
    ReverseIterator<Type> operator-(const OtherType diff) const;

    template <typename OtherType>
    ReverseIterator<Type> &operator+=(const OtherType diff);
    template <typename OtherType>
    ReverseIterator<Type> &operator-=(const OtherType diff);

    ReverseIterator<Type> &operator++();
    ReverseIterator<Type> operator++(int);

    ReverseIterator<Type> &operator--();
    ReverseIterator<Type> operator--(int);

    bool operator==(const ReverseIterator<Type> &iterator) const;
    bool operator!=(const ReverseIterator<Type> &iterator) const;

    bool operator>(const ReverseIterator<Type> &iterator) const;
    bool operator>=(const ReverseIterator<Type> &iterator) const;

    bool operator<(const ReverseIterator<Type> &iterator) const;
    bool operator<=(const ReverseIterator<Type> &iterator) const;

protected:
    Type *getCurPtr() const;
    void expiredCheck(const size_t line) const;
    void indexCheck(const size_t line, const size_t offset = 0) const;

private:
    std::weak_ptr<Type[]> ptr; // указатель без права собственности на объект
};

#include "ReverseIterator.hpp"

#endif
