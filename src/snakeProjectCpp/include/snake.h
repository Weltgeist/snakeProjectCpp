#ifndef SNAKE_H
#define SNAKE_H
#include <SDL2/SDL.h>
#include <list>
#include <vector>
#include <map>
#include "cube.h"
#include "SDLC.h"

class Snake
{
    private:
        std::vector<class Cube*> body;
        class Cube* head;
        std::map<std::vector<int>,std::vector<int>>  turns;
        SDL_Color color;
        int dirnx;
        int dirny;
    public:
        Snake();
        Snake(int pos[],SDL_Color color={0,0,0},int dirnx=0,int dirny=1);
        virtual ~Snake();

        bool move();
        void reset(int pos[]);
        void addCube();
        void draw(SDL_Renderer* surface);

        std::vector<class Cube*> getBody()const{
            return body;
        }



    protected:


};

#endif // SNAKE_H
