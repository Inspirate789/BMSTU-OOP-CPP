#include "modelstructure.h"

ModelStructure::ModelStructure(std::vector<Vertex> &vertexes, std::vector<Link> &links) :
    _center{ }, _vertexes(vertexes), _links(links) { }


ModelStructure::ModelStructure(std::vector<Vertex> &vertexes, std::vector<Link> &links,
                               Vertex &center):
    _center(center), _vertexes(vertexes), _links(links) { }

const std::vector<Vertex> &ModelStructure::getVertexes() const
{
    return _vertexes;
}

const std::vector<Link> &ModelStructure::getLinks() const
{
    return _links;
}

const Vertex ModelStructure::getCenter() const
{
    return _center;
}

void ModelStructure::addVertex(const Vertex &vertex)
{
    _vertexes.push_back(vertex);
    updateCenter();
}

void ModelStructure::addLink(const Link &link)
{
    _links.push_back(link);
}

void ModelStructure::updateCenter()
{
    _center = Vertex(0, 0, 0);
    size_t count = 0;

    for (const auto &element : _vertexes)
    {
        _center = _center + element.getCenter();
        count++;
    }

    _center = Vertex(_center.getX() / count,
                     _center.getY() / count,
                     _center.getZ() / count);
}

void ModelStructure::moveVertexesToOrigin(const Vertex &center)
{
    Vertex diff = Vertex(0, 0, 0) - center;

    Matrix<double> mtr = {{    1,            0,            0,             0      },
                          {    0,            1,            0,             0      },
                          {    0,            0,            1,             0      },
                          {diff.getX(),  diff.getY(),  diff.getZ(),       1      }};

    transformVertexes(mtr);
    updateCenter();
}

void ModelStructure::moveVertexesToCenter(const Vertex &center)
{
    Vertex diff = center - Vertex(0, 0, 0);

    Matrix<double> mtr = {{    1,            0,            0,             0      },
                          {    0,            1,            0,             0      },
                          {    0,            0,            1,             0      },
                          {diff.getX(),  diff.getY(),  diff.getZ(),       1      }};

    transformVertexes(mtr);
    updateCenter();
}

void ModelStructure::transformVertexes(const Matrix<double> &mtr)
{
    for (auto &vertex : _vertexes)
        vertex.transform(mtr);
}

void ModelStructure::transform(const Matrix<double> &mtr, const Vertex &center)
{
    updateCenter();

    moveVertexesToOrigin(center);
    transformVertexes(mtr);
    moveVertexesToCenter(center);
}
