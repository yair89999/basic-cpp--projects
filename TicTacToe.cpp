#include <iostream>

using namespace std;

class board{
    public:
        char cArrPlacedCharacters[9] = {
            '1','2','3',
            '4','5','6',
            '7','8','9'
        };
        char cArrPlacedCharactersAtFirst[9] = {
            '1','2','3',
            '4','5','6',
            '7','8','9'
        };
        int nArrSize = sizeof(cArrPlacedCharacters) / sizeof(cArrPlacedCharacters[0]);
        char cWhoWon = ' ';
    bool didSomeoneWon(){
        // the O cant win, fix it
        char ArrCheckedOnLine[3];
        
        // the two first for loops, each loop runs over a different line
        for (int i =0; i < this->nArrSize; i +=3){ // check horizontal lines
            ArrCheckedOnLine[0] = this->cArrPlacedCharacters[i];
            ArrCheckedOnLine[1] = this->cArrPlacedCharacters[i+1];
            ArrCheckedOnLine[2] = this->cArrPlacedCharacters[i+2];
            if (ArrCheckedOnLine[0] == ArrCheckedOnLine[1] && ArrCheckedOnLine[1] == ArrCheckedOnLine[2]){
                cout << "We have a line!" << endl;
                this->cWhoWon = ArrCheckedOnLine[0];
                return true;
            }
        }
        for (int i =0; i < this->nArrSize/3; i ++){ // check vertical lines
            ArrCheckedOnLine[0] = this->cArrPlacedCharacters[i];
            ArrCheckedOnLine[1] = this->cArrPlacedCharacters[i+3];
            ArrCheckedOnLine[2] = this->cArrPlacedCharacters[i+3+3];
            if (ArrCheckedOnLine[0] == ArrCheckedOnLine[1] && ArrCheckedOnLine[1] == ArrCheckedOnLine[2]){
                cout << "We have a line!" << endl;
                this->cWhoWon = ArrCheckedOnLine[0];
                return true;
            }
        }
        for (int i =0; i < this->nArrSize/3; i+=4){ // check diagonally line '\'
            ArrCheckedOnLine[0] = this->cArrPlacedCharacters[i];
            ArrCheckedOnLine[1] = this->cArrPlacedCharacters[i+4];
            ArrCheckedOnLine[2] = this->cArrPlacedCharacters[i+4+4];
            if (ArrCheckedOnLine[0] == ArrCheckedOnLine[1] && ArrCheckedOnLine[1] == ArrCheckedOnLine[2]){
                cout << "We have a line!" << endl;
                this->cWhoWon = ArrCheckedOnLine[0];
                return true;
            }
        }
        for (int i =2; i < this->nArrSize/3; i+=2){ // check diagonally line '/'
            ArrCheckedOnLine[0] = this->cArrPlacedCharacters[i];
            ArrCheckedOnLine[1] = this->cArrPlacedCharacters[i+2];
            ArrCheckedOnLine[2] = this->cArrPlacedCharacters[i+2+2];
            if (ArrCheckedOnLine[0] == ArrCheckedOnLine[1] && ArrCheckedOnLine[1] == ArrCheckedOnLine[2]){
                cout << endl;
                cout << "We have a line!" << endl;
                this->cWhoWon = ArrCheckedOnLine[0];
                return true;
            }
        }
        return false; // returning false if everything else didnt work
    }
    bool isBoardFull(){
        for (int i =0; i < this->nArrSize; i ++){
            if (this->cArrPlacedCharacters[i] == this->cArrPlacedCharactersAtFirst[i]){
                return false;
            }
        }
        return true;
    }
};

bool isANumber(char c){ // return true if number, false else
    //  ascii value of:     0                        9
    if ((int)c >= 48 && (int)c <= 57){
        return true;
    }
    return false;
}
bool isEmptySpot(board bUsingBoard, int nPos){
    if (isANumber(bUsingBoard.cArrPlacedCharacters[nPos-1]) == false){ // valid pos(no one placed there yet)
        cout << "You can't place it somewhere where the other user placed in" << endl;
        return false;
    }
    else if (nPos < 1 || nPos > 9){ // valid number(between 1-9)
        cout << "The square number must be between 1-9" << endl;
        return false;
    }
    return true;
}

