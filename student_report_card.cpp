#include <iostream>
#include <vector>

using namespace std;

class student{
    public:
        string name;
        string sSubjectsGrades = "";
        vector<string> vSubjectsGrades = {};
        student(){ // constructor(takes the input of the name, subject+grades)
            string input;
            cout << "Enter the student's name: " << endl;
            cin >> this->name;
            cout << "Enter the subject name and then the grade in it in this format: subject:grade" << endl;
            cout << "Enter -1 to finish putting the grades" << endl;
            while (input != "-1"){
                cout << "Enter a subject+grade:" << endl;
                cin >> input;
                if (input != "-1"){
                    this-> sSubjectsGrades += input + ",";
                    this->vSubjectsGrades.push_back(input);
                }
            }
            cout << this->sSubjectsGrades << endl;
            cout << "{";
            for (string s:this->vSubjectsGrades){
                cout << s + ",";
            }
            cout << "}" << endl;
        }
        student(string name){ // constructor(takes the input of the subject+grades and gets the name as a parameter)
            this->name = name;
            string input;
            cout << "Enter the subject name and then the grade in it in this format: subject:grade" << endl;
            cout << "Enter -1 to finish putting the grades" << endl;
            while (input != "-1"){
                cout << "Enter a subject+grade:" << endl;
                cin >> input;
                if (input != "-1"){
                    this-> sSubjectsGrades += input + ",";
                    this->vSubjectsGrades.push_back(input);
                }
            }
            cout << this->sSubjectsGrades << endl;
            cout << "{";
            for (string s:this->vSubjectsGrades){
                cout << s + ",";
            }
            cout << "}" << endl;
        }
    
        void printGrades(){ // printing the subjects and grades
            cout << this->name << "'s grades" << endl;
            cout << "Subject    | Grade" << endl;
            for (string subject:this->vSubjectsGrades){
                // spliting it by the : and printing them
                this->printSubjectGrade(subject);
            }
        }
    private:
        void printSubjectGrade(string subject){
            for (int i =0; i < subject.length(); i ++){
                if (subject[i] != ':'){
                    cout << subject[i];
                } else {
                    if ( i <= 7+3-1){ // length of the word "subject"
                        for (int j = i; j < 7+3; j ++){
                            cout << " ";
                        }
                    }
                    cout << " | ";
                }
            }
            cout << endl;
        }
};

int main(){
    student s = student("yair");
    cout << endl;
    s.printGrades();
}