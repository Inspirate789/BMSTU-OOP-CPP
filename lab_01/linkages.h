#ifndef LINKAGES_H
#define LINKAGES_H

#include <cstdio>

#include "errors.h"

typedef struct linkage
{
    size_t point_1;
    size_t point_2;
} linkage_t;

typedef struct linkages
{
    linkage_t *array = nullptr;
    size_t count;
} linkages_t;

error_t InputLinkages(linkages_t &linkages, FILE *f);
error_t CheckLinkages(linkages_t &linkages, size_t &points_count);
void FreeLinkages(linkages_t &linkages);

#endif // LINKAGES_H
