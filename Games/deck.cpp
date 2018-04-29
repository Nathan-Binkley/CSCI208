
#include "card.h"
#include "stack.h"
#include "deck.h"
#include <cstdlib>
#include <time.h>
using namespace std;


Deck::Deck() {
  srand(time(0));
  top = -1;
  // amount of cards -1 for index
  //build the deck
  //cout << "Constructor for deck" << endl;
  Card tempCard;
  for(int i = 1; i <=13; i++){
    tempCard = Card(i,Clubs);
    push(tempCard);
  }
  //cout << "Top is " << top << endl;
  for(int i = 1; i <=13; i++){
    tempCard = Card(i,Diamonds);
    push(tempCard);
  }
  //cout << "Top is " << top << endl;
  for(int i = 1; i <=13; i++){
    tempCard = Card(i,Hearts);
    push(tempCard);
  }
//  cout << "Top is " << top << endl;
  for(int i = 1; i <=13; i++){
    tempCard = Card(i,Spades);
    push(tempCard);
  }
  //cout << "End Deck constructor" << endl;
  //cout << TOSptr << endl;
//  cout << "Top is " << top << endl;
}

/****************************************************************
/*   FUNCTION NAME: Deal
/*  Description: "Deals" the cards
/*
/*   PARAMETERS: N/A
/*
/*   RETURN VALUES: Returns card delt
/*
/****************************************************************/
Card Deck::deal() { //deals cards
  shuffle();
  return pop(); // executes pop() and returns result of pop()
}

/****************************************************************
/*   FUNCTION NAME: Shuffle
/*  Description: Shuffles Deck
/*
/*   PARAMETERS: N/A
/*
/*   RETURN VALUES: N/A
/*
/****************************************************************/

void Deck::shuffle(){
  // get random number between 1 & 8
  int r = (rand() % 8) + 1;
  //cout << "Help 1" << endl;//debugging
  // Build stack A, size 22 + rand #
  stack <Card> pileA;

  //cout << "Help 2" << endl;//debugging
  for (int i = 0; i < 22 + r; i++)
  {
    //cout << "trying " << i << endl;//debugging
    pileA.push(this->pop());
    //cout << "gone through " << i << endl;//debugging
  }
  //cout << "Help 3" << endl;//debugging
  //build stack B, size 22 + (8-rand)
  stack <Card> pileB;
  //cout << "Help 4" << endl;//debugging
  while (this->isEmpty()==false)
  {
    pileB.push(this->pop());
  }
  //cout << "Help 5" << endl;//debugging
  // Merge stacks
  // pop from pile A
  for(int i = 0; i < 52; i++)
  {
    if(!pileA.isEmpty())
    {
      //cout << "Help 6" << endl;//debugging
    Card tempA = pileA.pop();
    this->push(tempA);
    //cout << "Help 7" << endl;//debugging
    }
    // pop from pileB
    if(!pileB.isEmpty())
    {
    Card tempB = pileB.pop();
    //cout << "Help 8" << endl;//debugging
    this->push(tempB);
    //cout << "Help 9" << endl;//debugging
    }
  }
  //cout << "Help 10" << endl; //debugging
}

/****************************************************************
/*   FUNCTION NAME: isEmpty
/*  Description: Returns true if empty, false otherwise
/*
/*   PARAMETERS: N/A
/*
/*   RETURN VALUES: bool
/*
/****************************************************************
bool Deck::isEmpty(){
  if(top == -1){
    //cout << "Top is " << top << endl;
    return true;
  }
  return false;
}

/****************************************************************
/*   FUNCTION NAME: push
/*  Description: puts selected card in deck
/*
/*   PARAMETERS:a new card
/*
/*   RETURN VALUES: N/A
/*
/****************************************************************
void Deck::push(Card newEntry){

  cout << "Top is " << top << " Push"<< endl;
  cout << "Capactiy is " << capacity << endl;
  if(top == 52){
    cout << "Top is " << top << " Push"<< endl;
    cout << "Capactiy is " << capacity << endl;
    throw DeckIsFull;
  }
//  cout << "Top is " << top << " Push"<< endl;
  cardArray[top] = newEntry;
  cout << cardArray[top].toString() << endl;
  top++;
//  cout << "Top is " << top << " Push" << endl;
}

/****************************************************************
/*   FUNCTION NAME: pop
/*  Description: puts card at top of deck in hands of people
/*
/*   PARAMETERS: N/A
/*
/*   RETURN VALUES: card in cardTemp
/*
/****************************************************************

Card Deck::pop(){ // removes top card
  if(top == capacity){
//    cout << "Top is " << top << endl;
    throw DeckIsFull;
  }
  Card cardTemp = cardArray[top];
  top--;
  return cardTemp;

}

/****************************************************************
/*   FUNCTION NAME: peek
/*  Description: looks at top card without using it
/*
/*   PARAMETERS: N/A
/*
/*   RETURN VALUES: returns card value at top of deck
/*
/****************************************************************

Card Deck::peek(){ // does exact same thing as pop without removing the card
  if(Deck::isEmpty()){
    throw DeckIsEmpty;
  }
  Card cardTemp = cardArray[top];
  return cardTemp;

}
*/
