#ifndef SNAKE_H
#define SNAKE_H
#include <SDL2/SDL.h>
#include <list>
#include <vector>
#include "cube.h"
#include "SDLC.h"

class Snake
{
    private:
        std::vector<class Cube*> body;
        class Cube* head;
        int turns[2];
        SDL_Color color;
        int dirnx;
        int dirny;
    public:
        Snake();
        Snake(int pos[],SDL_Color color={0,0,0},int dirnx=0,int dirny=1);
        virtual ~Snake();

        void move();
        void reset(int pos[]);
        void addCube();
        void draw(SDL_Surface surface);

    protected:


};

#endif // SNAKE_H
