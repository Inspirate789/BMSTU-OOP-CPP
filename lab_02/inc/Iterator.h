#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include <memory>

#include "BaseIterator.h"

template <typename Type>
class Vector;

template <typename Type>
class Iterator : public BaseIterator, public std::iterator<std::random_access_iterator_tag, Type>
{
    friend class Vector<Type>;

public:
    Iterator(const Vector<Type> &vector) noexcept;
    Iterator(const Iterator<Type> &iterator) noexcept;

    ~Iterator() = default;

    operator bool() const;
    Iterator<Type> &operator=(const Iterator<Type> &iterator) noexcept;

    Type &operator*();
    const Type &operator*() const;

    Type *operator->();
    const Type *operator->() const;

    template <typename OtherType>
    Iterator<Type> operator+(const OtherType diff) const;
    template <typename OtherType>
    Iterator<Type> operator-(const OtherType diff) const;

    template <typename OtherType>
    Iterator<Type> &operator+=(const OtherType diff);
    template <typename OtherType>
    Iterator<Type> &operator-=(const OtherType diff);

    Iterator<Type> &operator++();
    Iterator<Type> operator++(int);

    Iterator<Type> &operator--();
    Iterator<Type> operator--(int);

    bool operator==(const Iterator<Type> &iterator) const;
    bool operator!=(const Iterator<Type> &iterator) const;

    bool operator>(const Iterator<Type> &iterator) const;
    bool operator>=(const Iterator<Type> &iterator) const;

    bool operator<(const Iterator<Type> &iterator) const;
    bool operator<=(const Iterator<Type> &iterator) const;

protected:
    Type *getCurPtr() const;
    void expiredCheck(const size_t line) const;
    void indexCheck(const size_t line) const;

private:
    std::weak_ptr<Type[]> ptr; // указатель без права собственности на объект
};

#include "Iterator.hpp"

#endif
