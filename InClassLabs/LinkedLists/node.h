#ifndef node_h
#define node_h
#include <cstddef>
#include <iostream>
using namespace std;

template <typename t>
class Node {
  private:
    t item;
    Node<t>* nextPtr;
  public:
    Node(t argItem, Node<t>* argNext);
    Node(t argItem);
    //getters and setters
    t getItem();
    void setItem(t itemarg);
    Node* getNextPtr();
    void setNextPtr(Node<t>* nextPoint);

    //debugging
    void print();
};

//Constructors
template <typename t>
Node<t>::Node(t argItem, Node<t>* argNext)
{
    item = argItem;
    nextPtr = argNext;
}
template <typename t>
Node<t>::Node(t argItem){
  item = argItem;
  nextPtr = NULL;
}
/****************************************************************
/*   FUNCTION NAME:getItem
/*  Description: Returns the current item
/*
/*   PARAMETERS: N/A
/*
/*   RETURN VALUES: item of type t
/*
/****************************************************************/
template <typename t>
t Node<t>::getItem()
{
    return this->item;
}
/****************************************************************
/*   FUNCTION NAME: setItem
/*  Description: sets of item of type t
/*
/*   PARAMETERS: itemarg of type t
/*
/*   RETURN VALUES: N/A
/*
/****************************************************************/
template <typename t>
void Node<t>::setItem(t itemarg)
{
  this->item = itemarg;
}
/****************************************************************
/*   FUNCTION NAME:getNextPtr
/*  Description: returns the next pointer
/*
/*   PARAMETERS: N/A
/*
/*   RETURN VALUES: pointer of type Node<t>
/*
/****************************************************************/
template <typename t>
Node<t>* Node<t>::getNextPtr()
{
  //cout << "Made it to getnextptr()" << endl;
  return this->nextPtr;
}
/****************************************************************
/*   FUNCTION NAME: setNextPtr
/*  Description: sets pointer based on input
/*
/*   PARAMETERS: pointer node of type nextPoint
/*
/*   RETURN VALUES: N/A
/*
/****************************************************************/
template <typename t>
void Node<t>::setNextPtr(Node<t>* nextPoint)
{
  this->nextPtr = nextPoint;
}
/****************************************************************
/*   FUNCTION NAME: print()
/*  Description: prints out the node
/*
/*   PARAMETERS: N/A
/*
/*   RETURN VALUES: N/A -- just prints out everything -- kinda recursive
/*
/****************************************************************/
template <typename t>
void Node<t>::print()
{
  cout << this->getItem().toString() << endl;
  if(getNextPtr() != NULL)
    getNextPtr()->print();
}

#endif
