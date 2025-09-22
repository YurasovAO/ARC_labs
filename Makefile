CC=gcc
CFLAGS= -c -Wall
INCLUDE="./include/ ./src/"
.PHONY: clean
.PHONY: main

main:main.o BigNumber.o service_functions.o arifmetic_functions.o
	gcc -o main main.o BigNumber.o service_functions.o arifmetic_functions.o -lstdc++ -lm
main.o:
	$(CC) -c ./src/main.cpp 

BigNumber.o:
	$(CC) -c ./src/BigNumber.cpp 

service_functions.o:
	$(CC) -c ./src/service_functions.cpp

arifmetic_functions.o:
	$(CC) -c ./src/arifmetic_functions.cpp

clean:
	rm -rf *.o main
