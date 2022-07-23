# CP386 Assignment 4
## Features
This repository demonstrates the use of 3 algorithms; First Fit Algorithm, Best Fit Algorith, and Worst Fit Algorithm.
## Makefile
Below is the code in the makefile"
```
CC = gcc
CFLAGS = -std=gnu99
TARGET = allocation  
OBJFILES = allocation.o
all: $(TARGET)

allocation: allocation.c
	$(CC) $(CFLAGS) -o allocation allocation.c
	
run: allocation
	./allocation 1048576
clean:
	rm -f $(OBJFILES) $(TARGET) *~
```
Makefile is used for the students to test their code with a test case of 1048576

## About Developers
- [Zeel Patel](https://github.com/zeelp741)
- [Thenura Jayasinghe](https://github.com/Thenura)