#ifndef SOLUTION_H
#define SOLUTION_H

# include <initializer_list>
# include <memory>
# include <map>

#include "creators.h"

using namespace std;

template <typename Tprodcr>
class Solution
{
    using CreateCreator = unique_ptr<Tprodcr>(*)();
    using CallBackMap = map<size_t, CreateCreator>;

public:
    Solution() = default;
    Solution(initializer_list<pair<size_t, CreateCreator>> list);

    bool registration(size_t id, CreateCreator createProd);
    bool check(size_t id) { return callbacks.erase(id) == 1; }

    shared_ptr<Tprodcr> create(size_t id);

private:
    CallBackMap callbacks;
};


#endif // SOLUTION_H
