#include <iostream>
#include <string>
#include <vector>
#include <limits>


// Written by Ya��z Bartu Arslan 
// Sophomore Computer Science & Engineering Student at Sabanci University.
// Date: 09.03.2023

using namespace std;

bool isValidCode(const string& code);
string generateFeedback(const string& secret, const string& guess);
void runGame(const string& player1, const string& player2);
int getValidNumberOfRuns();
string getValidCode(const string& playerName);

int main() {
    string player1, player2;

    cout << "Please enter the names of the players: ";
    cin >> player1 >> player2;

    cout << "Welcome " << player1 << " and " << player2 << endl << endl;

    runGame(player1, player2);

    return 0;
}


bool isValidCode(const string& code) {
    if (code.length() != 4) {
        return false;
    }

    string validChars = "RGBPYM";
    for (char ch : code) {
        if (validChars.find(ch) == string::npos) {
            return false;
        }
    }

    // Check for duplicates
    for (size_t i = 0; i < code.length(); ++i) {
        for (size_t j = i + 1; j < code.length(); ++j) {
            if (code[i] == code[j]) {
                return false;
            }
        }
    }

    return true;
}


string generateFeedback(const string& secret, const string& guess) {
    int correctPosition = 0;
    int correctColor = 0;
    string feedback = "";

    for (size_t i = 0; i < secret.length(); ++i) {
        if (secret[i] == guess[i]) {
            correctPosition++;
        }
    }

    string secretCopy = secret;
    for (char ch : guess) {
        size_t pos = secretCopy.find(ch);
        if (pos != string::npos) {
            correctColor++;
            secretCopy[pos] = 'X'; // Mark as used
        }
    }

    correctColor -= correctPosition; // Adjust for correct positions
    feedback.append(correctPosition, 'R');
    feedback.append(correctColor, 'W');

    return feedback;
}


