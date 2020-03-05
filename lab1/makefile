CC=gcc
CFLAGS=-I.
DEPS = functionsLab1.h
OBJ = functionsLab1.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

functionsLab1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
