#include "matrix.h"

template <typename T>
MatrixIterator<T> Matrix<T>::begin()
{
    return MatrixIterator<T>(*this, 0);
}

template <typename T>
MatrixIterator<T> Matrix<T>::end()
{
    return MatrixIterator<T>(*this, *columns * (*rows));
}

template <typename T>
MatrixIterator<T> Matrix<T>::begin() const
{
    return MatrixIterator<T>(*this, 0);
}

template <typename T>
MatrixIterator<T> Matrix<T>::end() const
{
    return MatrixIterator<T>(*this, *columns * *rows);
}

template <typename T>
ConstMatrixIterator<T> Matrix<T>::cbegin() const
{
    return ConstMatrixIterator<T>(*this, 0);
}

template <typename T>
ConstMatrixIterator<T> Matrix<T>::cend() const
{
    return ConstMatrixIterator<T>(*this, *columns * *rows);
}

template <typename T>
void Matrix<T>::fill(const T &value)
{
    for (auto &el : *this)
        el = value;
}

template <typename T>
void Matrix<T>::fill(MatrixIterator<T> start)
{
    for (auto &el : *this)
    {
        el = *start;
        ++start;
    }
}

