final: main.o stos.o
	$(CC) -pedantic -Wall main.o stos.o -o final
main.o: main.c stos.h
	$(CC) -c -pedantic -Wall main.c
stos.o: stos.c stos.h
	$(CC) -c -pedantic -Wall stos.c
clean:
	rm *.o final