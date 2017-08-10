run: main.o
	gcc main.o -o run
main.o: sort.c
	gcc -c sort.c -o main.o

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf run
