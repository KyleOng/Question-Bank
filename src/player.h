/**********|**********|**********|
Program: 1151101783.cpp
Course: TCP1201 - OOPDS
Year: 2016/17 Trimester 2
Name: ONG KYLE
ID: 1151101783
Email: ongkyle@live.com.my
Phone: 017-9648026
**********|**********|**********/
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

class player
{
private:
    string firstName;
    string lastName;
    string fileName;
    int txtQuesNum;
    int quesNum;
    int finalMark;
public:
    player();
    string getFirstName();
    string getLastName();
    string getFileName();
    int getQuesNum();
    int getFinalMark();
    int getTxtQuesNum();
    void setName();
    void setFile();
    void setFinalMark(int markPar);
};

#endif // PLAYER_H
