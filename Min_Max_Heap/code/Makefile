
hw3: main.o minHeap.o maxHeap.o random_generator.o medianHeaps.o
	g++ -Wall -std=c++11 main.o minHeap.o maxHeap.o random_generator.o medianHeaps.o -o hw3

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

minHeap.o: minHeap.cpp minHeap.h
	g++ -c -std=c++11 minHeap.cpp

maxHeap.o: maxHeap.cpp maxHeap.h
	g++ -c -std=c++11 maxHeap.cpp

medianHeaps.o: medianHeaps.cpp medianHeaps.h
	g++ -c -std=c++11 medianHeaps.cpp

random_generator.o: random_generator.cpp random_generator.h
	g++ -c -std=c++11 random_generator.cpp

clean:
	rm *.o hw3