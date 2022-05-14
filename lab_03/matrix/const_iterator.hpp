#ifndef CONST_ITERATOR_HPP
#define CONST_ITERATOR_HPP

#include "const_iterator.h"

template<typename T>
void ConstMatrixIterator<T>::check_index() {
    if (_index >= _rows * _columns)
        throw IndexError(__FILE__, __LINE__, "wrong index MatrixIterator");
}

template<typename T>
void ConstMatrixIterator<T>::check_ptr() {
    if (!is_valid())
        throw PtrError(__FILE__, __LINE__, "wrong ptr MatrixIterator");
}

template<typename T>
ConstMatrixIterator<T>::ConstMatrixIterator() {
    ptr = nullptr;
    _columns = 0;
    _rows = 0;
    _index = 0;
}

template<typename T>
ConstMatrixIterator<T>::ConstMatrixIterator(const Matrix<T> &matrix, size_t index) {
    ptr = matrix.data;
    _index = index;
    _rows = matrix.rows;
    _columns = matrix.columns;
}

template<typename T>
ConstMatrixIterator<T>::~ConstMatrixIterator() {
    ptr.reset();
}

template<typename T>
bool ConstMatrixIterator<T>::is_valid() const {
    return !ptr.expired();
}

template<typename T>
bool ConstMatrixIterator<T>::is_end() const {
    return _index == _rows * _columns;
}

template<typename T>
ConstMatrixIterator<T>::operator bool() const {
    return ptr.expired();
}

template<typename T>
const T &ConstMatrixIterator<T>::operator*() const {
    check_index();
    check_ptr();

    std::shared_ptr<T[]> data_ptr = ptr.lock();
    return data_ptr[_index];
}

template<typename T>
const T *ConstMatrixIterator<T>::operator->() const {
    return &(operator*());
}

template<typename T>
const ConstMatrixIterator<T> &ConstMatrixIterator<T>::operator++() const {
    if (_index < _rows * _columns)
        ++_index;
    return *this;
}

template<typename T>
const ConstMatrixIterator<T> ConstMatrixIterator<T>::operator++(int) const {
    MatrixIterator<T> it(*this);
    ++(*this);
    return it;
}

template<typename T>
const ConstMatrixIterator<T> &ConstMatrixIterator<T>::operator--() const {
    if (_index > 0)
        --_index;
    return *this;
}

template<typename T>
const ConstMatrixIterator<T> ConstMatrixIterator<T>::operator--(int) {
    MatrixIterator<T> it(*this);
    --(*this);
    return it;
}

template<typename T>
bool ConstMatrixIterator<T>::operator!=(const ConstMatrixIterator &other) const {
    return _index != other._index;
}

template<typename T>
bool ConstMatrixIterator<T>::operator==(const ConstMatrixIterator &other) const {
    return _index == other._index;
}

template<typename T>
bool ConstMatrixIterator<T>::operator<(const ConstMatrixIterator &other) const {
    return _index < other._index;
}

template<typename T>
ConstMatrixIterator<T> &ConstMatrixIterator<T>::operator=(const ConstMatrixIterator<T> &it) {
    ptr = it.ptr;
    _index = it._index;
    _rows = it._rows;
    _columns = it._columns;

    return *this;
}


#endif //CONST_ITERATOR_HPP
