# MasterMind-Game
# Description
This project is a simulation of the MasterMind board game, a code-breaking game played by two players. The game involves one player creating a secret code using a set of colored pegs, while the other player attempts to guess the code within a limited number of attempts. The game implements core concepts of C++ such as strings, loops, and functions.

# Instructions
Inputs
The game requires the following inputs:

Names of the players.
Total number of runs (must be a positive even number).
Secret code (4 characters long, consisting of the letters "R", "G", "B", "P", "Y", or "M" without duplicates).
Guess code (4 characters long, consisting of the letters "R", "G", "B", "P", "Y", or "M" without duplicates).

# Game Flow
The user is prompted to enter the names of the two players.
The user is asked to enter the total number of runs for the game (must be a positive even number).
The game alternates between the two players, with one acting as the code-maker and the other as the code-breaker in each run.
The code-maker sets a secret code, and the code-breaker tries to guess it within six attempts.
Feedback is provided for each guess:
"R" for a correct color in the correct position.
"W" for a correct color in the wrong position.
Points are awarded based on the correctness of guesses and the number of attempts.
The game continues for the specified number of runs, and the player with the highest score at the end wins.

# Example Output
Please enter the names of the players: Duygu Gulsen
Welcome Duygu and Gulsen

Please enter the number of runs: 2

Duygu, it is your turn to select the secret!
Valid colors: R - Red, G - Green, B - Blue, P - Purple, Y - Yellow, M - Magenta
Duygu, please enter your secret: RGBP

Gulsen, please enter your guess: RBGY
WRW
Gulsen, please enter your guess: RGBP
Duygu, you won this run!

The game has ended!
Duygu: 1 - Gulsen: 0
Congrats Duygu, you have won the game!

# Files
main.cpp: Contains the main function and game logic.
README.md: This file, providing an overview and instructions.

# How to Run
Ensure you have a C++ compiler installed (e.g., g++, Visual Studio, XCode).
Compile the code:
g++ main.cpp -o MasterMindGame

Run the compiled program:
./MasterMindGame

# Functions
isValidCode: Validates the format of the code.
generateFeedback: Generates feedback for each guess.
runGame: Manages the game flow.
getValidNumberOfRuns: Validates and retrieves the number of runs.
getValidCode: Prompts for and validates the secret and guess codes.

# Author
Yağız Bartu Arslan
Written in my Sophomore Year at Sabanci University
