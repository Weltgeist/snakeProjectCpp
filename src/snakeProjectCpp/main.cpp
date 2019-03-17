#include <exception>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <resPath.h>
#include "InitError.h"
#include "SDLC.h"
#include "snake.h"
#include "cube.h"

using namespace std;

void messageBox(string subject, string content);

void randomSnack(int rows, snake s);

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
        sdl.draw();

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

void randomSnack(int rows, snake s){

}
