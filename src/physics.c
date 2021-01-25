#include "physics.h"
/*
    const float g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };
*/

Model PSX_TestTriangle(){
    Model final = {
        .point_count = 3,
        .position = (vec3){.x = 0, .y = 0, .z = 0},
        .scale = 1.0f,
        .points = malloc(sizeof(vec3) * 3)
    };

    final.points[0] = (vec3){.x = -1.0f, .y = -1.0f, .z = 0.0f};
    final.points[1] = (vec3){.x = 1.0f, .y = -1.0f, .z = 0.0f};
    final.points[2] = (vec3){.x = 0.0f, .y = 1.0f, .z = 0.0f};

    return final;
}