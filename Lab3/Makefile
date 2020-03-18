CC=gcc
CFLAGS=-I.
DEPS = func.h exe.h
OBJ = func.o exe.o main.o
EXEC = lab3

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o $(EXEC) 
