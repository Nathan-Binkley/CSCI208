# Makefile for the gameMenu program
menu: menu.o deck.o card.o marble.o
	g++ -std=c++11 -o game menu.o marble.o deck.o card.o Adventure.h

menu.o: menu.cpp
	g++ -std=c++11 -c menu.cpp

marble.o: marble.cpp
	g++ -std=c++11 -c marble.cpp

deck.o: deck.cpp
	g++ -std=c++11 -c deck.cpp

card.o: card.cpp
	g++ -std=c++11 -c card.cpp

Clean:
	rm *.o
