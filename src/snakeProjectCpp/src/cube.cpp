#include "cube.h"

cube::cube(int start[], int dirnx,int dirny, SDL_Color color):dirnx(1),dirny(0),color(color)
{
    for(int i=0;i<2;i++){
        pos[i]=start[i];
    }
    //ctor
}

cube::~cube()
{
    //dtor
}

void cube::move(int dirnx, int dirny){

}

void cube::draw(SDL_Surface surface, bool eyes,int rows,int w){
}