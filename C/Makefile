INCLUDE = -I D:/ROOT/include
CC = gcc -std=c99 -Wall -Wextra -g -Wno-deprecated
#CC = gcc -std=c99 -g -Wno-deprecated
CFLAGS = -c $(INCLUDES)

.c:
	$(CC) -lm -D DEBUG -o $* $<

all:

clean:
	rm -f *.o
	rm -f *.exe
