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

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)

OBJECTS = $(SOURCES:%.cpp=%.o)

all: driver

%.o: %.cpp
	${CXX} ${FLAGS} -c $< -o $@

driver: ${OBJECTS}
	${CXX} ${FLAGS} ${OBJECTS} -o $@

profile: FLAGS += -pg
profile: driver
clean:
	-@ rm -f core > /dev/null 2>&1
	-@ rm -f driver > /dev/null 2>&1
	-@ rm -f ${OBJECTS} > /dev/null 2>&1

# Automatically generate dependencies and include them in Makefile
depend: $(SOURCES) $(HEADERS)
	@echo "Generating dependencies"
	@$(CXX) -MM *.cpp > $@

-include depend

