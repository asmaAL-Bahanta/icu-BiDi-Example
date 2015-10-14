CC=g++



INC=-I/usr/include/x86_64-linux-gnu/ 

all: bidiExample

bidiExample: bidiExample.cpp
	$(CC) $< $(INC) -o $@  -L/home/asma/Qt/5.5/gcc_64/lib `pkg-config --libs --cflags icu-uc icu-io` -std=c++11
