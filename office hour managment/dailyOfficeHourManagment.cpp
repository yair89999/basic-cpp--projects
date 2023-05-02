#include <iostream>
#include <fstream>

using namespace std;

int main(){
    cout << "What action do you want to do?" << endl;
    cout << "1. Set a date to come to the office at" << endl;
    cout << "2. Get the information of who comes at a specific day" << endl;
    cout << "3. Get all of the dates" << endl;

    int decision;
    cout << "Action: ";
    cin >> decision;
    cout << endl;

    if (decision == 1){
        // appending to the file
        ofstream dates;
        dates.open("dates.txt",ios_base::app);
        string name,date;
        cout << "What is your name? ";
        cin >> name;
        cout << "Enter the date in this format dd/mm/yyyy:";
        cin >> date;
        dates << "\n" << name << ":" << date;
    } else if (decision == 2){
        string date;
        cout << "Enter the checking date: ";
        cin >> date;

        string text;
        ifstream dates("dates.txt");
        int indent = 10+2;
        cout << "Name      | date" << endl;
        while (getline (dates, text)) {
            int startIndex;
            for (int i =0; i < text.length(); i ++){
                if (text[i] == ':'){
                        startIndex = i;
                }
            }
            string checkOnDate = "";
            for (int i = startIndex+1; i < text.length();i++){
                checkOnDate += text[i];
            }
            //cout << checkOnDate << " " << date << endl;
            if (checkOnDate == date){
                for (int i =0; i < text.length(); i ++){
                    if (text[i] != ':'){
                        cout << text[i];
                    } else if (text[i] == ':'){
                        if (i < indent){
                            for (int j =i; j < indent; j ++){
                                cout << " ";
                            }
                        }
                    }
                }
                cout << endl;
            }
        }
    } else { // decision == 3
        string text;
        ifstream dates("dates.txt");
        int indent = 10+2;
        cout << "Name      | date" << endl;
        while (getline (dates, text)) {
                for (int i =0; i < text.length(); i ++){
                    if (text[i] != ':'){
                        cout << text[i];
                    } else if (text[i] == ':'){
                        if (i < indent){
                            for (int j =i; j < indent; j ++){
                                cout << " ";
                            }
                        }
                    }
                }
                cout << endl;
            }
    }

    char answer;
    cout << "Do you want to do another action(y/n):" << endl;
    cin >> answer;
    if (answer == 'y'){
        main();
    } // no need to do else, it just finishes the program

}
