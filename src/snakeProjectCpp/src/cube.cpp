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
   // SDL_Rect()
    //SDL_RenderDrawRect(SDL_Renderer*   renderer,
                      // const SDL_Rect* rect)


}
