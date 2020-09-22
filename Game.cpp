#include "Game.h"

Game::Game(){
    p1.setColor('B');
    p2.setColor('R');
}


void Game::start(){
    int cnt=0;
    int gameIsOn=1;
    int thereIsWinner=0;

    while(gameIsOn){ /*if R or B won the game, so gameIsOn return 0*/
        if(cnt%2==0){
            board.printBoard(); 
            cout << "B:" << endl;
            gameIsOn=p1.move(board);
            thereIsWinner=checkWinner(0,0,p1.getColor()); /*check all board*/
            if(thereIsWinner){
                cout << "B wins the game." << endl;
                return;
            }
            cnt++;
        }
        else{
            board.printBoard();
            cout << "R:" << endl;
            gameIsOn=p2.move(board);
            thereIsWinner=checkWinner(0,0,p2.getColor()); /*check all board*/
            if(thereIsWinner){
                cout << "R wins the game." << endl;
                return;
            }
            cnt++;
        }
    }
}

bool Game::checkWinner(int i,int j,char color){
    int sum=0;
    int indexToReturn=0;
    for(int k=0;k<board.getSize();k++){ /*check just the first row/col*/
        if(p1.getColor()==color){ /*check for blue*/
            if(board.getBoard()[k][0].getColor()==color){ /*check the first coloum of the board*/
                indexToReturn=CheckNeighbor(k,j,sum,color); /*j=0*/
                if(indexToReturn==1) return true;
            }
        }
        if(p2.getColor()==color){ /*check for red*/
            if(board.getBoard()[0][k].getColor()==color){ /*check the first coloum of the board*/
                indexToReturn=CheckNeighbor(i,k,sum,color); /*i=0*/
                if(indexToReturn==1) return true;
            }
        }
    }
    return false;
}


