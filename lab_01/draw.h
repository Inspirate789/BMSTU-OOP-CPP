#ifndef DRAW_H
#define DRAW_H

#include <QGraphicsScene>

#include "points.h"
#include "linkages.h"
#include "errors.h"

typedef struct scene
{
    QGraphicsScene *canvas;
    double width;
    double height;
} scene_t;

error_t DrawLinkages(const scene_t &scene, const linkages_t &linkages, const points_t &points);

#endif // DRAW_H
