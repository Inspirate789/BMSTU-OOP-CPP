#include "matrix.h"

template <typename T>
std::shared_ptr<T[]> Matrix<T>::allocate_data(size_t size) {
    data = nullptr;
    try {
        data = std::shared_ptr<T[]>(new T[size]);
    }
    catch (std::bad_alloc &err) {
        throw MemoryError(__FILE__, __LINE__, "bad alloc data");
    }

    return data;
}
