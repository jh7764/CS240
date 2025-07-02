CC = gcc
CFLAGS = -Wall
RM = rm -f

default: all

all: q1 q2 q3

q1: q1.c 
	$(CC) $(CFLAGS) -o q1 q1.c 

q2: q2.c
	$(CC) $(CFLAGS) -o q2 q2.c 

q3: q3.c 
	$(CC) $(CFLAGS) -o q3 q3.c -lm

clean:
	$(RM) q1 q2 q3
