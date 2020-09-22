#ifndef Player_H_
#define Player_H_

#include "Hex.h"
#include "Cell.h"
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Player{
    public:
        Player(){colorPlayer='O';}
        Player(char colorPlayer);
        /*the big three*/
        Player(const Player& other);
	    Player& operator=(const Player& other);
        virtual ~Player();

        inline void setColor( char c){colorPlayer=c;}
        char getColor() const;
        bool move(Hex &b);

    private:
        char colorPlayer;
};

#endif /* Player_H_ */