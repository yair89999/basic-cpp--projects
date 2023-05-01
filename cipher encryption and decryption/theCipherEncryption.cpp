#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;


int getRandomKey(){
    int min = 1;
    int max = 103;
    srand((unsigned) time(0)); //seed
    int range = max - min + 1;
    int num = rand() % range + min;
    //num = pow(num,3);
    return num;
}

void encrypt(string word){
    int originalKey = getRandomKey();
    int key = originalKey % 103;
    cout << "Key:           " << originalKey << endl;
    cout << "Original word: " << word << endl;
    int value;
    for (int i =0; i < word.length(); i ++){
        value = word[i] + key;
        word[i] = value % 126;
    }
    cout << "Encrypted word:" << word << endl;
}
void decrypt(string word,int key){
    cout << "Given key:      " << key << endl;
    cout << "Encrypted word: " << word << endl;
    int value;
    for (int i =0; i < word.length(); i ++){
        value = word[i] - key;
        if (value < 0){
            value = 126+value;
        }
        word[i] = value;
    }
    cout << "Decrypted word: " << word << endl;
}

int main(){
    encrypt("Hello");
    cout << endl;
    decrypt("#@GGJ",89);
}
