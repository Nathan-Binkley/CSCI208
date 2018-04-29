
// list.h

#ifndef list_H
#define list_H

#include <cstdlib>
#include <iostream>

#include "node.h"

using namespace std;
  // EXCEPTIONS THROWN
	static const int ItemNotFound = 8001;
	static const int  IndexOutOfBoundsException = 8002;
	static const int ListIsEmpty = 8003;
/******************************************************************
 Class list
 This class defines a data structure for a linked list of integers
*******************************************************************/
template <typename t>
class list
{
  private:
   Node<t>* headNodePtr;

  public:

 // METHODS
   list ();
   ~list();
   bool isEmpty();
   void clear();
   int size();
   void printList();

 /* INSERTION
    A new node is created and inserted in the linked list.
	There are four cases considered while inserting a node:
		Insertion at the start
		Insertion at the end
		Insertion at a particular position
		Insertion in order
 */
   void push_front(t);
   void push_back(t);
   void insert(int position, t value);
   void insert(t);


 /* DELETION
	There are also four cases in which a node can be deleted:
		Deletion at the start
		Deletion at the end
		Deletion at a particular position
		Deletion of a particular value
*/
   t pop_front();
   t pop_back();
   t removeAtPos (int );
   void remove (t);

	 friend ostream& operator<<(ostream& os, const Card& card);
};

// ostream& operator<<(ostream& os, const Card& card)
// {
// 	os << card.myRank << " of " << card.mySuit;
// 	return os;
// }


/*=====================================================================
/*     IMPLEMENTATION OF METHOD/FUNCTIONS
/*=====================================================================

/******************************************************************
 Class list
 Function:  Constructor
     Create am empty linked list
	 This is indicated by a null pointer in the start of list (headNodePtr)
 *******************************************************************/
template<typename t>
list<t>::list()
{
	//REPLACE THE LINE BELOW WITH YOUR OWN CODE
  headNodePtr = NULL;
   //cout << "You must implement this function" <<endl;
}
/******************************************************************
 Class list
 Function:  Destructor
     Remove nodes from the list and delete then from memory.
 *******************************************************************/
template<typename t>
list<t>::~list()
{
	//REPLACE THE LINE BELOW WITH YOUR OWN CODE
  while(!isEmpty())
    clear();
  // cout << "You must implement this function" <<endl;
}

/******************************************************************
 Class list
 Function:  size
 Parameters: None
  Returns an integer count of the number of items in the list
*******************************************************************/
template<typename t>
int list<t>::size()
{
    if(isEmpty())
    {
      return 0;
    }
    int number = 0;
   //REPLACE THE LINE BELOW WITH YOUR OWN CODE
   Node<t>* next = NULL;
   Node<t>* current;
   current = headNodePtr;

    while(current->getNextPtr() != NULL)
      {
        current = current->getNextPtr();
        number += 1;
      }
    return number + 1;
   //cout << "You must implement this function" <<endl;
}

/******************************************************************
 Class list
 Function:  printList
    Walks through the list printing the value of each node


 Parameters:  None
 Result:  List of item values is sent to the standard output device
 Return: Void
 Exception: ListIsEmpty is thrown if an empty list is encountered.
*******************************************************************/
template<typename t>
void list<t>::printList ()
{
    if(isEmpty())
    {
      cout << "List is empty" << endl;
      return;
    }
   Node<t>* current;
   current = headNodePtr;
   //REPLACE THE LINE BELOW WITH YOUR OWN CODE
   // Print each item on a new line
   //cout << "You must implement this function" <<endl;
   while(current != NULL)
   {
      cout << current->getItem().toString() << endl;
      current = current->getNextPtr();
   }
}



 /******************************************************************
 Class list
 Function:  clear
 Parameters: None
  Removes and deletes all the entries of the list
   Function:  isEmpty
  Returns void
*******************************************************************/
template<typename t>
void list<t>::clear()
{
   //REPLACE THE LINE BELOW WITH YOUR OWN CODE
   // Print each item on a new line
   // cout << "You must implement this function" <<endl;
   Node<t>* current = headNodePtr;
	 int n = 0;
	 int siz = size();
	 for(int i = 0; i < siz; i++)
   {
		 current = current->getNextPtr();
     pop_front();
		 //cout << "que " << n << endl; // debugging

		 n++;
   }
}


 /******************************************************************
 Class list
 Function:  isEmpty
 Parameters: None
  Returns a bool that indicates if the linked list is or is not empty
*******************************************************************/
template<typename t>
bool list<t>::isEmpty()
{
   //REPLACE THE LINE BELOW WITH YOUR OWN CODE
   // Print each item on a new line
   //cout << "You must implement this function" <<endl;
  if(headNodePtr == NULL)
    return true;

  return false;
}


