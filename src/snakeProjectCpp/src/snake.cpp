#include <SDL2/SDL.h>
#include "snake.h"

Snake::Snake()
{
        pos[0]=25;
        pos[1]=25;
        color={255,0,0};

}

Snake::Snake(int pos[],SDL_Color color):color(color)
{
        for(int i=0;i<2;i++){
        this->pos[i]=pos[i];
    }
}

Snake::~Snake()
{
    //dtor
}

void Snake::move()
{
    //ctor
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


