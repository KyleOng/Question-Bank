/**********|**********|**********|
Program: 1151101783.cpp
Course: TCP1201 - OOPDS
Year: 2016/17 Trimester 2
Name: ONG KYLE
ID: 1151101783
Email: ongkyle@live.com.my
Phone: 017-9648026
**********|**********|**********/
#include "Admin.h"
#include "LinkedList.h"
#include "Rank.h"
#include "fstream"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

Admin::Admin():
    password("admin") //default constructor initialize password as "admin"
{

}

bool Admin::authorize(string passwordPar)
{
    if(passwordPar==password) //admin entered password == system password
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Admin::addQuestion()
{
    Question* q; //question object
    LinkedList<Question*> l; // a linked list of question
    string quesType;
    ifstream instream;

    cout<<endl;
    cout<<"These are Questions List:"<<endl;
    string list;
    instream.open("QuestionList.txt"); //list of question txt file in "QuestionList.txt"
    while(getline(instream,list))
    {
        cout<<list<<endl;
    }
    instream.close();
    cout<<endl;

    cout<<"Insert a file name from the Question List: ";
    getline(cin,fileName);

    instream.open(fileName.c_str());
    if(instream.fail()) //fail open the file entered by the admin
    {
        cout<<"Error file input"<<endl;
        cout<<"Abort Question Adding"<<endl;
    }
    else
    {
        int i=0;
        instream>>quesNum;
        cout<<"Number of question in "<<fileName<<" :"<<quesNum<<endl; //print current total number of question
        while(instream>>quesType) //in file every question from txt
        {
            if(quesType=="TF")
            {
                q=new QuestionTF;
                q->setQuestion(instream);
                i++;
                l.insert(q); //insert to the linked list
            }
            if(quesType=="MC")
            {
                q=new QuestionMC;
                q->setQuestion(instream);
                i++;
                l.insert(q);
            }
            if(quesType=="SA")
            {
                q=new QuestionSA;
                q->setQuestion(instream);
                i++;
                l.insert(q);
            }
        }
        instream.close();

        cout<<"Question Type: ";
        getline(cin,quesType); //admin input question type
        if(quesType=="TF"||quesType=="tf")
        {
            quesType="TF";
            q=new QuestionTF;
            q->adminInput(quesType); //admin input the content of the question depends on the question type
            q->getQuesType();
            q->getQuestion();
            q->getAns();
            q->getMarks();
            l.insert(q); //insert into the last position of the linked list
        }
        if(quesType=="MC"||quesType=="mc")
        {
            quesType="MC";
            q=new QuestionMC;
            q->adminInput(quesType);
            q->getQuesType();
            q->getQuestion();
            q->getAns();
            q->getQuantity();
            for(int i=0;i<q->getQuantity();i++)
            {
                q->getChoice(i);
            }
            q->getMarks();
            l.insert(q);
        }
        if(quesType=="SA"||quesType=="sa")
        {
            quesType="SA";
            q=new QuestionSA;
            q->adminInput(quesType);
            q->getQuesType();
            q->getQuestion();
            q->getAns();
            q->getMarks();
            l.insert(q);
        }
        quesNum++;

        PrintToText(l); //out file to the Question txt file
        cout<<"Number of question in "<<fileName<<" :"<<quesNum<<endl; //print out the new number of question in the txt file
    }
}

void Admin::removeQuestion()
{
    Question* q;
    LinkedList<Question*> l;
    string quesType;
    ifstream instream;

    cout<<endl;
    cout<<"These are Questions List:"<<endl;
    string list;
    instream.open("QuestionList.txt");
    while(getline(instream,list))
    {
        cout<<list<<endl;
    }
    instream.close();
    cout<<endl;

    cout<<"Insert a file name from the Question List: ";
    getline(cin,fileName);

    instream.open(fileName.c_str());
    if(instream.fail())
    {
        cout<<"Error file input"<<endl;
        cout<<"Abort Question Adding"<<endl;
    }
    else
    {
        int i=0;
        instream>>quesNum;
        cout<<"Number of question in "<<fileName<<" :"<<quesNum<<endl;

        string numRemove;
        cout<<"Position of the question want to be removed: "; //insert remove position
        getline(cin,numRemove);
        position=atoi(numRemove.c_str());

        while(instream>>quesType)
        {
            if(quesType=="TF")
            {
                q=new QuestionTF;
                q->setQuestion(instream);
                i++;
                l.insert(q);
            }
            if(quesType=="MC")
            {
                q=new QuestionMC;
                q->setQuestion(instream);
                i++;
                l.insert(q);
            }
            if(quesType=="SA")
            {
                q=new QuestionSA;
                q->setQuestion(instream);
                i++;
                l.insert(q);
            }
        }
        instream.close();
        //same algorithm for in file every question
        l.erase(position); //remove question at the position
        quesNum--;

        PrintToText(l);//out file to the Question txt file
        cout<<"Number of question in "<<fileName<<" :"<<quesNum<<endl;
    }
}

void Admin::SearchAndEdit()
{
    Question* q;
    LinkedList<Question*> l;
    LinkedList<Question*> temp; //a temporary linked list that store question (for later use)
    string quesType;
    ifstream instream;

    cout<<endl;
    cout<<"These are Questions List:"<<endl;
    string list;
    instream.open("QuestionList.txt");
    while(getline(instream,list))
    {
        cout<<list<<endl;
    }
    instream.close();
    cout<<endl;

    cout<<"Insert a file name from the Question List: ";
    getline(cin,fileName);

    instream.open(fileName.c_str());
    if(instream.fail())
    {
        cout<<"Error file input"<<endl;
        cout<<"Abort Question Adding"<<endl;
    }
    else
    {
        int i=0;
        instream>>quesNum;
        cout<<"Number of question in "<<fileName<<":"<<quesNum<<endl;
        while(instream>>quesType)
        {
            if(quesType=="TF")
            {
                q=new QuestionTF;
                q->setQuestion(instream);
                l.insert(q);
                temp.insert(q); //insert temp linked list

                i++;
            }
            if(quesType=="MC")
            {
                q=new QuestionMC;
                q->setQuestion(instream);
                l.insert(q);
                temp.insert(q);
                i++;
            }
            if(quesType=="SA")
            {
                q=new QuestionSA;
                q->setQuestion(instream);
                l.insert(q);
                temp.insert(q);

                i++;
            }
        }
        instream.close();

        string phrase;
        cout<<"Insert the phrase that you want to search: "; //insert phrase
        getline(cin,phrase);

        for (int i=1;i<=quesNum;i++)
        {
             size_t found = l.retrieve(i)->getQuestion().find(phrase); //finding question that contain the phrase
             if (found!=string::npos) //question that contain phrase has been found
             {
                 string access;
                 cout<<"Question "<<i<<endl;
                 cout<<"============="<<endl;
                 l.retrieve(i)->displayQuestion();
                 cout<<endl;
                 cout<<"Do you want to edit this question? (enter y/Y to edit)"<<endl;
                 getline(cin, access);
                 if(access=="Y"||access=="y") //admin want to edit question
                 {
                     string quesType;
                     cout<<"Question Type: ";
                     getline(cin,quesType); //set new Question Type
                     if(quesType=="TF"||quesType=="tf")
                     {
                        quesType="TF";
                        q=new QuestionTF;
                        q->adminInput(quesType); //set the content of the Question based on the Question Type
                        for(int j=quesNum;j>=i;j--)
                        {
                            l.erase(j); //remove from the last to the current position of the found question
                        }

                        for(int j=1;j<=i;j++)
                        {
                            temp.erase(1); //remove from the first to the current position of the found question
                        }
                        l.insert(q); //insert the new set question to the current position of the found question

                        for(int j=1;j<=temp.getLength();j++)
                        {
                            l.insert(temp.retrieve(j)); //insert every question in temp linked list to the original linked list
                        }
                     }
                     if(quesType=="MC"||quesType=="mc")
                     {
                        quesType="MC";
                        q=new QuestionMC;
                        q->adminInput(quesType);
                        for(int j=quesNum;j>=i;j--)
                        {
                            l.erase(j);
                        }

                        for(int j=1;j<=i;j++)
                        {
                            temp.erase(1);
                        }
                        l.insert(q);

                        for(int j=1;j<=temp.getLength();j++)
                        {
                            l.insert(temp.retrieve(j));
                        }

                     }
                     if(quesType=="SA"||quesType=="sa")
                     {
                        quesType="SA";
                        q=new QuestionSA;
                        q->adminInput(quesType);
                        for(int j=quesNum;j>=i;j--)
                        {
                            l.erase(j);
                        }

                        for(int j=1;j<=i;j++)
                        {
                            temp.erase(1);
                        }
                        l.insert(q);

                        for(int j=1;j<=temp.getLength();j++)
                        {
                            l.insert(temp.retrieve(j));
                        }
                     }
                     PrintToText(l); //out file to the txt file
                     cout<<"Edit successful!"<<endl; //edit successful!
                     cout<<endl;
                 }
                 else
                 {
                     cout<<"Edit abort! Proceed to another question contain the same phrase"<<endl;
                     cout<<endl;
                 }
             }
        }
    }
}

void Admin::Scoreboard()
{
    Rank h; //rank object
    LinkedList<Rank>r; //a linked list of rank object

    string RankTitle;
    string RankFirstName;
    string RankLastName;
    string RankFinalMark;
    string RankFileName;
    ifstream in_stream;
    in_stream.open("Rank.txt");
    cout<<endl;

    cout<<"TOP 10 SCOREBOARD"<<endl;
    cout<<"================================================================="<<endl;
    cout<<"|"<<setw(15)<<left<<"First Name"<<"|";
    cout<<setw(15)<<left<<"First Name"<<"|";
    cout<<setw(15)<<left<<"Text File"<<"|";
    cout<<setw(15)<<left<<"Score"<<"|"<<endl;
    cout<<"================================================================="<<endl;
    for(int i=1;i<=10;i++)
    {
        getline(in_stream,RankFirstName,'|');
        getline(in_stream,RankLastName,'|');
        getline(in_stream,RankFileName,'|');
        getline(in_stream,RankFinalMark); //in file to Rank.txt
        h.setFirstName(RankFirstName);
        h.setLastName(RankLastName);
        h.setMark(atoi(RankFinalMark.c_str()));
        h.setFileName(RankFileName);
        r.insert(h); //insert into linked list
        cout<<"|"<<setw(15)<<left<<r.retrieve(i).getFirstName()<<"|";
        cout<<setw(15)<<left<<r.retrieve(i).getlastName()<<"|";
        cout<<setw(15)<<left<<r.retrieve(i).getFileName()<<"|";
        cout<<setw(15)<<left<<r.retrieve(i).getMark()<<"|"<<endl;  //print on screen
    }
    cout<<"================================================================="<<endl;
    in_stream.close();
    string wait;
    cout<<"Enter anything to proceed"<<endl;
    getline(cin,wait);
}

void Admin::PrintToText(LinkedList<Question*> l)
{
    ofstream outstream;
    outstream.open(fileName.c_str());
    outstream<<quesNum<<endl;
    for(int i=1;i<=quesNum;i++)
    {
        outstream<<(l.retrieve(i)->getQuesType()+" ");
        outstream<<l.retrieve(i)->getMarks()<<endl;
        outstream<<l.retrieve(i)->getQuestion()<<endl;
        if(l.retrieve(i)->getQuantity()>0)
        {
            outstream<<l.retrieve(i)->getQuantity()<<endl;
            int j=0;
            while(j<l.retrieve(i)->getQuantity())
            {
                outstream<<l.retrieve(i)->getChoice(j)<<endl;
                j++;
            }
        }
        outstream<<l.retrieve(i)->getAns()<<endl;
    }

}