int Game::CheckNeighbor(int i,int j,int sum,char color){ /*will check 6 neighbors*/
    if(board.getBoard()[i][j].getColor()==p1.getColor() && j==board.getSize()-1){ /*this cell for blue*/
        return sum+1;
    }
    
    if(board.getBoard()[i][j].getColor()==p2.getColor() && i==board.getSize()-1){ 
        return sum+1;
    }

    /*check neighbors*/
    if(i==0 && j==0){ /*top left - just 2 neighbors*/
        board.getBoard()[i][j].setIsVisited(true);
        if(board.getBoard()[i][j+1].getColor()==color && board.getBoard()[i][j+1].getIsVisited()==false){
            board.getBoard()[i][j+1].setIsVisited(true);
            sum=CheckNeighbor(i,j+1,sum,color);
            board.getBoard()[i][j+1].setIsVisited(false);
        }
        if(board.getBoard()[i+1][j].getColor()==color && board.getBoard()[i+1][j].getIsVisited()==false){
            board.getBoard()[i+1][j].setIsVisited(true);
            sum=CheckNeighbor(i+1,j,sum,color);
            board.getBoard()[i+1][j].setIsVisited(false);
        }
    }

    if(i==board.getSize()-1 && j==0){ /*bottom left - just 3 neighbors*/
        if(board.getBoard()[i-1][j].getColor()==color && board.getBoard()[i-1][j].getIsVisited()==false){
            board.getBoard()[i-1][j].setIsVisited(true);
            sum=CheckNeighbor(i-1,j,sum,color);
            board.getBoard()[i-1][j].setIsVisited(false);
        }
        if(board.getBoard()[i-1][j+1].getColor()==color && board.getBoard()[i-1][j+1].getIsVisited()==false){
            board.getBoard()[i-1][j+1].setIsVisited(true);
            sum=CheckNeighbor(i-1,j+1,sum,color);
            board.getBoard()[i-1][j+1].setIsVisited(false);
        }
        if(board.getBoard()[i][j+1].getColor()==color && board.getBoard()[i][j+1].getIsVisited()==false){
            board.getBoard()[i][j+1].setIsVisited(true);
            sum=CheckNeighbor(i,j+1,sum,color);
            board.getBoard()[i][j+1].setIsVisited(false);
        }
    }

    if(i==0 && j==board.getSize()-1){ /*top right - just 3 neighbors*/
        if(board.getBoard()[i][j-1].getColor()==color && board.getBoard()[i][j-1].getIsVisited()==false){
            board.getBoard()[i][j-1].setIsVisited(true);
            sum=CheckNeighbor(i,j-1,sum,color);
            board.getBoard()[i][j-1].setIsVisited(false);
        }
        if(board.getBoard()[i+1][j-1].getColor()==color && board.getBoard()[i+1][j-1].getIsVisited()==false){
            board.getBoard()[i+1][j-1].setIsVisited(true);
            sum=CheckNeighbor(i+1,j-1,sum,color);
            board.getBoard()[i+1][j-1].setIsVisited(false);
        }
        if(board.getBoard()[i+1][j].getColor()==color && board.getBoard()[i+1][j].getIsVisited()==false){
            board.getBoard()[i+1][j].setIsVisited(true);
            sum=CheckNeighbor(i+1,j,sum,color);
            board.getBoard()[i+1][j].setIsVisited(false);
        }
    }

    if(i==board.getSize()-1 && j==board.getSize()-1){ /*bottom right - just 2 neighbors*/
        if(board.getBoard()[i][j-1].getColor()==color && board.getBoard()[i][j-1].getIsVisited()==false){
            board.getBoard()[i][j-1].setIsVisited(true);
            sum=CheckNeighbor(i,j-1,sum,color);
            board.getBoard()[i][j-1].setIsVisited(false);
        }
        if(board.getBoard()[i-1][j].getColor()==color && board.getBoard()[i-1][j].getIsVisited()==false){
            board.getBoard()[i-1][j].setIsVisited(true);
            sum=CheckNeighbor(i-1,j,sum,color);
            board.getBoard()[i-1][j].setIsVisited(false);
        }
    }

    if(i!=0 && j==0){ /*first coloum without (0,0) (10,0)*/
        if(board.getBoard()[i-1][j].getColor()==color && board.getBoard()[i-1][j].getIsVisited()==false){
            board.getBoard()[i-1][j].setIsVisited(true);
            sum=CheckNeighbor(i-1,j,sum,color);
            board.getBoard()[i-1][j].setIsVisited(false);
        }
        if(board.getBoard()[i-1][j+1].getColor()==color && board.getBoard()[i-1][j+1].getIsVisited()==false){
            board.getBoard()[i-1][j+1].setIsVisited(true);
            sum=CheckNeighbor(i-1,j+1,sum,color);
            board.getBoard()[i-1][j+1].setIsVisited(false);
        }
        if(board.getBoard()[i][j+1].getColor()==color && board.getBoard()[i][j+1].getIsVisited()==false){
            board.getBoard()[i][j+1].setIsVisited(true);
            sum=CheckNeighbor(i,j+1,sum,color);
            board.getBoard()[i][j+1].setIsVisited(false);
        }
        if(board.getBoard()[i+1][j].getColor()==color && board.getBoard()[i+1][j].getIsVisited()==false){
            board.getBoard()[i+1][j].setIsVisited(true);
            sum=CheckNeighbor(i+1,j,sum,color);
            board.getBoard()[i+1][j].setIsVisited(false);
        }
    }

    if(i!=0 && j==board.getSize()-1){ /*last coloum without (0,10) (10,10)*/
        if(board.getBoard()[i-1][j].getColor()==color && board.getBoard()[i-1][j].getIsVisited()==false){
            board.getBoard()[i-1][j].setIsVisited(true);
            sum=CheckNeighbor(i-1,j,sum,color);
            board.getBoard()[i-1][j].setIsVisited(false);
        }
        if(board.getBoard()[i][j-1].getColor()==color && board.getBoard()[i][j-1].getIsVisited()==false){
            board.getBoard()[i][j-1].setIsVisited(true);
            sum=CheckNeighbor(i,j-1,sum,color);
            board.getBoard()[i][j-1].setIsVisited(false);
        }
        if(board.getBoard()[i+1][j-1].getColor()==color && board.getBoard()[i+1][j-1].getIsVisited()==false){
            board.getBoard()[i+1][j-1].setIsVisited(true);
            sum=CheckNeighbor(i+1,j-1,sum,color);
            board.getBoard()[i+1][j-1].setIsVisited(false);
        }
        if(board.getBoard()[i+1][j].getColor()==color && board.getBoard()[i+1][j].getIsVisited()==false){
            board.getBoard()[i+1][j].setIsVisited(true);
            sum=CheckNeighbor(i+1,j,sum,color);
            board.getBoard()[i+1][j].setIsVisited(false);
        }
    }
    
    else if(i==0 && j!=0){ /*first row without (0,0) (0,10)*/
        if(board.getBoard()[i][j+1].getColor()==color && board.getBoard()[i][j+1].getIsVisited()==false){
            board.getBoard()[i][j+1].setIsVisited(true);
            sum=CheckNeighbor(i,j+1,sum,color);
            board.getBoard()[i][j+1].setIsVisited(false);
        }
        if(board.getBoard()[i][j-1].getColor()==color && board.getBoard()[i][j-1].getIsVisited()==false){
            board.getBoard()[i][j-1].setIsVisited(true);
            sum=CheckNeighbor(i,j-1,sum,color);
            board.getBoard()[i][j-1].setIsVisited(false);
        }
        if(board.getBoard()[i+1][j-1].getColor()==color && board.getBoard()[i+1][j-1].getIsVisited()==false){
            board.getBoard()[i+1][j-1].setIsVisited(true);
            sum=CheckNeighbor(i+1,j-1,sum,color);
            board.getBoard()[i+1][j-1].setIsVisited(false);
        }
        if(board.getBoard()[i+1][j].getColor()==color && board.getBoard()[i+1][j].getIsVisited()==false){
            board.getBoard()[i+1][j].setIsVisited(true);
            sum=CheckNeighbor(i+1,j,sum,color);
            board.getBoard()[i+1][j].setIsVisited(false);
        }
    }

    if(i==board.getSize()-1 && j!= 0){ /*last row without (10,0) (10,10)*/
        if(board.getBoard()[i][j-1].getColor()==color && board.getBoard()[i][j-1].getIsVisited()==false){
            board.getBoard()[i][j-1].setIsVisited(true);
            sum=CheckNeighbor(i,j-1,sum,color);
            board.getBoard()[i][j-1].setIsVisited(false);
        }
        if(board.getBoard()[i-1][j].getColor()==color && board.getBoard()[i-1][j].getIsVisited()==false){
            board.getBoard()[i-1][j].setIsVisited(true);
            sum=CheckNeighbor(i-1,j,sum,color);
            board.getBoard()[i-1][j].setIsVisited(false);
        }
        if(board.getBoard()[i-1][j+1].getColor()==color && board.getBoard()[i-1][j+1].getIsVisited()==false){
            board.getBoard()[i-1][j+1].setIsVisited(true);
            sum=CheckNeighbor(i-1,j+1,sum,color);
            board.getBoard()[i-1][j+1].setIsVisited(false);
        }
        if(board.getBoard()[i][j+1].getColor()==color && board.getBoard()[i][j+1].getIsVisited()==false){
            board.getBoard()[i][j+1].setIsVisited(true);
            sum=CheckNeighbor(i,j+1,sum,color);
            board.getBoard()[i][j+1].setIsVisited(false);
        }
    }
    
    /*the cell in the middle of the board check 6 options*/
    else{
        if(i>0 && j>0){/*for prevent sigmentation fault*/
            if(board.getBoard()[i-1][j].getColor()==color && board.getBoard()[i-1][j].getIsVisited()==false){
                board.getBoard()[i-1][j].setIsVisited(true);
                sum=CheckNeighbor(i-1,j,sum,color);
                board.getBoard()[i-1][j].setIsVisited(false);
            }

            if(board.getBoard()[i-1][j+1].getColor()==color && board.getBoard()[i-1][j+1].getIsVisited()==false){
                board.getBoard()[i-1][j+1].setIsVisited(true);
                sum=CheckNeighbor(i-1,j+1,sum,color);
                board.getBoard()[i-1][j+1].setIsVisited(false);
            }

            if (board.getBoard()[i][j-1].getColor()==color && board.getBoard()[i][j-1].getIsVisited()==false){
                board.getBoard()[i][j-1].setIsVisited(true);
                sum=CheckNeighbor(i,j-1,sum,color);
                board.getBoard()[i][j-1].setIsVisited(false);
            }

            if(board.getBoard()[i][j+1].getColor()==color && board.getBoard()[i][j+1].getIsVisited()==false){
                board.getBoard()[i][j+1].setIsVisited(true);
                sum=CheckNeighbor(i,j+1,sum,color);
                board.getBoard()[i][j+1].setIsVisited(false);
            }

            if(board.getBoard()[i+1][j-1].getColor()==color && board.getBoard()[i+1][j-1].getIsVisited()==false){
                board.getBoard()[i+1][j-1].setIsVisited(true);
                sum=CheckNeighbor(i+1,j-1,sum,color);
                board.getBoard()[i+1][j-1].setIsVisited(false);
            }
            if(board.getBoard()[i+1][j].getColor()==color && board.getBoard()[i+1][j].getIsVisited()==false){
                board.getBoard()[i+1][j].setIsVisited(true);
                sum=CheckNeighbor(i+1,j,sum,color);
                board.getBoard()[i+1][j].setIsVisited(false);
            }
        }
    }

    board.getBoard()[i][j].setIsVisited(false);
    return sum;
}