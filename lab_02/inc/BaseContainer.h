#ifndef _BASE_CONTAINER_H_
#define _BASE_CONTAINER_H_

#include <cstdlib>

class BaseContainer
{
public:
    BaseContainer();
    BaseContainer(const size_t sizeValue);
    bool IsEmpty() const;
    size_t GetSize() const;
    virtual ~BaseContainer() = 0;

protected:
    size_t size = 0;
};

#endif
