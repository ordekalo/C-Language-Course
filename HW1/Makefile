CC=gcc
CFLAGS=-I.
DEPS = general.h exe.h
OBJ = general.o exe.o main.o
EXEC = hw1

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o $(EXEC)
