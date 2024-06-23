.phony: clean all

CXXFLAGS = -g -O3 -Wpedantic -Wall -Wextra -Wmisleading-indentation -Wunused -Wuninitialized -Wshadow -Wconversion  -std=c++17

OBJS = library

all:  ${OBJS} 

BookT.o: BookT.h
BookList.o: BookList.h
ReaderT.o: ReaderT.h
ReaderList.o: ReaderList.h
Parser.o: Parser.h BookT.h BookList.h ReaderT.h ReaderList.h

library: Parser.o BookList.o BookT.o ReaderList.o ReaderT.o

clean:
	rm -f  ${OBJS} *.o