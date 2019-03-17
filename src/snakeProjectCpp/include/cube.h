#ifndef CUBE_H
#define CUBE_H
#include <SDL2/SDL.h>
#include <vector>
#include <constant.h>



class cube
{
    private:

        int pos[2]={0,0};
        int dirnx=1;
        int dirny=0;
        SDL_Color color={0,0,0};

    public:

        static int rows;
        static int w;

    public:
        cube(int start[],int dirnx=1,int dirny=0, SDL_Color color={0,0,0});
        virtual ~cube();

        void move(int dirnx, int dirny);
        void draw(SDL_Surface surface, bool eyes,int rows,int w);

    protected:




};



#endif // CUBE_H
