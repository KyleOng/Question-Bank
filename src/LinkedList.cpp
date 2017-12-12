/**********|**********|**********|
Program: 1151101783.cpp
Course: TCP1201 - OOPDS
Year: 2016/17 Trimester 2
Name: ONG KYLE
ID: 1151101783
Email: ongkyle@live.com.my
Phone: 017-9648026
**********|**********|**********/
#include "LinkedList.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

template<class ItemType>
LinkedList<ItemType>::LinkedList(): headPtr(nullptr), itemCount(0)
{
}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : itemCount(aList.itemCount)
{
   Node<ItemType>* origChainPtr = aList.headPtr;

   if (origChainPtr == nullptr)
      headPtr = nullptr;
   else
   {
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      Node<ItemType>* newChainPtr = headPtr;
      origChainPtr = origChainPtr->getNext();
      while (origChainPtr != nullptr)
      {
         ItemType nextItem = origChainPtr->getItem();
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         newChainPtr->setNext(newNodePtr);
         newChainPtr = newChainPtr->getNext();
         origChainPtr = origChainPtr->getNext();
      }

      newChainPtr->setNext(nullptr);
   }
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty()
{
   return itemCount == 0;
}

template<class ItemType>
int LinkedList<ItemType>::getLength()
{
   return itemCount;
}

template<class ItemType>
void LinkedList<ItemType>::insert(const ItemType& newEntry)
{
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

    if (itemCount == 0)
    {
         headPtr = newNodePtr;
    }
    else
    {
        Node<ItemType>* currPtr = headPtr;
        while(currPtr->getNext() != nullptr)
        {
            currPtr=currPtr->getNext();
        }
        currPtr->setNext(newNodePtr);
    }
    itemCount++;
}

template<class ItemType>
void LinkedList<ItemType>::erase(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      Node<ItemType>* curPtr = nullptr;
      if (position == 1)
      {
         curPtr = headPtr;
         headPtr = headPtr->getNext();
      }
      else
      {
         Node<ItemType>* prevPtr = getNodeAt(position - 1);
         curPtr = prevPtr->getNext();
         prevPtr->setNext(curPtr->getNext());
      }


      curPtr->setNext(nullptr);
      delete curPtr;
      curPtr = nullptr;

      itemCount--;
   }
}

template<class ItemType>
void LinkedList<ItemType>::clear()
{
   while (!isEmpty())
   {
       erase(1);
   }

}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position)
{
   Node<ItemType>* curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();

   return curPtr;
}

template<class ItemType>
ItemType LinkedList<ItemType>::retrieve(int position) throw(PrecondViolatedExcep)
{
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
      Node<ItemType>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
    }
    else
    {
      string message = "retrieve() called with an empty list or ";
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message));
    }
    }

template<class ItemType>
void LinkedList<ItemType>::randomize()
{
    srand(time(NULL));
    for(int i=1;i<=itemCount;i++)
    {
        int num=(rand()%(itemCount))+1;
        Node<ItemType>* FirstNode=getNodeAt(i);
        Node<ItemType>* SecondNode=getNodeAt(num);

        Node<ItemType>* TempNode= new Node<ItemType>;
        TempNode->setItem(FirstNode->getItem());

        if(i!=num)
        {
            FirstNode->setItem(SecondNode->getItem());
            SecondNode->setItem(TempNode->getItem());
        }
    }
}

template<class ItemType>
bool LinkedList<ItemType>::sortedInsertDesc(const ItemType& newEntry)
{
  Node<ItemType> *newPtr = new Node<ItemType>(newEntry);

  if(itemCount == 0 || newEntry >= headPtr->getItem())
  {
    newPtr->setNext(headPtr);
    headPtr = newPtr;
    itemCount++;
    return true;
  }
  else
  {
    Node<ItemType> *currPtr;
    Node<ItemType> *prevPtr;
    int i = 1;
    prevPtr = headPtr;

    while(i < itemCount)
    {
      currPtr = prevPtr->getNext();

      if( (newEntry <= prevPtr->getItem()) && (newEntry >= currPtr->getItem()) )
      {
        prevPtr->setNext(newPtr);
        newPtr->setNext(currPtr);
        itemCount++;
        return true;
      }
      prevPtr = prevPtr->getNext();
      i = i + 1;
    }

    newPtr->setNext(nullptr);
    prevPtr->setNext(newPtr);
    itemCount++;
    return true;
  }
}
