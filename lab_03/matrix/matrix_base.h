#include <memory>

class BaseMatrix
{
protected:
    std::shared_ptr<size_t> rows;
    std::shared_ptr<size_t> columns;

public:
    BaseMatrix();
    explicit BaseMatrix(size_t size);
    explicit BaseMatrix(size_t rows, size_t columns);
    virtual void clear() = 0;

    size_t get_rows() const;
    size_t get_columns() const;

    virtual ~BaseMatrix() = default;
};

