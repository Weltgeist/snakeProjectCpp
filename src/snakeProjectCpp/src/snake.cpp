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


