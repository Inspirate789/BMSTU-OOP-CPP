#ifndef CRCREATOR_H
#define CRCREATOR_H

#include "creators.h"

using namespace std;

template <typename Tprodcr>
class CrCreator
{
public:
    static shared_ptr<Tprodcr> createProdCreator()
    {
        return shared_ptr<Tprodcr>(new Tprodcr());
    }
};


#endif // CRCREATOR_H
