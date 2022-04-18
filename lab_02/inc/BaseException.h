#ifndef _BASE_EXCEPTION_H_
#define _BASE_EXCEPTION_H_

#include <exception>
#include <string>

using str = std::string;

class BaseException : public std::exception
{
public:
    BaseException(const str &time, const str &filename,
                  const size_t &line, const str &class_name,
                  const str &method_name, const str &info);
    virtual const char *what() const noexcept override;

protected:
    str ErrorInfo;
};

#endif
