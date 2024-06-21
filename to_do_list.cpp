#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Function to add a new task to the list
void addTask(vector<Task>& tasks, const string& description) {
    tasks.push_back(Task(description));
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    cout << "\n==================== TO-DO LIST ====================\n";
    cout << setw(4) << "No." << setw(20) << "Description" << setw(15) << "Status" << endl;
    cout << "-----------------------------------------------------\n";

    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << setw(4) << i + 1 << setw(20) << tasks[i].description << setw(15);
        if (tasks[i].completed) {
            cout << "Completed";
        } else {
            cout << "Pending";
        }
        cout << endl;
    }
    cout << "=====================================================\n";
}

// Function to mark a task as completed
void markCompleted(vector<Task>& tasks, int index) {
    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
    } else {
        cout << "Invalid task number.\n";
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& tasks, int index) {
    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    vector<Task> tasks;
    char choice;

    do {
        // Display menu
        viewTasks(tasks);
        cout << "MENU:\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Completed\n";
        cout << "3. Remove Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                cin.ignore(); // Clear the input buffer
                string taskDescription;
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                addTask(tasks, taskDescription);
                break;
            }
            case '2': {
                int index;
                cout << "Enter task number to mark as completed: ";
                cin >> index;
                markCompleted(tasks, index);
                break;
            }
            case '3': {
                int index;
                cout << "Enter task number to remove: ";
                cin >> index;
                removeTask(tasks, index);
                break;
            }
            case '4':
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 4.\n";
        }
    } while (choice != '4');

    return 0;
}
