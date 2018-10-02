CC = g++
DEBUG = -g -Wall -O0 -pedantic-errors
CFLAGS=-std=c++14
LFLAGS=-std=c++14
COMPILE=$(CC) $(DEBUG) $(CFLAGS) -c
LINK=$(CC) $(DEBUG) $(LFLAGS)
RM=rm -f

all: BankSimulation 

BankSimulation: BankSimulation.o QueType.o PriorityQueue.o
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -o BankSimulation BankSimulation.o QueType.o PriorityQueue.o
BankSimulation.o: BankSimulation.cpp PriorityQueue.h QueType.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c BankSimulation.cpp
PriorityQueue.o: PriorityQueue.cpp PriorityQueue.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c PriorityQueue.cpp
QueType.o: QueType.cpp QueType.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c QueType.cpp
clean:
	rm -rf BankSimulator
	rm -rf *.o
