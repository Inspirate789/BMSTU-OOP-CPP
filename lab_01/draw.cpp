#include <cstdio>

#include "draw.h"

static void DrawLinkage(const scene_t &scene, const linkage_t &linkage, const points_t &points)
{
    point_t point_1 = points.array[linkage.point_1];
    point_t point_2 = points.array[linkage.point_2];

    scene.canvas->addLine(
                point_1.x + scene.width / 2,
                point_1.y + scene.height / 2,
                point_2.x + scene.width / 2,
                point_2.y + scene.height / 2
           );
}

error_t DrawLinkages(const scene_t &scene, const linkages_t &linkages, const points_t &points)
{
    if (linkages.array == nullptr || points.array == nullptr)
        return MEMORY_ERROR;

    for (size_t i = 0; i < linkages.count; ++i)
        DrawLinkage(scene, linkages.array[i], points);

    return SUCCESS;
}
