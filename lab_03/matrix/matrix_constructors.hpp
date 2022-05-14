#include "matrix.h"

template <typename T>
void check_ptr(T ptr)
{
    if (!ptr)
        throw PtrError(__FILE__, __LINE__, "bad ptr");
}

template <typename T>
Matrix<T>::Matrix() : BaseMatrix()
{
    data = nullptr;
}

template <typename T>
Matrix<T>::Matrix(size_t size) : BaseMatrix(size)
{
    data = allocate_data(*rows * *columns);
}

template <typename T>
Matrix<T>::Matrix(size_t _rows, size_t _columns) : BaseMatrix(_rows, _columns)
{
    data = allocate_data(*rows * *columns);
}

template <typename T>
Matrix<T>::Matrix(Matrix &&other) noexcept : BaseMatrix(*other.rows, *other.columns)
{
    data = other.data;
}

template <typename T>
Matrix<T>::Matrix(size_t _rows, size_t _columns, T *matrix) : BaseMatrix(_rows, _columns)
{
    check_ptr(matrix);
    data = allocate_data(*rows * *columns);

    for (size_t i = 0; i < *rows * *columns; i++)
    {
        check_ptr(matrix + i);
        data[i] = matrix[i];
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix &other) : BaseMatrix(*other.rows, *other.columns)
{
    data = allocate_data(*rows * *columns);

    for (size_t i = 0; i < *rows * *columns; i++)
        data[i] = other.data[i];
}

template <typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> init_list)
{
    size_t _rows = init_list.size();
    auto it = init_list.begin();
    size_t _cols = it->size();

    for (const auto &ilist : init_list)
        if (ilist.size() != _cols)
            throw InvalidListArgument(__FILE__, __LINE__, "Bad initializer list");

    data = allocate_data(*rows * *columns);
    *rows = _rows;
    *columns = _cols;
    size_t i = 0;
    for (const auto &ilist : init_list)
        for (const auto &elem : ilist)
        {
            data[i] = elem;
            ++i;
        }
}

template <typename T>
void Matrix<T>::clear()
{
    data = nullptr;
}
