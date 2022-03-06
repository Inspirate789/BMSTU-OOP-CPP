#include "tasks_handling.h"

error_t HandleTask(task_t &task)
{
    error_t error_code = SUCCESS;
    static figure_t figure = InitFigure();

    switch (task.action)
    {
        case LOAD:
            error_code = LoadFigure(figure, task.filename);
            break;
        case MOVE:
            error_code = MoveFigure(figure, task.move_coefs);
            break;
        case SCALE:
            error_code = ScaleFigure(figure, task.center, task.scale_coefs);
            break;
        case ROTATE:
            error_code = RotateFigure(figure, task.center, task.rotate_coefs);
            break;
        case DRAW:
            error_code = DrawFigure(figure, task.scene);
            break;
        case DESTROY:
            FreeFigure(figure);
            break;
        default:
            error_code = INCORRECT_COMMAND;
            break;
    }

    return error_code;
}
