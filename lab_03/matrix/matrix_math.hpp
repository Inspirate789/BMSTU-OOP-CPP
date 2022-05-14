#include "matrix.h"
template <typename T>
void exclude_copy(Matrix<T> &dst, const Matrix<T> &src, size_t ex_row, size_t ex_col)
{
    if (dst.get_rows() != src.get_rows() - 1 || dst.get_columns() != src.get_columns() - 1)
    {
        throw CopyError(__FILE__, __LINE__, "bad sizes when exclude_copy");
    }

    size_t row_index, col_index;
    for (size_t i = 0; i < src.get_rows() - 1; ++i)
        for (size_t j = 0; j < src.get_columns() - 1; ++j)
        {
            row_index = i >= ex_row ? i + 1 : i;
            col_index = j >= ex_col ? j + 1 : j;
            dst[i * src.get_columns() + j] = src[row_index * src.get_columns() + col_index];
        }
}

template <typename T>
bool Matrix<T>::is_square() const
{
    return *rows == *columns;
}

template <typename T>
Matrix<T> Matrix<T>::transpose()
{
    Matrix<T> newMatrix(*this);
    std::swap(newMatrix.rows, newMatrix.columns);

    for (size_t i = 0; i < *rows; ++i)
        for (size_t j = 0; j < *columns; ++j)
            newMatrix[j][i] = (*this)(i, j);


    return newMatrix;
}

template <typename T>
T Matrix<T>::determinant() const
{
    if (!is_square())
        throw DetError(__FILE__, __LINE__, "matrix must bu square to count det");

    if (get_rows() == 2)
        return data[0] * data[3] - data[2] * data[1];
    if (get_rows() == 1)
        return data[0];

    Matrix<T> tmp(get_rows() - 1, get_columns() - 1);
    T res = {};
    for (size_t i = 0; i < get_rows(); ++i)
    {
        exclude_copy(tmp, *this, 0, i);
        T minor = tmp.determinant();
        if (i % 2 == 1)
            minor = -minor;
        res += minor * data[i];
    }

    return res;
}

template <typename T>
Matrix<T> Matrix<T>::inverse()
{
    if (!is_square())
        throw DetError(__FILE__, __LINE__, "Only square matrix can be inversed ");

    T det = determinant();

    if (!det)
    {
        throw DetError(__FILE__, __LINE__, "and determinant must be != 0");
    }

    Matrix<T> res(*rows, *columns);
    Matrix<T> tmp(*rows - 1, *columns - 1);
    T value = {};

    for (size_t i = 0; i < *rows; ++i)
        for (size_t j = 0; j < *columns; ++j)
        {
            exclude_copy(tmp, *this, i, j);
            value = tmp.determinant() / det;
            if ((i + j) & 1)
                value = -value;
            res(j, i) = value;
        }

    return res;
}
