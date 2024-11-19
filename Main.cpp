/***************************************************************************
Course Section: Section 3 - 12:00 p.m.
Program: MathTutorV5
Programmers: Kylian James and Confidence Affang
Date: 11/19/2024
GitHub URL: https://github.com/KylianJ65/MathTutorV5.git
Description: This is the Funniest and Craziest Math
Tutor Game for Children. Version 3 invites you to the Math Tutor game.
It welcomes you, gives you fun math facts, it asks for your name,
it asks you a math question that has a variety of different equations,
and then it tells you whether you got the question right or wrong while
giving you the answer. Furthermore, if you got the question right
multiple times, you can increase the difficulty by "level 2" to be
challenged by advance math problems. However, if you get the same
problem wrong multiple times, it will decrease the level and put you
back to level 1, if you are on level 2. Either way, you can always play
this game and test your knowledge by choosing to continue or if you
want to stop, you can have the option. This is a fun program to
practice your knowledge on math while having fun. Throughout the program the
information such as the left number, math symbol, right number, answer, and
attempts is stored in a 2D vector. This allows us to make a summary report
at the end which the user can review to see what problems they had and how
they did on the test. we did subdivide math tutor version 4 into several functions.
***************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>
#include <iomanip>
using namespace std;
//defining the global variables
const int LEVEL_RANGE_CHANGE = 10;
const int MAX_ATTEMPTS = 3;

//Defining the functions and
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

    return;
}; //

// the function below gets the users name ans returns it so it can be passed in other functions
string GetUserName() {
    string userName;
    cout << "*\tPlease enter your name: ";
    getline(cin, userName);
    cout << endl << "*\tWelcome " << userName << " to the Math Tutor!" << endl;
    return userName;
}

// get the input from the user and makes sure it's a number and not any other character
int GetNumericValue() {
    int userAns;
    while (!(cin >> userAns)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\tInvalid input! Please enter a number: ";
    }
    return userAns;
}

// a function that asks the user whether they would like to play again and returns yes or no which are the user's input
string AskToPlayAgain(string userName) {
    string userInput;
    while (true) {
        cout << "*\tDo you want to continue, " << userName << "? (y=yes | n=no): ";
        cin >> userInput;
        for (auto &c: userInput) c = tolower(c); // Convert to lowercase
        if (userInput == "y" || userInput == "yes" || userInput == "n" || userInput == "no") {
            break;
        } else {
            cout << "*\tInvalid input, please try again..." << endl;
        }
    }
    return userInput; // returns a string
}


// vector function that generates a random question and uses an enum and returns the
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

// function assigned to give 3 attempts to the user and return whether he or she got it true or not
bool GiveThreeAttempts(string userName, vector<int> &currentQuestion, int &totalCorrect, int &totalIncorrect) {
    int userAns = 0;
    bool isCorrect = false;
    for (int i = 1; i <= MAX_ATTEMPTS; ++i) {
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
            if (i < MAX_ATTEMPTS) cout << "Try again." << endl;
        }
    }

    if (!isCorrect) {
        currentQuestion[5] = 0;
        totalIncorrect++;
        cout << "\tOut of attempts. The correct answer was: " << currentQuestion[4] << endl;
    }

    return isCorrect;
}


// the function below checks if the user gets 3 correct and levels them up and if they get 3 incorrect and they are in a level higher than 1 and reduces it by one and also alongside the level of the questions asked
void CheckForLevelChange(int &totalCorrect, int &totalIncorrect, int &mathLevel, int &currentRange) {
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
    } else if (totalIncorrect >= 3) {
        mathLevel--;
        totalCorrect = 0;
        totalIncorrect = 0;
    }
    return;
}
// the function below displays the final report of the user
void DisplaySummaryReport(const vector<vector<int>> &allQuestions) {
    int totalCorrect = 0;
    int totalIncorrect = 0;

    cout << "=======================================" << endl;
    cout << "              Summary Report           " << endl;
    cout << "========================================" << endl;
    cout << setw(10) << left << "Level"
         << setw(15) << left << " Question"
         << setw(10) << left << "  Attempts" << endl;
    cout << "------  ----------------  -----------" << endl;

    for (const auto &q : allQuestions) {
        int questionLevel = q[0];
        int qLeftNum = q[1];
        char qMathSymbol = static_cast<char>(q[2]);
        int qRightNum = q[3];
        int qCorrectAns = q[4];
        int qAttempts = q[5];

        cout << setw(10) << left << questionLevel
             << setw(2) << left << qLeftNum << " " << qMathSymbol << " " <<setw(2)<< left << qRightNum<< setw(2)<<right<<" = "<<  qCorrectAns;

        if (qAttempts == 0) {
            cout << setw(15) << "Incorrect" << endl;
            totalIncorrect++;
        } else {
            cout << setw(11) << qAttempts << endl;
            totalCorrect++;
        }
    }

    cout << endl;
    cout << "* Total Questions: " << setw(3) << allQuestions.size() << endl;
    cout << "* Total Correct..: " << setw(3) << totalCorrect << endl;
    cout << "* Total Incorrect: " << setw(3) << totalIncorrect << endl;
    cout << "* Average correct : " << setw(3) << (static_cast<double>(totalCorrect)/static_cast<double>(allQuestions.size()))*100 << "%"<< endl;
    cout << "___________________________________ " << endl;
}



int main() {
    int totalCorrect = 0;
    int totalIncorrect = 0;
    int mathLevel = 1;
    int currentRange = 10;
    vector<vector<int> > questions;
    string userName, userInput;
    bool playAgain = true;

    srand(time(0));

    DisplayGameIntro();
    userName = GetUserName();

    while (playAgain) {
        // Generate a random math question
        vector<int> question = GenerateRandomQuestion(mathLevel, currentRange);

        // Allow the user to attempt the question
        GiveThreeAttempts(userName, question, totalCorrect, totalIncorrect);

        // Record the question for the summary
        questions.push_back(question);

        // Check for level changes
        CheckForLevelChange(totalCorrect, totalIncorrect, mathLevel, currentRange);

        // Ask the user if they want to play again
        userInput = AskToPlayAgain(userName);
        playAgain = (userInput == "y" || userInput == "yes");
    }


    DisplaySummaryReport(questions);

    cout << endl << "\tCheck back soon for the next version. Goodbye!" << endl;
    return 0;
}
