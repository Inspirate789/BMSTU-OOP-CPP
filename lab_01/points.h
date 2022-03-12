#ifndef POINTS_H
#define POINTS_H

#include <cstdio>

#include "figure_actions.h"
#include "errors.h"

struct point_t
{
    double x;
    double y;
    double z;
};

struct points_t
{
    point_t *array;
    size_t count;
};

void InitPoints(points_t &points);
error_t InputPoints(points_t &points, FILE *f);
size_t GetPointsCount(const points_t &points);
error_t MovePoints(points_t &points, const move_t &coefs);
error_t ScalePoints(points_t &points, const point_t &center, const scale_t &coefs);
error_t RotatePoints(points_t &points,const point_t &center,  const rotate_t &coefs);
void FreePoints(points_t &points);

#endif // POINTS_H
