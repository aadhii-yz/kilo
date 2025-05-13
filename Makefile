CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99

kilo: main.c
	$(CC) main.c -o kilo $(CFLAGS)

run: kilo
	./kilo

clean:
	rm kilo
