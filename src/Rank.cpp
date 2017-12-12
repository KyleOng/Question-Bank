/**********|**********|**********|
Program: 1151101783.cpp
Course: TCP1201 - OOPDS
Year: 2016/17 Trimester 2
Name: ONG KYLE
ID: 1151101783
Email: ongkyle@live.com.my
Phone: 017-9648026
**********|**********|**********/
#include "Rank.h"
#include <iostream>
using namespace std;

Rank::Rank():
    firstName("NA"),
    lastName("NA"),
    mark(0),
    fileName("NA")
    {}

Rank::~Rank()
{};


string Rank::getFirstName()
{
    return firstName;
}

string Rank::getlastName()
{
    return lastName;
}


int Rank::getMark()
{
    return mark;
}

string Rank::getFileName()
{
    return fileName;
}

void Rank::setFirstName(string firstNamePar)
{
    firstName=firstNamePar;
}

void Rank::setLastName(string lastNamePar)
{
    lastName=lastNamePar;
}

void Rank::setMark(int markPar)
{
    mark=markPar;
}

void  Rank::setFileName(string fileNamePar )
{
    fileName=fileNamePar;
}

bool operator<= (Rank s1, Rank s2)
{
  return (s1.getMark() <= s2.getMark());
}

bool operator>= (Rank s1, Rank s2)
{
  return (s1.getMark() >= s2.getMark());
}
