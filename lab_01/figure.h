#ifndef FIGURE_H
#define FIGURE_H

#include <cstdio>

#include "figure_actions.h"
#include "points.h"
#include "linkages.h"
#include "draw.h"
#include "errors.h"

struct figure_t
{
    points_t points;
    linkages_t linkages;
};

typedef const char* filename_ptr_t;

figure_t &InitFigure(void);
error_t CheckFigure(figure_t &figure);
void CopyFigure(figure_t &dst, const figure_t &src);
error_t LoadFigure(figure_t &figure, filename_ptr_t &filename);
error_t DrawFigure(const figure_t &figure, const scene_t &scene);
error_t MoveFigure(figure_t &figure, const move_t &coefs);
error_t ScaleFigure(figure_t &figure, const point_t &center, const scale_t &coefs);
error_t RotateFigure(figure_t &figure, const point_t &center, const rotate_t &coefs);
void FreeFigure(figure_t &figure);

#endif // FIGURE_H
