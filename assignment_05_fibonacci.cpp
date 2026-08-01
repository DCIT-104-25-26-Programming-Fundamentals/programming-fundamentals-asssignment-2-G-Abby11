#include <iostream>
using namespace std;

void printFibonacci(int n) {
    long long prev = 0, curr = 1;
    
    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << prev << " ";
        long long next = prev + curr;
        prev = curr;
        curr = next;
    }
    cout << endl;
}

void checkFibonacci(long long num) {
    if (num < 0) {
        cout << num << " is NOT a Fibonacci number." << endl;
        return;
    }

    long long prev = 0, curr = 1;
    
    if (num == 0 || num == 1) {
        cout << num << " is a Fibonacci number." << endl;
        return;
    }

    while (curr < num) {
        long long next = prev + curr;
        prev = curr;
        curr = next;
    }

    if (curr == num) {
        cout << num << " is a Fibonacci number." << endl;
    } else {
        cout << num << " is NOT a Fibonacci number." << endl;
    }
}

int main() {
    int choice;
    cout << "Choose an option:" << endl;
    cout << "1. Print first N terms" << endl;
    cout << "2. Check if a number is Fibonacci" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        int n;
        cout << "How many terms? ";
        cin >> n;
        if (n <= 0) {
            cout << "Error: N must be a positive integer." << endl;
        } else {
            printFibonacci(n);
        }
    } else if (choice == 2) {
        long long num;
        cout << "Enter a number to check: ";
        cin >> num;
        checkFibonacci(num);
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
