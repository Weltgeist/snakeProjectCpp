#include <SDL2/SDL.h>
#include "snake.h"
#include "cube.h"

Snake::Snake()
{
        color={255,0,0};

}

Snake::Snake(int pos[],SDL_Color color,int dirnx,int dirny):color(color),dirnx(dirnx),dirny(dirny)
{

        head= new Cube(pos);
        body.push_back(head);

}

Snake::~Snake()
{
    //dtor
}

bool Snake::move()
{

//     //Handle events on queue
//     while( SDL_PollEvent( &user_event ) != 0 ) { //User requests quit
//         if( e.type == SDL_QUIT ) {
//         quit = true;
//         }
//     }


	SDL_Event event;
    int go=true;
    //SDL_WaitEvent(&event);
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
        go = false;
        break;
        case SDL_KEYDOWN: /* Si appui sur une touche */
        switch (event.key.keysym.sym)
        {
            case SDLK_ESCAPE:
            go = false;
            break;
            case SDLK_UP:

            break;
            case SDLK_DOWN:

            break;
            case SDLK_RIGHT:

            break;
            case SDLK_LEFT:

            break;


        }
        break;


    }

    return go;


}

void Snake::reset(int pos[])
{
    //ctor
}

void Snake::addCube()
{
    //ctor
}

void Snake::draw(SDL_Surface surface)
{
    //ctor
}


