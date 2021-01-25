#include "engine.h"

    const float g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };

//Local funtion loads shader, basicly copy paste of openg website
GLuint LoadShaders(const char *vertex_path, const char *fragment_path){
    GLuint vertex_id = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragment_id = glCreateShader(GL_FRAGMENT_SHADER);

    char *vertex_code = CR_LoadFile(vertex_path, NULL);
    char *fragment_code = CR_LoadFile(fragment_path, NULL);

    GLint result = GL_FALSE;
    int log_len;

    printf("[INFO] Compiling Vertex\n");

    glShaderSource(vertex_id, 1, (const GLchar * const*)&vertex_code, NULL);
    glCompileShader(vertex_id);

    glGetShaderiv(vertex_id, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertex_id, GL_INFO_LOG_LENGTH, &log_len);

    if(log_len > 0){
        char *error_code = malloc(log_len + 1);
        glGetShaderInfoLog(vertex_id, log_len, NULL, error_code);
        printf("%s\n", error_code);
        free(error_code);
    }

    printf("[INFO] Compilation Finished\n");

    printf("[INFO] Compiling Fragment\n");
    glShaderSource(fragment_id, 1, (const GLchar * const*)&fragment_code, NULL);
    glCompileShader(fragment_id);

    glGetShaderiv(fragment_id, GL_COMPILE_STATUS, &result);
    glGetShaderiv(fragment_id, GL_INFO_LOG_LENGTH, &log_len);

    if(log_len > 0){
        char *error_code = malloc(log_len + 1);
        glGetShaderInfoLog(fragment_id, log_len, NULL, error_code);
        printf("%s\n", error_code);
        free(error_code);
    }

    printf("[INFO] Compilation Finished\n");

    GLuint program_id = glCreateProgram();
    glAttachShader(program_id, vertex_id);
    glAttachShader(program_id, fragment_id);
    glLinkProgram(program_id);

    glGetProgramiv(program_id, GL_LINK_STATUS, &result);
    glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &log_len);

    if(log_len > 0){
        char *error_code = malloc(log_len + 1);
        glGetProgramInfoLog(program_id, log_len, NULL, error_code);
        printf("%s\n", error_code);
        free(error_code);
    }

    glDetachShader(program_id, vertex_id);
    glDetachShader(program_id, fragment_id);

    glDeleteShader(vertex_id);
    glDeleteShader(fragment_id);

    free(vertex_code);
    free(fragment_code);

    return program_id;

}

engine ENG_Init(int width, int height){
    engine final;
    glewExperimental = GL_TRUE;
    final.running = 1;
    final.model = PSX_TestTriangle();


    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    final.window = SDL_CreateWindow("Prototype", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    final.context = SDL_GL_CreateContext(final.window);

    if(glewInit()){
        printf("[ERROR] FAILED TO START GLEW\n");
    }

    SDL_GL_SetSwapInterval(1);

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * final.model.point_count, final.model.points, GL_STATIC_DRAW);

    final.vertex_buffer = vertexbuffer;
    final.program = LoadShaders("shaders/vertex.glsl", "shaders/fragment.glsl");
    return final;
}

//Update function for the engine
void ENG_Update(engine *eng){
    while(SDL_PollEvent(&eng->event)){
        if(eng->event.type == SDL_QUIT)
            eng->running = 0;
    }
}

//Draw funtion for the engine
void ENG_Draw(engine *eng){
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(eng->program);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, eng->vertex_buffer);
    glVertexAttribPointer(
        0,                  
        3,                  
        GL_FLOAT,           
        GL_FALSE,           
        0,                 
        (void*)0            
    );

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);

    SDL_GL_SwapWindow(eng->window);
}

//Free engine memory
void ENG_Stop(engine eng){
    SDL_GL_DeleteContext(eng.context);
    SDL_DestroyWindow(eng.window);
    SDL_Quit();
}