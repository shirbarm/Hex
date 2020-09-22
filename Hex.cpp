#include "Hex.h"

Hex::Hex(int size){
    this->size=size;
    board = new Cell*[size];
	for(int i = 0; i < size; i++) {
		board[i] = new Cell[size];
	}
}

Hex::Hex(const Hex& other){ /*for big tree*/
    this->size=other.size;
    board = new Cell*[size];
	for(int i=0;i<size;i++) {
		board[i] = new Cell[size];
		for(int j=0;j<size;j++) {
			board[i][j] = other.board[i][j];
		}
	}
}

Hex& Hex::operator=(const Hex& other){ /*for big tree*/
    if(this==&other){ /*if they equals*/
        return *this;
    }
    else{
        int size = getSize();
        board = new Cell*[size];
        for (int i = 0; i < size; i++) {
            board[i] = new Cell[size];
            for(int j=0;j<size;j++){
                getBoard()[i][j] = other.board[i][j];
            }
        }
    return *this;
    }
}

int Hex::getSize()const{
    return this->size;
}

Cell** Hex::getBoard(){
    return board;
}

void Hex::printBoard(int size) const{
    for(int i=0;i<size;i++){
        int count=i+1;
        for(int j=0;j<size;j++){
            cout << board[i][j].getColor();
            if(j!=size-1) /*this condition for not print the last space in each line*/
                cout << " "; /*for the space between each letter*/
        }
        cout << endl;

        if(i!=size-1){ /*this condition for not print the last line of spaces*/
            while(count){ /*for the space between the lines*/
                cout << " ";
                count--;
            }
        }
    }
}

int Hex::getInput(char colorPlayer)const{ /*1 if it's good, 0 if it's invalid input, -1 if he quit*/
    string str;
    char c;
    int x,y,number;

    while(1){
        cin >> str;
        if(str=="QUIT"){
            return -1; /*should say who win*/
        }

        if(str.length()==2 || str.length()==3){ /*should be 2 or 3 - for example A8, A11*/
            c = str.at(0);
            if(isupper(c)){ /*is a big letter*/
                switch (c)
                {
                case 'A':
                    y=0;
                    break;
                case 'B':
                    y=1;
                    break;
                case 'C':
                    y=2;
                    break;
                case 'D':
                    y=3;
                    break;
                case 'E':
                    y=4;
                    break;
                case 'F':
                    y=5;
                    break;
                case 'G':
                    y=6;
                    break;
                case 'H':
                    y=7;
                    break;
                case 'I':
                    y=8;
                    break;
                case 'J':
                    y=9;
                    break;
                case 'K':
                    y=10;
                    break;
                default:
                    cout << "Invalid move; the game awaits a valid move" << endl;
                    return 0;
                }
                
            }
            else{ /*the first character isn't an alpgha*/
                cout << "Invalid move; the game awaits a valid move" << endl;
                return 0;
            }

            str = str.substr(1,str.length());
            stringstream s1(str);
            s1 >> number;
            if(number >= 1 && number <= 11){
                x = number-1;
            }
            else{ /*if number bigger then 11 or smaller then 1*/
                cout << "Invalid move; the game awaits a valid move" << endl;
                return 0;
            }
        }
        else{ /*the string is longer then 2*/
            cout << "Invalid move; the game awaits a valid move" << endl;
            return 0;
        }

        if(board[x][y].getColor()!='O'){ /*if this cell has been visited*/
            cout << "Invalid move; the game awaits a valid move" << endl;
            return 0;
        }
        else{ /*update the cell values*/ 
            board[x][y].setX(x);
            board[x][y].setY(y);
            board[x][y].setColor(colorPlayer);
            
        }
        return 1;
    }
}

Hex::~Hex(){
    for(int i=0;i<getSize();i++) {
		delete[] board[i];
	}
	delete[] board;
}