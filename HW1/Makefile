CC=gcc
CFLAGS=-I.
DEPS = general.h exe.h q1.h q2.h q3.h
OBJ = general.o exe.o q1.o q2.o q3.o main.o
EXEC = hw1

%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o $(EXEC)
