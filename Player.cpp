#include "Player.h"

Player::Player(char colorPlayer){
    this->colorPlayer=colorPlayer;

}

char Player::getColor() const{
    return colorPlayer;
}

Player::Player(const Player& other){ /*for big three*/
    this->colorPlayer=other.colorPlayer;
}

Player& Player::operator=(const Player& other){ /*for big three*/
    if(this==&other){ /*if thry equals*/
        return *this;
    }
    else{
        this->colorPlayer=other.colorPlayer;
    }
    return *this;
}

bool Player::move(Hex &b){
    while(1) { 
        int input = b.getInput(getColor());
        if(input == 1) return true;
        if(input == -1) {
            if(colorPlayer=='B'){
                cout << "B: QUIT" << endl;
                b.printBoard();
                cout << "R wins the game." << endl;
            }
            else {
                cout << "R: QUIT" << endl;
                b.printBoard();
                cout << "B wins the game." << endl;
            }
            return false;
        }
        /* else = the input is invalid, so go to the loop again*/
    }
}

Player::~Player(){}