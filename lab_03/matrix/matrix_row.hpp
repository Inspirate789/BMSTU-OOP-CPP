#ifndef MATRIX_ROW_HPP
#define MATRIX_ROW_HPP

#include "matrix.h"

template <typename T>
Matrix<T>::MatrixRow::MatrixRow()
{
    row_data = nullptr;
    row_size = 0;
}

template <typename T>
Matrix<T>::MatrixRow::MatrixRow(T *_data, size_t size)
{
    row_data = std::shared_ptr<T[]>(_data);
    row_size = size;
}

template <typename T>
T &Matrix<T>::MatrixRow::operator[](size_t index)
{
    if (index > row_size)
        throw IndexError(__FILE__, __LINE__, "Index error Matrix row class");
    return row_data[index];
}

template <typename T>
const T &Matrix<T>::MatrixRow::operator[](size_t index) const
{
    if (index > row_size)
        throw IndexError(__FILE__, __LINE__, "Index error Matrix row class");
    return row_data[index];
}

#endif // MATRIX_ROW_HPP
