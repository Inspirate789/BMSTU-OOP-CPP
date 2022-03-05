#include "tasks_handling.h"

error_t HandleTask(task_t &task)
{
    error_t error_code;
    static figure_t figure;

    switch (task.action)
    {
        case LOAD:
            FreeFigure(figure);
            error_code = LoadFigure(figure, task.attribute.filename);
            break;
        case MOVE:
            error_code = MoveFigure(figure, task.attribute.move_coefs);
            break;
        case SCALE:
            error_code = ScaleFigure(figure, task.attribute.scale_coefs);
            break;
        case ROTATE:
            error_code = RotateFigure(figure, task.attribute.rotate_coefs);
            break;
        case DRAW:
            error_code = DrawFigure(figure, task.attribute.scene);
            break;
        case DESTROY:
            FreeFigure(figure);
            error_code = SUCCESS;
            break;
        default:
            error_code = INCORRECT_COMMAND;
            break;
    }

    return error_code;
}
