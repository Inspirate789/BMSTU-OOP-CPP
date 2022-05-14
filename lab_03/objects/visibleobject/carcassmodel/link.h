#ifndef LINK_H
#define LINK_H

#include <cstddef>

class Link
{
public:
    Link() = default;
    Link(const std::size_t firstVertex, const std::size_t secondVertex);
    Link(const Link &link) = default;

    ~Link() = default;

    std::size_t getFirst() const;
    std::size_t getSecond() const;

    void setFirst(const std::size_t index);
    void setSecond(const std::size_t index);

private:
    std::size_t _first;
    std::size_t _second;
};

#endif //LINK_H
