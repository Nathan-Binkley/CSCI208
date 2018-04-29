#ifndef DECK_H
#define DECK_H

#include "card.h"
#include "node.h"
#include "stack.h"
#include <ctime>
#include <cmath>
#include <cstdlib>


const int DeckIsEmpty = 1042;
const char DeckIsFull = 'F';

class Deck: public stack<Card> {
private:
  const int capacity = 52;
  int top;
  Card cardArray[52];

public:
  Deck();
  Card deal();
  void shuffle();
  //bool isEmpty();
  //void push(Card);
  //Card pop();
  //Card peek();
  //string toString(); // move all these
};
#endif
