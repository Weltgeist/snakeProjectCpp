#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include "SDLC.h"
#include "InitError.h"
#include "constant.h"
#include "resPath.h"
#include "snake.h"
#include "cube.h"
#include "Timer.h"

using namespace std;

SDLC::SDLC( unsigned int flags )
{
    if ( SDL_Init( flags ) != 0 )
        throw InitError();

    //if ( SDL_CreateWindowAndRenderer( SCREEN_WIDTH, SCREEN_WIDTH, SDL_WINDOW_SHOWN, &m_window, &m_renderer ) != 0 ) //Combination of SDLCreateWindow & SDL_CreateRenderer
    m_window =SDL_CreateWindow("Weltgeist's Snake Application",  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if ( m_window == nullptr ) // Follow C++11 std
        throw InitError();
    m_renderer=SDL_CreateRenderer(m_window,-1, SDL_RENDERER_ACCELERATED  ); //SDL_RENDERER_PRESENTVSYNC
    if ( m_renderer == nullptr )
        throw InitError();
    std::string imagePath = getResourcePath() + "ok.bmp";
    m_bmp=SDL_LoadBMP(imagePath.c_str());
    if ( m_renderer == nullptr )
        throw InitError();

    SDL_SetWindowIcon(m_window,m_bmp);

    m_tex=SDL_CreateTextureFromSurface(m_renderer,m_bmp );
    if ( m_renderer == nullptr )
        throw InitError();
}

SDLC::~SDLC()
{
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
    SDL_Quit();
}

void SDLC::draw(class Snake* s,class Cube* g,bool &flag) //redraw
{
    class Timer clockFPS;
    class Timer capFPS;
    //unsigned int frameCount = 0;
    unsigned int frameTick=0;
    unsigned int n=0;
    clockFPS.start();
    while(flag){
            //Start cap timer

            SDL_Delay( 50 );
            flag=(s->move());
            n++;
            if(n!=0){
            frameTick=capFPS.getTicks();}
            capFPS.start();
            cout<<frameTick<<endl;
            //if( frameTick < SCREEN_TICKS_PER_FRAME ){
                //Wait remaining time
            //    SDL_Delay( SCREEN_TICKS_PER_FRAME - frameTick ); //SCREEN_TICKS_PER_FRAME - frameTick
             //    cout<<"cond2"<<endl;
            //}
            SDL_Delay( 100);
            if((s->getBody()[0])->getPos()==g->getPos()){s->addCube();}
            redraw(s,g);
            SDL_Delay( 100 );

    }
}

void SDLC::redraw(class Snake* s,class Cube* g){

        //J:\Git\Software\Cpp\snakeProjectCpp\src\snakeProjectCpp\include\cube.h
        //Clear the window with a black background
        SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
        SDL_RenderClear( m_renderer );
        //Draw lines, dividing the screen in a grid
        drawGrid();
        //Draw snake;
        s->draw( m_renderer );
        g->draw( m_renderer,false);


        // Show the window
        SDL_RenderPresent( m_renderer ); //draw function

    //    int rgb[] = { 203, 203, 203, // Gray
    //                  254, 254,  31, // Yellow
    //                    0, 255, 255, // Cyan
    //                    0, 254,  30, // Green
    //                  255,  16, 253, // Magenta
    //                  253,   3,   2, // Red
    //                   18,  14, 252, // Blue
    //                    0,   0,   0  // Black
    //                };

    //    SDL_Rect colorBar;
    //    colorBar.x = 0; colorBar.y = 0; colorBar.w = 90; colorBar.h = 480;

        // Render a new color bar every 0.5 seconds
       // for ( int i = 0; i != sizeof rgb / sizeof *rgb; i += 3, colorBar.x += 90 )
       // {
            //SDL_SetRenderDrawColor( m_renderer, rgb[i], rgb[i + 1], rgb[i + 2], 255 );
            //SDL_RenderFillRect( m_renderer, &colorBar );
            //SDL_RenderPresent( m_renderer );
            //SDL_Delay( 500 );
       // }



}

void SDLC::drawGrid()
{
    unsigned int sizeBetween=SCREEN_WIDTH/SCREEN_ROWS;
    unsigned int x=0;
    unsigned int y=0;
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
        for(unsigned int i=0;i<SCREEN_ROWS;i++){
            x+=sizeBetween;
            y+=sizeBetween;
            SDL_RenderDrawLine( m_renderer, x, 0, x, SCREEN_WIDTH );
            SDL_RenderDrawLine( m_renderer, 0, y, SCREEN_WIDTH, y );
    }
}
