
all: program

program: main.o
	cc -o program main.o

main.o: src/main.c
	cc -c src/main.c

clean:
	rm program