//   _----------------  INSERTIONS  --------------------//
/******************************************************************
 Class list
 Function:  push_front
     Inserts a new item at the front of the list
	 This routing will create a Node object to contain the item to add
 Parameters: item to add to the list
 Return: void
*******************************************************************/
template<typename t>
void list<t>::push_front(t item)
{
   Node<t>* newNode = new Node<t>(item, headNodePtr);
   //Look at me
   //Look at me
   headNodePtr = newNode; // I am the new node now.
}

/******************************************************************
 Class list
 Function:  push_back
     Inserts a new item at the end of the list
	 This routing will create a Node object to contain the item to add
 Parameters: item to add to the list
 Return: void
*******************************************************************/
template<typename t>
void list<t>::push_back (t item)
{
   //REPLACE THE LINE BELOW WITH YOUR OWN CODE
   //cout << "You must implement this function" <<endl;
   //create new node
   Node<t>* temp = new Node<t>(item);
   //if empty add to head & exit
   if(isEmpty()){
     headNodePtr=temp;
     return;
   }
   //go to end of list & add node
   if(headNodePtr->getNextPtr() == NULL)
   {
     headNodePtr->setNextPtr(temp);
   }
   else
   {
     Node<t>* loopPtr = headNodePtr;
     while(loopPtr!=NULL)
     {
       loopPtr = loopPtr->getNextPtr();
     }
     loopPtr->setNextPtr(temp);
   }
}


/******************************************************************
 Class list
 Function:  insert
    Insert an item in the list at the position specified in the parameter.

	Note: be sure to explicitly hand the situation when the new node
	is added to the front of the list

 Parameters:  Position in the container where the new elements are inserted.
              Item to add.

 Return: Void
 Exception thrown:  IndexOutOfBoundsException
 *******************************************************************/
template<typename t>
void list<t>::insert(int position, t item)
{
	 if(isEmpty())
	 {
		 cout << "List is empty" << endl;
		 return;
	 }
	 if(position > size())
	 {
		 cout << "Size is smaller than position" << endl;
		 return;
	 }
   if(headNodePtr == NULL)
   {
     push_front(item);
   }
   if(position == this->size())
   {
     this->push_back(item);
   }
   //REPLACE THE LINE BELOW WITH YOUR OWN CODE
   Node<t>* addPtr = new Node<t>(item);
   if(position == 0)
   {
      addPtr->setNextPtr(headNodePtr);
      headNodePtr = addPtr;
   }
   Node<t>* loopPtr = headNodePtr;
   Node<t>* previous = loopPtr;

   int counter = 0;

   while (counter != position)
   {
     previous = loopPtr;
     loopPtr = loopPtr->getNextPtr();
     counter++;
   }
   previous->setNextPtr(addPtr);
   addPtr->setNextPtr(loopPtr);

   //cout << "You must implement this function" << endl;
}

/******************************************************************
 Class list
 Function:  insert
    Insert an item in the list IN ORDER. That is, it is inserted after all
	integers that are smaller than it and before integers that are larger than it

	Note: be sure to explicitly hand the situation when the new node
	is added to the front of the list

 Parameters: item to add.

 Return: Void
 *******************************************************************/
template<typename t>
void list<t>::insert(t item)
   {
   //REPLACE THE LINE BELOW WITH YOUR OWN CODE

   Node<int>* previous = NULL;
   Node<int>* current = headNodePtr;
   while(current->getNextPtr() != NULL)
   {
     previous = current;
     current = current->getNextPtr();
   }
   Node<int>* newNode = new Node<int>(item, current);
   previous->setNextPtr(newNode);

   //cout << "You must implement this function" <<endl;
}



