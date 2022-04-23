#include "BaseContainer.h"

BaseContainer::BaseContainer()
{
    size = 0;
}

BaseContainer::BaseContainer(size_t sizeValue)
{
    size = sizeValue;
}

bool BaseContainer::IsEmpty() const
{
    return size == 0;
}

size_t BaseContainer::GetSize() const
{
    return size;
}

BaseContainer::~BaseContainer() = default;
