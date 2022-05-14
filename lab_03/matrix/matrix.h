#ifndef MATRIX_H
#define MATRIX_H

#include "matrix_base.h"
#include "iterator.h"
#include "matrix_exceptions.h"
#include "const_iterator.h"

template <typename T>
class Matrix: public BaseMatrix
{
public:
    class MatrixRow;
    friend MatrixIterator<T>;
    friend ConstMatrixIterator<T>;

    Matrix();
    explicit Matrix(size_t size);
    Matrix(size_t _rows, size_t _columns);
    Matrix(size_t _rows, size_t _columns, T *matrix);
    Matrix(std::initializer_list<std::initializer_list<T> > init_list);
    Matrix(Matrix &&other) noexcept;
    explicit Matrix(const Matrix &other);
    void clear() override;

    Matrix<T> &operator=(const Matrix &matrix);
    Matrix<T> &operator=(Matrix &&matrix) noexcept;
    Matrix<T> &operator=(std::initializer_list<std::initializer_list<T> > init_list);

    Matrix<T> operator+(const Matrix &other) const;
    Matrix<T> add_matrix(const Matrix &other) const;
    Matrix<T> operator+(const T &scalar) const;
    Matrix<T> add_elem(const T &scalar) const;

    Matrix<T> &operator+=(const Matrix &other);
    Matrix<T> &add_eq_matrix(const Matrix &other);
    Matrix<T> &operator+=(const T &scalar);
    Matrix<T> &add_eq_elem(const T &scalar);

    Matrix<T> operator-(const Matrix &other) const;
    Matrix<T> sub_matrix(const Matrix &other) const;
    Matrix<T> operator-(const T &scalar) const;
    Matrix<T> sub_elem(const T &scalar) const;
    Matrix<T> &operator-=(const Matrix &other);
    Matrix<T> &sub_eq_matrix(const Matrix &other);
    Matrix<T> &operator-=(const T &scalar);
    Matrix<T> &sub_eq_elem(const T &scalar);

    Matrix<T> operator*(const Matrix &other) const;
    Matrix<T> mul_matrix(const Matrix &other) const;
    Matrix<T> operator*(const T &scalar) const;
    Matrix<T> mul_elem(const T &scalar) const;
    Matrix<T> &operator*=(const Matrix &other);
    Matrix<T> &mul_eq_matrix(const Matrix &other);
    Matrix<T> &operator*=(const T &scalar);
    Matrix<T> &mul_eq_elem(const T &scalar);

    Matrix<T> operator/(const Matrix &other) const;
    Matrix<T> div_matrix(const Matrix &other) const;
    Matrix<T> operator/(const T &scalar) const;
    Matrix<T> div_elem(const T &scalar) const;
    Matrix<T> &operator/=(const Matrix &other);
    Matrix<T> &div_eq_matrix(const Matrix &other);
    Matrix<T> &operator/=(const T &scalar);
    Matrix<T> &div_eq_elem(const T &scalar);

    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    Matrix<T> operator-() const;
    Matrix<T> neg() const ;

    const MatrixRow operator[](size_t index) const;
    MatrixRow operator[](size_t index);

    const T &operator()(size_t row, size_t col) const;
    T &operator()(size_t row, size_t col);

    MatrixIterator<T> begin();
    MatrixIterator<T> end();

    MatrixIterator<T> begin() const;
    MatrixIterator<T> end() const;

    ConstMatrixIterator<T> cbegin() const;
    ConstMatrixIterator<T> cend() const;

    void fill(const T &value);
    void fill(MatrixIterator<T> start);

    bool is_square() const;
    T determinant() const;
    Matrix<T> transpose();
    Matrix<T> inverse();

    ~Matrix() = default;

    class MatrixRow {
    public:
        friend ConstMatrixIterator<T>;
        friend MatrixIterator<T>;

        MatrixRow();
        MatrixRow(T *_data, size_t size);
        T &operator[](size_t index);
        const T &operator[](size_t index) const;

    private:
        std::shared_ptr<T[]> row_data;
        size_t row_size;
    };
    
private:

    std::shared_ptr<T[]> data; 

    std::shared_ptr<T[]> allocate_data(size_t size);
    void check_sizes_for_add(const std::shared_ptr<size_t> &_rows,
                             const std::shared_ptr<size_t> &_columns) const;
    void check_sizes_for_mul(const std::shared_ptr<size_t> &rows) const;
    void check_index(size_t index) const;
    void check_for_zero(T &scalar) const;
};


#include "allocation_data.hpp"
#include "matrix_constructors.hpp"
#include "matrix_operators.hpp"
#include "matrix_iterator.hpp"
#include "matrix_math.hpp"
#include "matrix_row.hpp"


template <typename T>
Matrix<T> type_add_matrix(T &el, Matrix<T> &matrix) {
    return matrix + el;
}

template <typename T>
Matrix<T> type_mul_matrix(T &el, Matrix<T> &matrix) {
    return matrix * el;
}

template <typename T>
Matrix<T> type_div_matrix(T &el, Matrix<T> &matrix) {
    return matrix / el;
}

template <typename T>
Matrix<T> type_sub_matrix(T &el, Matrix<T> &matrix) {
    return matrix - el;
}

#endif

