run: output
	./main.out
	
output: main.o
	gcc -o main.out main.o -g
	
main.o: main.c
	gcc -Wall -c main.c

clean:
	rm *.o *.out
