#ifndef FIGURE_ACTIONS_H
#define FIGURE_ACTIONS_H

typedef struct move
{
    double dx;
    double dy;
    double dz;
} move_t;

typedef struct scale
{
    double kx;
    double ky;
    double kz;
} scale_t;

typedef struct rotate
{
    double ax;
    double ay;
    double az;
} rotate_t;

#endif // FIGURE_ACTIONS_H
