#include "BaseContainer.h"

bool BaseContainer::IsEmpty() const
{
    return size == 0;
}

size_t BaseContainer::GetSize() const
{
    return size;
}

BaseContainer::~BaseContainer() = default;
