
graph: main.o graph.o
	g++ -Wall -std=c++11 main.o graph.o -o graph

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

graph.o: graph.cpp
	g++ -c -std=c++11 graph.cpp

clean:
	rm *.o graph
