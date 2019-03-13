#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include "SDLC.h"
#include "InitError.h"
#include "constant.h"

SDLC::SDLC( Uint32 flags )
{
    if ( SDL_Init( flags ) != 0 )
        throw InitError();

    if ( SDL_CreateWindowAndRenderer( 640, 480, SDL_WINDOW_SHOWN,
                                      &m_window, &m_renderer ) != 0 )
        throw InitError();
}

SDLC::~SDLC()
{
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
    SDL_Quit();
}

void SDLC::draw()
{

    // Clear the window with a black background
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );
    //Draw lines, dividing the screen in a grid
    drawGrid();
    // Show the window
    SDL_RenderPresent( m_renderer );

    int rgb[] = { 203, 203, 203, // Gray
                  254, 254,  31, // Yellow
                    0, 255, 255, // Cyan
                    0, 254,  30, // Green
                  255,  16, 253, // Magenta
                  253,   3,   2, // Red
                   18,  14, 252, // Blue
                    0,   0,   0  // Black
                };

    SDL_Rect colorBar;
    colorBar.x = 0; colorBar.y = 0; colorBar.w = 90; colorBar.h = 480;

    // Render a new color bar every 0.5 seconds
    for ( int i = 0; i != sizeof rgb / sizeof *rgb; i += 3, colorBar.x += 90 )
    {
        SDL_SetRenderDrawColor( m_renderer, rgb[i], rgb[i + 1], rgb[i + 2], 255 );
        SDL_RenderFillRect( m_renderer, &colorBar );
        SDL_RenderPresent( m_renderer );
        SDL_Delay( 500 );
    }
}

void SDLC::drawGrid()
{
    unsigned int sizeBetween=SCREEN_WIDTH/SCREEN_ROWS;
    unsigned int x=0;
    unsigned int y=0;
        for(unsigned int i=0;i<SCREEN_ROWS;i++){
            x+=sizeBetween;
            y+=sizeBetween;
            SDL_RenderDrawLine( m_renderer, x, 0, x, SCREEN_WIDTH );
            SDL_RenderDrawLine( m_renderer, 0, y, SCREEN_WIDTH, y );
    }
}