int main(){
    board bPlayedOnBoard;
    bool bSomeoneWon = false;
    char cWhosTurn = 'X'; // will be X if its the x's turn or O if its the o's turn
    int nPlaceOnSquare;
    cout << "Press on the number of the square you want to put your X/O on" << endl;
    cout << "X starts the game" << endl;
    while (bSomeoneWon == false){
        cout << "   |   |  \n";
        cout << " "<< bPlayedOnBoard.cArrPlacedCharacters[0] << " | " << bPlayedOnBoard.cArrPlacedCharacters[1] << " | " << bPlayedOnBoard.cArrPlacedCharacters[2] << "  \n";
        cout << "___|___|___\n";
        cout << "   |   |   \n";
        cout << " "<< bPlayedOnBoard.cArrPlacedCharacters[3] << " | " << bPlayedOnBoard.cArrPlacedCharacters[4] << " | " << bPlayedOnBoard.cArrPlacedCharacters[5] << "  \n";
        cout << "___|___|___\n";
        cout << "   |   |   \n";
        cout << " "<< bPlayedOnBoard.cArrPlacedCharacters[6] << " | " << bPlayedOnBoard.cArrPlacedCharacters[7] << " | " << bPlayedOnBoard.cArrPlacedCharacters[8] << "  \n";
        cout << "   |   |   \n";


        cout << "On what square do you want to put on? ";
        cin >> nPlaceOnSquare;
        bool placed = false;
        if (isEmptySpot(bPlayedOnBoard, nPlaceOnSquare) == true){
            bPlayedOnBoard.cArrPlacedCharacters[nPlaceOnSquare-1] = cWhosTurn;
            placed = true;
        } else  {
            cout << "On what square do you want to put on? ";
            cin >> nPlaceOnSquare;
            while (isEmptySpot(bPlayedOnBoard, nPlaceOnSquare) == false){
                cout << "On what square do you want to put on? ";
                cin >> nPlaceOnSquare;
                if (isEmptySpot(bPlayedOnBoard, nPlaceOnSquare) == true){ // because there is another input we need another check
                    bPlayedOnBoard.cArrPlacedCharacters[nPlaceOnSquare-1] = cWhosTurn;
                    placed = true;
                }
            }
            if (isEmptySpot(bPlayedOnBoard, nPlaceOnSquare) == true){
                bPlayedOnBoard.cArrPlacedCharacters[nPlaceOnSquare-1] = cWhosTurn;
                placed = true;
            }
        }
        if (placed == true){
            if (cWhosTurn == 'X'){
                cWhosTurn = 'O';
            } else {
                cWhosTurn = 'X';
            }
        }
        bSomeoneWon = bPlayedOnBoard.didSomeoneWon();
        if (bPlayedOnBoard.isBoardFull() == true && bSomeoneWon == false){
            cout << "The game ends with a tie :(" << endl;
        }
    }
    if (bSomeoneWon == true){
        cout << bPlayedOnBoard.cWhoWon << " won the game" << endl;
    }
    cout << "The finished board: " << endl;
    cout << "   |   |  \n";
    cout << " "<< bPlayedOnBoard.cArrPlacedCharacters[0] << " | " << bPlayedOnBoard.cArrPlacedCharacters[1] << " | " << bPlayedOnBoard.cArrPlacedCharacters[2] << "  \n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " "<< bPlayedOnBoard.cArrPlacedCharacters[3] << " | " << bPlayedOnBoard.cArrPlacedCharacters[4] << " | " << bPlayedOnBoard.cArrPlacedCharacters[5] << "  \n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " "<< bPlayedOnBoard.cArrPlacedCharacters[6] << " | " << bPlayedOnBoard.cArrPlacedCharacters[7] << " | " << bPlayedOnBoard.cArrPlacedCharacters[8] << "  \n";
    cout << "   |   |   \n";

    char cYesNoInput;
    cout << "Do you want to play again(y/n)?";
    cin >> cYesNoInput;
    if (cYesNoInput == 'y'){
        main();
    }
    cout << "Thanks for playing my Tic Tac Toe game :)";
}
