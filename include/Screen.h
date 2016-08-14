#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

namespace creatingParticles
{

class Screen
{
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer1;
    Uint32 *m_buffer2;

public:
    const static int WINDOW_WIDTH = 800;
    const static int WINDOW_HEIGHT = 600;

public:
    Screen();
    bool init();
    void screenUpdate();
    void setPixel (int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    bool processEvents();
    void boxBlur();
    void close();
};

}
#endif // SCREEN_H
