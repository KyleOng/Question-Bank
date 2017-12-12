/**********|**********|**********|
Program: 1151101783.cpp
Course: TCP1201 - OOPDS
Year: 2016/17 Trimester 2
Name: ONG KYLE
ID: 1151101783
Email: ongkyle@live.com.my
Phone: 017-9648026
**********|**********|**********/
#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include "Question.h"
#include "QuestionTF.h"
#include "QuestionMC.h"
#include "QuestionSA.h"
#include "LinkedList.h"
using namespace std;
class Admin
{
private:
    int position;
    string fileName;
    string password;
    string quesType;
    string question;
    string ans;
    int quesNum;
    void PrintToText(LinkedList<Question*>);
public:
    Admin();
    bool authorize(string passwordPar);
    void addQuestion();
    void removeQuestion();
    void SearchAndEdit();
    void Scoreboard();

};
#endif // ADMIN_H
