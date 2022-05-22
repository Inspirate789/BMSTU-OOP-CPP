#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "object.h"

class Composite : public Object
{
    friend class DrawCompositeAdapter;

public:
    Composite() = default;
    explicit Composite(std::shared_ptr<Object> &element);
    explicit Composite(const std::vector<std::shared_ptr<Object>> &vector);

    bool add(const std::shared_ptr<Object> &element) override;
    bool remove(const Iterator &iter) override;

    bool isVisible() override;
    bool isComposite() override;

    virtual Vertex getCenter() const override;
    virtual void moveElemsToOrigin() override;
    virtual void moveElemsToCenter(const Vertex &center) override;
    virtual void transformElems(const Matrix<double> &mtr) override;
    virtual void transform(const Matrix<double> &mtr) override;

    Iterator begin() override;
    Iterator end() override;

private:
    Vertex _center;
    std::vector<std::shared_ptr<Object>> _elements;
};

#endif //COMPOSITE_H
