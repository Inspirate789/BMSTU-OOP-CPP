#ifndef FIGURE_ACTIONS_H
#define FIGURE_ACTIONS_H

struct move_t
{
    double dx;
    double dy;
    double dz;
};

struct scale_t
{
    double kx;
    double ky;
    double kz;
};

struct rotate_t
{
    double ax;
    double ay;
    double az;
};

#endif // FIGURE_ACTIONS_H
