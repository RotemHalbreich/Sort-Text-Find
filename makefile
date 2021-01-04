CC = gcc 
FLAGS = -Wall -g

all: isort txtfind

# Make isort
isort: main.o isort.o
	$(CC) $(FLAGS) -o isort main.o isort.o
	
main.o: main.c isort.h
	$(CC) $(FLAGS) -c main.c

isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c
	

# Make txtfind
txtfind: txtmain.o txtfind.o
	$(CC) $(FLAGS) -o txtfind txtmain.o txtfind.o

txtmain.o: txtmain.c txtfind.h
	$(CC) $(FLAGS) -c txtmain.c

txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c


.PHONY: clean all

clean:
	rm -f *.o isort txtfind