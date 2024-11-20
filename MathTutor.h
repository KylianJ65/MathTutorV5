//
// Created by james on 11/19/2024.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
#ifndef MATHTUTOR_H
#define MATHTUTOR_H


// Function Prototypes
void DisplayGameIntro();
string GetUserName();
int GetNumericValue();
string AskToPlayAgain(string userName);
void DisplaySummaryReport(const vector<vector<int>> &allQuestions);
vector<int> GenerateRandomQuestion(int mathLevel, int currentRange);
bool GiveThreeAttempts(string userName, vector<int> &currentQuestion, int &totalCorrect, int &totalIncorrect);
void CheckForLevelChange(int &totalCorrect, int &totalIncorrect, int &mathLevel, int &currentRange);

#endif //MATHTUTOR_H
