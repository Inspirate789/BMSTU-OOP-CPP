#ifndef CRCREATOR_H
#define CRCREATOR_H

#include "creators.h"

using namespace std;

template <typename Tprodcr>
class CrCreator
{
public:
    static unique_ptr<Tprodcr> createProdCreator()
    {
        if (nullptr == _creator)
            createInstance();

        return _creator;
    }

    static void createInstance()
    {
        _creator = unique_ptr<Tprodcr>(new Tprodcr());
    }

    static unique_ptr<Tprodcr> _creator;
};


#endif // CRCREATOR_H
