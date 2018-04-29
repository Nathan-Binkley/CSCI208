#ifndef stack_h
#define stack_h

#include "node.h"
#include <iostream>
using namespace std;

const int stackIsEmpty = 99;

template<typename t>
class stack{
  protected:
    Node<t>* TOSptr;
  public:

    stack(); // Constructor
    ~stack(); // Destructor
    bool isEmpty();
    void push(t arg);
    t pop();
    t peek();

    //debugging
    void print();
};

template <typename t>
stack<t>::stack()
{
    TOSptr = NULL;
}
/****************************************************************
/*   FUNCTION NAME:isEmpty
/*  Description: Checks if given stack is empty
/*
/*   PARAMETERS: N/A
/*
/*   RETURN VALUES: True or False
/*
/****************************************************************/
template <typename t>
bool stack<t>::isEmpty()
{
    //cout << "Checking if empty " << endl;
    if(TOSptr == NULL){
      return true;
    }
    return false;
}
/****************************************************************
/*   FUNCTION NAME: push
/*  Description: pushes desired input to desired stack
/*
/*   PARAMETERS: arg of type t
/*
/*   RETURN VALUES: N/A
/*
/****************************************************************/
template<typename t>
void stack<t>::push(t arg)
{
  //Create a new node
  //Should point to old TOS
  //cout << "Made it inside push" << endl; //debugging
  Node<t>* newNode = new Node<t>(arg, TOSptr);
  //cout << "Set newNode" << endl;//debugging

  //TOS points to new node
  TOSptr = newNode;
  //cout << "Set TOSptr to newNode" << endl;//debugging
  //cout << TOSptr << endl;//debugging
  //cout << "THAT's TOSptr" << endl;//debugging
}
/****************************************************************
/*   FUNCTION NAME: pop
/*  Description: returns the top of the stack, removes it, if the stack
/*                                                            is not empty
/*
/*   PARAMETERS: N/A
/*
/*   RETURN VALUES: object of type t
/*
/****************************************************************/
template <typename t>
t stack<t>::pop()
{
  //cout << "Made it inside pop" << endl;
  //printd();
  if(this->isEmpty())
  {
    cout << "Stack is empty" << endl;
    throw stackIsEmpty;
  }

  //remove top node from stack
  //cout << "Node removal attempt"<< endl;//debugging
  Node<t>* popNodePtr = TOSptr;
  //cout << "Node Removal half succ" << endl;//debugging
  //cout << TOSptr << endl;//is null//debugging
  TOSptr = TOSptr->getNextPtr();
  //cout << "Node removal full succ" << endl;//debugging

  // save info to return
  t returnItem = popNodePtr->getItem();
  //cout << "Save info to return " <<endl;//debugging

  //delete old node
  delete popNodePtr;
  //cout << "Deleted old ptr" <<endl;//debugging
  popNodePtr = NULL;
  //cout << "Set ptr to null" << endl; //debugging

  return returnItem;
}
/****************************************************************
/*   FUNCTION NAME: print
/*  Description: useful for debugging purposes of printing out entire stacks
/*
/*   PARAMETERS: N/A
/*
/*   RETURN VALUES: top of stack pointer but not returned, just calls it to the node's print funcion
/*
/****************************************************************/
template<typename t>
void stack<t>::print()
{
    if(!isEmpty())
    {
      TOSptr->print();
    }
}
/****************************************************************
/*   FUNCTION NAME: ~stack
/*  Description: deconstructor for any stack. ever.
/*
/*   PARAMETERS: N/A
/*
/*   RETURN VALUES: N/A
/*
/****************************************************************/
template<typename t>
stack<t>::~stack()
{
  while(!this->isEmpty())
  {
    pop();
  }
}
#endif
