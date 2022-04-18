#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include "BaseException.h"

class ExpiredException : public BaseException
{
public:
    ExpiredException(const str &time, const str &filename,
                     const size_t &line, const str &class_name,
                     const str &method_name,
                     const str &info = "An attempt was made to access an expired weak pointer.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class MemoryException : public BaseException
{
public:
    MemoryException(const str &time, const str &filename,
                    const size_t &line, const str &class_name,
                    const str &method_name,
                    const str &info = "Memory allocation error.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class EmptyVectorException : public BaseException
{
public:
    EmptyVectorException(const str &time, const str &filename,
                         const size_t &line, const str &class_name,
                         const str &method_name,
                         const str &info = "Error when performing an operation on an empty vector.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class OutOfRangeException : public BaseException
{
public:
    OutOfRangeException(const str &time, const str &filename,
                        const size_t &line, const str &class_name,
                        const str &method_name,
                        const str &info = "Index is out of range.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class NotEqualSizesException : public BaseException
{
public:
    NotEqualSizesException(const str &time, const str &filename,
                           const size_t &line, const str &class_name,
                           const str &method_name,
                           const str &info = "Error when performing an operation with vectors of different sizes.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class Not3DException : public BaseException
{
public:
    Not3DException(const str &time, const str &filename,
                   const size_t &line, const str &class_name,
                   const str &method_name,
                   const str &info = "Vector product with non 3D-vectors.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

class DivisionByZeroException : public BaseException
{
public:
    DivisionByZeroException(const str &time, const str &filename,
                            const size_t &line, const str &class_name,
                            const str &method_name,
                            const str &info = "Division by zero occured.")
        : BaseException(time, filename, line, class_name, method_name, info){};
};

#endif
