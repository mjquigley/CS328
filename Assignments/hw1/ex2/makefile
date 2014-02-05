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
## Filename   :  makefile2.txt
##
###############################################################################

###############################################################################
## This makefile will build the second example
###############################################################################

CXX = g++
FLAGS = -W -Wall -s -pedantic-errors
OBJECTS = driver.o scanner.o signal.o tokenlist.o token.o parser.o

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
driver.o: driver.cpp signal.h parser.h tokenlist.h token.h enTokens.h \
    Amatrix.h Avector.h scanner.h enChar.h
scanner.o: scanner.cpp scanner.h enChar.h tokenlist.h token.h enTokens.h \
    signal.h
signal.o: signal.cpp signal.h
tokenlist.o: tokenlist.cpp tokenlist.h token.h enTokens.h signal.h
token.o: token.cpp token.h enTokens.h
parser.o: parser.cpp parser.h tokenlist.h token.h enTokens.h Amatrix.h \
    Avector.h signal.h
