#include <iostream>
#include <fstream>

using namespace std;

int getRandomNum(int max, int min){
    srand((unsigned) time(0)); //seed
    int range = max - min + 1;
    int num = rand() % range + min;
    return num;
}


string sWords[12993];
int nWordsArrLength = sizeof(sWords) / sizeof(sWords[0]);
void setPossibleWordsArray(){
    ifstream wordsFile("hangmanWords.txt");
    string sCurrentWord;
    int nIndex = 0;
    while (getline (wordsFile, sCurrentWord)) {
        sWords[nIndex] = sCurrentWord;
        nIndex += 1;
    }
}

string chooseWord(){
    int nWordIndex = getRandomNum(nWordsArrLength,0);
    return sWords[nWordIndex];
}

int main(){
    setPossibleWordsArray();
    string sChosenWord = chooseWord(); //"hello";
    cout << "A word have been selected" << endl;
    string sHiddenWord = ""; //this is the string that starts as **** and the user finds and change its values depend if his answer is right or wrong
    for (int i =0; i < sChosenWord.length(); i++){ // making the word with _
        sHiddenWord += "*";
    }
    cout << "The word is: " <<  sHiddenWord << endl;

    int nWrongTries = 5; // user has 5 tries to guess the word, each wrong guess this variable is going down by one
    char cUserGuess;

    while (nWrongTries != 0 && sChosenWord != sHiddenWord){
        cout << "Enter your guess: ";
        cin >> cUserGuess;
        
        // checking if his guess is correct
        bool bGuessedRight = false;
        for (int i =0; i < sChosenWord.length(); i++){
            if (sChosenWord[i] == cUserGuess){
                sHiddenWord[i] = cUserGuess;
                bGuessedRight = true;
            }
        }
        if (bGuessedRight == true){
            cout << "You are right" << endl;
            cout << "The word now is: " << sHiddenWord << endl;
        } else {
            nWrongTries -= 1;
            cout << "You guess is wrong" << endl;
            cout << "You have " << nWrongTries << " more guesses" << endl;
        }
    }

    cout << endl; // going down a line for better look
    if (nWrongTries == 0){
        cout << "You couldn't guess the word :(" << endl;
        cout << "The word is: " << sChosenWord << endl;
    } else if (sChosenWord == sHiddenWord){
        cout << "Correct, the word is: " << sChosenWord << endl;
    }

    char cYesNoInput;
    cout << "Would you like to play again(y/n)? ";
    cin >> cYesNoInput;
    if (cYesNoInput == 'y'){
        main();
    }
    cout << "Thanks for playing my hangman game :)";
}