/**********|**********|**********|
Program: 1151101783.cpp
Course: TCP1201 - OOPDS
Year: 2016/17 Trimester 2
Name: ONG KYLE
ID: 1151101783
Email: ongkyle@live.com.my
Phone: 017-9648026
**********|**********|**********/
#ifndef QUESTION_H
#define QUESTION_H
#include <iostream>
using namespace std;
class Question
{
protected:
    int marks;
    bool trueOrFalse;
    string quesType;
    string question;
    string playerAns;
    string ans;
    string file;
    string* choice;
    int quantity;
public:
    Question();
    virtual ~Question();
    virtual void setMarks(int& marksPar)=0;
    virtual void setQuestion(ifstream& in_stream)=0;
    virtual void displayQuestion()=0;
    virtual void answerQuestion()=0;
    virtual void adminInput(string quesTypePar)=0;

    string getQuesType();
    string getQuestion();
    string getAns();
    string getChoice(int i);
    int getQuantity();
    int getMarks();

};


#endif // QUESTION_H
