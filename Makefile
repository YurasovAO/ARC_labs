CC=gcc
CFLAGS= -c -Wall
INCLUDE="./include/ ./src/"
.PHONY: clean
.PHONY: main

main:main.o BigNumber.o
	gcc -o main main.o BigNumber.o -lstdc++ -lm
main.o:
	$(CC) -c ./src/main.cpp 

BigNumber.o:
	$(CC) -c ./src/BigNumber.cpp 
clean:
	rm -rf *.o main
