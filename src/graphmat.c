#include "graphmat.h"

vec2 v2_identity(){
    return (vec2){.x = 1, .y = 1};
}

vec3 v3_identity(){
    return (vec3){.x = 1, .y = 1, .z = 1};
}

vec4 v4_identity(){
    return (vec4){.x = 1, .y = 1, .z = 1, .w = 1};
}

vec2 v2_add(vec2 v1, vec2 v2){
    return (vec2){.x = v1.x + v2.x, .y = v1.y + v2.y};
}

vec3 v3_add(vec3 v1, vec3 v2){
    return (vec3){.x = v1.x + v2.x, .y = v1.y + v2.y, .z = v1.z + v2.z};
}

vec4 v4_add(vec4 v1, vec4 v2){
    return (vec4){.x = v1.x + v2.x, .y = v1.y + v2.y, .z = v1.z + v2.z, .w = v1.w + v2.w};
}

vec2 v2_mult(vec2 v1, vec2 v2){
    return (vec2){.x = v1.x * v2.x, .y = v1.y * v2.y};
}

vec3 v3_mult(vec3 v1, vec3 v2){
    return (vec3){.x = v1.x * v2.x, .y = v1.y * v2.y, .z = v1.z * v2.z};
}

vec4 v4_mult(vec4 v1, vec4 v2){
    return (vec4){.x = v1.x * v2.x, .y = v1.y * v2.y, .z = v1.z * v2.z, .w = v1.w * v2.w};
}

float v2_norm(vec2 v){
    return sqrtf(v.x + v.y);
}

float v3_norm(vec3 v){
    return sqrtf(v.x + v.y + v.z);
}

float v4_norm(vec4 v){
    return sqrtf(v.x + v.y + v.z + v.w);
}

float v2_dot(vec2 v1, vec2 v2){
    return v1.x * v2.x + v1.y * v2.y;
}

float v3_dot(vec3 v1, vec3 v2){
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float v4_dot(vec4 v1, vec4 v2){
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

mat2 m2_identity(){
    mat2 f = malloc(sizeof(float) * 4);
    for(int y = 0; y < 2; y++){
        for(int x = 0; x < 2; x++){
            if(y == x)
                f[y * 2 + x] = 1.0f;
            else
                f[y * 2 + x] = 0.0f;
        }
    }
    return f;
}

mat3 m3_identity(){
    mat3 f = malloc(sizeof(float) * 9);
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            if(y == x)
                f[y * 3 + x] = 1.0f;
            else
                f[y * 3 + x] = 0.0f;
        }
    }
    return f;
}

mat4 m4_identity(){
    mat4 f = malloc(sizeof(float) * 16);
    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
            if(y == x)
                f[y * 4 + x] = 1.0f;
            else
                f[y * 4 + x] = 0.0f;
        }
    }
    return f;    
}

mat2 m2_add(mat2 m1, mat2 m2){
    mat2 final = malloc(sizeof(float) * 4);

    for(int i = 0; i < 4; i++){
        final[i] = m1[i] + m2[i];
    }

    return final;
}

mat3 m3_add(mat3 m1, mat3 m2){
    mat3 final = malloc(sizeof(float) * 9);

    for(int i = 0; i < 9; i++){
        final[i] = m1[i] + m2[i];
    }

    return final;
}

mat4 m4_add(mat4 m1, mat4 m2){
    mat4 final = malloc(sizeof(float) * 16);

    for(int i = 0; i < 16; i++){
        final[i] = m1[i] + m2[i];
    }

    return final;
}

mat2 m2_mult(mat2 m1, mat2 m2){
    mat2 final = malloc(sizeof(float) * 4);

    vec2 lines[2] = {0};
    vec2 cols[2] = {0};

    lines[0] = (vec2){.x = m1[0], .y = m1[1]};
    lines[1] = (vec2){.x = m1[2], .y = m1[3]};

    cols[0] = (vec2){.x = m2[0], .y = m2[2]};
    cols[1] = (vec2){.x = m2[1], .y = m2[3]};

    for(int y = 0; y < 2; y++){
        for(int x = 0; x < 2; x++){
            final[y * 2 + x] = v2_dot(lines[y], cols[x]);
        }
    }

    return final;
}

mat3 m3_mult(mat3 m1, mat3 m2){
    mat3 final = malloc(sizeof(float) * 9);

    vec3 lines[3] = {0};
    vec3 cols[3] = {0};

    lines[0] = (vec3){.x = m1[0], .y = m1[1], .z = m1[2]};
    lines[1] = (vec3){.x = m1[3], .y = m1[4], .z = m1[5]};
    lines[2] = (vec3){.x = m1[6], .y = m1[7], .z = m1[8]};

    cols[0] = (vec3){.x = m2[0], .y = m2[3], .z = m2[6]};
    cols[1] = (vec3){.x = m2[1], .y = m2[4], .z = m2[7]};
    cols[2] = (vec3){.x = m2[2], .y = m2[5], .z = m2[8]};

    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            final[y * 3 + x] = v3_dot(lines[y], cols[x]);
        }
    }

    return final;   
}

mat4 m4_mult(mat4 m1, mat4 m2){
    mat4 final = malloc(sizeof(float) * 16);

    vec4 lines[4] = {0};
    vec4 cols[4] = {0};

    lines[0] = (vec4){.x = m1[0], .y = m1[1], .z = m1[2], .w = m1[3]};
    lines[1] = (vec4){.x = m1[4], .y = m1[5], .z = m1[6], .w = m1[7]};
    lines[2] = (vec4){.x = m1[8], .y = m1[9], .z = m1[10], .w = m1[11]};
    lines[3] = (vec4){.x = m1[12], .y = m1[13], .z = m1[14], .w = m1[15]};

    cols[0] = (vec4){.x = m2[0], .y = m2[4], .z = m2[8], .w = m2[12]};
    cols[1] = (vec4){.x = m2[1], .y = m2[5], .z = m2[9], .w = m2[13]};
    cols[2] = (vec4){.x = m2[2], .y = m2[6], .z = m2[10], .w = m2[14]};
    cols[3] = (vec4){.x = m2[3], .y = m2[7], .z = m2[11], .w = m2[15]};

    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
            final[y * 4 + x] = v4_dot(lines[y], cols[x]);
        }
    }

    return final;   
}

vec4 m4v4_mult(mat4 m, vec4 v){
    vec4 final = {0};

    for(int y = 0; y < 4; y++){
        final.x += m[y] * v.x;
        final.y += m[y + 4] * v.y;
        final.z += m[y + 8] * v.z;
        final.w += m[y + 12] * v.w;
    }

    return final;
}

vec4 v4_rotateX(vec4 v, float angle){
    float mat[16] = {1, 0, 0, 0,
                    0, cosf(angle), -sinf(angle), 0,
                    0, sinf(angle), cosf(angle), 0,
                    0, 0, 0, 1};
    
    return m4v4_mult(mat, v);
}

vec4 v4_rotateY(vec4 v, float angle){
    float mat[16] = {cosf(angle), 0, sinf(angle), 0,
                    0, 1, 0, 0,
                    sinf(angle), 0 , cosf(angle), 0,
                    0, 0, 0, 1};

    return m4v4_mult(mat, v);
}

vec4 v4_rotateZ(vec4 v, float angle){
    float mat[16] = {cosf(angle), -sinf(angle), 0, 0,
                    sinf(angle), cosf(angle), 0, 0,
                    0, 0 , 1, 0,
                    0, 0, 0, 1};
                    
    return m4v4_mult(mat, v);
}