#include <iostream>
#include <cstdlib>
#include <ctime>
#include "marble.h"

Marble::Marble(){
  color = "black";
}

Marble::Marble(string newColor){
  color = newColor;
}
/****************************************************************
/*   FUNCTION NAME:setColor
/*  Description: sets the color of the marble
/*
/*   PARAMETERS: newColor of type string
/*
/*   RETURN VALUES: N/A
/*
/****************************************************************/
void Marble::setColor(string newColor){
  color = newColor;
}
/****************************************************************
/*   FUNCTION NAME: getColor
/*  Description: returns color of marble
/*
/*   PARAMETERS: N/A
/*
/*   RETURN VALUES: color of type string
/*
/****************************************************************/
string Marble::getColor(){
  return color;
}
/****************************************************************
/*   FUNCTION NAME: toString
/*  Description: returns the color of the marble in string format
/*
/*   PARAMETERS: N/A
/*
/*   RETURN VALUES: color of type string
/*
/****************************************************************/
string Marble::toString()
{
  return color;
}
