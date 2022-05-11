#ifndef CREATORS_H
#define CREATORS_H

#include <memory>

using namespace std;

class BaseProdCreator
{
public:
    BaseProdCreator() = default;
    ~BaseProdCreator() = default;
};

template <typename Tprod>
class ProdCreator // : public BaseProdCreator
{
public:
    virtual unique_ptr<Tprod> createProd()
    {
        return unique_ptr<Tprod>(new Tprod());
    }
};

#endif // CREATORS_H
