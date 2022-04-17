#include "BaseContainer.h"

bool BaseContainer::is_empty() const
{
    return size == 0;
}

size_t BaseContainer::get_size() const
{
    return size;
}

BaseContainer::~BaseContainer() = default;
