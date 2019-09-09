CFLAGS = -O
CC = g++
SRC = src/main.cpp src/filehandler.cpp src/crypt.cpp
OBJ = $(SRC:.cpp = .o)

Test: $(OBJ)
	$(CC) $(CFLAGS) -o Test $(OBJ)

clean:
	rm -f core *.o
