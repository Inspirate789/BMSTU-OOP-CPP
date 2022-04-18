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

    ~ConstIterator() = default;

    operator bool() const;
    ConstIterator<Type> &operator=(const ConstIterator<Type> &iterator) noexcept;

    const Type &operator*() const;
    const Type *operator->() const;

    ConstIterator<Type> operator+(const size_t diff) const;
    ConstIterator<Type> operator-(const size_t diff) const;

    ConstIterator<Type> &operator+=(const size_t diff);
    ConstIterator<Type> &operator-=(const size_t diff);

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
    void indexCheck(const size_t line) const;

private:
    std::weak_ptr<Type[]> ptr; // указатель без права собственности на объект
};

#include "ConstIterator.hpp"

#endif
