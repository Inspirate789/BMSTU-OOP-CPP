#ifndef FIGURE_H
#define FIGURE_H

#include <cstdio>

#include "figure_actions.h"
#include "points.h"
#include "linkages.h"
#include "draw.h"
#include "errors.h"

typedef struct figure
{
    points_t points;
    linkages_t linkages;
} figure_t;

typedef const char* filename_t;

error_t LoadFigure(figure_t &figure, filename_t &filename);
error_t DrawFigure(const figure_t &figure, const scene_t &scene);
error_t MoveFigure(figure_t &figure, const move_t &coefs);
error_t ScaleFigure(figure_t &figure, const scale_t &coefs);
error_t RotateFigure(figure_t &figure, const rotate_t &coefs);
void FreeFigure(figure_t &figure);

#endif // FIGURE_H
