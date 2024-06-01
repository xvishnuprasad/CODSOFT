#include <iostream>
using namespace std;

int main() {
    float num1, num2, out;
    char operation;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;
    if (operation == '+') {
        out = num1 + num2;
        cout << "Result: " << out << endl;
    } else if (operation == '-') {
        out = num1 - num2;
        cout << "Result: " << out << endl;
    } else if (operation == '*') {
        out = num1 * num2;
        cout << "Result: " << out << endl;
    } else if (operation == '/') {
        if (num2 != 0) {
            out = num1 / num2;
            cout << "Result: " << out << endl;
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
        }
    } else {
        cout << "Error: Invalid operation." << endl;
    }

    return 0;
}
