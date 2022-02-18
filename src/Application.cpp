#include <iostream>

#include <SDL2/SDL.h>
#include <glad/glad.h>

#include "uranium/Application.h"


Uranium::Application::Application(Uint32 SDL_Flags, std::string name, int x, int y, int width, int height, bool vsync ,Uint32 SDL_WindowFlags, int gl_major, int gl_minor, SDL_GLprofile profile_mask)
{

    this->SDL_Flags = SDL_Flags;
    this->SDL_WindowFlags = SDL_WindowFlags;
    

    m_Name = name;
    m_X = x;
    m_Y = y;
    m_Width = width;
    m_Height = height;
    m_VSync = vsync;
    // m_Info = info; 

    m_GLMajor = gl_major;
    m_GLMinor = gl_minor;
    m_GLProfileMask = profile_mask;

    m_Window = nullptr;

    if (SDL_Init(SDL_Flags) < 0)
    {
        std::cout << "Error: SDL Cannot initialize: " << SDL_GetError() << std::endl;
    }
    else
    {
        std::cout << "SDL Successfully Initialized!" << std::endl;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, m_GLMajor);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, m_GLMinor);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, m_GLProfileMask);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    //std::cout << "Yo1" << std::endl;
    m_Window = SDL_CreateWindow(m_Name.c_str(), m_X, m_Y, m_Width, m_Height, SDL_WindowFlags);
    //td::cout << "Yo2" << std::endl;
    m_Context = SDL_GL_CreateContext(m_Window);

    gladLoadGLLoader(SDL_GL_GetProcAddress);

}

void Uranium::Application::run(bool run)
{

    m_isApplicationRunning = run;

    while(m_isApplicationRunning)
    {
        glViewport(0, 0, m_Width, m_Height);
        while (SDL_PollEvent(&m_Event))
        {
            if (m_Event.type == SDL_QUIT)
            {
                SDL_Quit();
            }

            const Uint8* state = SDL_GetKeyboardState(NULL);

            if (state[SDL_SCANCODE_SPACE])
            {
                std::cout << "Space key is pressed!" << std::endl;
            }
        }

        glClearColor(1.0f, 0.7f, 0.4f, 1.0f);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(m_Window);
        //SDL_GL_SetSwapInterval((int)m_VSync);

    }
    
    
}

Uranium::Application::~Application()
{
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
    std::cout << "SDL Has successfully quit" << std::endl;

}

void Uranium::Application::setName(std::string name)
{
    m_Name = name;
}

void Uranium::Application::setWindowHeight(int height)
{
    m_Height = height;
}

void Uranium::Application::setWindowWidth(int width)
{
    m_Width = width;
}

void Uranium::Application::setWindowX(int x)
{
    m_X = x;
}

void Uranium::Application::setWindowY(int y)
{
    m_Y = y;
}

void Uranium::Application::setVSync(bool vsync)
{
    m_VSync = vsync;
}

int Uranium::Application::getWindowWidth()
{
    return m_Width;
}

int Uranium::Application::getWindowHeight()
{
    return m_Height;
}

int Uranium::Application::getWindowX()
{
    return m_X;
}

int Uranium::Application::getWindowY()
{
    return m_Y;
}

SDL_GLContext Uranium::Application::getContext()
{
    return m_Context;
}

SDL_Window* Uranium::Application::getWindow()
{
    return m_Window;
}

std::string Uranium::Application::getName()
{
    return m_Name;
}

SDL_Event Uranium::Application::getEvent()
{
    return m_Event;
}

bool Uranium::Application::getVSync()
{
    return m_VSync;
}

int Uranium::Application::getGLMajorVersion()
{
    return m_GLMajor;
}

int Uranium::Application::getGLMinorVersion()
{
    return m_GLMinor;
}

SDL_GLprofile Uranium::Application::getGLProfileMask()
{
    return m_GLProfileMask;
}

bool Uranium::Application::isApplicationRunning()
{
    return m_isApplicationRunning;
}