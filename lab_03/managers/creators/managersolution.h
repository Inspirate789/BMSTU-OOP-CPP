#ifndef CREATEMANAGERSOLUTION_H
#define CREATEMANAGERSOLUTION_H

#include <memory>

template<typename Tcreator>
class ManagerSolution
{
public:
    decltype(auto) create();
};

template<typename Tcreator>
decltype(auto) ManagerSolution<Tcreator>::create()
{
    auto creator = Tcreator();
    decltype(creator.createManager()) moderator = creator.createManager();

    return moderator;
}

#endif // CREATEMANAGERSOLUTION_H