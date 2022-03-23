#include <cstdlib>

#include "linkages.h"

void InitLinkages(linkages_t &linkages)
{
    linkages.array = nullptr;
    linkages.count = 0;
}

static error_t InputLinkagesCount(size_t &count, FILE *f)
{
    error_t error_code = SUCCESS;

    if (fscanf(f, "%zu", &count) != 1)
        error_code = INCORRECT_NUMBER;
    else
        if (count == 0 || count > SIZE_MAX / 2)
            error_code = INCORRECT_LINKAGES_COUNT;

    return error_code;
}

static error_t AllocateLinkagesArray(linkage_t *array, size_t count)
{
    error_t error_code = SUCCESS;
    array = (linkage_t *)malloc(count * sizeof(linkage_t));

    if (array == nullptr)
        error_code = MEMORY_ALLOCATE_ERROR;

    return error_code;
}

static error_t InputLinkage(linkage_t &linkage, FILE *f)
{
    error_t error_code = SUCCESS;

    if (fscanf(f, "%zu %zu", &linkage.point_1, &linkage.point_2) != 2)
        error_code = INCORRECT_NUMBER;
    else
        if (linkage.point_1 > SIZE_MAX / 2 || linkage.point_2 > SIZE_MAX / 2)
            error_code = INCORRECT_LINKAGE_DATA;

    return error_code;
}

static error_t InputLinkagesArray(linkage_t *array, size_t count, FILE *f)
{
    error_t error_code = SUCCESS;
    error_t tmp_error_code = SUCCESS;

    for (size_t i = 0; i < count; ++i)
    {
        tmp_error_code = InputLinkage(array[i], f);

        if (tmp_error_code != SUCCESS)
            error_code = tmp_error_code;
    }

    return error_code;
}

error_t InputLinkages(linkages_t &linkages, FILE *f)
{
    if (linkages.array != nullptr)
        return MEMORY_ERROR;

    if (f == nullptr)
        return FILE_OPEN_ERROR;

    error_t error_code = InputLinkagesCount(linkages.count, f);

    if (error_code == SUCCESS)
    {
        error_code = AllocateLinkagesArray(linkages.array, linkages.count);

        if (error_code == SUCCESS)
        {
            error_code = InputLinkagesArray(linkages.array, linkages.count, f);

            if (error_code != SUCCESS)
                FreeLinkages(linkages.array);
        }

    }

    return error_code;
}

error_t CheckLinkages(linkages_t &linkages, size_t &points_count)
{
    if (linkages.array == nullptr)
        return MEMORY_ERROR;

    error_t error_code = SUCCESS;

    for (size_t i = 0; i < linkages.count; ++i)
    {
        linkage_t cur_linkage = linkages.array[i];

        if (cur_linkage.point_1 >= points_count || cur_linkage.point_1 >= points_count)
            error_code = INCORRECT_LINKAGE_DATA;
    }

    return error_code;
}

static void DrawLinkage(const scene_t &scene, const linkage_t &linkage, const points_t &points)
{
    point_t point_1 = points.array[linkage.point_1];
    point_t point_2 = points.array[linkage.point_2];

    DrawLine(scene, point_1, point_2);
}

error_t DrawLinkages(const scene_t &scene, const linkages_t &linkages, const points_t &points)
{
    if (linkages.array == nullptr || points.array == nullptr)
        return MEMORY_ERROR;

    for (size_t i = 0; i < linkages.count; ++i)
        DrawLinkage(scene, linkages.array[i], points);

    return SUCCESS;
}

void FreeLinkages(linkage_t *array)
{
    if (array != nullptr)
    {
        free(array);
        array = nullptr;
    }
}
