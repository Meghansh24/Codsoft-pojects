#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Task {
    string description;
    int priority;
    string dueDate;
    bool isCompleted;
};

vector<Task> todoList;

void addTask(string description, int priority, string dueDate) {
    Task task = {description, priority, dueDate, false};
    todoList.push_back(task);
}

void viewTasks() {
    for (int i = 0; i < todoList.size(); i++) {
        cout << "Task " << i + 1 << ": " << todoList[i].description << endl;
        cout << "Priority: " << todoList[i].priority << endl;
        cout << "Due Date: " << todoList[i].dueDate << endl;
        cout << "Status: " << (todoList[i].isCompleted ? "Completed" : "Pending") << endl;
        cout << "" << endl;
    }
}

void markTaskAsCompleted(int taskNumber) {
    if (taskNumber > 0 && taskNumber <= todoList.size()) {
        todoList[taskNumber - 1].isCompleted = true;
    }
}

void removeTask(int taskNumber) {
    if (taskNumber > 0 && taskNumber <= todoList.size()) {
        todoList.erase(todoList.begin() + taskNumber - 1);
    }
}

int main() {
    int choice;
    char nextMove = 'y';

    while (nextMove == 'y') {
        cout << "This will keep track of the things you need to do!" << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Add to my to-do list" << endl;
        cout << "2. Display my to-do list" << endl;
        cout << "3. Mark a task as completed" << endl;
        cout << "4. Remove a task from the list" << endl;

        cin >> choice;

        if (choice == 1) {
            string description;
            int priority;
            string dueDate;

            cout << "What is the description of the activity?" << endl;
            cin.ignore();
            getline(cin, description);
            cout << "How urgent is this? Rank 1-5. 1 for not really important, 5 for very important" << endl;
            cin >> priority;
            cout << "When is the due date? (in day/month format)" << endl;
            cin >> dueDate;

            addTask(description, priority, dueDate);
        } else if (choice == 2) {
            viewTasks();
        } else if (choice == 3) {
            int taskNumber;
            cout << "Enter the task number to mark as completed: " << endl;
            cin >> taskNumber;
            markTaskAsCompleted(taskNumber);
        } else if (choice == 4) {
            int taskNumber;
            cout << "Enter the task number to remove: " << endl;
            cin >> taskNumber;
            removeTask(taskNumber);
        }

        cout << "Do you want to continue? (y/n)" << endl;
        cin >> nextMove;
    }

    return 0;
}