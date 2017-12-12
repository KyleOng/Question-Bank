/**********|**********|**********|
Program: 1151101783.cpp
Course: TCP1201 - OOPDS
Year: 2016/17 Trimester 2
Name: ONG KYLE
ID: 1151101783
Email: ongkyle@live.com.my
Phone: 017-9648026
**********|**********|**********/
#include "Question.h"
#include <iostream>
using namespace std;

Question::Question():
    marks(0),trueOrFalse(true),quesType("NA"),question("NA"),playerAns("NA"),ans("NA"),file("NA"),choice(NULL),quantity(0)
    {

    }

Question::~Question()
{

}

string Question::getQuesType()
{
    return quesType;
}

string Question::getQuestion()
{
    return question;
}

string Question::getAns()
{
    return ans;
}

string Question::getChoice(int i)
{
    return choice[i];
}

int Question::getQuantity()
{
    return quantity;
}

int Question::getMarks()
{
    return marks;
}
