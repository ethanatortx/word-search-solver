CC=g++
CFLAGS=-I.. -std=gnu++14 
SRCS=wordSearch.h charTable.h error.h process.h wordSearch.cpp charTable.cpp process.cpp main.cpp

main.o: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o main.o

clean:
	del "main.o"