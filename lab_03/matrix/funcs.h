#ifndef LAB2_FUNCS_H
#define LAB2_FUNCS_H

#include <memory>
#include <matrix_exceptions.h>

std::shared_ptr<size_t> allocate_size(size_t size);

template <typename T>
void check_ptr(T ptr);


#endif //LAB2_FUNCS_H
