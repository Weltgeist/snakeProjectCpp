#ifndef SDLC_H
#define SDLC_H
#include <string>
#include <iostream>
#include <SDL2/SDL.h>



class SDLC
{
    SDL_Window * m_window; //window
    SDL_Renderer * m_renderer; //render
    SDL_Surface *m_bmp; //image
    SDL_Texture *m_tex;//texture
    //std::string m_imgPath;//image path from res
public:
    SDLC( Uint32 flags = 0 );
    virtual ~SDLC();
    void draw();
    void drawGrid();
};

#endif // SDLC_H
