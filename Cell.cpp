#include "Cell.h"

Cell::Cell(char color){
    this->color='O';
}

Cell::Cell(const Cell& other){ /*for big three*/
    this->color=other.color;
    this->x=other.x;
    this->y=other.y;
}

Cell& Cell::operator=(const Cell& other){ /*for big three*/
    if(this==&other){ /*if they equals*/
        return *this;
    }
    else{
        this->color=other.color;
        this->isVisited=other.isVisited;
        this->x=other.x;
        this->y=other.y;
    }
    return *this;
}

char Cell::getColor() const{
    return color;
}

void Cell::setColor(char color){
    this->color = color;
}

int Cell::getX() const{
    return x;
}

int Cell::getY() const{
    return y;
}
        
void Cell::setX(int x){
    this->x = x;
}

void Cell::setY(int y){
    this->y = y;
}

void Cell::setIsVisited(bool isVisited){ 
    this->isVisited=isVisited;
}

bool Cell::getIsVisited() const{
    if(this->isVisited==true) return true;
    return false;
}

Cell::~Cell(){}