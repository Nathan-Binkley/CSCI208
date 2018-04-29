# Makefile for Separate Compilation Example

# *****************************************************
# Parameters to control Makefile operation

CXX = g++

# flag -g set for debugging

CXXFLAGS = -Wall -g

# ****************************************************
# Entries to bring the executable up to date

main: main.o Point23.o 
	$(CXX) $(CXXFLAGS) -o main main.o Point23.o 

main.o: Point23.h 

Point23.o: Point23.h




