#ifndef _CONST_REVERSE_ITERATOR_H_
#define _CONST_REVERSE_ITERATOR_H_

#include <memory>

#include "BaseIterator.h"

template <typename Type>
class Vector;

template <typename Type>
class ConstReverseIterator : public BaseIterator, public std::iterator<std::random_access_iterator_tag, Type>
{
    friend class Vector<Type>;

public:
    ConstReverseIterator(const Vector<Type> &vector) noexcept;
    ConstReverseIterator(const ConstReverseIterator<Type> &iterator) noexcept;

    ~ConstReverseIterator();

    operator bool() const;
    ConstReverseIterator<Type> &operator=(const ConstReverseIterator<Type> &iterator) noexcept;

    const Type &operator*() const;
    const Type *operator->() const;
    const Type &operator[](const size_t offset) const;

    template <typename OtherType>
    ConstReverseIterator<Type> operator+(const OtherType diff) const;
    template <typename OtherType>
    ConstReverseIterator<Type> operator-(const OtherType diff) const;

    template <typename OtherType>
    ConstReverseIterator<Type> &operator+=(const OtherType diff);
    template <typename OtherType>
    ConstReverseIterator<Type> &operator-=(const OtherType diff);

    ConstReverseIterator<Type> &operator++();
    ConstReverseIterator<Type> operator++(int);

    ConstReverseIterator<Type> &operator--();
    ConstReverseIterator<Type> operator--(int);

    bool operator==(const ConstReverseIterator<Type> &iterator) const;
    bool operator!=(const ConstReverseIterator<Type> &iterator) const;

    bool operator>(const ConstReverseIterator<Type> &iterator) const;
    bool operator>=(const ConstReverseIterator<Type> &iterator) const;

    bool operator<(const ConstReverseIterator<Type> &iterator) const;
    bool operator<=(const ConstReverseIterator<Type> &iterator) const;

protected:
    Type *getCurPtr() const;
    void expiredCheck(const size_t line) const;
    void indexCheck(const size_t line, const size_t offset = 0) const;

private:
    std::weak_ptr<Type[]> ptr; // указатель без права собственности на объект
};

#include "ConstReverseIterator.hpp"

#endif
