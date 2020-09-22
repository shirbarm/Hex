#ifndef Cell_H_
#define Cell_H_

#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;

class Cell{
    public:
        Cell(){color='O';}
        Cell(char color);

        /*the big three*/
        Cell(const Cell& other); 
	    Cell& operator=(const Cell& other); 
        virtual ~Cell();
    
        char getColor() const;
        void setColor(char color);
        int getX() const;
        int getY() const;
        void setX(int x);
        void setY(int y);
        void setIsVisited(bool isVisited);
        bool getIsVisited() const;

    private:
        char color; 
        int x,y;
        bool isVisited;
};

#endif