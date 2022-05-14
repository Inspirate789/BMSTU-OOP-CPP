#include "modelstructure.h"

ModelStructure::ModelStructure(std::vector<Vertex> &vertexes, std::vector<Link> &links) :
    _center{}, _vertexes(vertexes), _links(links) {}


ModelStructure::ModelStructure(std::vector<Vertex> &vertexes, std::vector<Link> &links,
                               Vertex &center):
    _center(center), _vertexes(vertexes), _links(links) {}

const std::vector<Vertex> &ModelStructure::getVertexes() const
{
    return _vertexes;
}


const std::vector<Link> &ModelStructure::getLinks() const
{
    return _links;
}


const Vertex &ModelStructure::getCenter() const
{
    return _center;
}

void ModelStructure::addVertex(const Vertex &vertex)
{
    _vertexes.push_back(vertex);
}


void ModelStructure::addLink(const Link &link)
{
    _links.push_back(link);
}

void ModelStructure::transform(const Matrix<double> &mtr)
{
    _center.transform(mtr);

    for (auto &vertex : _vertexes)
        vertex.transform(mtr);
}
