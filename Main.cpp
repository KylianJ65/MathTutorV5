/***************************************************************************
Course Section: Section 3 - 12:00 p.m.
Program: MathTutorV4
Programmers: Kylian James and Clay Rasmussen
Date: 10/22/2024
GitHub URL: https://github.com/KylianJ65/MathTutorV4
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
they did on the test.
***************************************************************************/
#include <iostream> // Needed for cin/cout, /t for tab spacing, and left and right  alignment
#include <string> // Needed for string variables - date types
#include <cstdlib> // Needed for random numbers
#include <ctime> // Needed for system time
#include <limits> // Used for limits library
#include <vector> // used so we can make our 2D Vector
#include <iomanip> //for the setw
using namespace std; // used to not put "std" in cin/cout
void DisplayGameIntro() {
    // Displaying the Program Intro/Presentation.
    cout << " ______________________________________________________________ " <<
            endl;
    cout << " " <<
            endl;
    cout << " __ __ _ _ _______ _ " <<
            endl;
    cout << " | || | | | | | |__ __| | | " <<
            endl;
    cout << " | | __ _ | |_ | |__ | | _ _ | |_ ___ _ __ " <<
            endl;
    cout << " | |||| | / _` || __|| '_ | | || | | || __|/ _ | | '__| " <<
            endl;
    cout << " | | | || (_| || |_ | | | | | || |_| || |_| (_) || | " <<
            endl;
    cout << " |_| |_| |__,_| |__||_| |_| |_| |__,_| |__||___/ |_| " <<
            endl;
    cout << " " <<
            endl;
    cout << " ______________________________________________________________ " <<
            endl;
    cout << endl;
    cout << "| Welcome to the Craziest Math Tutor Game! |" <<
            endl;
    cout << " ______________________________________________________________ " <<
            endl;
    cout << endl;
    // Displaying for the User Fun Facts about Math that are Interesting.
    cout << "-\tFun Math Facts! " << endl;
    cout << endl;
    cout << "\t * The most used number in math is 3." << endl;
    cout << "\t * Every odd number has an (e) in it." << endl;
    cout << "\t * -40 Celcius is -40 Fahrenheit." << endl;
    cout << "\t * Zero is not represented in Roman numerals." << endl;
    cout << endl;
    cout << " ______________________________________________________________ " << endl;
    return;

}; //
string GetUserName(string userName) {
    // Welcoming the User and asking for their Name.
    cout << endl;
    cout << "*\tPlease enter your name: ";
    cin >> userName;
    cout << endl;
    cout << "*\tWelcome " << userName << " to the Math Tutor!" << endl;
    cout << endl;
}; //
int GetNumericValue() {

}; //
string AskToPlayAgain(string userName) {

}; //
void DisplaySummaryReport(const vector<vector<int>> &allQuestions) {
        cout << "*\t" << "Thanks for playing this amazing game " << userName << "!" <<
            endl;
    cout << " ______________________________________________________________ " <<
            endl;
    cout << endl;
    cout << endl;
    cout << "___________________________________ " << endl;
    cout << " SUMMARY REPORT "                     << endl;
    cout << "___________________________________ " << endl;
    cout << "LEVEL QUESTION ATTEMPTS "             << endl;
    cout << "_____ __________________ __________ " << endl;
    cout << endl;
    totalCorrect = 0; //set to zero because they were used above, reset because they are being used in summary report
    totalIncorrect = 0;
    // extracts values from vectors
    for (int i = 0; i < questions.size(); i++) {

        // displays question details mathlevel, leftNum, symbol, rightNum, =, correctAnswer, then attempts per question
        cout << setw(3) << right << mathLevel << " "
                << setw(3) << right << leftNum
                << " " << symbol << " "
                << setw(3) << left << rightNum << " = "
                << setw(3) << right << correctAnswer;
        // Displays the number of attempts or Incorrect
        if (Attempts != 0) {
            cout << right << " " << Attempts << endl;
            totalCorrect++;
        } else {
            cout << " " << "Incorrect" << endl;
            totalIncorrect++;
        }
    }
    // Displays the Summary Totals
    cout << endl;
    cout << "* Total Questions: " << setw(3) << right << questions.size() << endl;
    cout << "* Total Correct..: " << setw(3) << right << totalCorrect << endl;
    cout << "* Total Incorrect: " << setw(3) << right << totalIncorrect << endl;
    cout << "* Average........: " << setw(3) << right << (totalCorrect * 100) /
            questions.size() << "%" << endl;
    cout << "___________________________________ " << endl;
    // Displaying to the User that the Program is Finished and that it will be back.
    cout << endl;
    cout << "*\tThis is all the program does now." << endl;
    cout << "*\tCheck back soon for the next version." << endl;
    cout << " ______________________________________________________________ " <<
            endl;
    cout << endl;
    cout << "| Goodbye! |" <<
            endl;
    cout << " ______________________________________________________________ " <<
            endl;
}; //
vector<int> GenerateRandomQuestion(int mathLevel) {
    enum MathType { MT_ADD = 1, MT_SUB = 2, MT_MUL = 3, MT_DIV = 4 }; // Shows different math types
    MathType questionType;
    int leftNum = 0; // Generate random numbers between 1 and 10
    int rightNum = 0; // Generate random numbers between 1 and 10
    char symbol = '?'; // Gets characters
    int correctAnswer = 0; // Used for the correct answer
    int currentRange = 0;
    int tempNum = 0;
    // This generates a random number between 1 through 10.
    leftNum = (rand() % currentRange) + 1;
    rightNum = (rand() % currentRange) + 1;
    // Randomly choose a math operation.
    questionType = static_cast<MathType>(rand() % 4 + 1);
    // Switches the question type
    switch (questionType) {
        case MT_ADD: // used for addition
            symbol = '+';
            correctAnswer = leftNum + rightNum;
        break;
        case MT_SUB: // used for subtraction
            symbol = '-';
            if (leftNum < rightNum) {
                tempNum = leftNum;
                leftNum = rightNum;
                rightNum = tempNum;
            }
            correctAnswer = leftNum - rightNum;
            break;
        case MT_MUL: // used for multiplication
            symbol = '*';
            correctAnswer = leftNum * rightNum;
        break;
        case MT_DIV: // used for division
            symbol = '/';
            correctAnswer = leftNum;
            leftNum *= rightNum;
        break;
        // This shows that the code is broken, it displays a message.
        default:
            cout << "Error, Invalid Math Type " << "(mathType)" << "." << endl;
            cout << "error -1" << endl;
            cout << "Contact clayrasmussen425@gmail.com" << endl;
            return -1;
    }
}; //
bool GiveThreeAttempts(string userName, vector <int> &currentQuestion) {
    int mathLevel = currentQuestion.at(0); //
    int leftNum = currentQuestion.at(1); //
    char symbol = static_cast<char>(currentQuestion.at(2)); //
    int rightNum = currentQuestion.at(3); //
    int correctAnswer = currentQuestion.at(4); //
    int Attempts = currentQuestion.at(5); //

}; //
void CheckForLevelChange(int &totalCorrect, int &totalIncorrect, int &mathLevel); //
int main() {


    int tempNum = 0; // Used for the subtraction in the switch

    int totalCorrect = 0; // Used to calculate the total correct questions a user has gotten
    int totalIncorrect = 0; // Used to calculate the total incorrect questions a user has gotten

    int currentRange = 10; // Initial range of random numbers
    int Attempts = 0; // Includes Initial Attempts
    vector<vector<int> > questions; //stores every question the suer answers
    const int MAX_ATTEMPTS = 3; // Giving the user the amount of max attempts
    const int LEVEL_RANGE_CHANGE = 10; // Changes the range of questions
    int userAns = 0; // Gets the user answer
    string userInput = "";
    string userName = "?";
    // Seed the random number generator
    srand(time(0));

    DisplayGameIntro();


    // This shows the amount of attempts for the user.
    cout << "*\tYou have a maximum of " << MAX_ATTEMPTS << " attempts for each question. " << endl;
    cout << endl;
    do {
        // Loop-body

        // create a vector to store one question
        vector<int> row = {mathLevel, leftNum, symbol, rightNum, correctAnswer};
        // Shows what level the user is on
        for (int i = 1; i <= MAX_ATTEMPTS; i++) {
            cout << "[Level #" << mathLevel << "] " << userName << ", what is "
                    << leftNum << " " << symbol << " " << rightNum << " = ";
            // Loop until the user enters valid data
            while (!(cin >> userAns)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //
                cout << "\tInvalid input!" << endl;
                cout << "\tPlease enter a number: ";
            }
            cout << endl;
            // Check if the answer is correct
            if (userAns == correctAnswer) {
                cout << "*\t" << "Correct! It looks like you are a math genius. " << endl;
                totalCorrect++;
                row.push_back(i); // adding the users attempt to the users attempt
                break;
            } else if (MAX_ATTEMPTS - i == 0) {
                //
                cout << "*\tSorry, you are out of attempts" << endl;
                cout << "*\tThe correct answer was: " << correctAnswer << endl;
                row.push_back(0); // Records zero to signify incorrect in the summary report
            } else {
                // Shows how many attempts they have left
                cout << "*\t" << "Incorrect. Next try you have it!" << endl;
                totalIncorrect++;
                cout << "*\tYou have " << (MAX_ATTEMPTS - i) << " attempts left." << endl;
                cout << endl;
            }
        }
        questions.push_back(row); // after attempt adds the row to question vector
        if (totalCorrect >= 3) {
            mathLevel++; // Increases the math level
            currentRange += LEVEL_RANGE_CHANGE; // Increase range to have harder questions
            totalCorrect = 0;
            totalIncorrect = 0;
            cout << endl;
            cout << "*\tGreat Job! You are leveling up to level: " << mathLevel <<
                    endl;
            //
            cout << "*\tThe range of numbers will now be: 1-" << currentRange <<
                    endl; //
            cout << endl;
        } else if (totalIncorrect >= 3 && mathLevel > 1) {
            mathLevel--; //
            currentRange -= LEVEL_RANGE_CHANGE; // Decrease range for easier questions
            totalCorrect = 0;
            totalIncorrect = 0;
            cout << endl;
            cout << "*\tWhat a disappointment - You are leveling down to level: " << mathLevel << endl;
            cout << "*\tThe range of numbers will now be: 1-" << currentRange << endl;
            cout << endl;
        }
        getline(cin, userInput); // used to reset input buffer
        while (true) {
            cout << endl;
            cout << "*\tDo you want to continue? (y=yes | n=no) ";
            getline(cin, userInput); // Gets the user input for if they want to continue
            cout << endl;
            for (int i = 0; i < userInput.size(); i++) {
                userInput.at(i) = tolower(userInput.at(i));
            }
            if (userInput == "y" || userInput == "yes"
                || userInput == "n" || userInput == "no") {
                break;
            } else {
                cout << "*\tInvalid input, please try again..." << endl;
                cout << endl;
            }
        }
    } while (userInput == "yes" || userInput == "y"); // Loops the entire code/game ifuser says "yes again
            cout
    <<
    endl;

    return 0;
}
