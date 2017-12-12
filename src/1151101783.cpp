/**********|**********|**********|
Program: 1151101783.cpp
Course: TCP1201 - OOPDS
Year: 2016/17 Trimester 2
Name: ONG KYLE
ID: 1151101783
Email: ongkyle@live.com.my
Phone: 017-9648026
**********|**********|**********/
#include <iostream>
#include "player.h"
#include "Question.h"
#include "QuestionTF.h"
#include "QuestionMC.h"
#include "QuestionSA.h"
#include "LinkedList.h"
#include "Rank.h"
#include "Admin.h"
#include <fstream>
#include <ctime>
#include <cstring>
#include <iomanip>

using namespace std;

void AdminMode(); //Function only for admin

void PlayerRankSetting(string firstName,string lastName,int finalMark,string fileName); //Setting ranking for the player

void PlayerMode(); //Function only for player

int main()
{
    cout<<"=========================WELCOME TO============================"<<endl;
    cout<<"  #####  #     # ### #######    ######     #    #     # #    # "<<endl;
    cout<<" #     # #     #  #       #     #     #   # #   ##    # #   #  "<<endl;
    cout<<" #     # #     #  #      #      #     #  #   #  # #   # #  #   "<<endl;
    cout<<" #     # #     #  #     #       ######  #     # #  #  # ###    "<<endl;
    cout<<" #   # # #     #  #    #        #     # ####### #   # # #  #   "<<endl;
    cout<<" #    #  #     #  #   #         #     # #     # #    ## #   #  "<<endl;
    cout<<"  #### #  #####  ### #######    ######  #     # #     # #    # "<<endl;
    cout<<"========================VERSION 2.0============================"<<endl;
    cout<<"                   BY ONG KYLE (1151101783)                    "<<endl;
    cout<<endl;
    while(true)
    {
        string user;
        cout<<"Player or Admin: ";
        getline(cin,user); //insert whether admin or player

        for(int i=0;i<user.length();i++)
        {
            user[i]=tolower(user[i]); //conversion all char to lower case
        }

        if (user=="player")
        {
            PlayerMode(); //player function
            break;
        }
        else
        {
            if(user=="admin")
            {
               AdminMode(); //admin function
               break;
            }
            else
            {
                cout<<"Invalid user input"<<endl; //Error message: loop until user enter a valid input
            }
        }
    }
    cout<<endl;
    cout<<"PROGRAM END"<<endl;
    return 0;
}

//function definition
void AdminMode()
{
    Admin a; //admin object
    string password;
    cout<<"password (case sensitive): ";
    getline(cin,password); //entering password

    if(a.authorize(password)==true) //correct password
    {
        cout<<endl;
        cout<<"WELCOME ADMIN"<<endl;
        while(true)
        {
            string input;
            cout<<"==============="<<endl;
            cout<<"  ADMIN MENU   "<<endl;
            cout<<"==============="<<endl;
            cout<<"1. Add question"<<endl;
            cout<<"2. Remove question"<<endl;
            cout<<"3. Search and Edit"<<endl;
            cout<<"4. Scoreboard"<<endl;
            cout<<"5. Exit"<<endl;
            cout<<endl;
            cout<<"Select an option:";
            getline(cin,input);
            switch(atoi(input.c_str()))
            {
            case 1:
                {
                    a.addQuestion(); //when admin enter 1, admin can add question
                    break;
                }
            case 2:
                {
                    a.removeQuestion(); //when admin enter 2, admin can remove question at any position
                    break;
                }
            case 3:
                {
                    a.SearchAndEdit(); //when admin enter 3, admin can search for questions at any position that contain specific phrase, and edit at his/her own will
                    break;
                }
            case 4:
                {
                    a.Scoreboard(); //when admin enter 4, admin can see the score board
                    break;
                }
            case 5:
                {
                    cout<<"PROGRAM END"<<endl;
                    exit(1); //exit program immediately when admin enter 4
                    break;
                }
            default:
                {
                    cout<<"invalid option"<<endl;
                    break;
                }

            }
            cout<<endl;
        }
    }
    else //incorrect password
    {
        cout<<"Invalid admin password"<<endl; //incorrect password, exit program immediately
    }

}


void PlayerRankSetting(string firstName,string lastName,int finalMark,string fileName)
{
    Rank h; //rank object
    LinkedList<Rank>r; //a linked list of rank object

    string RankTitle;
    string RankFirstName;
    string RankLastName;
    string RankFinalMark;
    string RankFileName;
    ifstream in_stream;
    ofstream out_stream;
    in_stream.open("Rank.txt");
    while(!in_stream.eof()) //in file stream score of every previous player from Rank.txt
    {
        getline(in_stream,RankFirstName,'|');
        getline(in_stream,RankLastName,'|');
        getline(in_stream,RankFileName,'|');
        getline(in_stream,RankFinalMark);
        h.setFirstName(RankFirstName);
        h.setLastName(RankLastName);
        h.setMark(atoi(RankFinalMark.c_str()));
        h.setFileName(RankFileName);
        r.insert(h); //insert score
    }
    in_stream.close();

    h.setFirstName(firstName);
    h.setLastName(lastName);
    h.setMark(finalMark);
    h.setFileName(fileName);
    r.sortedInsertDesc(h); //insert "current player"score and sort descending

    out_stream.open("Rank.txt");
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
        cout<<"|"<<setw(15)<<left<<r.retrieve(i).getFirstName()<<"|";
        cout<<setw(15)<<left<<r.retrieve(i).getlastName()<<"|";
        cout<<setw(15)<<left<<r.retrieve(i).getFileName()<<"|";
        cout<<setw(15)<<left<<r.retrieve(i).getMark()<<"|"<<endl;  //print on screen
        out_stream<<r.retrieve(i).getFirstName()<<"|";
        out_stream<<r.retrieve(i).getlastName()<<"|";
        out_stream<<r.retrieve(i).getFileName()<<"|";
        out_stream<<r.retrieve(i).getMark()<<endl; //out file to Rank.txt
    }
    cout<<"================================================================="<<endl;
    out_stream.close();

}

void PlayerMode()
{
    cout<<endl;
    cout<<"WELCOME PLAYER"<<endl;
    cout<<endl;
    string firstName;
    string lastName;
    string fileName;
    int finalMark;
    int quesNum;
    player a; //player object
    a.setName(); //set player name
    a.setFile(); //set question file that players want

    firstName=a.getFirstName();
    lastName=a.getLastName();
    fileName=a.getFileName();
    finalMark=a.getFinalMark();
    quesNum=a.getQuesNum(); //get player question num

    Question* q; //Question object
    LinkedList<Question*> l; //A linked list of question
    string quesType;
    ifstream instream;
    instream.open(fileName);
    int i=0;
    while(instream>>quesType) //in file every question, marks and answer
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
    l.randomize();

    for(int i=1;i<=quesNum;i++) //display and answer by player
    {
        l.retrieve(i)->displayQuestion(); //display question
        l.retrieve(i)->answerQuestion(); //answer question
        l.retrieve(i)->setMarks(finalMark); //set the final mark
        cout<<endl;
    }
    a.setFinalMark(finalMark);

    PlayerRankSetting(firstName,lastName,finalMark,fileName); //set rank depends on player score
}
