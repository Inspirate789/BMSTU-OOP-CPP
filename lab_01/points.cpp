#include <cstdlib>
#include <limits.h>
#include <cmath>

#include "points.h"

void InitPoints(points_t &points)
{
    points.array = nullptr;
    points.count = 0;
}

static error_t InputPointsCount(size_t &count, FILE *f)
{
    error_t error_code = SUCCESS;

    if (fscanf(f, "%zu", &count) != 1)
        error_code = INCORRECT_NUMBER;
    else
        if (count < 2 || count > SIZE_MAX / 2)
            error_code = INCORRECT_POINTS_COUNT;

    return error_code;
}

static error_t AllocatePointsArray(point_t *array, size_t count)
{
    error_t error_code = SUCCESS;
    array = (point_t *)malloc(count * sizeof(point_t));

    if (array == nullptr)
        error_code = MEMORY_ALLOCATE_ERROR;

    return error_code;
}

static error_t InputPoint(point_t &point, FILE *f)
{
    error_t error_code = SUCCESS;

    if (fscanf(f, "%lf %lf %lf", &point.x, &point.y, &point.z) != 3)
        error_code = INCORRECT_POINT_DATA;

    return error_code;
}

static error_t InputPointsArray(point_t *array, size_t count, FILE *f)
{
    error_t error_code = SUCCESS;
    error_t tmp_error_code = SUCCESS;

    for (size_t i = 0; i < count; ++i)
    {
        tmp_error_code = InputPoint(array[i], f);

        if (tmp_error_code != SUCCESS)
            error_code = tmp_error_code;
    }

    return error_code;
}

error_t InputPoints(points_t &points, FILE *f)
{
    if (points.array != nullptr)
        return MEMORY_ERROR;

    if (f == nullptr)
        return FILE_OPEN_ERROR;

    error_t error_code = InputPointsCount(points.count, f);

    if (error_code == SUCCESS)
    {
        error_code = AllocatePointsArray(points.array, points.count);

        if (error_code == SUCCESS)
        {
            error_code = InputPointsArray(points.array, points.count, f);

            if (error_code != SUCCESS)
                FreePoints(points.array);
        }
    }

    return error_code;
}

size_t GetPointsCount(const points_t &points)
{
    return points.count;
}

static void MovePoint(point_t &point, const move_t &coefs)
{
    point.x += coefs.dx;
    point.y += coefs.dy;
    point.z += coefs.dz;
}

error_t MovePoints(points_t &points, const move_t &coefs)
{
    if (points.array == nullptr)
        return MEMORY_ERROR;

    for (size_t i = 0; i < points.count; ++i)
        MovePoint(points.array[i], coefs);

    return SUCCESS;
}

static void ScalePoint(point_t &point, const point_t &center, const scale_t &coefs)
{
    point.x = coefs.kx * point.x + (1 - coefs.kx) * center.x;
    point.y = coefs.ky * point.y + (1 - coefs.ky) * center.y;
    point.z = coefs.kz * point.z + (1 - coefs.kz) * center.z;
}

error_t ScalePoints(points_t &points, const point_t &center, const scale_t &coefs)
{
    if (points.array == nullptr)
        return MEMORY_ERROR;

    for (size_t i = 0; i < points.count; ++i)
        ScalePoint(points.array[i], center, coefs);

    return SUCCESS;
}

static double to_radians(const double &angle)
{
    return angle * M_PI / 180.0;
}

static void MovePointToOrigin(point_t &point, const point_t &center)
{
    move_t move_to_origin;
    move_to_origin.dx = -center.x;
    move_to_origin.dy = -center.y;
    move_to_origin.dz = -center.z;
    MovePoint(point, move_to_origin);
}

static void MovePointToCenter(point_t &point, const point_t &center)
{
    move_t move_to_center;
    move_to_center.dx = center.x;
    move_to_center.dy = center.y;
    move_to_center.dz = center.z;
    MovePoint(point, move_to_center);
}

static void RotatePointX(point_t &point, const double &angle)
{
    double temp_y = point.y;
    point.y = point.y * cos(to_radians(angle)) - point.z * sin(to_radians(angle));
    point.z = temp_y * sin(to_radians(angle)) + point.z * cos(to_radians(angle));
}

static void RotatePointY(point_t &point, const double &angle)
{
    double temp_x = point.x;
    point.x = point.x * cos(to_radians(angle)) + point.z * sin(to_radians(angle));
    point.z = -temp_x * sin(to_radians(angle)) + point.z * cos(to_radians(angle));
}

static void RotatePointZ(point_t &point, const double &angle)
{
    double temp_x = point.x;
    point.x = point.x * cos(to_radians(angle)) - point.y * sin(to_radians(angle));
    point.y = temp_x * sin(to_radians(angle)) + point.y * cos(to_radians(angle));
}

static void RotatePoint(point_t &point, const point_t &center, const rotate_t &coefs)
{
    MovePointToOrigin(point, center);

    RotatePointX(point, coefs.ax);
    RotatePointY(point, coefs.ay);
    RotatePointZ(point, coefs.az);

    MovePointToCenter(point, center);
}

error_t RotatePoints(points_t &points, const point_t &center, const rotate_t &coefs)
{
    if (points.array == nullptr)
        return MEMORY_ERROR;

    for (size_t i = 0; i < points.count; ++i)
        RotatePoint(points.array[i], center, coefs);

    return SUCCESS;
}

void FreePoints(point_t *array)
{
    if (array != nullptr)
    {
        free(array);
        array = nullptr;
    }
}
