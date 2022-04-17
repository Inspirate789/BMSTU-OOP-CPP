#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <memory>

#include "BaseContainer.h"
#include "Iterator.h"
#include "ConstIterator.h"

template <typename Type>
class Vector: public BaseContainer
{
    friend class Iterator<Type>;
    friend class ConstIterator<Type>;

private:
    std::shared_ptr<Type[]> data = nullptr;
protected:
    void allocate(size_t size_value);
    void zeroSizeCheck (const size_t line);
    void indexCheck(const size_t index, const size_t line) const;
    template <typename OtherType>
    void sizesCheck(const Vector<OtherType> &vector, const size_t line) const;
    template <typename OtherType>
    void vector3DSizesCheck(const Vector<OtherType> &vector, const size_t line) const; // vectorProdSizesCheck
    template <typename OtherType>
    void divisionByZeroCheck(const OtherType &num, const size_t line) const;
public: // Добавить pragma region?
    Vector() = default;
    explicit Vector(size_t size_value);
    explicit Vector(const Vector<Type> &vector);
    Vector(size_t sizeValue, const Type &filler);
    Vector(size_t sizeValue, const Type *arr);
    Vector(std::initializer_list<Type> elements);
    Vector(Vector<Type> &&vector) noexcept;
    template <typename IterType>
    Vector(IterType begin, IterType end);

    ~Vector() override = default;

    Iterator<Type> begin() noexcept;
    Iterator<Type> end() noexcept;
    ConstIterator<Type> begin() const noexcept;
    ConstIterator<Type> end() const noexcept;
    ConstIterator<Type> cbegin() const noexcept;
    ConstIterator<Type> cend() const noexcept;

    Vector<Type> &operator=(std::initializer_list<Type> elements);
    Vector<Type> &operator=(const Vector<Type> &vector);
    Vector<Type> &operator=(Vector<Type> &&vector) noexcept;

    bool operator==(const Vector<Type> &vector) const;
    // bool isEqual(const Vector<Type> &vector) const;
    bool operator!=(const Vector<Type> &vector) const;
    // bool isNotEqual(const Vector<Type> &vector) const;

    Type &operator[](const size_t index);
    const Type &operator[](const size_t index) const;

    template <typename OutType>
    OutType length() const;

    template <typename OutType>
    Vector<OutType> getUnit() const;
};

#endif
