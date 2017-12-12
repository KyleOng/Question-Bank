/**********|**********|**********|
Program: 1151101783.cpp
Course: TCP1201 - OOPDS
Year: 2016/17 Trimester 2
Name: ONG KYLE
ID: 1151101783
Email: ongkyle@live.com.my
Phone: 017-9648026
**********|**********|**********/
#ifndef QUESTIONSA_H
#define QUESTIONSA_H
#include "Question.h"
#include <iostream>
using namespace std;

class QuestionSA: public Question
{
public:
    QuestionSA();
    ~QuestionSA();
    void setMarks(int& marksPar);
    void setQuestion(ifstream& in_stream);
    void displayQuestion();
    void answerQuestion();

    void adminInput(string quesTypePar);
};

#endif // QUESTIONTF_H
