#ifndef MODELSTRUCTURE_H
#define MODELSTRUCTURE_H

#include <vector>

#include "vertex.h"
#include "link.h"

class ModelStructure
{
public:
    ModelStructure() = default;
    ModelStructure(std::vector<Vertex> &vertexes, std::vector<Link> &links);
    ModelStructure(std::vector<Vertex> &vertexes, std::vector<Link> &links, Vertex &center);

    ~ModelStructure() = default;

    const std::vector<Vertex> &getVertexes() const;
    const std::vector<Link> &getLinks() const;
    const Vertex getCenter() const;

    void addVertex(const Vertex &vertex);
    void addLink(const Link &link);
    void updateCenter();

    void moveVertexesToOrigin(const Vertex &center);
    void moveVertexesToCenter(const Vertex &center);
    void transformVertexes(const Matrix<double> &mtr);
    void transform(const Matrix<double> &mtr, const Vertex &center);

private:
    Vertex _center;

    std::vector<Vertex> _vertexes;
    std::vector<Link> _links;
};


#endif //MODELSTRUCTURE_H
