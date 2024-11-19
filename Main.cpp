#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>
#include <iomanip>
using namespace std;

// Function Prototypes
void DisplayGameIntro();
string GetUserName();
int GetNumericValue();
string AskToPlayAgain(string userName);
void DisplaySummaryReport(const vector<vector<int>> &allQuestions);
vector<int> GenerateRandomQuestion(int mathLevel, int currentRange);
bool GiveThreeAttempts(string userName, vector<int> &currentQuestion, int &totalCorrect, int &totalIncorrect);
void CheckForLevelChange(int &totalCorrect, int &totalIncorrect, int &mathLevel, int &currentRange);

int main() {
    int totalCorrect = 0;
    int totalIncorrect = 0;
    int mathLevel = 1;
    int currentRange = 10;
    vector<vector<int>> questions;
    const int MAX_ATTEMPTS = 3;
    string userName, userInput;
    bool playAgain = true;

    srand(time(0));

    DisplayGameIntro();
    userName = GetUserName();

    while (playAgain) {
        // Generate a random math question
        vector<int> question = GenerateRandomQuestion(mathLevel, currentRange);

        // Allow the user to attempt the question
        if (GiveThreeAttempts(userName, question, totalCorrect, totalIncorrect)) {
            questions.push_back(question);
        }

        // Check for level changes
        CheckForLevelChange(totalCorrect, totalIncorrect, mathLevel, currentRange);

        // Ask the user if they want to play again
        userInput = AskToPlayAgain(userName);
        playAgain = (userInput == "y" || userInput == "yes");
    }

    DisplaySummaryReport(questions);

    cout << endl << "*\tCheck back soon for the next version. Goodbye!" << endl;
    return 0;
}

// Function Definitions

void DisplayGameIntro() {
    // Displaying the Program Intro/Presentation.
    cout << " ______________________________________________________________ " << endl;
    cout << "                                                                " << endl;
    cout << "    __  __         _    _       _______      _                  " << endl;
    cout << "   |  ||  |       | |  | |     |__   __|    | |                 " << endl;
    cout << "   |      |  __ _ | |_ | |__      | | _   _ | |_  ___   _ __    " << endl;
    cout << "   | |||| | / _` || __|| '_ |     | || | | || __|/ _ | | '__|   " << endl;
    cout << "   | |  | || (_| || |_ | | | |    | || |_| || |_| (_) || |      " << endl;
    cout << "   |_|  |_| |__,_| |__||_| |_|    |_| |__,_| |__||___/ |_|      " << endl;
    cout << "                                                                " << endl;
    cout << " ______________________________________________________________ " << endl;
    cout << endl;
    cout << "|           Welcome to the Craziest Math Tutor Game!           |" << endl;
    cout << " ______________________________________________________________ " << endl;
    cout << endl;

    // Displaying for the User Fun Facts about Math that are Interesting.
    cout << "-\tFun Math Facts! " << endl;
    cout << endl;
    cout << "\t    * The most used number in math is 3." << endl;
    cout << "\t    * Every odd number has an (e) in it." << endl;
    cout << "\t    * -40 Celcius is -40 Fahrenheit." << endl;
    cout << "\t    * Zero is not represented in Roman numerals." << endl;
    cout << endl;
    cout << " ______________________________________________________________ " << endl;


}; //

string GetUserName() {
    string userName;
    cout << "*\tPlease enter your name: ";
    cin >> userName;
    cout << endl << "*\tWelcome " << userName << " to the Math Tutor!" << endl;
    return userName;
}

int GetNumericValue() {
    int value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\tInvalid input! Please enter a number: ";
    }
    return value;
}

string AskToPlayAgain(string userName) {
    string userInput;
    while (true) {
        cout << "*\tDo you want to continue, " << userName << "? (y=yes | n=no): ";
        cin >> userInput;
        for (auto &c : userInput) c = tolower(c); // Convert to lowercase
        if (userInput == "y" || userInput == "yes" || userInput == "n" || userInput == "no") {
            break;
        } else {
            cout << "*\tInvalid input, please try again..." << endl;
        }
    }
    return userInput;
}

