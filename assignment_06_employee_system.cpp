#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Employee {
    string name;
    int id;
    double salary;
};

void addEmployee(Employee emp[], int &count) {
    if (count >= 10) {
        cout << "Error: Maximum number of employees reached." << endl;
        return;
    }
    cout << "Enter name: ";
    cin.ignore(); // Clear buffer
    getline(cin, emp[count].name);
    cout << "Enter ID: ";
    cin >> emp[count].id;
    cout << "Enter salary: ";
    cin >> emp[count].salary;
    count++;
    cout << "Employee added successfully." << endl;
}

void displayEmployees(Employee emp[], int count) {
    if (count == 0) {
        cout << "No employees to display." << endl;
        return;
    }
    cout << left << setw(15) << "Name" << setw(10) << "ID" << setw(10) << "Salary" << endl;
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < count; i++) {
        cout << left << setw(15) << emp[i].name 
             << setw(10) << emp[i].id 
             << fixed << setprecision(2) << emp[i].salary << endl;
    }
}

void updateSalary(Employee emp[], int count) {
    int searchId;
    cout << "Enter employee ID to update: ";
    cin >> searchId;

    for (int i = 0; i < count; i++) {
        if (emp[i].id == searchId) {
            cout << "Enter new salary: ";
            cin >> emp[i].salary;
            cout << "Salary updated for " << emp[i].name << endl;
            return;
        }
    }
    cout << "Employee ID not found." << endl;
}

int main() {
    Employee employees[10];
    int count = 0;
    int choice;

    do {
        cout << "\n=== Employee Management System ===" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Display All Employees" << endl;
        cout << "3. Update Salary" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(employees, count); break;
            case 2: displayEmployees(employees, count); break;
            case 3: updateSalary(employees, count); break;
            case 4: cout << "Goodbye!" << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}
