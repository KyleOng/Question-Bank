/**********|**********|**********|
Program: 1151101783.cpp
Course: TCP1201 - OOPDS
Year: 2016/17 Trimester 2
Name: ONG KYLE
ID: 1151101783
Email: ongkyle@live.com.my
Phone: 017-9648026
**********|**********|**********/
#ifndef _LINKED_LIST
#define _LINKED_LIST
#include "Node.h"
#include "PrecondViolatedExcep.h"
#include <iostream>
using namespace std;

template<class ItemType>
class LinkedList
{
private:
    Node<ItemType>* headPtr;
    int itemCount;
    Node<ItemType>* getNodeAt(int position);
    void clear();
public:
    LinkedList();
    LinkedList(const LinkedList<ItemType>& aList);
    ~LinkedList();
    bool isEmpty();
    int getLength();
    void insert(const ItemType& newEntry);
    void erase(int position);
    ItemType retrieve(int position) throw(PrecondViolatedExcep);;
    void randomize();
    bool sortedInsertDesc(const ItemType& newEntry);

};


#include "LinkedList.cpp"
#endif
