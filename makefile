CC = g++
CPPFLAGS = -g -I.
main: main.o LookupTable.o
main.o: main.cpp LookupTable.h List.h Item.h
LookupTable.o: LookupTable.cpp LookupTable.h List.h Item.h
clean:
	rm *.o *~
	rm main
