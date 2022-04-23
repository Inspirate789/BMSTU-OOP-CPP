#include "BaseException.h"

BaseException::BaseException(const str &time, const str &filename, 
                             const size_t &line, const str &class_name, 
                             const str &method_name, const str &info)
{
    ErrorInfo = "\n Time: " + time + 
                " Error in file " + filename + 
                ", line " + std::to_string(line) + 
                ", in method " + method_name + 
                " of class " + class_name + 
                "\n Info: " + info + "\n";
}

const char *BaseException::what() const noexcept
{
    return ErrorInfo.c_str();
}
