CC=gcc
CFLAGS=-I.
DEPS = array.h
OBJ = array.o main.o
EXEC = lab4

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o $(EXEC) 
