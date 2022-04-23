#ifndef _CONST_ITERATOR_H_
#define _CONST_ITERATOR_H_

#include <memory>

#include "BaseIterator.h"

template <typename Type>
class Vector;

template <typename Type>
class ConstIterator : public BaseIterator, public std::iterator<std::random_access_iterator_tag, Type>
{
    friend class Vector<Type>;

public:
    ConstIterator(const Vector<Type> &vector) noexcept;
    ConstIterator(const ConstIterator<Type> &iterator) noexcept;

    ~ConstIterator();

    operator bool() const;
    ConstIterator<Type> &operator=(const ConstIterator<Type> &iterator) noexcept;

    const Type &operator*() const;
    const Type *operator->() const;
    const Type &operator[](const size_t offset) const;

    template <typename OtherType>
    ConstIterator<Type> operator+(const OtherType diff) const;
    template <typename OtherType>
    ConstIterator<Type> operator-(const OtherType diff) const;

    template <typename OtherType>
    ConstIterator<Type> &operator+=(const OtherType diff);
    template <typename OtherType>
    ConstIterator<Type> &operator-=(const OtherType diff);

    ConstIterator<Type> &operator++();
    ConstIterator<Type> operator++(int);

    ConstIterator<Type> &operator--();
    ConstIterator<Type> operator--(int);

    bool operator==(const ConstIterator<Type> &iterator) const;
    bool operator!=(const ConstIterator<Type> &iterator) const;

    bool operator>(const ConstIterator<Type> &iterator) const;
    bool operator>=(const ConstIterator<Type> &iterator) const;

    bool operator<(const ConstIterator<Type> &iterator) const;
    bool operator<=(const ConstIterator<Type> &iterator) const;

protected:
    Type *getCurPtr() const;
    void expiredCheck(const size_t line) const;
    void indexCheck(const size_t line, const size_t offset = 0) const;

private:
    std::weak_ptr<Type[]> ptr; // указатель без права собственности на объект
};

#include "ConstIterator.hpp"

#endif
