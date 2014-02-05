##############################################################################
## -->Makefile<--
###############################################################################

###############################################################################
##
## Instructor :  Clayton Price
## Class      :  CS328 Spring 2014
## Assignment :  Assignment 1
## Programmer :  Matthew Quigley	|	UserID:  mjqpq8
## Date       :  Jan 26, 2014
## Filename   :  makefile1.txt
##
###############################################################################

###############################################################################
## This makefile will build the first example
###############################################################################

all: brewMain.cpp wine.h additives.o beer.o wine.hpp 
	g++ brewMain.cpp additives.o beer.o -o driver

beer.o: beer.cpp beer.h yeast.h hops.h grains.h
	g++ -c beer.cpp -o beer.o

additives.o: additives.cpp additives.h
	g++ -c additives.cpp -o additives.o

clean:
	-@ rm -f core > /dev/null 2>&1
	-@ rm -f driver > /dev/null 2>&1
	-@ rm -f *.o > /dev/null 2>&1