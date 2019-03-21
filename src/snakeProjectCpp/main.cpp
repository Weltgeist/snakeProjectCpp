#include <exception>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <resPath.h>
#include "InitError.h"
#include "snake.h"
#include "cube.h"
#include "SDLC.h"
#include <cstdlib>

using namespace std;

void messageBox(string subject, string content);

int* randomSnack(int rows, Snake* s);

//template <typename Collection,typename unop>
//void for_each(Collection col, unop op);
//
//template <typename Collection,typename Predicate>
//Collection filterNot(Collection col,Predicate predicate );
//
//template <typename Collection,typename Predicate>
//Collection filter(Collection col,Predicate predicate);

int main( int argc, char * argv[] )
{
//// Alternative initialization
//    if(SDL_INIT(SDL_INIT|SDL_INIT_TIMER)<0){
//            std::cout<<"SDL could not initialize: "<<SDL_GetError();
//            return 1;
//        }
//    std::cout << "Resource path is: " << getResourcePath() << std::endl;
//    //sdl.draw();
//    //SDL_QUIT();
//    return 0;

    try
    {
        SDLC sdl( SDL_INIT_VIDEO | SDL_INIT_TIMER ); //SDL INIT
        std::cout << "Resource path is: " << getResourcePath() << std::endl;
        SDL_Color red={255,0,0};
        SDL_Color green={0,255,0};
        int initPos[2]={10,10};
        Snake s(initPos,red);
        Cube g(initPos,0,0,green);
        bool flag=true;
        sdl.draw(&s,&g, flag);



        return 0;
    }
    catch ( const InitError & err )
    {
        std::cerr << "Error while initializing SDL:  "
                  << err.what()
                  << std::endl;
    }

    return 1;
}

void messageBox(string subject, string content){

}

int* randomSnack(int rows, Snake* s){
    std::vector<class Cube*> posList;
    posList=s->getBody();
    int x;
    int y;
    int res[2]={15,15};
    bool flag;
//    while(1){
//    flag=false;
//            x=rand() % SCREEN_ROWS;
//            y=rand() % SCREEN_ROWS;
//   // auto lambda=[](Cube* z,int a, int b){ return (z->getPos()[0]==a)&&(z->getPos()[1]==b);};
//
//    for(unsigned int i=0;i<posList.size();i++)
//    {
//     if((posList[i]->getPos()[0]==x)&&(posList[i]->getPos()[1]==y)){flag= true;}
//    }
//    if(!flag){break;}
//    }

    return res;

}


//template <typename Collection,typename Predicate>
//Collection filterNot(Collection col,Predicate predicate ) {
//    auto returnIterator = std::remove_if(col.begin(),col.end(),predicate);
//    col.erase(returnIterator,std::end(col));
//    return col;
//}
//
//template <typename Collection,typename Predicate>
//Collection filter(Collection col,Predicate predicate) {
// //capture the predicate in order to be used inside function
// auto fnCol = filterNot(col,[predicate](typename Collection::value_type i) { return !predicate(i);});
// return fnCol;
//}
//
//template <typename Collection,typename unop>
//void for_each(Collection col, unop op){
//  std::for_each(col.begin(),col.end(),op);
//}
