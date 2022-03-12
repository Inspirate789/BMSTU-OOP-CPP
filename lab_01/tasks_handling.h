#ifndef TASKS_HANDLING_H
#define TASKS_HANDLING_H

#include "figure.h"
#include "draw.h"
#include "errors.h"

enum action_t
{
    LOAD,
    MOVE,
    SCALE,
    ROTATE,
    DRAW,
    DESTROY
};

struct task_t
{
    action_t action;
    point_t center;
    union
    {
        filename_ptr_t filename; // for LOAD
        move_t move_coefs;       // for MOVE
        scale_t scale_coefs;     // for SCALE
        rotate_t rotate_coefs;   // for ROTATE
        scene_t scene;           // for DRAW
    };
};

error_t HandleTask(task_t &task);

#endif // TASKS_HANDLING_H
