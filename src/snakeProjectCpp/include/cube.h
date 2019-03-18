#ifndef CUBE_H
#define CUBE_H
#include <SDL2/SDL.h>
#include <vector>
#include <constant.h>



class Cube
{
    private:

        std::vector<int> pos{0,0};
        int dirnx=1;
        int dirny=0;
        SDL_Color color={0,0,0};

    public:

        static int rows;
        static int w;


    public:
        Cube(int start[],int dirnx=1,int dirny=0, SDL_Color color={0,0,0});
        virtual ~Cube();

        void move(int dirnx, int dirny);
        void draw(SDL_Surface surface, bool eyes);

        std::vector<int> getPos()const{
            return pos;
        }
        int getDirnx()const{
            return dirnx;
        }
        int getDirny()const{
            return dirny;
        }

        void setPos(std::vector<int> pos){
            this->pos=pos;
            return;
        }

        void setDirnx(int dirnx){
            this->dirnx=dirnx;
            return;
        }

        void setDirny(int dirny){
            this->dirny=dirny;
            return;
        }
    protected:




};



#endif // CUBE_H
