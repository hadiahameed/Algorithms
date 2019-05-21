CC=gcc
CXX=c++
CFLAGS=-ggdb -O2 -I. 
LDFLAGS=-L. -lcs590

OBJ=timer.o random_generator.o sort.o


cs590:	libcs590.a main.o
	$(CXX) $(CFLAGS) main.o -o hw1 $(LDFLAGS)

libcs590.a:	$(OBJ)
	ar ru libcs590.a $(OBJ)
	ranlib libcs590.a

.cc.o:
	$(CXX) -c $(CFLAGS) $<


clean:
	@rm -f *.o
	@rm -f libcs590.a
	@rm -f hw1

