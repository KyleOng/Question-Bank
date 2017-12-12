/**********|**********|**********|
Program: 1151101783.cpp
Course: TCP1201 - OOPDS
Year: 2016/17 Trimester 2
Name: ONG KYLE
ID: 1151101783
Email: ongkyle@live.com.my
Phone: 017-9648026
**********|**********|**********/
#ifndef QUESTIONMC_H
#define QUESTIONMC_H
#include "Question.h"
#include <iostream>
using namespace std;

class QuestionMC: public Question
{
private:
    char letter;
public:
    QuestionMC();
    ~QuestionMC();
    void setMarks(int& marksPar);
    void setQuestion(ifstream& in_stream);
    void displayQuestion();
    void answerQuestion();

    void adminInput(string quesTypePar);
};

#endif // QUESTIONMC_H
