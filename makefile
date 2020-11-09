all: main.o songs.o symbols.o
	gcc -o myTunes main.o songs.o symbols.o

main.o: main.c songs.h symbols.h
	gcc -c main.c

songs.o: songs.c
	gcc -c songs.c

symbols.o: symbols.c
	gcc -c symbols.c

run:
	./myTunes

clean:
	rm *.o
