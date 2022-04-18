#ifndef _BASE_CONTAINER_H_
#define _BASE_CONTAINER_H_

#include <cstdlib>

class BaseContainer
{
public:
    virtual bool IsEmpty() const;
    virtual size_t GetSize() const;
    virtual ~BaseContainer() = 0;

protected:
    size_t size = 0;
};

#endif
