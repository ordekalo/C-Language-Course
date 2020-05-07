CC=gcc
CFLAGS=-I.
DEPS = family.h building.h
OBJ = family.o building.o main.o
EXEC = lab7B

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o $(EXEC) 
