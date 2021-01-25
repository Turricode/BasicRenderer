#pragma once

#include <math.h>
#include <stdlib.h>

typedef struct VEC2{
    float x, y;
}vec2;

typedef struct VEC3{
    float x, y, z;
}vec3;

typedef struct VEC4{
    float x, y, z, w;
}vec4;

typedef float *mat2;
typedef float *mat3;
typedef float *mat4;

vec2 v2_identity();
vec3 v3_identity();
vec4 v4_identity();

vec2 v2_add(vec2 v1, vec2 v2);
vec3 v3_add(vec3 v1, vec3 v2);
vec4 v4_add(vec4 v1, vec4 v2);

vec2 v2_mult(vec2 v1, vec2 v2);
vec3 v3_mult(vec3 v1, vec3 v2);
vec4 v4_mult(vec4 v1, vec4 v2);

float v2_dot(vec2 v1, vec2 v2);
float v3_dot(vec3 v1, vec3 v2);
float v4_dot(vec4 v1, vec4 v2);

float v2_norm(vec2 v);
float v3_norm(vec3 v);
float v4_norm(vec4 v);


mat2 m2_identity();
mat3 m3_identity();
mat4 m4_identity();

mat2 m2_add(mat2 m1, mat2 m2);
mat3 m3_add(mat3 m1, mat3 m2);
mat4 m4_add(mat4 m1, mat4 m2);

mat2 m2_mult(mat2 m1, mat2 m2);
mat3 m3_mult(mat3 m1, mat3 m2);
mat4 m4_mult(mat4 m1, mat4 m2);

vec4 m4v4_mult(mat4 m, vec4 v);

vec4 v4_rotateX(vec4 v, float angle);
vec4 v4_rotateY(vec4 v, float angle);
vec4 v4_rotateZ(vec4 v, float angle);