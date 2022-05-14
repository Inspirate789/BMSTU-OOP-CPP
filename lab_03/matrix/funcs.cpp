#include "funcs.h"


std::shared_ptr<size_t> allocate_size(size_t size)
{
    std::shared_ptr<size_t> size_ptr = nullptr;

    try {
        size_ptr = std::make_shared<size_t>(size);
    }
    catch (std::bad_alloc &err) {
        throw MemoryError(__FILE__, __LINE__, "bad alloc size");
    }

    return size_ptr;
}

