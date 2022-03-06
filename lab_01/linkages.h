#ifndef LINKAGES_H
#define LINKAGES_H

#include <cstdio>

#include "points.h"
#include "draw.h"
#include "errors.h"

typedef struct linkage
{
    size_t point_1;
    size_t point_2;
} linkage_t;

typedef struct linkages
{
    linkage_t *array;
    size_t count;
} linkages_t;

void InitLinkages(linkages_t &linkages);
error_t InputLinkages(linkages_t &linkages, FILE *f);
error_t CheckLinkages(linkages_t &linkages, size_t &points_count);
error_t DrawLinkages(const scene_t &scene, const linkages_t &linkages, const points_t &points);
void FreeLinkages(linkages_t &linkages);

#endif // LINKAGES_H
