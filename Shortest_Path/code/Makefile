
hw7: main.o graph.o random_generator.o 
	g++ -Wall -std=c++11 main.o graph.o random_generator.o -o hw7

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

graph.o: graph.cpp graph.h
	g++ -c -std=c++11 graph.cpp

random_generator.o: random_generator.cpp random_generator.h
	g++ -c -std=c++11 random_generator.cpp

clean:
	rm *.o hw7