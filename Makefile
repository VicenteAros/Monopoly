run: output
	./main.out
	
output: main.o jueguito.o
	gcc -o main.out main.o jueguito.o -g
	
main.o: main.c
	gcc -Wall -c main.c
	
jueguito.o: jueguito.c jueguito.h
	gcc -Wall -c jueguito.c

clean:
	rm *.o *.out
