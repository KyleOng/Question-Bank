/**********|**********|**********|
Program: 1151101783.cpp
Course: TCP1201 - OOPDS
Year: 2016/17 Trimester 2
Name: ONG KYLE
ID: 1151101783
Email: ongkyle@live.com.my
Phone: 017-9648026
**********|**********|**********/
#include "QuestionSA.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

QuestionSA::QuestionSA()
{

}

QuestionSA::~QuestionSA()
{

}

void QuestionSA::setMarks(int& marksPar)
{
    if (trueOrFalse==true)
    {
        marksPar=marksPar+marks;
    }
    else
    {
        marksPar=marksPar-marks;
    }
    cout<<"current total marks: "<<marksPar<<endl;

}

void QuestionSA::setQuestion(ifstream& instream)
{
    quesType="SA";
    instream>>marks;
    instream.ignore();
    getline(instream,question);
    getline(instream,ans);
}

void QuestionSA::displayQuestion()
{
    cout<<question<<endl;
}

void QuestionSA::answerQuestion()
{
    cout<<"answer: ";
    getline(cin,playerAns);

    for(int i=0;i<playerAns.length();i++)
    {
        playerAns[i]=tolower(playerAns[i]);
    }

    string LCans(ans);
    for(int i=0;i<ans.length();i++)
    {
        ans[i]=tolower(ans[i]);
    }

    if(playerAns==ans)
    {
        cout<<"correct, you get "<<marks<<" marks"<<endl;
        trueOrFalse=true;
    }
    else
    {
        cout<<"wrong, you lost "<<marks<<" marks"<<endl;
        cout<<"The correct answer is "<<ans<<endl;
        trueOrFalse=false;
    }
}

void QuestionSA::adminInput(string quesTypePar)
{
    quesType=quesTypePar;
    cout<<"Question: ";
    getline(cin,question);
    cout<<"Answer: ";
    getline(cin,ans);
    string marksInString;
    cout<<"Mark: ";
    getline(cin,marksInString);
    marks=atoi(marksInString.c_str());
}
