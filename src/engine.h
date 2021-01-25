#pragma once

#define SDL_MAIN_HANDLED

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "core.h"
#include "physics.h"

typedef struct ENGINE{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_GLContext *context;
    SDL_Event event;
    GLuint program;
    GLuint vertex_buffer;

    Model model;

    int running;

}engine;

engine ENG_Init(int width, int height);

void ENG_Update(engine *eng);
void ENG_Draw(engine *eng);

void ENG_Stop(engine eng);