int getValidNumberOfRuns() {
    int runs;
    cout << "Please enter the number of runs: ";  // Burada endl kald�r�ld�
    while (!(cin >> runs) || runs <= 0 || runs % 2 != 0) {
        cout << "Invalid number of runs!" << endl;  // Hatal� giri�lerde endl korunacak
        cout << "Please enter the number of runs: ";  // Burada endl kald�r�ld�
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return runs;
}




string getValidCode(const string& playerName, bool isSecret) {
    string code;
    string prompt = isSecret ? "secret" : "guess";
    if (isSecret) {
        cout << playerName << ", please enter your " << prompt << ": ";
    }
    else {
        cout <<playerName << ", please enter your " << prompt << ": ";
    }
    while (true) {
        cin >> code;
        if (isValidCode(code)) {
            break;
        }
        else {
            //cout << endl;
            cout << "Invalid " << prompt << "!" << endl;
            if (isSecret) {
                cout << playerName << ", please enter your " << prompt << ": ";
            }
            else {
                cout << playerName << ", please enter your " << prompt << ": ";
            }
        }
    }
    return code;
}





void runGame(const string& player1, const string& player2) {
    int numberOfRuns = getValidNumberOfRuns();
    int score1 = 0, score2 = 0;

    for (int run = 1; run <= numberOfRuns; ++run) {
        string secretCode, guess;
        bool isPlayer1CodeMaker = run % 2 != 0;

        string codeMaker = isPlayer1CodeMaker ? player1 : player2;
        string codeBreaker = isPlayer1CodeMaker ? player2 : player1;
        cout << endl;
        cout << codeMaker << ", it is your turn to select the secret!" << endl;
        cout << "Valid colors: R - Red, G - Green, B - Blue, P - Purple, Y - Yellow, M - Magenta" << endl;
        secretCode = getValidCode(codeMaker, true); // true for secret code

        bool codeBroken = false;
        for (int chance = 1; chance <= 6; ++chance) {
            guess = getValidCode(codeBreaker, false); // false for guess

            if (guess == secretCode) {
                cout << codeBreaker << ", you won this run!" << endl;
                codeBroken = true;
                if (codeBreaker == player1) score1++; // Code-breaker (Player 1) gets a point
                else score2++; // Code-breaker (Player 2) gets a point
                break;
            }
            else {
                if (codeMaker == player1) score1++; // Code-maker (Player 1) gets a point
                else score2++; // Code-maker (Player 2) gets a point
                cout << endl;
                string feedback = generateFeedback(secretCode, guess);
                cout << feedback << endl;
            }
        }

        if (!codeBroken) {
            cout << codeBreaker << ", you're out of chances, you lost this run!" << endl;
            // Code maker gets points for each incorrect guess plus one additional point if the code is never broken
            int pointsEarned = 1; // 1 additional point
            if (codeMaker == player1) score1 += pointsEarned;
            else score2 += pointsEarned;
        }
    }
    cout << endl;
    cout << "The game has ended!" << endl;
    cout << player1 << ": " << score1 << " - " << player2 << ": " << score2 << endl << endl;

    if (score1 == score2) {
        cout << player1 << " and " << player2 << ", there is a tie!" << endl << endl;
    }
    else if (score1 > score2) {
        cout << "Congrats " << player1 << ", you have won the game!" << endl << endl;
    }
    else {
        cout << "Congrats " << player2 << ", you have won the game!" << endl << endl;
    }
}





//Gulsen, it is your turn to select the secret!
//Valid colors : R - Red, G - Green, B - Blue, P - Purple, Y - Yellow,
//M - Magenta
//Gulsen, please enter your secret : GPYB
//Duygu, please enter your guess : GPYB // Duygu bildi, bildi�i i�in 1 puan ald� -> G�l�en: 0 - Duygu: 1
//Duygu, you won this run!
//Duygu, it is your turn to select the secret!
//Valid colors : R - Red, G - Green, B - Blue, P - Purple, Y - Yellow,
//M - Magenta
//Duygu, please enter your secret : BPYM
//Gulsen, please enter your guess : GPMR // G�l�en bilemedi bu y�zden Duygu 1 puan daha ald� -> G�l�en: 0 - Duygu: 2
//RW
//Gulsen, please enter your guess : GMPY // G�l�en bilemedi bu y�zden Duygu 1 puan daha ald� -> G�l�en: 0 - Duygu: 3
//WWW
//Gulsen, please enter your guess : MPRB // G�l�en bilemedi bu y�zden Duygu 1 puan daha ald� -> G�l�en: 0 - Duygu: 4
//RWW
//Gulsen, please enter your guess : BPMR // G�l�en bilemedi bu y�zden Duygu 1 puan daha ald� -> G�l�en: 0 - Duygu: 5
//RRW
//Gulsen, please enter your guess : BPMY //G�l�en bilemedi bu y�zden Duygu 1 puan daha ald� -> G�l�en: 0 - Duygu: 6
//RRWW
//Gulsen, please enter your guess : BPYM //G�l�en bildi, 1 puan o ald�. -> G�l�en: 1 - Duygu 6
//Gulsen, you won this run! 
//Gulsen, it is your turn to select the secret!
//Valid colors : R - Red, G - Green, B - Blue, P - Purple, Y - Yellow,
//M - Magenta
//Gulsen, please enter your secret : YMGB
//Duygu, please enter your guess : YGMP //Duygu bilemedi bu y�zden G�l�en 1 puan ald� -> G�l�en: 2 - Duygu: 6
//RWW
//Duygu, please enter your guess : YMPG //Duygu bilemedi bu y�zden G�l�en 1 puan ald� -> G�l�en: 3 - Duygu: 6
//RRW
//Duygu, please enter your guess : YMGP //Duygu bilemedi bu y�zden G�l�en 1 puan ald� -> G�l�en: 4 - Duygu: 6
//RRR
//Duygu, please enter your guess : YMGB //Duygu bildi, 1 puan ald� -> G�l�en: 4 - Duygu: 7
//Duygu, you won this run!
//Duygu, it is your turn to select the secret!
//Valid colors : R - Red, G - Green, B - Blue, P - Purple, Y - Yellow,
//M - Magenta
//Duygu, please enter your secret : PBYG 
//Gulsen, please enter your guess : GBYP //G�l�en bilemedi, bu y�zden Duygu 1 puan daha ald� -> G�l�en: 4 - Duygu 8
//RRWW
//Gulsen, please enter your guess : PBYG //G�l�en bildi, 1 puan ald� -> G�l�en 5: - Duygu 8
//Gulsen, you won this run!
//The game has ended!
//Gulsen : 5 - Duygu : 8
//Congrats Duygu, you have won the game!

// SAMPLE RUN 2 G�D�� YOLU BU OLMALI, B�R OYUNCU B�LEMEZSE D��ER OYUNCUYA PUAN AKTARILIYOR, E�ER 6.DA DA B�LEMEZSE EKSTRA 1 PUAN DAHA AKTARILACAK
// D��ER OYUNCU DO�RU B�L�RSE B�LEN OYUNCUYA 1 PUAN