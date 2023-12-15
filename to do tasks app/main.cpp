#include <iostream>
#include <vector>
#include <string> 
#include <fstream>

using namespace std;

void loadAllToDoTasks(vector<string>* v) {
	ifstream tasksFile("tasks.txt");
	string task;
	while (getline(tasksFile, task)) {
		if (task != "") {
			(*v).push_back(task);
		}
	}
}
void saveAllToDoTasks(vector<string>* v) {
	ofstream tasksFile("tasks.txt");
	string tasks = "";
	for (string s : *v) {
		tasks += s + "\n";
	}
	tasksFile << tasks;
}

void removeFromVector(vector<string> *vs, string value) {
	vector<string> newvs = {};
	for (string s : *vs) {
		if (s != value) {
			newvs.push_back(s);
		}
	}
	*vs = newvs;
}

int main() {
	vector<string> tasksToDo = {};
	loadAllToDoTasks(&tasksToDo);

	cout << "What action do you want to do?" << endl;
	cout << "1. enter task to the list" << endl;
	cout << "2. mark task as done" << endl;
	cout << "3. print to do tasks" << endl;
	cout << "4. exit" << endl;
	cout << "Action number: ";
	int action;
	cin >> action;

	cin.ignore(); // make possible to use getline(cin,var) func
	cout << endl;
	if (action == 1) {
		string task;
		cout << ">What task to you want to enter?\n";
		getline(cin, task);
		tasksToDo.push_back(task);
		saveAllToDoTasks(&tasksToDo);
		cout << "\nTask saved" << endl;
	}
	else if (action == 2) {
		cout << "Tasks to do:" << endl;
		int i = 1;
		for (string s : tasksToDo) {
			cout << i << ". " << s << endl;
			i += 1;
		}
		cout << endl;
		cout << "Enter the task number: " << endl;
		int indexOfRemovingString;
		cin >> indexOfRemovingString;
		removeFromVector(&tasksToDo, tasksToDo[indexOfRemovingString - 1]);
		cout << "Task marked as completed!" << endl;
	}
	else if (action == 3) {
		if (tasksToDo.size() != 0) {
			cout << "Tasks to do:" << endl;
			int i = 1;
			for (string s : tasksToDo) {
				cout << i << ". " << s << endl;
				i += 1;
			}
			cout << endl;
		}
		if (tasksToDo.size() == 0) {
			cout << "You don't have any task to do :)" << endl;
		}
	}
	else if (action == 4) {
		exit(0); // 0 means exit successfully
	}

	saveAllToDoTasks(&tasksToDo);
	main();
}