#ifndef LAB2_ITERATOR_H
#define LAB2_ITERATOR_H

#include "memory"
#include "iterator_exceptions.h"

template <typename T>
class Matrix;

template <typename T>
class MatrixIterator: public std::iterator<std::bidirectional_iterator_tag, T> {
private:
    std::weak_ptr<T[]> ptr;
    size_t _index;
    size_t _rows;
    size_t _columns;

    void check_index();
    void check_ptr();
public:
    MatrixIterator();
    explicit MatrixIterator(const Matrix<T> &matrix, size_t index = 0);
    MatrixIterator(const MatrixIterator &it) = default;

    T& operator*();
    const T& operator*() const;

    T* operator->();
    const T* operator->() const;

    MatrixIterator<T>& operator++();
    const MatrixIterator<T> operator++(int);

    MatrixIterator<T>& operator--();
    const MatrixIterator<T> operator--(int);

    bool operator!=(MatrixIterator const& other) const;
    bool operator==(MatrixIterator const& other) const;
    bool operator<(MatrixIterator const& other) const;

    MatrixIterator<T> &operator=(const MatrixIterator<T> &it);

    explicit operator bool() const;
    bool is_end() const;
    bool is_valid() const;

    ~MatrixIterator();
};

#include "iterator.hpp"

#endif //LAB2_ITERATOR_H
