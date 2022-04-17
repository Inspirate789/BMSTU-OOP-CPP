#ifndef _BASE_CONTAINER_H_
#define _BASE_CONTAINER_H_

#include <cstdlib>

class BaseContainer
{
protected:
    size_t size = 0;

public:
    virtual bool IsEmpty() const;
    virtual size_t GetSize() const;
    virtual ~BaseContainer() = 0;
};

#endif
