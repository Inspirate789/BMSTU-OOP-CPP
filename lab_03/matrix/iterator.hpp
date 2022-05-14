#include "iterator.h"

template<typename T>
MatrixIterator<T>::MatrixIterator(const Matrix<T> &matrix, size_t index) {
    ptr = matrix.data;
    _index = index;
    _rows = matrix.get_rows();
    _columns = matrix.get_columns();
}

template<typename T>
T &MatrixIterator<T>::operator*() {
    check_index();
    check_ptr();

    std::shared_ptr<T[]> data_ptr = ptr.lock();
    return data_ptr[_index];
}

template<typename T>
const T &MatrixIterator<T>::operator*() const {
    check_index();
    check_ptr();

    std::shared_ptr<T[]> data_ptr = ptr.lock();
    return data_ptr[_index];
}

template<typename T>
T *MatrixIterator<T>::operator->() {
    return &(operator*());
}

template<typename T>
const T *MatrixIterator<T>::operator->() const {
    return &(operator*());
}

template<typename T>
MatrixIterator<T> &MatrixIterator<T>::operator++() {
    if (_index < _rows * _columns)
        ++_index;
    return *this;
}

template<typename T>
const MatrixIterator<T> MatrixIterator<T>::operator++(int) {
    MatrixIterator<T> it(*this);
    ++(*this);
    return it;
}

template<typename T>
MatrixIterator<T> &MatrixIterator<T>::operator--() {
    if (_index > 0)
        --_index;
    return *this;
}

template<typename T>
const MatrixIterator<T> MatrixIterator<T>::operator--(int) {
    MatrixIterator<T> it(*this);
    --(*this);
    return it;
}

template<typename T>
MatrixIterator<T>::MatrixIterator() {
    ptr.lock() = nullptr;
    _rows = 0;
    _columns = 0;
    _index = 0;
}

template<typename T>
bool MatrixIterator<T>::operator!=(const MatrixIterator &other) const {
    return _index != other._index;
}

template<typename T>
bool MatrixIterator<T>::operator==(const MatrixIterator &other) const {
    return _index == other._index;
}

template<typename T>
bool MatrixIterator<T>::operator<(const MatrixIterator &other) const {
    return _index < other._index;
}

template<typename T>
MatrixIterator<T> &MatrixIterator<T>::operator=(const MatrixIterator<T> &it) {
    ptr = it.ptr;
    _index = it._index;
    _rows = it._rows;
    _columns = it._columns;

    return *this;
}

template<typename T>
MatrixIterator<T>::operator bool() const {
    return ptr.expired();
}

template<typename T>
bool MatrixIterator<T>::is_end() const {
    return _index == _rows * _columns;
}

template<typename T>
bool MatrixIterator<T>::is_valid() const {
    return !ptr.expired();
}

template<typename T>
MatrixIterator<T>::~MatrixIterator() {
    ptr.reset();
}

template<typename T>
void MatrixIterator<T>::check_index() {
    if (_index >= _rows * _columns)
        throw IndexError(__FILE__, __LINE__, "wrong index MatrixIterator");
}

template<typename T>
void MatrixIterator<T>::check_ptr() {
    if (!is_valid())
        throw PtrError(__FILE__, __LINE__, "wrong ptr MatrixIterator");
}
