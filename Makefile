CC=g++

DEBUG=-g

TARGET=bstSearch

CFLAGS= -c -Wall $(DEBUG)


all: $(TARGET)

$(TARGET): driver.o binary_search.o
	   $(CC) driver.o binary_search.o -o $(TARGET)

driver.o: driver.cpp binary_search.h
	$(CC) $(CFLAGS) driver.cpp

binary_search.o: binary_search.cpp binary_search.h
	$(CC) $(CFLAGS) binary_search.cpp

clean:
	rm *.o $(TARGET)
	rm *~
