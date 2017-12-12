/**********|**********|**********|
Program: 1151101783.cpp
Course: TCP1201 - OOPDS
Year: 2016/17 Trimester 2
Name: ONG KYLE
ID: 1151101783
Email: ongkyle@live.com.my
Phone: 017-9648026
**********|**********|**********/
#ifndef RANK_H
#define RANK_H
#include <iostream>
using namespace std;
class Rank
{
    friend bool operator<= (Rank s1, Rank s2);
    friend bool operator>= (Rank s1, Rank s2);
private:
    string firstName;
    string lastName;
    int mark;
    string fileName;
public:
    Rank();
    ~Rank();
    string getFirstName();
    string getlastName();
    int getMark();
    string getFileName();
    void setFirstName(string firstNamePar);
    void setLastName(string lastNamePar);
    void setMark(int markPar);
    void  setFileName(string fileNamePar );

};

#endif // SCORE_H
