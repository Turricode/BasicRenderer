#include "engine.h"
#include "core.h"

int main(int argc, char const *argv[])
{
    engine eng = ENG_Init(800, 600);
    

    while(eng.running){
        ENG_Update(&eng);
        ENG_Draw(&eng);
    }

    ENG_Stop(eng);
}
