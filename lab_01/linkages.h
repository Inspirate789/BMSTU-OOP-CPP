#ifndef LINKAGES_H
#define LINKAGES_H

#include <cstdio>

#include "points.h"
#include "draw.h"
#include "errors.h"

struct linkage_t
{
    size_t point_1;
    size_t point_2;
};

struct linkages_t
{
    linkage_t *array;
    size_t count;
};

void InitLinkages(linkages_t &linkages);
error_t InputLinkages(linkages_t &linkages, FILE *f);
error_t CheckLinkages(linkages_t &linkages, size_t &points_count);
error_t DrawLinkages(const scene_t &scene, const linkages_t &linkages, const points_t &points);
void FreeLinkages(linkages_t &linkages);

#endif // LINKAGES_H
