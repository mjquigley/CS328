##############################################################################
## -->Makefile<--
###############################################################################

###############################################################################
##
## Instructor :  Clayton Price
## Class      :  CS328 Spring 2014
## Assignment :  Assignment 2
## Programmer :  Matthew Quigley	|	UserID:  mjqpq8
## Date       :  Feb 4, 2014
## Filename   :  makefile
##
###############################################################################

###############################################################################
## This makefile will build the driver for assignment 2
###############################################################################

CXX = g++
FLAGS = -W -Wall -pedantic-errors
OBJECTS = driver.o polarCoord.o

.SUFFIXES: .cpp

.cpp.o : $<
	${CXX} -c ${FLAGS} $< -o $@

all: driver
driver: ${OBJECTS}
	${CXX} ${FLAGS} ${OBJECTS} -o $@

clean:
	-@ rm -f core > /dev/null 2>&1
	-@ rm -f driver > /dev/null 2>&1
	-@ rm -f ${OBJECTS} > /dev/null 2>&1


#Dependency lists for OBJECTS
driver.o: driver.cpp norm.h polarCoord.o
polarCoord.o: polarCoord.cpp polarCoord.hpp
