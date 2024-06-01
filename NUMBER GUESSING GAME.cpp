#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(0)); 
    int sn = rand() % 100 + 1; 
    int g;
    int attempts = 0;
    cout << "the Number Guessing Game!\n";
    cout << "I am thinking of a number between 1 and 100. Can you guess what it is? \n";
    do {
        cout << "Enter your guess: ";
        cin >> g;
        attempts++;
        if (g < sn)
            cout << "Too low! Try again.\n";
        else if (g > sn)
            cout << "Too high! Try again.\n";
        else
            cout << "Congratulations! You've guessed the number " << sn << " correctly in " << attempts << " attempts. \n";
    } while (g != sn);
    return 0;
}
