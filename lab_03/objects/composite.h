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

    virtual bool add(const std::shared_ptr<Object> &element) override;
    virtual bool remove(const Iterator &iter) override;
    virtual void updateCenter() override;

    virtual bool isVisible() override;
    virtual bool isComposite() override;

    virtual Vertex getCenter() const override;
    virtual void moveElemsToOrigin() override;
    virtual void moveElemsToCenter(const Vertex &center) override;
    virtual void transformElems(const Matrix<double> &mtr) override;
    virtual void transform(const Matrix<double> &mtr) override;

    virtual Iterator begin() override;
    virtual Iterator end() override;

private:
    Vertex _center;
    std::vector<std::shared_ptr<Object>> _elements;
};

#endif //COMPOSITE_H
