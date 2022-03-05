#include <cstdlib>
#include <limits.h>
#include <cmath>

#include "points.h"

static error_t InputPointsCount(size_t &count, FILE *f)
{
    error_t error_code = SUCCESS;
    size_t temp_count;

    if (fscanf(f, "%zu", &temp_count) != 1)
        error_code = INCORRECT_NUMBER;
    else
        if (temp_count >= 2 && temp_count <= SIZE_MAX / 2)
            count = temp_count;
        else
            error_code = INCORRECT_POINTS_COUNT;

    return error_code;
}

static error_t AllocatePointsArray(points_t &points)
{
    error_t error_code = SUCCESS;
    point_t *temp_array = (point_t *)malloc(points.count * sizeof(point_t));

    if (temp_array)
        points.array = temp_array;
    else
        error_code = MEMORY_ALLOCATE_ERROR;

    return error_code;
}

static error_t InputPointsArray(points_t &points, FILE *f)
{
    error_t error_code = SUCCESS;
    long int start_pos = ftell(f);

    for (size_t i = 0; i < points.count; ++i)
        if (fscanf(f, "%lf %lf %lf", &points.array[i].x, &points.array[i].y, &points.array[i].z) != 3)
        {
            error_code = INCORRECT_POINT_DATA;
            break;
        }

    if (error_code != SUCCESS)
        fseek(f, start_pos, SEEK_SET);

    return error_code;
}

//static error_t InputPointsArray(points_t &points, FILE *f)
//{
//    error_t error_code = SUCCESS;
//    long int start_pos = ftell(f);
//    double x, y, z;

//    for (size_t i = 0; i < points.count; ++i)
//        if (fscanf(f, "%lf %lf %lf", &x, &y, &z) != 3)
//        {
//            error_code = INCORRECT_POINT_DATA;
//            break;
//        }

//    fseek(f, start_pos, SEEK_SET);

//    if (error_code == SUCCESS)
//        for (size_t i = 0; i < points.count; ++i)
//            fscanf(f, "%lf %lf %lf", &points.array[i].x, &points.array[i].y, &points.array[i].z);

//    return error_code;
//}

error_t InputPoints(points_t &points, FILE *f)
{
    if (points.array != nullptr || f == nullptr)
        return MEMORY_ERROR;

    points_t temp_points;
    error_t error_code = InputPointsCount(temp_points.count, f);

    if (error_code != SUCCESS)
        return error_code;

    error_code = AllocatePointsArray(temp_points);

    if (error_code != SUCCESS)
        return error_code;

    error_code = InputPointsArray(temp_points, f);

    if (error_code == SUCCESS)
        points = temp_points;
    else
        FreePoints(temp_points);

    return error_code;
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

static void ScalePoint(point_t &point, const scale_t &coefs)
{
    point.x *= coefs.kx;
    point.y *= coefs.ky;
    point.z *= coefs.kz;
}

error_t ScalePoints(points_t &points, const scale_t &coefs)
{
    if (points.array == nullptr)
        return MEMORY_ERROR;

    for (size_t i = 0; i < points.count; ++i)
        ScalePoint(points.array[i], coefs);

    return SUCCESS;
}

static double to_radians(const double &angle)
{
    return angle * M_PI / 180.0;
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

static void RotatePoint(point_t &point, const rotate_t &coefs)
{
    RotatePointX(point, coefs.ax);
    RotatePointY(point, coefs.ay);
    RotatePointZ(point, coefs.az);
}

error_t RotatePoints(points_t &points, const rotate_t &coefs)
{
    if (points.array == nullptr)
        return MEMORY_ERROR;

    for (size_t i = 0; i < points.count; ++i)
        RotatePoint(points.array[i], coefs);

    return SUCCESS;
}

void FreePoints(points_t &points)
{
    if (points.array != nullptr)
    {
        free(points.array);
        points.array = nullptr;
    }
}
