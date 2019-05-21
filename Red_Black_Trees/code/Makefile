
hw4: main.o rb_tree.o bs_tree.o random_generator.o timer.o sort.o
	g++ -Wall -std=c++11 main.o rb_tree.o bs_tree.o random_generator.o timer.o sort.o -o hw4

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

rb_tree.o: rb_tree.cpp rb_tree.h
	g++ -c -std=c++11 rb_tree.cpp

bs_tree.o: bs_tree.cpp bs_tree.h
	g++ -c -std=c++11 bs_tree.cpp

timer.o: timer.cpp timer.h
	g++ -c -std=c++11 timer.cpp

random_generator.o: random_generator.cpp random_generator.h
	g++ -c -std=c++11 random_generator.cpp

sort.o: sort.cpp sort.h
	g++ -c -std=c++11 sort.cpp

clean:
	rm *.o hw4