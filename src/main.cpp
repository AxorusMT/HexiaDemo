#include <iostream>

#include <SDL2/SDL.h>
#include "uranium/Application.h"

int main(int argc, const char* argv[])
{
    
    Uranium::Application Hexia(SDL_INIT_VIDEO, "Hexia", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, true, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL, 4, 5, SDL_GL_CONTEXT_PROFILE_CORE);
    Hexia.run(true);
    return 0;
}