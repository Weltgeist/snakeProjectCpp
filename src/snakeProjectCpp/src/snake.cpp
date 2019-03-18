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
            //std::vector<int> t;
            //std::copy (this->head->getPos(),this->head->getPos()+2,std::back_inserter(t));
            case SDLK_ESCAPE:
                go = false;
            break;
            case SDLK_UP:
                this->dirnx=0;
                this->dirny=1;
                this->turns[this->head->getPos()]={this->dirnx,this->dirny}; //MAPS vector to another vector
            break;
            case SDLK_DOWN:
                this->dirnx=0;
                this->dirny=-1;
                this->turns[this->head->getPos()]={this->dirnx,this->dirny}; //MAPS vector to another vector
            break;
            case SDLK_RIGHT:
                this->dirnx=1;
                this->dirny=0;
                this->turns[this->head->getPos()]={this->dirnx,this->dirny}; //MAPS vector to another vector
            break;
            case SDLK_LEFT:
                this->dirnx=-1;
                this->dirny=0;
                this->turns[this->head->getPos()]={this->dirnx,this->dirny}; //MAPS vector to another vector

            break;


        }
        break;


    }

    for(std::vector<Cube*>::iterator it = this->body.begin();it != this->body.end(); ++it){ //iterator, like a for loop in python

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


