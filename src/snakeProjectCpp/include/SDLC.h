#ifndef SDLC_H
#define SDLC_H
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include "InitError.h"

class SDLC
{
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
public:
    SDLC( Uint32 flags = 0 );
    virtual ~SDLC();
    void draw();
};

#endif // SDLC_H