//   -----------------  DELETIONS  --------------------//
/******************************************************************
 Class list
 Function:  pop_front
     Deletes anitem from the front of the list
	 This routing will return the value of the node at the top of the list
	 Removes that node from the list
 Parameters: none
 Return: value of the first node
 Exception Returned: ListIsEmpty if list is empty
*******************************************************************/
template<typename t>
t list<t>::pop_front()
{
 	//REPLACE THE LINE BELOW WITH YOUR OWN CODE
  //cout << "You must implement this function" <<endl;
  if(this->isEmpty())
  {
    cout << "Stack is empty" << endl;
    throw ListIsEmpty;
  }

  //remove top node from stack
  //cout << "Node removal attempt"<< endl;//debugging
  Node<t>* popNodePtr = headNodePtr;
  //cout << "Node Removal half succ" << endl;//debugging
  //cout << TOSptr << endl;//is null//debugging
  headNodePtr = headNodePtr->getNextPtr();
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

/******************************************************************
 Class list
 Function:  pop_back;
     Deletes an item from the back of the list
	 This routing will return the value of the node at the end of the list
	 Removes that node from the list
 Parameters: None
 Return: value of the last node
  Exception Returned: ListIsEmpty if list is empty
*******************************************************************/
template<typename t>
t list<t>::pop_back()
{
 	//REPLACE THE LINE BELOW WITH YOUR OWN CODE
  //cout << "You must implement this function" <<endl;
  Node<t>* temp;
  //if empty add to head & exit
  if(isEmpty()){
		cout << "List is Empty" << endl;
  	return 0;
  }
	if(size() == 1)
	{
		pop_front();
	}
  Node<t>* loopPtr = headNodePtr;
  Node<t>* nPtr = NULL;
	t element;
  //go to end of list & add node
  if(headNodePtr->getNextPtr() == NULL)
  {
    headNodePtr->setNextPtr(loopPtr);
  }


  while(loopPtr->getNextPtr() != NULL)
  {
    nPtr = loopPtr;
    loopPtr = loopPtr->getNextPtr();

  }
  element = loopPtr->getItem();
	delete loopPtr;
	loopPtr = NULL;
	nPtr->setNextPtr(NULL);

  return element;
}
/******************************************************************
 Class list
 Function:  remove
    Remove an item from the list

	Note: be sure to handle the situation when this is the last node
	  in the list

 Parameters: item to remove.

 Return: N/A

 Exceptions thrown:  ListIsEmpty
 *******************************************************************/
template<typename t>
void list<t>::remove(t item)
   {
   //REPLACE THE LINE BELOW WITH YOUR OWN CODE

   //cout << "You must implement this function" <<endl;
   Node<t>* temp = new Node<t>(item);
   //if empty add to head & exit
   if(isEmpty()){
     headNodePtr=temp;
     return;
   }
   //go to end of list & add node
   if(headNodePtr->getNextPtr() == NULL)
   {
     headNodePtr->setNextPtr(temp);
   }
	 else
	 {
     Node<t>* loopPtr = headNodePtr;
     Node<t>* nPtr = NULL;
     while(loopPtr->getNextPtr() != NULL)
     {
       nPtr = loopPtr;
       loopPtr = loopPtr->getNextPtr();

			 if(nPtr == headNodePtr && nPtr->getItem() == item) {
				 pop_front();
			 }

			 else if(nPtr->getItem() == item)
       {
				 temp->setNextPtr(loopPtr);
         delete nPtr;
				 nPtr = NULL;
			 }

			 else {
				 temp = nPtr;
			 }
     }
	 }
     //loopPtr->setNextPtr(temp);
}



/******************************************************************
 Class list
 Function:  RemoveAtPos
    Walks through the list looking for a node at the position passed.
	The position starts counting at 1. That is the first node in the list
	is at position 1.
	If that node is found, it removes the node from the list
	 and returns the value.

	 If the position is not valid, signal an  exception: IndexOutOfBoundsException

 Parameters: Position in list.

 Result:  Node with item is removed from the list.
 Return: item at that position
 Exception thrown:  IndexOutOfBoundsException
*******************************************************************/
template<typename t>
t list<t>::removeAtPos (int pos)
{
   //REPLACE THE LINE BELOW WITH YOUR OWN CODE
   //cout << "You must implement this function" <<endl;
	 if(isEmpty())
	 {
		 cout << "List is empty" << endl;
		 return 0;
	 }
	 if(pos > size())
	 {
		 cout << "Size is smaller than position" << endl;
		 return 0;
	 }
   if(pos == this->size())
   {
     this->pop_back();
   }
   //REPLACE THE LINE BELOW WITH YOUR OWN CODE
   if(pos == 0)
   {
     cout << "0 is not a valid option. please try again " << endl;
		 return 0;
   }
   Node<t>* loopPtr = headNodePtr;
   Node<t>* previous = loopPtr;

   int counter = 0, num = 0;

   while (counter != pos)
   {
     previous = loopPtr;
     loopPtr = loopPtr->getNextPtr();
		 num = loopPtr->getItem();
     counter++;
   }
	 previous->setNextPtr(loopPtr->getNextPtr());
   delete loopPtr;
	 loopPtr = NULL;

	 return num;
}




#endif
