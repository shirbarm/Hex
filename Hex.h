#ifndef Hex_H_
#define Hex_H_

#include "Cell.h"
#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;


class Hex{
    public:
        enum{BOARD_SIZE = 11};
        Hex(int size = BOARD_SIZE);
        /*the big three*/
        Hex(const Hex& other);
	    Hex& operator=(const Hex& other);
        virtual ~Hex();

        void printBoard(int size = BOARD_SIZE)const;
        int getInput(char colorPlayer)const;
        Cell **getBoard();
        int getSize()const;

    private:
        Cell **board;
        int size;
};

#endif /* Hex_H_ */