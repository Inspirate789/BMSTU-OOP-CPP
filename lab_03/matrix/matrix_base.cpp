#include <memory>
#include "funcs.h"
#include "matrix_base.h"

BaseMatrix::BaseMatrix() {
    rows = allocate_size(0);
    columns = allocate_size(0);
}

BaseMatrix::BaseMatrix(size_t size) {
    rows = allocate_size(size);
    columns = allocate_size(size);
}

BaseMatrix::BaseMatrix(size_t _rows, size_t _columns) {
    rows = allocate_size(_rows);
    columns = allocate_size(_columns);
}

size_t BaseMatrix::get_rows() const {
    return *(rows);
}

size_t BaseMatrix::get_columns() const {
    return *(columns);
}
