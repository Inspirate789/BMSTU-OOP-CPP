#ifndef ITERATOR_EXCEPTIONS_H
#define ITERATOR_EXCEPTIONS_H

#include "exception"
#include "string"

using string = std::string;


class ExceptionIterator: public std::exception {
protected:
    string error_msg;
public:
    ExceptionIterator(const string file_info, const int line_info,
                      const string errmsg)
    {
        error_msg = "File: " + file_info + "\nLine: " + std::to_string(line_info) +
                    "\nError: " + errmsg + "\nClass: Iterator\n";
    }

    virtual ~ExceptionIterator() {};
    virtual const char *what() const noexcept override
    {
        return error_msg.c_str();
    }
};

class IndexError: public ExceptionIterator {
public:
    IndexError(const string file_info, const int line_info,
               const string errmsg):
            ExceptionIterator(file_info, line_info, errmsg) {
        error_msg += " (error type: IndexError)";
    }
};

class PtrError: public ExceptionIterator {
public:
    PtrError(const string file_info, const int line_info,
               const string errmsg):
            ExceptionIterator(file_info, line_info, errmsg) {
        error_msg += " (error type: PtrError)";
    }
};

#endif //ITERATOR_EXCEPTIONS_H
