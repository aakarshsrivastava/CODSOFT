#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std ;

void guessTheNumber(const string& userName) {

    srand(time(0)); // Ensures that random number is generated each time code is run

 
    int numberToGuess = rand() % 100 + 1; // rand()% ensures number is from 0 to 99 adding +1 
    int guess = 0; // initialises variable to store user guess
    int attempts = 3;// sets the number of attempts

    cout << "I have selected a number between 1 and 100. You have 3 chances to guess it." << endl;

    for (int i = 0; i < attempts; ++i) // loop for user attempts  
    {
        cout << "Enter your guess: ";
        cin >> guess;

        if (cin.fail()) {
   
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Please enter a valid number." << endl;
            --i; 
        } else if (guess < numberToGuess) {
            cout << "Too low! Try again, " << userName << "." << endl;
        } else if (guess > numberToGuess) {
            cout << "Too high! Try again, " << userName << "." << endl;
        } else {
            cout << "Congratulations, " << userName << "! You guessed the number." << endl;
            return; 
        }
    }
    cout << "Sorry, " << userName << ", you've run out of attempts. The correct number was " << numberToGuess << "." << endl;
}

int main() {
    string userName;

    cout << "Hello, I am Jarvis." << endl;
    cout << "What is your name? ";
    getline(cin, userName);

    cout << "Nice to meet you, " << userName << "!" << "Welcome toh the Number Guessing name " << endl << endl ;
    guessTheNumber(userName);

    return 0;// successful completion of program
}
