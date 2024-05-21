#include <iostream>
#include <string>
using namespace std;

void printTasks(string tasks[], int taskCount) {
    for(int i = 0; i < taskCount; i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

int main() {
    string tasks[10] = {"", "", "", "", "", "", "", "", "", ""};
    int taskCount = 0;
    int option;

    do {
        system("CLS");
        cout << "To-Do List" << endl;
        cout << "1. Add new task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Delete task" << endl;
        cout << "0. Terminate" << endl;
        cout << "Enter your option: ";
        cin >> option;

        switch(option) {
            case 1:
                if(taskCount >= 10) {
                    cout << "Task list is full." << endl;
                } else {
                    cout << "Enter a new task: ";
                    cin.ignore();
                    getline(cin, tasks[taskCount]);
                    taskCount++;
                }
                break;
            case 2:
                printTasks(tasks, taskCount);
                system("PAUSE");
                break;
            case 3:
                int delTask;
                if(taskCount == 0) {
                    cout << "No tasks to delete." << endl;
                } else {
                    cout << "Enter the task number to delete: ";
                    cin >> delTask;
                    if(delTask < 0 || delTask > taskCount) {
                        cout << "Invalid task number." << endl;
                    } else {
                        for(int i = delTask - 1; i < taskCount - 1; i++) {
                            tasks[i] = tasks[i + 1];
                        }
                        taskCount--;
                    }
                }
                break;
            case 0:
                cout << "Terminating..." << endl;
                break;
            default:
                cout << "Enter a valid option." << endl;
                system("PAUSE");
        }
    } while(option != 0);

    return 0;
}