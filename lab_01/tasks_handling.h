#ifndef TASKS_HANDLING_H
#define TASKS_HANDLING_H

#include "figure.h"
#include "draw.h"
#include "errors.h"

typedef enum
{
    LOAD,
    MOVE,
    SCALE,
    ROTATE,
    DRAW,
    DESTROY
} action_t;

typedef union action_attributes
{
    filename_t filename; // for LOAD
    move_t move_coefs; // for MOVE
    scale_t scale_coefs; // for SCALE
    rotate_t rotate_coefs; // for ROTATE
    scene_t scene; // for DRAW
} action_attribute_t;

typedef struct task
{
    action_t action;
    action_attribute_t attribute;
} task_t;

error_t HandleTask(task_t &task);

#endif // TASKS_HANDLING_H
