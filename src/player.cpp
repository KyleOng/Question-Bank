/**********|**********|**********|
Program: 1151101783.cpp
Course: TCP1201 - OOPDS
Year: 2016/17 Trimester 2
Name: ONG KYLE
ID: 1151101783
Email: ongkyle@live.com.my
Phone: 017-9648026
**********|**********|**********/
#include "player.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

player::player():
    firstName("NA"),lastName("NA"),fileName("NA"),txtQuesNum(0),quesNum(0),finalMark(0)
    {
    }

string player::getFirstName()
{
    return firstName;
}

string player::getLastName()
{
    return lastName;
}

string player::getFileName()
{
    return fileName;
}

int player::getQuesNum()
{
    return quesNum;
}

int player::getFinalMark()
{
    return finalMark;
}

int player::getTxtQuesNum()
{
    return txtQuesNum;
}

void player::setName()
{
    while(true)
    {
        cout<<"Enter your first Name: ";
        getline(cin,firstName);
        if (firstName=="")
        {
            cout<<"invalid input"<<endl;
        }
        else
        {
            break;
        }
    }

    while(true)
    {
        cout<<"Enter your last Name: ";
        getline(cin,lastName);
        if (lastName=="")
        {
            cout<<"invalid input"<<endl;
        }
        else
        {
            break;
        }
    }
}

void player::setFile()
{
    char input[100];
    while(true)
    {
        ifstream fin;

        cout<<endl;
        cout<<"These are Questions List:"<<endl;
        string list;
        fin.open("QuestionList.txt");
        while(getline(fin,list))
        {
            cout<<list<<endl;
        }
        fin.close();
        cout<<endl;

        cout<<"insert file name from the Question List: ";
        getline(cin,fileName);

        fin.open(fileName.c_str());
        if(fin.fail())
        {
            cout<<"error file input"<<endl;
        }
        else
        {
            cout<<"file opening success"<<endl;
            fin>>txtQuesNum;
            do
            {
                cout<<"How many question would you like to do?: ";
                cin.getline(input,100);
                bool noError=true;
                int i=0;
                do
                {
                    if(isdigit(input[i])==0)
                    {
                        noError=false;
                        break;
                    }
                    i++;
                }while(input[i]!='\0');

                if(noError==true)
                {
                    quesNum=atoi(input);
                    if (quesNum>0&&quesNum<=txtQuesNum)
                    {
                        cout<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"Invalid number of question"<<endl;
                    }
                }
                else
                {
                    cout<<"invalid input"<<endl;
                }

            }while (true);
            fin.close();
            break;
        }
    }
}

void player::setFinalMark(int markPar)
{
    finalMark=markPar;
}
