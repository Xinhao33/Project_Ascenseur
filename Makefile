main.o : main.c elevator.c person.c
	gcc -c main.c elevator.c person.c



main : main.o elevator.o person.o
	gcc -g -o main main.o elevator.o person.o -lncurses
	gdb main
	
run : main
	./main

clean:
	rm -f main *.o