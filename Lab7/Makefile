CC=gcc
CFLAGS=-I.
DEPS = functions.h exe.h
OBJ = functions.o exe.o main.o
EXEC = lab7

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o $(EXEC) 
