#pragma once

#include "graphmat.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct MODEL{
    vec3 *points;
    int point_count;
    vec3 position;
    float scale;
}Model;

Model PSX_TestCube();
Model PSX_TestTriangle();
