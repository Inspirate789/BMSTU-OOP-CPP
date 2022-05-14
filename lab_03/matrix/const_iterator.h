#ifndef CONST_ITERATOR_H
#define CONST_ITERATOR_H

#include "memory"
#include "iterator_exceptions.h"

template <typename T>
class Matrix;

template <typename T>
class ConstMatrixIterator: public std::iterator<std::bidirectional_iterator_tag, T> {
private:
    std::weak_ptr<T[]> ptr;
    mutable size_t _index;
    size_t _rows;
    size_t _columns;

    void check_index();
    void check_ptr();
public:
    ConstMatrixIterator();
    explicit ConstMatrixIterator(const Matrix<T> &matrix, size_t index = 0);
    ConstMatrixIterator(const ConstMatrixIterator &it) = default;

    const T& operator*() const;

    const T* operator->() const;

    explicit operator bool() const;

    const ConstMatrixIterator<T>& operator++() const;
    const ConstMatrixIterator<T> operator++(int) const;

    const ConstMatrixIterator<T>& operator--() const;
    const ConstMatrixIterator<T> operator--(int);

    bool operator!=(ConstMatrixIterator const& other) const;
    bool operator==(ConstMatrixIterator const& other) const;
    bool operator<(ConstMatrixIterator const& other) const;

    ConstMatrixIterator<T> &operator=(const ConstMatrixIterator<T> &it);

    bool is_end() const;
    bool is_valid() const;

    ~ConstMatrixIterator();
};

#include "const_iterator.hpp"

#endif //CONST_ITERATOR_H
