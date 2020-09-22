#ifndef Game_H_
#define Game_H_

#include "Player.h"
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Game{
    public:
        Game();
        void start();
        bool checkWinner(int i,int j,char color);
        int CheckNeighbor(int i,int j,int sum,char color);
        /*no need for the big three*/

    private:
        Player p1,p2;
        Hex board;
};

#endif /* Game_H_ */