#include "card.h"
#include <iostream>
#include <string>
using namespace std;

//constructors
Card::Card(){ // default
  Suit mySuit = (Suit)0; // Clubs
  myRank = 0; // Joker
}
Card::Card(int rank, Suit theSuit){
  myRank = rank;
  mySuit = theSuit;
}
//Functions
/****************************************************************
/*   FUNCTION NAME: setSuit
/*  Description: sets the suit to the passed through variable
/*
/*   PARAMETERS: s of type Suit
/*
/*   RETURN VALUES: N/A because void
/*
/****************************************************************/
void Card::setSuit(Suit s){
  mySuit = s;
}
/****************************************************************
/*   FUNCTION NAME: setRank
/*  Description: sets rank to the number assigned
/*
/*   PARAMETERS: num of type int
/*
/*   RETURN VALUES: N/A because void
/*
/****************************************************************/
void Card::setRank(int num){
  myRank = num;
}
/****************************************************************
/*   FUNCTION NAME: getRank
/*  Description:Returns the rank of the card
/*
/*   PARAMETERS: N/A
/*
/*   RETURN VALUES: myRank
/*
/****************************************************************/
int Card::getRank(){
  return myRank;
}

/****************************************************************
/*   FUNCTION NAME: getSuit
/*  Description: Returns the suit of the current card
/*
/*   PARAMETERS: N/A
/*
/*   RETURN VALUES: mySuit
/*
/****************************************************************/
Suit Card::getSuit(){
  return mySuit;
}
/****************************************************************
/*   FUNCTION NAME: toString
/*  Description: Puts everything in a string for a card
/*
/*   PARAMETERS: None
/*
/*   RETURN VALUES:returns string values of Rank and Suit in word format
/*
/****************************************************************/
string Card::toString(){
  if(myRank == 0){
    return "Joker";
  }
  else{

    return myRankS[myRank - 1] + " of " + suitString[mySuit-1];
  }
}
