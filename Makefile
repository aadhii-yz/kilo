CC=gcc
CFLAGS=-Wall -Wextra

kilo: main.c
	$(CC) main.c -o kilo $(CFLAGS)

run: kilo
	./kilo

clean:
	rm kilo
