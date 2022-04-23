#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <memory>

#include "BaseContainer.h"
#include "Iterator.h"
#include "ConstIterator.h"
#include "ReverseIterator.h"
#include "ConstReverseIterator.h"

template <typename Type>
class Vector : public BaseContainer
{
    friend class Iterator<Type>;
    friend class ConstIterator<Type>;
    friend class ReverseIterator<Type>;
    friend class ConstReverseIterator<Type>;

public:
    #pragma region Constructors
    Vector();
    explicit Vector(size_t size_value);
    explicit Vector(const Vector<Type> &vector);
    Vector(size_t sizeValue, const Type &filler);
    Vector(size_t sizeValue, const Type *arr);
    Vector(std::initializer_list<Type> elements);
    Vector(Vector<Type> &&vector) noexcept;
    template <typename IterType>
    Vector(IterType begin, IterType end);
    #pragma endregion Constructors

    ~Vector() override;

    #pragma region Iterators
    Iterator<Type> begin() noexcept;
    Iterator<Type> end() noexcept;
    ConstIterator<Type> begin() const noexcept;
    ConstIterator<Type> end() const noexcept;
    ConstIterator<Type> cbegin() const noexcept;
    ConstIterator<Type> cend() const noexcept;
    ReverseIterator<Type> rbegin() noexcept;
    ReverseIterator<Type> rend() noexcept;
    ConstReverseIterator<Type> rbegin() const noexcept;
    ConstReverseIterator<Type> rend() const noexcept;
    ConstReverseIterator<Type> crbegin() const noexcept;
    ConstReverseIterator<Type> crend() const noexcept;
    #pragma endregion Iterators

    #pragma region Operations
    #pragma region UnaryOperations
    Vector<Type> neg() const;
    Vector<Type> operator-() const;
    
    template <typename OutType>
    OutType length() const;

    bool isZero() const;
    bool isUnit() const;

    template <typename OutType>
    Vector<OutType> getUnit() const;
    #pragma endregion UnaryOperations

    #pragma region Assignments
    Vector<Type> &operator=(std::initializer_list<Type> elements);
    Vector<Type> &operator=(const Vector<Type> &vector);
    Vector<Type> &operator=(Vector<Type> &&vector) noexcept;
    #pragma endregion Assignments

    #pragma region Comparsions
    template <typename OtherType>
    bool isEqual(const Vector<OtherType> &vector) const;
    template <typename OtherType>
    bool isNotEqual(const Vector<OtherType> &vector) const;
    template <typename OtherType>
    bool operator==(const Vector<OtherType> &vector) const;
    template <typename OtherType>
    bool operator!=(const Vector<OtherType> &vector) const;
    #pragma endregion Comparsions

    #pragma region Indexations
    Type &operator[](const size_t index);
    const Type &operator[](const size_t index) const;
    #pragma endregion Indexations

    #pragma region Sum
    Vector<Type> VecSum(const Vector<Type> &vector) const;
    Vector<Type> operator+(const Vector<Type> &vector) const;
    Vector<Type> ByNumSum(const Type &num) const;
    Vector<Type> operator+(const Type &num) const;

    Vector<Type> &EqVecSum(const Vector<Type> &vector);
    Vector<Type> &operator+=(const Vector<Type> &vector);
    Vector<Type> &EqByNumSum(const Type &num);
    Vector<Type> &operator+=(const Type &num);
    #pragma endregion Sum

    #pragma region Diff
    Vector<Type> VecDiff(const Vector<Type> &vector) const;
    Vector<Type> operator-(const Vector<Type> &vector) const;
    Vector<Type> ByNumDiff(const Type &num) const;
    Vector<Type> operator-(const Type &num) const;

    Vector<Type> &EqVecDiff(const Vector<Type> &vector);
    Vector<Type> &operator-=(const Vector<Type> &vector);
    Vector<Type> &EqByNumDiff(const Type &num);
    Vector<Type> &operator-=(const Type &num);
    #pragma endregion Diff
    
    #pragma region Mul
    Vector<Type> ByNumMul(const Type &num) const;
    Vector<Type> operator*(const Type &num) const;

    Vector<Type> &EqByNumMul(const Type &num);
    Vector<Type> &operator*=(const Type &num);
    #pragma endregion Mul

    #pragma region Div
    Vector<Type> ByNumDiv(const Type &num) const;
    Vector<Type> operator/(const Type &num) const;

    Vector<Type> &EqByNumDiv(const Type &num);
    Vector<Type> &operator/=(const Type &num);
    #pragma endregion Div

    #pragma region ScalarProd
    Type scalarProd(const Vector<Type> &vector) const;
    Type operator&(const Vector<Type> &vector) const;
    #pragma endregion ScalarProd

    #pragma region VectorProd
    Vector<Type> vectorProd(const Vector<Type> &vector) const;
    Vector<Type> operator^(const Vector<Type> &vector) const;

    Vector<Type> &eqVectorProd(const Vector<Type> &vector);
    Vector<Type> &operator^=(const Vector<Type> &vector);
    #pragma endregion VectorProd

    #pragma region OtherBinaryOperations
    double angle(const Vector<Type> &vector) const;
    template <typename OtherType>
    double angle(const Vector<OtherType> &vector) const;

    bool isCollinear(const Vector<Type> &vector) const;
    template <typename OtherType>
    bool isCollinear(const Vector<OtherType> &vector) const;

    bool isOrthogonal(const Vector<Type> &vector) const;
    template <typename OtherType>
    bool isOrthogonal(const Vector<OtherType> &vector) const;
    #pragma endregion OtherBinaryOperations
    #pragma endregion Operations

protected:
    void allocate(size_t size_value);

    #pragma region Checks
    void zeroSizeCheck(const size_t line) const;
    void indexCheck(const size_t index, const size_t line) const;
    template <typename OtherType>
    void sizesCheck(const Vector<OtherType> &vector, const size_t line) const;
    template <typename OtherType>
    void divisionByZeroCheck(const OtherType &num, const size_t line) const;
    #pragma endregion Checks

private:
    std::shared_ptr<Type[]> data = nullptr;
};

#include "Vector.hpp"

#endif
