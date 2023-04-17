#include <iostream>
#include <vector>

using namespace std;

/*
This is a "search engine" file that can act as a library
*/

string searchS(string toSearch, string arr[],int nArrLength){ // return a string
    // the function gets a word/word part and returns an array with all of the strings in the array that has that word/word part in them
    /* example:
    toSearch:"he"
    arr[] = {"hello","ello","he","hihe"}
    will return: "hello,he,hihe"
    */

    string sGoodWords = "";
    string sCurrentWord;
    for (int i =0; i < nArrLength; i ++){
        sCurrentWord = arr[i];
        if (sCurrentWord.find(toSearch) != string::npos){ // check if the word is good to get in(there is the toSearch variable in)
            sGoodWords += sCurrentWord += ",";
        }
    }
    return sGoodWords;
}

int searchA(string toSearch, string arr[],int nArrLength){ // return an array pointer
    // the function gets a word/word part and changes everything in the given array that doesn't have that specific word in
    // returns the number of words that has the required word in
    /* example:
    toSearch:"he"
    arr[] = {"hello","ello","he","hihe"}
    will change to: {"hello","he","hihe"}
    */

    string sCurrentWord;
    int nGoodWordsCount = 0;
    for (int i =0; i < nArrLength; i ++){
        sCurrentWord = arr[i];
        if (sCurrentWord.find(toSearch) != string::npos){ // check if the word is good to get in(there is the toSearch variable in)
            nGoodWordsCount += 1;
        } else {
            arr[i] = "";
        }
    }
    string sFinalArr[nGoodWordsCount];
    int nOpenSpaceIndex = 0;
    for (int i =0; i < nArrLength; i ++){
        sCurrentWord = arr[i];
        if (sCurrentWord.find(toSearch) != string::npos){ // check if the word is good to get in(there is the toSearch variable in)
            sFinalArr[nOpenSpaceIndex] = sCurrentWord;
        }
    }

    return nGoodWordsCount;
}

vector<string> searchV(string toSearch, vector<string> searchInV){
    vector<string> vFinalVector;
    for (string sCurrentWord:searchInV){
        if (sCurrentWord.find(toSearch) != string::npos){ // check if the word is good to get in(there is the toSearch variable in)
            vFinalVector.push_back(sCurrentWord);
        }
    }
    return vFinalVector;
}

int main(){
    // vector one
    vector<string> v = {"hello","ello","he","hihe","test"};
    string searchWord = "he";
    cout << "Searched string: " << searchWord << endl;

    vector<string> vWithKeyWordVector = searchV(searchWord,v);
    cout << "Vector searchV(): {";
    for (string s:vWithKeyWordVector){
        cout << s << ", ";
    }
    cout << "}" << endl << endl;


    string b[] = {"hello","ello","he","hihe","test"};
    searchWord = "he";

    cout << "Searched string: " << searchWord << endl;

    // string one
    string wordsString = searchS(searchWord,b,sizeof(b) / sizeof(b[0]));
    cout << "String searchS(): " << wordsString << endl;
    // array one
    int nGoodWordsNum = searchA(searchWord,b,sizeof(b) / sizeof(b[0]));
    // creating the array only with those words
    string searchAArray[nGoodWordsNum];
    int i =0;
    for (string s:b){
        if (s != ""){
            searchAArray[i] = s;
            i +=1;
        }
    }
    // printing the array
    cout << "Array SearchA(): {";
    for (string s:searchAArray){
        cout << s << ",";
    }
    cout << "}" << endl;
    
    /* creating a pointer of an array and returning the value of the array in specific pos
    string (*p)[5] = & b;
    cout << p << endl;
    string c[] = (*p)[0];
    cout << c << endl;*/

}