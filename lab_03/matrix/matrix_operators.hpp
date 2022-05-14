#include "matrix.h"

#include <ostream>

template<typename T>
void Matrix<T>::check_sizes_for_add(const std::shared_ptr<size_t> &_rows,
                                    const std::shared_ptr<size_t> &_columns) const {
    if (*rows != *_rows || *columns != *_columns)
        throw AddSizesError(__FILE__, __LINE__, "when sum matrix sizes must be equal");
}

template<typename T>
void Matrix<T>::check_sizes_for_mul(const std::shared_ptr<size_t>& _rows) const {
    if (*columns != *_rows)
        throw MulSizesError(__FILE__, __LINE__, "when mul matrix col_1 must be equal row_2");
}

template<typename T>
void Matrix<T>::check_index(size_t index) const {
    if (index > *rows * *columns)
        throw MatrixIndexError(__FILE__, __LINE__, "Index error");
}

template<typename T>
void Matrix<T>::check_for_zero(T &scalar) const {
    if (scalar == 0)
        throw DivZeroError(__FILE__, __LINE__, "Div by zero");
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix &matrix) {
    data = allocate_data(*matrix.rows * *matrix.columns);
    rows = matrix.rows;
    columns = matrix.columns;

    for (size_t i = 0; i < *rows * *columns; i++)
        data[i] = matrix.data[i];

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(Matrix &&matrix) noexcept {
    data = matrix.data;
    rows = matrix.rows;
    columns = matrix.columns;

    return *this;
}

template<typename T>
std::ostream &operator<<(std::ostream &stream, const Matrix<T> &matrix) {
    for (size_t i = 0; i < matrix.get_rows(); ++i) {
        for (size_t j = 0; j < matrix.get_columns(); ++j)
        {
            if (i % matrix.get_columns() == 0)
                stream << std::endl;

            stream << matrix[i][j] << ' ';
        }
    }

    return stream;
}

template<typename T>
std::istream &operator>>(std::istream &stream, Matrix<T> &matrix) {
    for (size_t i = 0; i < matrix.get_rows() * matrix.get_columns(); ++i) {
        stream >> matrix[i];
    }

    return stream;
}

template<typename T>
const typename Matrix<T>::MatrixRow Matrix<T>::operator[](size_t index) const {
    check_index(index);

    MatrixRow tmp(data.get() + index * *columns, *columns);
    return tmp;
}

template<typename T>
const T &Matrix<T>::operator()(size_t rowInd, size_t colInd) const{
    return data[rowInd * (*columns) + colInd];
}

template<typename T>
T &Matrix<T>::operator()(size_t rowInd, size_t colInd) {
    return data[rowInd * (*columns) + colInd];
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &other) const {
    check_sizes_for_add(other.rows, other.columns);

    Matrix<T> tmp(*rows, *columns);
    for (size_t i = 0; i < *rows * *columns; i++)
        tmp.data[i] = data[i] + other.data[i];

    return tmp;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix &other) const {
    check_sizes_for_add(other.rows, other.columns);

    Matrix<T> tmp(*rows, *columns);
    for (size_t i = 0; i < *rows * *columns; i++)
        tmp.data[i] = data[i] - other.data[i];

    return tmp;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &other) const {
    check_sizes_for_mul(other.rows);

    Matrix<T> tmp(*rows, *other.columns);
    for (size_t i = 0; i < *rows; i++)
        for (size_t j = 0; j < *other.columns; j++) {
            T sum = {};
            for (size_t k = 0; k < *columns; k++)
                sum += data[i * *columns + k] * other.data[k * *other.columns + j];
            tmp.data[i * *other.columns + j] = sum;
        }

    return tmp;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const T &scalar) const {
    Matrix<T> tmp(*rows, *columns);

    for (size_t i = 0; i < *rows; i++)
        for (size_t j = 0; j < *columns; j++)
            tmp.data[i * *columns + j] = data[i * *columns + j] + scalar;

    return tmp;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const T &scalar) const {
    Matrix<T> tmp(*rows, *columns);

    for (size_t i = 0; i < *rows; i++)
        for (size_t j = 0; j < *columns; j++)
            tmp.data[i * *columns + j] = data[i * *columns + j] - scalar;

    return tmp;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T &scalar) const {
    Matrix<T> tmp(*rows, *columns);

    for (size_t i = 0; i < *rows; i++)
        for (size_t j = 0; j < *columns; j++)
            tmp.data[i * *columns + j] = data[i * *columns + j] * scalar;

    return tmp;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T &scalar) const {
    check_for_zero(scalar);
    Matrix<T> tmp(*rows, *columns);

    for (size_t i = 0; i < *rows; i++)
        for (size_t j = 0; j < *columns; j++)
            tmp.data[i * *columns + j] = data[i * *columns + j] / scalar;

    return tmp;
}

template<typename T>
Matrix<T> Matrix<T>::operator-() const{
    Matrix<T> tmp(*rows, *columns);

    for (size_t i = 0; i < *rows; i++)
        for (size_t j = 0; j < *columns; j++)
            tmp.data[i * *columns + j] = -data[i * *columns + j];

    return tmp;
}

template<typename T>
bool Matrix<T>::operator==(const Matrix &other) const {
    bool flag = true;
    if (*rows != *other.rows || *columns != *other.columns)
        flag = false;

    for (size_t i = 0; flag && i < *rows * *columns; ++i)
        if (data[i] != other.data[i])
            flag = false;

    return flag;
}

template<typename T>
bool Matrix<T>::operator!=(const Matrix &other) const {
    return !(this == other);
}

template<typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix &other) {
    check_sizes_for_add(other.rows, other.columns);

    for (size_t i = 0; i < *rows * *columns; i++)
        data[i] += other.data[i];

    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix &other) {
    check_sizes_for_add(other.rows, other.columns);

    for (size_t i = 0; i < *rows * *columns; i++)
        data[i] -= other.data[i];

    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix &other) {
    check_sizes_for_mul(other.rows);

    for (size_t i = 0; i < *rows; i++)
        for (size_t j = 0; j < *other.columns; j++) {
            T sum = {};
            for (size_t k = 0; k < *columns; k++)
                sum += data[i * *columns + k] * other.data[k * *other.columns + j];
            data[i * *other.columns + j] = sum;
        }

    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator+=(const T &scalar) {
    for (size_t i = 0; i < *rows; i++)
        for (size_t j = 0; j < *columns; j++)
            data[i * *columns + j] += scalar;

    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator-=(const T &scalar) {
    for (size_t i = 0; i < *rows; i++)
        for (size_t j = 0; j < *columns; j++)
            data[i * *columns + j] -= scalar;

    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator*=(const T &scalar) {
    for (size_t i = 0; i < *rows; i++)
        for (size_t j = 0; j < *columns; j++)
            data[i * *columns + j] *= scalar;

    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator/=(const T &scalar) {
    check_for_zero(scalar);

    for (size_t i = 0; i < *rows; i++)
        for (size_t j = 0; j < *columns; j++)
            data[i * *columns + j] /= scalar;

    return *this;
}

template<typename T>
typename Matrix<T>::MatrixRow Matrix<T>::operator[](size_t index) {
    check_index(index);


    MatrixRow tmp(data.get() + index * *columns, *columns);
    return tmp;
}

template<typename T>
Matrix<T> Matrix<T>::add_matrix(const Matrix &other) const {
    return operator+(other);
}

template<typename T>
Matrix<T> Matrix<T>::sub_matrix(const Matrix &other) const {
    return operator-(other);
}

template<typename T>
Matrix<T> Matrix<T>::mul_matrix(const Matrix &other) const {
    return operator*(other);
}

template<typename T>
Matrix<T> Matrix<T>::add_elem(const T &scalar) const {
    return operator+(scalar);
}

template<typename T>
Matrix<T> Matrix<T>::sub_elem(const T &scalar) const {
    return operator-(scalar);
}

template<typename T>
Matrix<T> Matrix<T>::mul_elem(const T &scalar) const {
    return operator*(scalar);
}

template<typename T>
Matrix<T> Matrix<T>::div_elem(const T &scalar) const {
    return operator/(scalar);
}

template<typename T>
Matrix<T> &Matrix<T>::add_eq_matrix(const Matrix &other) {
    return operator+=(other);
}

template<typename T>
Matrix<T> &Matrix<T>::sub_eq_matrix(const Matrix &other) {
    return operator-=(other);
}

template<typename T>
Matrix<T> &Matrix<T>::mul_eq_matrix(const Matrix &other) {
    return operator*=(other);
}

template<typename T>
Matrix<T> &Matrix<T>::sub_eq_elem(const T &scalar) {
    return operator-=(scalar);
}

template<typename T>
Matrix<T> &Matrix<T>::mul_eq_elem(const T &scalar) {
    return operator*=(scalar);
}

template<typename T>
Matrix<T> &Matrix<T>::add_eq_elem(const T &scalar) {
    return operator+=(scalar);
}

template<typename T>
Matrix<T> &Matrix<T>::div_eq_elem(const T &scalar) {
    return operator/=(scalar);
}

template<typename T>
Matrix<T> Matrix<T>::neg() const{
    return operator-();
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const Matrix &other) const {
    Matrix<T> tmp(other);
    tmp.inverse();
    return operator *(tmp);
}

template<typename T>
Matrix<T> &Matrix<T>::operator/=(const Matrix &other) {
    Matrix<T> tmp = operator/(other);
    *this = tmp;
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::div_matrix(const Matrix &other) const {
    return operator/(other);
}

template<typename T>
Matrix<T> &Matrix<T>::div_eq_matrix(const Matrix &other) {
    return operator/=(other);
}

template<typename T>
Matrix<T> &Matrix<T>::operator=(std::initializer_list<std::initializer_list<T>> init_list) {
    size_t _rows = init_list.size();
    auto it = init_list.begin();
    size_t _cols = it->size();

    for (const auto &ilist: init_list)
        if (ilist.size() != _cols)
            throw InvalidListArgument(__FILE__, __LINE__, "Bad initializer list");

    *rows = _rows;
    *columns = _cols;
    
    size_t i = 0;
    for (const auto &ilist: init_list)
        for (const auto &elem: ilist)
        {
            data[i / _cols][i % _cols] = elem;
            ++i;
        }
    return *this;
}
