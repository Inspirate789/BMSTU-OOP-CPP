#ifndef DRAW_H
#define DRAW_H

#include <QGraphicsScene>

#include "points.h"
#include "errors.h"

typedef struct scene
{
    QGraphicsScene *canvas;
    double width;
    double height;
} scene_t;

void DrawLine(const scene_t &scene, const point_t &point_1, const point_t &point_2);
void ClearScene(const scene_t &scene);

#endif // DRAW_H
