
#include <string>
#include <SDL2/SDL.h>


namespace Uranium
{
    class Application
    {
        private:
            int m_X;
            int m_Y;
            int m_Width;
            int m_Height;
            int SDL_Flags;
            int SDL_WindowFlags;
            bool m_VSync;
            std::string m_Name;
            bool m_isApplicationRunning;

            int m_GLMajor;
            int m_GLMinor;
            SDL_GLprofile m_GLProfileMask;

            SDL_GLContext m_Context;
            SDL_Window* m_Window;
            SDL_Event m_Event;


        public:
            Application(Uint32 SDL_Flags, std::string name, int x, int y, int width, int height, bool vsync, Uint32 SDL_WindowFlags, int gl_major, int gl_minor, SDL_GLprofile profile_mask);
            ~Application();

            int getWindowX();
            int getWindowY();
            int getWindowWidth();
            int getWindowHeight();
            std::string getName();
            SDL_GLContext getContext();
            SDL_Window* getWindow();
            SDL_Event getEvent();
            bool getVSync();
            int getGLMajorVersion();
            int getGLMinorVersion();
            SDL_GLprofile getGLProfileMask();
            bool isApplicationRunning();

            void setWindowX(int x);
            void setWindowY(int y);
            void setWindowWidth(int width);
            void setWindowHeight(int height);
            void setName(std::string name);
            void setVSync(bool vsync);

            void run(bool run);

    };
}