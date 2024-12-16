#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> 
#include <ctime>     
#include <cstdlib>  

using namespace std;

// chooses word
vector<string> loadWords(const string& filename) {
    vector<string> words;
    ifstream file(filename);
    string word;

    if (file.is_open()) {
        while (getline(file, word)) {
            if (!word.empty()) {
                words.push_back(word);
            }
        }
        file.close();
    } else {
        cerr << "Error: Could not open the file " << filename << endl;
    }

    return words;
}

// display hangman graphics
void displayHangman(int attempts) {
    cout << "\n  -----" << endl;
    cout << "  |   |" << endl;
    if (attempts >= 1) cout << "  O   |" << endl; else cout << "      |" << endl;
    if (attempts == 2) cout << "  |   |" << endl;
    if (attempts == 3) cout << " /|   |" << endl;
    if (attempts >= 4) cout << " /|\\  |" << endl;
    if (attempts == 5) cout << " /    |" << endl;
    if (attempts == 6) cout << " / \\  |" << endl;
    if (attempts < 2) cout << "      |" << endl;
    cout << "      |" << endl;
    cout << "__________" << endl;
}

// display the word with spaces between guessed letters
void displayWord(const string& guessedWord) {
    for (char c : guessedWord) {
        cout << c << " ";
    }
    cout << endl;
}

int main() {
    // Word to guess
    vector<string> words = loadWords("words.txt");
    if (words.empty()) {
        cerr << "No words loaded. Please check the file." << endl;
        return 1;
    }
    srand(static_cast<unsigned>(time(0)));
    string word = words[rand() % words.size()];

    string guessedWord(word.length(), '_');
    
    vector<char> incorrectGuesses; // To store incorrect guesses
    int maxAttempts = 6;           // Maximum incorrect attempts
    int attempts = 0;              // Current incorrect attempts

    cout << "Welcome to Hangman!" << endl;
    cout << "Guess the word letter by letter." << endl;
    cout << "You have " << maxAttempts << " attempts." << endl;

    while (attempts < maxAttempts && guessedWord != word) {
        displayHangman(attempts); // Show hangman graphic
        cout << "\nWord: ";
        displayWord(guessedWord); // Show the guessed word with spaces
        cout << "Incorrect guesses: ";
        for (char c : incorrectGuesses) {
            cout << c << " ";
        }
        cout << endl;

        cout << "Enter your guess: ";
        char guess;
        cin >> guess;

        bool correct = false;

        // Check if the guessed letter is in the word
        for (size_t i = 0; i < word.length(); i++) {
            if (word[i] == guess && guessedWord[i] != guess) {
                guessedWord[i] = guess;
                correct = true;
            }
        }

        if (!correct) {
            // Check if the guess is not already in the incorrect guesses
            if (find(incorrectGuesses.begin(), incorrectGuesses.end(), guess) == incorrectGuesses.end()) {
                incorrectGuesses.push_back(guess);
                attempts++;
                cout << "Wrong guess! Attempts left: " << maxAttempts - attempts << endl;
            } else {
                cout << "You already guessed that letter!" << endl;
            }
        } else {
            cout << "Good guess!" << endl;
        }
    }

    displayHangman(attempts); // Final hangman graphic

    if (guessedWord == word) {
        cout << "\nCongratulations! You guessed the word: " << word << endl;
    } else {
        cout << "\nGame over! The word was: " << word << endl;
    }

    return 0;
}

