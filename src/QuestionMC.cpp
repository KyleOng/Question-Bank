/**********|**********|**********|
Program: 1151101783.cpp
Course: TCP1201 - OOPDS
Year: 2016/17 Trimester 2
Name: ONG KYLE
ID: 1151101783
Email: ongkyle@live.com.my
Phone: 017-9648026
**********|**********|**********/
#include "QuestionMC.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

QuestionMC::QuestionMC():
    letter('A')
{

}

QuestionMC::~QuestionMC()
{

}

void QuestionMC::setMarks(int& marksPar)
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

void QuestionMC::setQuestion(ifstream& instream)
{
    string line;
    quesType="MC";
    instream>>marks;
    instream.ignore();
    getline(instream,question);
    getline(instream,line);
    quantity=atoi(line.c_str());
    choice=new string[quantity];
    for(int i=0; i<quantity;i++)
    {
        getline(instream,choice[i]);
    }
    getline(instream,ans);

}

void QuestionMC::displayQuestion()
{
    cout<<question<<endl;
    for(int i=0;i<quantity;i++)
    {
        cout<<letter++<<"-> "<<choice[i]<<endl;
    }

}

void QuestionMC::answerQuestion()
{
    while(true)
    {
        cout<<"answer: ";
        getline(cin,playerAns);

        for(int i=0;i<playerAns.length();i++)
        {
            playerAns[i]=tolower(playerAns[i]);
        }

        if(playerAns.size()<2&&playerAns[0]>=char(65)&&(playerAns[0]<=char(65+quantity-1)))
        {
            break;
        }
        else
        {
            if(playerAns.size()<2&&playerAns[0]>=char(97)&&(playerAns[0]<=char(97+quantity-1)))
            {

                break;
            }
            else
            {
                cout<<endl;
                cout<<"Error: Invalid input (Input must be alphabetical AND inside the range of choices)"<<endl;
                cout<<endl;
            }
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
    delete [] choice;

}

void QuestionMC::adminInput(string quesTypePar)
{
    quesType=quesTypePar;
    cout<<"Question: ";
    getline(cin,question);
    cout<<"Choice: "<<endl;
    cout<<"Quantity: ";

    string quantityInString;
    getline(cin,quantityInString);
    quantity=atoi(quantityInString.c_str());

    choice=new string[quantity];
    for(int i=0; i<quantity;i++)
    {
        cout<<letter<<"-> ";
        getline(cin,choice[i]);
        letter++;
    }
    cout<<"Answer: ";
    getline(cin,ans);

    string marksInString;
    cout<<"Mark: ";
    getline(cin,marksInString);
    marks=atoi(marksInString.c_str());
}
