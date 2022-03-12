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

static error_t AllocateLinkagesArray(linkages_t &linkages)
{
    error_t error_code = SUCCESS;
    linkages.array = (linkage_t *)malloc(linkages.count * sizeof(linkage_t));

    if (linkages.array == nullptr)
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

static error_t InputLinkagesArray(linkages_t &linkages, FILE *f)
{
    error_t error_code = SUCCESS;
    long int start_pos = ftell(f);

    for (size_t i = 0; i < linkages.count; ++i)
    {
        error_code = InputLinkage(linkages.array[i], f);

        if (error_code != SUCCESS)
            break;
    }

    if (error_code != SUCCESS)
        fseek(f, start_pos, SEEK_SET);

    return error_code;
}

error_t InputLinkages(linkages_t &linkages, FILE *f)
{
    if (linkages.array != nullptr || f == nullptr)
        return MEMORY_ERROR;

    error_t error_code = InputLinkagesCount(linkages.count, f);

    if (error_code != SUCCESS)
    {
        FreeLinkages(linkages);
        return error_code;
    }

    error_code = AllocateLinkagesArray(linkages);

    if (error_code != SUCCESS)
    {
        FreeLinkages(linkages);
        return error_code;
    }

    error_code = InputLinkagesArray(linkages, f);

    if (error_code != SUCCESS)
        FreeLinkages(linkages);

    return error_code;
}

error_t CheckLinkages(linkages_t &linkages, size_t &points_count)
{
    if (linkages.array == nullptr)
        return MEMORY_ERROR;

    for (size_t i = 0; i < linkages.count; ++i)
    {
        linkage_t cur_linkage = linkages.array[i];

        if (cur_linkage.point_1 >= points_count || cur_linkage.point_1 >= points_count)
            return INCORRECT_LINKAGE_DATA;
    }

    return SUCCESS;
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

void FreeLinkages(linkages_t &linkages)
{
    if (linkages.array != nullptr)
    {
        free(linkages.array);
        linkages.array = nullptr;
    }
}
