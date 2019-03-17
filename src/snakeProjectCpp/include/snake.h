#ifndef SNAKE_H
#define SNAKE_H
#include <SDL2/SDL.h>
#include "SDLC.h"

class Snake
{
    private:

        int pos[2];
        SDL_Color color;
    public:
        Snake();
        Snake(int pos[],SDL_Color color={0,0,0});
        virtual ~Snake();

        void move();
        void reset(int pos[]);
        void addCube();
        void draw(SDL_Surface surface);

    protected:


};

#endif // SNAKE_H
