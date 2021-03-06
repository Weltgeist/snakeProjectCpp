#include <SDL2/SDL.h>
#include "snake.h"
#include "cube.h"
#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

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
std::vector<int> p;
std::vector<int> turn;
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
                this->dirny=-1;
                this->turns[this->head->getPos()]={this->dirnx,this->dirny}; //MAPS vector to another vector
            break;
            case SDLK_DOWN:
                this->dirnx=0;
                this->dirny=1;
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


    //for(std::vector<Cube*>::iterator it = this->body.begin();it != this->body.end(); ++it){ //iterator, like a for loop in python
        unsigned int i;
        i=0;
        for( i=0;i<body.size();i++){
            p=body[i]->getPos(); //get position of cube object
                cout<<"Move 0"<<endl;
            if(turns.find(p)!=turns.end()){ // if p is in the turns OR turns.count(p)
                    turn=turns[p];
                    body[i]->move(turn[0],turn[1]);
                     cout<<"Move 1"<<endl;
            for( std::map<std::vector<int>,std::vector<int>> ::const_iterator it = turns.cbegin(); it != turns.cend(); ++it)
                {
                    std::cout << it->first[0] << " "<< it->first[1] << " " << it->second[0]<< " " << it->second[1]<< "\n";
                }

                    if(i==body.size()-1){
                        turns.erase(p);
                        //cout<<"Cond?"<<endl;
                        } //if we are on last cube, we remove the turn
       }
            else{
                if(((body[i]->getDirnx())==-1) && (body[i]->getPos()[0])<=0){body[i]->setPos({SCREEN_ROWS-1,body[i]->getPos()[1]});} //check if outside of screen
                else if(((body[i]->getDirnx())==1 )&& (body[i]->getPos()[0])>=(int)SCREEN_ROWS-1){body[i]->setPos({0,body[i]->getPos()[1]});}
                else if(((body[i]->getDirny())==-1 ) && (body[i]->getPos()[1])>=(int)SCREEN_HEIGHT-1){body[i]->setPos({body[i]->getPos()[0],0});} //down
                else if(((body[i]->getDirny())==1 )&& (body[i]->getPos()[1])<=0){body[i]->setPos({body[i]->getPos()[0],SCREEN_HEIGHT-1});}
                else{body[i]->move(body[i]->getDirnx(),body[i]->getDirny());}
                body[i]->move(body[i]->getDirnx(),body[i]->getDirny());
                cout<<"Move 2"<<endl;
                cout<<body[i]->getDirnx()<<body[i]->getDirny()<<endl;
            for( std::map<std::vector<int>,std::vector<int>> ::const_iterator it = turns.cbegin(); it != turns.cend(); ++it)
                {
                    std::cout << it->first[0] << " "<< it->first[1] << " " << it->second[0]<< " " << it->second[1]<< "\n";
                }





            }

        }



    return go;


}

void Snake::reset(int pos[])
{
    //ctor
}

void Snake::addCube()
{
    Cube* tail=body.back();
    int dx=tail->getDirnx();
    int dy=tail->getDirny();
    int arr[2];
    Cube*p;

    if (dx == 1 && dy == 0)
    {arr[0]=tail->getPos()[0]-1;
     arr[1]=tail->getPos()[1];
        p=new Cube(arr,0,0,{255,0,0});
            body.push_back(p);}
    else if (dx == -1 && dy == 0)
    {arr[0]=tail->getPos()[0]+1;
     arr[1]=tail->getPos()[1];
        p=new Cube(arr,0,0,{255,0,0});
            body.push_back(p);}
    else if (dx == 0 && dy == 1)
    {arr[0]=tail->getPos()[0];
     arr[1]=tail->getPos()[1]-1;
        p=new Cube(arr,0,0,{255,0,0});
            body.push_back(p);}
    else if (dx == 0 && dy == -1)
    {arr[0]=tail->getPos()[0];
     arr[1]=tail->getPos()[1]+1;
        p=new Cube(arr,0,0,{255,0,0});
            body.push_back(p);}

    body.back()->setDirnx(dx);
    body.back()->setDirny(dy);
}

void Snake::draw(SDL_Renderer* surface)
{
            for(unsigned int i=0;i<body.size();i++){
                if (i==0){
                    body[i]->draw(surface,true); //true to add eyes
                }
                else{
                    body[i]->draw(surface,false);
                }



            }







}


