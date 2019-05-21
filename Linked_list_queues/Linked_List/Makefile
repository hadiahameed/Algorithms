
prob1: problem1.o LinkedList.o
	g++ -Wall -std=c++11 problem1.o LinkedList.o -o prob1

problem1.o: problem1.cpp
	g++ -c -std=c++11 problem1.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c -std=c++11 LinkedList.cpp

clean:
	rm *.o prob1