#include <cstdlib>
#include "linkages.h"

static error_t InputLinkagesCount(size_t &count, FILE *f)
{
    error_t error_code = SUCCESS;
    size_t temp_count;

    if (fscanf(f, "%zu", &temp_count) != 1)
        error_code = INCORRECT_NUMBER;
    else
        if (temp_count != 0 && temp_count <= SIZE_MAX / 2)
            count = temp_count;
        else
            error_code = INCORRECT_LINKAGES_COUNT;

    return error_code;
}

static error_t AllocateLinkagesArray(linkages_t &linkages)
{
    error_t error_code = SUCCESS;
    linkage_t *temp_array = (linkage_t *)malloc(linkages.count * sizeof(linkage_t));

    if (temp_array)
        linkages.array = temp_array;
    else
        error_code = MEMORY_ALLOCATE_ERROR;

    return error_code;
}

static error_t InputLinkage(linkage_t &linkage, FILE *f)
{
    error_t error_code = SUCCESS;
    linkage_t temp_linkage;

    if (fscanf(f, "%zu %zu", &temp_linkage.point_1, &temp_linkage.point_2) != 2)
        error_code = INCORRECT_NUMBER;
    else
        if (temp_linkage.point_1 <= SIZE_MAX / 2 && temp_linkage.point_2 <= SIZE_MAX / 2)
            linkage = temp_linkage;
        else
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

//static error_t InputLinkagesArray(linkages_t &linkages, FILE *f)
//{
//    error_t error_code = SUCCESS;
//    long int start_pos = ftell(f);
//    linkage_t temp_linkage;

//    for (size_t i = 0; i < linkages.count; ++i)
//    {
//        error_code = InputLinkage(temp_linkage, f);

//        if (error_code != SUCCESS)
//            break;
//    }

//    fseek(f, start_pos, SEEK_SET);

//    if (error_code == SUCCESS)
//        for (size_t i = 0; i < linkages.count; ++i)
//            InputLinkage(linkages.array[i], f);

//    return error_code;
//}

error_t InputLinkages(linkages_t &linkages, FILE *f)
{
    if (linkages.array != nullptr || f == nullptr)
        return MEMORY_ERROR;

    linkages_t temp_linkagess;
    error_t error_code = InputLinkagesCount(temp_linkagess.count, f);

    if (error_code != SUCCESS)
        return error_code;

    error_code = AllocateLinkagesArray(temp_linkagess);

    if (error_code != SUCCESS)
        return error_code;

    error_code = InputLinkagesArray(temp_linkagess, f);

    if (error_code == SUCCESS)
        linkages = temp_linkagess;
    else
        FreeLinkages(temp_linkagess);

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

void FreeLinkages(linkages_t &linkages)
{
    if (linkages.array != nullptr)
    {
        free(linkages.array);
        linkages.array = nullptr;
    }
}