void DisplaySummaryReport(const vector<vector<int>> &allQuestions) {
    int totalCorrect = 0, totalIncorrect = 0;
    cout << "___________________________________ " << endl;
    cout << "         SUMMARY REPORT             " << endl;
    cout << "___________________________________ " << endl;
    cout << "LEVEL      QUESTION       ATTEMPTS  " << endl;
    cout << "_____ __________________ __________ " << endl;

    for (const auto &q : allQuestions) {
        cout << setw(5) << q[0] << " "
             << setw(3) << q[1] << " " << char(q[2]) << " " << setw(3) << q[3]
             << " = " << setw(3) << q[4] << " ";
        if (q[5] > 0) {
            cout << q[5] << " attempts" << endl;
            totalCorrect++;
        } else {
            cout << "Incorrect" << endl;
            totalIncorrect++;
        }
    }
    cout << "* Total Questions: " << setw(3) << allQuestions.size() << endl;
    cout << "* Total Correct..: " << setw(3) << totalCorrect << endl;
    cout << "* Total Incorrect: " << setw(3) << totalIncorrect << endl;
    cout << "    Average........: " << setw(3) << (totalCorrect * 100) / allQuestions.size() << "%" << endl;
    cout << "___________________________________ " << endl;
}

vector<int> GenerateRandomQuestion(int mathLevel, int currentRange) {
    enum MathType { MT_ADD = 1, MT_SUB, MT_MUL, MT_DIV };
    MathType questionType = static_cast<MathType>(rand() % 4 + 1);
    int leftNum = rand() % currentRange + 1;
    int rightNum = rand() % currentRange + 1;
    char symbol = '?';
    int correctAnswer = 0;

    switch (questionType) {
        case MT_ADD:
            symbol = '+';
            correctAnswer = leftNum + rightNum;
            break;
        case MT_SUB:
            symbol = '-';
            if (leftNum < rightNum) swap(leftNum, rightNum);
            correctAnswer = leftNum - rightNum;
            break;
        case MT_MUL:
            symbol = '*';
            correctAnswer = leftNum * rightNum;
            break;
        case MT_DIV:
            symbol = '/';
            correctAnswer = leftNum;
            leftNum *= rightNum;
            break;
        default:
            break;
    }
    return {mathLevel, leftNum, static_cast<int>(symbol), rightNum, correctAnswer, 0};
}

bool GiveThreeAttempts(string userName, vector<int> &currentQuestion, int &totalCorrect, int &totalIncorrect) {
    int userAns, attempts = 0;
    bool isCorrect = false;
    for (int i = 1; i <= 3; ++i) {
        cout << "[Level #" << currentQuestion[0] << "] " << userName
             << ", what is " << currentQuestion[1] << " "
             << char(currentQuestion[2]) << " " << currentQuestion[3] << "? ";
        userAns = GetNumericValue();
        if (userAns == currentQuestion[4]) {
            cout << "\tCorrect! Well done!" << endl;
            currentQuestion[5] = i;
            totalCorrect++;
            isCorrect = true;
            break;
        } else {
            cout << "\tIncorrect. ";
            if (i < 3) cout << "Try again." << endl;
            totalIncorrect++;
        }
    }
    if (!isCorrect) {
        cout << "\tOut of attempts. The correct answer was: " << currentQuestion[4] << endl;
    }
    return isCorrect;
}

void CheckForLevelChange(int &totalCorrect, int &totalIncorrect, int &mathLevel, int &currentRange) {
    const int LEVEL_RANGE_CHANGE = 10;
    if (totalCorrect >= 3) {
        mathLevel++;
        currentRange += LEVEL_RANGE_CHANGE;
        totalCorrect = 0;
        totalIncorrect = 0;
        cout << "*\tLeveling up to Level " << mathLevel << ". Range: 1-" << currentRange << endl;
    } else if (totalIncorrect >= 3 && mathLevel > 1) {
        mathLevel--;
        currentRange -= LEVEL_RANGE_CHANGE;
        totalCorrect = 0;
        totalIncorrect = 0;
        cout << "*\tLeveling down to Level " << mathLevel << ". Range: 1-" << currentRange << endl;
    }
}

