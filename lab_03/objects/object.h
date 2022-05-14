#ifndef OBJECT_H
#define OBJECT_H

#include <memory>
#include <vector>
#include <QDebug>

#include "vertex.h"


class Object;

using Iterator = std::vector<std::shared_ptr<Object>>::iterator;

class Object
{
public:
    Object() { _id = _nextId++; };
    virtual ~Object() = default;

    virtual bool add(const std::shared_ptr<Object> &) { return false; };
    virtual bool remove(const Iterator &) { return false; };

    virtual bool isVisible() { return false; };
    virtual bool isComposite() { return  false; };

    virtual void moveElems(std::vector<Vertex> &) { };
    virtual std::vector<Vertex> getElemsDistances(Vertex &) const { return std::vector<Vertex>(); };
    virtual Vertex getCenter() const = 0;
    virtual void transform(const Matrix<double> &mtr) = 0;

    virtual Iterator begin() { return Iterator(); };
    virtual Iterator end() { return Iterator(); };

    virtual std::size_t getId() { return _id; }

protected:
    std::size_t _id;
    static std::size_t _nextId;
};

#endif //OBJECT_H
