#include <SDL2/SDL.h>
#include "cube.h"

using namespace std;


int Cube::rows=SCREEN_ROWS;
int Cube::w=SCREEN_WIDTH;

Cube::Cube(int start[], int dirnx,int dirny, SDL_Color color):dirnx(1),dirny(0),color(color)
{
    for(int i=0;i<2;i++){
        pos[i]=start[i];
    }

    //ctor
}

Cube::~Cube()
{
    //dtor
}

void Cube::move(int dirnx, int dirny){
    this->dirnx=dirnx;
    this->dirny=dirny;
    this->pos[0]=this->pos[0]+this->dirnx;
    this->pos[1]=this->pos[1]+this->dirny;

}

void Cube::draw(SDL_Renderer* surface, bool eyes){
    int dis=SCREEN_WIDTH/SCREEN_ROWS;
    int i=pos[0];
    int j=pos[1];
    int center;
    int radius;
    SDL_Point c1;
    SDL_Point c2;

    SDL_SetRenderDrawColor(surface,color.r,color.g,color.b,255);

    SDL_Rect rect;
    SDL_
    rect.x=i*dis+1;
    rect.y=j*dis+1;
    rect.w=dis-2;
    rect.h=dis-2;

    SDL_RenderDrawRect(surface, &rect);
    SDL_RenderFillRect(surface, &rect);

    if(eyes){
        center=dis/2;
        radius=3;
        c1.x=i*dis+center-radius
        c1.y=j*dis+8
        c2.x=i*dis+dis-radius*2
        c2.y=j*dis+8

        //TODO 1: Draw circlers for the eyes. or squares.
    }




}
