#ifndef POINTS_H
#define POINTS_H

#include <cstdio>

#include "figure_actions.h"
#include "errors.h"

typedef struct
{
    double x;
    double y;
    double z;
} point_t;

typedef struct points
{
    point_t *array = nullptr;
    size_t count;
} points_t;

error_t InputPoints(points_t &points, FILE *f);
error_t MovePoints(points_t &points, const move_t &coefs);
error_t ScalePoints(points_t &points, const scale_t &coefs);
error_t RotatePoints(points_t &points, const rotate_t &coefs);
void FreePoints(points_t &points);

#endif // POINTS_H
