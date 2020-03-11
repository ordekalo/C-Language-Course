CC=gcc
CFLAGS=-I.
DEPS = functionsLab2.h exe.h arrays.h
OBJ = functionsLab2.o exe.o arrays.o prog.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

functionsLab2: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
