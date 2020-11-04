all: main.o songs.o
	gcc -o main main.o songs.o

songs.o: songs.c songs.h
	gcc -c songs.c 
	
main.o: main.c songs.h
	gcc -c main.c 

run: main
	./main