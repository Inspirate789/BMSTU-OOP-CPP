#ifndef BASEDIRECTOR_H
#define BASEDIRECTOR_H


#include <string>
#include <fstream>
#include <memory>

#include "object.h"

class BaseDirector
{
public:
    BaseDirector() = default;
    virtual ~BaseDirector() = default;

    virtual void open(std::string &fileName) = 0;
    virtual void close() = 0;
};

#endif // BASEDIRECTOR_H
