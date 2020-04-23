CC=gcc
CFLAGS=-I.
DEPS = address.h person.h
OBJ = address.o exe.o person.o
EXEC = lab6

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o $(EXEC) 
