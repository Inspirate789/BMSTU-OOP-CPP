#include <cstdio>

#include "draw.h"

void DrawLine(const scene_t &scene, const point_t &point_1, const point_t &point_2)
{
    scene.canvas->addLine(
                point_1.x + scene.width / 2,
                -point_1.y + scene.height / 2,
                point_2.x + scene.width / 2,
                -point_2.y + scene.height / 2
           );
}

void ClearScene(const scene_t &scene)
{
    scene.canvas->clear();
}
