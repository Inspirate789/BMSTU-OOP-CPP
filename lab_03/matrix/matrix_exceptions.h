#ifndef MATRIX_EXCEPTIONS_H
#define MATRIX_EXCEPTIONS_H

#include "exception"
#include "string"

using string = std::string;


class ExceptionMatrix: public std::exception {
protected:
    string error_msg;
public:
    ExceptionMatrix(const string file_info, const int line_info,
                    const string errmsg)
    {
        error_msg = "File: " + file_info + "\nLine: " + std::to_string(line_info) +
                    "\nError: " + errmsg + "\nClass: Matrix\n";
    }

    virtual ~ExceptionMatrix() {};
    virtual const char *what() const noexcept override
    {
        return error_msg.c_str();
    }
};

class MemoryError: public ExceptionMatrix {
public:
    MemoryError(const string file_info, const int line_info,
               const string errmsg):
            ExceptionMatrix(file_info, line_info, errmsg) {
        error_msg += " (error type: MemoryError)";
    }
};

class CopyError: public ExceptionMatrix {
public:
    CopyError(const string file_info, const int line_info,
             const string errmsg):
            ExceptionMatrix(file_info, line_info, errmsg) {
        error_msg += " (error type: CopyError)";
    }
};

class DetError: public ExceptionMatrix {
public:
    DetError(const string file_info, const int line_info,
              const string errmsg):
            ExceptionMatrix(file_info, line_info, errmsg) {
        error_msg += " (error type: DetError)";
    }
};

class MulSizesError: public ExceptionMatrix {
public:
    MulSizesError(const string file_info, const int line_info,
             const string errmsg):
            ExceptionMatrix(file_info, line_info, errmsg) {
        error_msg += " (error type: MulSizesError)";
    }
};

class AddSizesError: public ExceptionMatrix {
public:
    AddSizesError(const string file_info, const int line_info,
                  const string errmsg):
            ExceptionMatrix(file_info, line_info, errmsg) {
        error_msg += " (error type: AddSizesError)";
    }
};

class MatrixIndexError: public ExceptionMatrix {
public:
    MatrixIndexError(const string file_info, const int line_info,
                  const string errmsg):
            ExceptionMatrix(file_info, line_info, errmsg) {
        error_msg += " (error type: MatrixIndexError)";
    }
};

class DivZeroError: public ExceptionMatrix {
public:
    DivZeroError(const string file_info, const int line_info,
               const string errmsg):
            ExceptionMatrix(file_info, line_info, errmsg) {
        error_msg += " (error type: DivZeroError)";
    }
};

class InvalidListArgument: public ExceptionMatrix {
        public:
    InvalidListArgument(const string file_info, const int line_info,
        const string errmsg):
        ExceptionMatrix(file_info, line_info, errmsg) {
            error_msg += " (error type: InvalidListArgument)";
        }
};

#endif //MATRIX_EXCEPTIONS_H
