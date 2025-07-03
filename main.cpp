#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> tasks;

void showMenu() {
    cout << "\n--- TO-DO LIST ---\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

void addTask() {
    cout << "Enter the task: ";
    string task;
    cin.ignore(); // clear input buffer
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added!\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks yet!\n";
        return;
    }

    cout << "Your Tasks:\n";
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void deleteTask() {
    viewTasks();
    if (tasks.empty()) return;

    cout << "Enter task number to delete: ";
    int index;
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number!\n";
    } else {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted!\n";
    }
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: deleteTask(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid option!\n";
        }
    } while (choice != 4);

    return 0;
}
