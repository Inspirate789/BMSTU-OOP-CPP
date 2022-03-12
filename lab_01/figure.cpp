#include <cstdio>

#include "figure.h"

figure_t &InitFigure(void)
{
    static figure_t figure;
    InitPoints(figure.points);
    InitLinkages(figure.linkages);

    return figure;
}

static error_t LoadTempFigure(figure_t &temp_figure, FILE *f)
{
    error_t error_code = InputPoints(temp_figure.points, f);

    if (error_code != SUCCESS)
        return error_code;

    error_code = InputLinkages(temp_figure.linkages, f);

    if (error_code != SUCCESS)
    {
        FreePoints(temp_figure.points);
        return error_code;
    }

    return error_code;
}

error_t CheckFigure(figure_t &figure)
{
    size_t points_count = GetPointsCount(figure.points);
    error_t error_code = CheckLinkages(figure.linkages, points_count);

    return error_code;
}

void CopyFigure(figure_t &dst, const figure_t &src)
{
    dst = src;
}

error_t LoadFigure(figure_t &figure, filename_ptr_t &filename)
{
    figure_t temp_figure = InitFigure();
    FILE *f = fopen(filename, "r");

    if (f == nullptr)
        return FILE_OPEN_ERROR;

    error_t error_code = LoadTempFigure(temp_figure, f);
    fclose(f);

    if (error_code == SUCCESS)
    {
        error_code = CheckFigure(temp_figure);

        if (error_code == SUCCESS)
        {
            FreeFigure(figure);
            CopyFigure(figure, temp_figure);
        }
        else
            FreeFigure(temp_figure);
    }

    return error_code;
}

error_t DrawFigure(const figure_t &figure, const scene_t &scene)
{
    ClearScene(scene);
    error_t error_code = DrawLinkages(scene, figure.linkages, figure.points);

    return error_code;
}

error_t MoveFigure(figure_t &figure, const move_t &coefs)
{
    error_t error_code = MovePoints(figure.points, coefs);

    return error_code;
}

error_t ScaleFigure(figure_t &figure, const point_t &center, const scale_t &coefs)
{
    error_t error_code = ScalePoints(figure.points, center, coefs);

    return error_code;
}

error_t RotateFigure(figure_t &figure, const point_t &center, const rotate_t &coefs)
{
    error_t error_code = RotatePoints(figure.points, center, coefs);

    return error_code;
}

void FreeFigure(figure_t &figure)
{
    FreePoints(figure.points);
    FreeLinkages(figure.linkages);
}
