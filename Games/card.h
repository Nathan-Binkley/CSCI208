#ifndef CARD_H
#define CARD_H

/****************************************************************
/****************************************************************
/*   FILE NAME: card.h
/*
/*    AUTHOR: Nathan Binkley
/*
/*   DESCRIPTION: Basis of the main.cpp for creating a deck of cards and testing the functions within this class
/*
/****************************************************************
/****************************************************************/


#include <iostream>
#include <string>
using namespace std;

//Arrays/Variables

enum Suit{Clubs=1, Diamonds=2, Hearts=3, Spades=4};

class Card{
private:


public:
  int myRank;
  Suit mySuit;

  string suitString[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
  string myRankS[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

  //Constructors
  Card();
  Card(int rank, Suit theSuit);
  //Functions
  /****************************************************************
/*   FUNCTION NAME: Setters (setSuit and setRank)
/*  Description: sets the suit and the rank for a specified card.
/*
/*   PARAMETERS:the suit you want to work with as a value of an int (known by compiler as a suit) or the rank taken as an int.
/*
/*   RETURN VALUES: N/A
/*
/****************************************************************/
  void setSuit(Suit s);
  void setRank(int num);
  /****************************************************************
/*   FUNCTION NAME:Getter functions (getRank() and getSuit())
/*  Description:Gets the rank and/or suit from a specified card.
/*
/*   PARAMETERS:N/A. Static. Expected value of a specified card in main.cpp and in the format card.function().
/*
/*   RETURN VALUES: myRank (rank of the card) or mySuit (Suit of the card as a number)
/*
/****************************************************************/
  int getRank();
  Suit getSuit();
  /****************************************************************
/*   FUNCTION NAME: toString()
/*  Description: Non-default to string function to print every basic
/*
/*   PARAMETERS: N/A it's predefined to a specific card in main.cpp becasue it is a static type.
/*
/*   RETURN VALUES: N/A it's a type void function
/*
/****************************************************************/
  string toString();

};

#endif
