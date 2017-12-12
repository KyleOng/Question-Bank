/**********|**********|**********|
Program: 1151101783.cpp
Course: TCP1201 - OOPDS
Year: 2016/17 Trimester 2
Name: ONG KYLE
ID: 1151101783
Email: ongkyle@live.com.my
Phone: 017-9648026
**********|**********|**********/
#include "QuestionTF.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

QuestionTF::QuestionTF()
{

}

QuestionTF::~QuestionTF()
{

}

void QuestionTF::setMarks(int& marksPar)
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

void QuestionTF::setQuestion(ifstream& instream)
{
    quesType="TF";
    instream>>marks;
    instream.ignore();
    getline(instream,question);
    getline(instream,ans);
}

void QuestionTF::displayQuestion()
{
    cout<<question<<endl;
}

void QuestionTF::answerQuestion()
{
    while (true)
    {
        cout<<"answer: ";
        getline(cin,playerAns);

        for(int i=0;i<playerAns.length();i++)
        {
            playerAns[i]=tolower(playerAns[i]);
        }

        if(playerAns=="true"||playerAns=="false")
        {
            break;
        }
        else
        {
            cout<<endl;
            cout<<"Error: Invalid input (Input must be true/false)"<<endl;
            cout<<endl;
        }
    }

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

void QuestionTF::adminInput(string quesTypePar)
{
    quesType=quesTypePar;
    cout<<"Question:";
    getline(cin,question);
    question=question+ " (true/false)";
    cout<<"Answer: ";
    getline(cin,ans);

    string marksInString;
    cout<<"Mark: ";
    getline(cin,marksInString);
    marks=atoi(marksInString.c_str());
}
