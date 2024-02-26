CC = gcc
CFLAGS=-g

main.o: main.c prediction.h
	gcc -c main.c `pkg-config --cflags --libs gtk+-3.0` 

prediction.o: prediction.c prediction.h tabhash.h
	gcc -c prediction.c

tabhash.o: tabhash.c tabhash.h
	gcc -c tabhash.c

mon_exe: tabhash.o prediction.o main.o
	gcc tabhash.o prediction.o main.o -o mon_exe `pkg-config --cflags --libs gtk+-3.0`