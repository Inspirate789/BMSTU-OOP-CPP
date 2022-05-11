#include "solution.h"

template <typename Tprodcr>
Solution<Tprodcr>::Solution(initializer_list<pair<size_t, CreateCreator>> list)
{
    for (auto elem : list)
        this->registration(elem.first, elem.second);
}

template <typename Tprod>
bool Solution<Tprod>::registration(size_t id, CreateCreator createProd)
{
    return callbacks.insert(CallBackMap::value_type(id, createProd)).second;
}

template <typename Tprodcr>
shared_ptr<Tprodcr> Solution<Tprodcr>::create(size_t id)
{
    typename CallBackMap::const_iterator it = callbacks.find(id);

//    if (it == callbacks.end())
//    {
//        throw IdError();
//    }

    return shared_ptr<Tprodcr>((it->second)());
}
