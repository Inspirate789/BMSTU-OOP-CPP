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
    virtual shared_ptr<Tprod> createProd()
    {
        return shared_ptr<Tprod>(new Tprod());
    }
};

#endif // CREATORS_H
