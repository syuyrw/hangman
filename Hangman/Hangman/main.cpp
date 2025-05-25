//
//  main.cpp
//  Hangman
//
//  Created by jordan reitz on 5/24/25.
//

#include <iostream>
#include <string>
// Just to be safe, including this for rand/srand
#include <cstdlib>
// Needed for time()
#include <ctime>   // Needed for time()

using namespace std;

// This version of hangman might be a bit dramatic...
int main()
{
    // Seed randomness once – otherwise it repeats the same "random" word

    srand(time(0));
    // Not sure if 50 is overkill, but I wanted variety
    const string wordBank[50] = {
        "apple", "banana", "grape", "orange", "peach",
        "strawberry", "melon", "kiwi", "mango", "lemon",
        "computer", "keyboard", "monitor", "mouse", "printer",
        "internet", "website", "browser", "email", "software",
        "school", "teacher", "student", "library", "homework",
        "guitar", "piano", "violin", "trumpet", "drums",
        "mountain", "river", "ocean", "forest", "desert",
        "window", "mirror", "table", "chair", "couch",
        "elephant", "giraffe", "dolphin", "kangaroo", "penguin",
        "rocket", "planet", "galaxy", "comet", "astronaut"
    };
    // pick random word from list
    string mysteryWord = wordBank[rand() % 50];
    // placeholder for guessed word
    string revealed(mysteryWord.length(), '_');
    int wrongGuesses = 0;
    // 7 feels fair. Like 1 head, 1 torso, 2 arms, 2 legs, and... idk, a hat?
    const int maxAttempts = 7;
    string guessedLetters = "";
    char userGuess;

    cout << "Welcome to Hangman. Try not to commit fictional murder.\n";

    while (wrongGuesses < maxAttempts && revealed != mysteryWord)
    {
        cout << "\nCurrent word: " << revealed << "\n";
        cout << "Guess a letter: ";
        cin >> userGuess;

        // Normalize case maybe? skipping for now
        bool letterFound = false;

        // Already guessed?
        if (guessedLetters.find(userGuess) != string::npos) {
            cout << "You already guessed that letter! Try another one idiot.\n";
            continue;
        }

        // set letter guessed as variable
        guessedLetters += userGuess;

        // Check if guess is in the word
        for (int i = 0; i < mysteryWord.size(); ++i)
        {
            if (mysteryWord[i] == userGuess)
            {
                revealed[i] = userGuess;
                letterFound = true;
            }
        }
        
// statements for if letter is/isn't correct
        if (letterFound)
        {
            cout << "Nice one! That letter's in there.\n";
        }
        else
        {
            cout << "Nope. Try again.\n";
            wrongGuesses++;
        }

    }

    // statements for when user wins/loses
    if (revealed == mysteryWord)
    {
        cout << "\nYou won! The guy lives another day.\n";
    }
    else
    {
        cout << "\nToo many mistakes... The correct word was: " << mysteryWord << endl;
        cout << "RIP idiot.\n";
    }

    return 0;
}
