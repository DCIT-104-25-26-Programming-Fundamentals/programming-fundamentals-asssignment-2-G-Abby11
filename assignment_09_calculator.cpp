#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }

double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero." << endl;
        return 0; 
    }
    return a / b;
}

int calculateModulus(int a, int b) {
    if (b == 0) {
        cout << "Error: Cannot perform modulus by zero." << endl;
        return 0;
    }
    return a % b;
}

double exponentiate(double base, double exp) {
    return pow(base, exp);
}

int main() {
    int choice;
    double num1, num2, result;

    do {
        cout << "\n============================" << endl;
        cout << "     SIMPLE CALCULATOR" << endl;
        cout << "============================" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;
        cout << "Select an operation (1-7): ";
        cin >> choice;

        if (choice >= 1 && choice <= 6) {
            cout << "Enter first number : ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;

            switch (choice) {
                case 1: 
                    result = add(num1, num2); 
                    cout << fixed << setprecision(2) << "Result: " << num1 << " + " << num2 << " = " << result << endl; 
                    break;
                case 2: 
                    result = subtract(num1, num2); 
                    cout << fixed << setprecision(2) << "Result: " << num1 << " - " << num2 << " = " << result << endl; 
                    break;
                case 3: 
                    result = multiply(num1, num2); 
                    cout << fixed << setprecision(2) << "Result: " << num1 << " * " << num2 << " = " << result << endl; 
                    break;
                case 4: 
                    result = divide(num1, num2); 
                    if (num2 != 0) cout << fixed << setprecision(2) << "Result: " << num1 << " / " << num2 << " = " << result << endl; 
                    break;
                case 5: 
                    if (num1 == (int)num1 && num2 == (int)num2) {
                        int res = calculateModulus((int)num1, (int)num2);
                        if ((int)num2 != 0) cout << "Result: " << (int)num1 << " % " << (int)num2 << " = " << res << endl;
                    } else {
                        cout << "Error: Modulus requires integer values." << endl;
                    }
                    break;
                case 6: 
                    result = exponentiate(num1, num2); 
                    cout << fixed << setprecision(2) << "Result: " << num1 << " ^ " << num2 << " = " << result << endl; 
                    break;
            }
        } else if (choice != 7) {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 7);

    cout << "Goodbye!" << endl;
    return 0;
}
