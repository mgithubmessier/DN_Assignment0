CC = g++
CPPFLAGS = -g -I.
main: main.o LookupTable.o List.o Node.o
main.o: main.cpp LookupTable.h List.h Node.h Item.h
Node.o: Node.cpp Node.h Item.h
List.o: List.cpp List.h Node.h Item.h
LookupTable.o: LookupTable.cpp LookupTable.h List.h Node.h Item.h
clean:
	rm *.o *~
	rm main
