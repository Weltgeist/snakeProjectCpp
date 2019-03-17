#ifndef SNAKE_H
#define SNAKE_H
#include <SDL2/SDL.h>
#include "SDLC.h"

class snake
{
    public:
        snake(int pos[],SDL_Color color={0,0,0});
        virtual ~snake();

        void move();
        void reset(int pos[]);
        void addCube();
        void draw(SDL_Surface surface);

    protected:

    private:
};

#endif // SNAKE_H
