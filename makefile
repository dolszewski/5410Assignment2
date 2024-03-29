CFLAGS = -O
LDFLAGS="-L/usr/local/opt/openssl/lib"
CPPFLAGS="-I/usr/local/opt/openssl/include"
CC = g++
SRC1 = src/gsend.cpp src/filehandler.cpp src/crypt.cpp src/lib/PracticalSocket/PracticalSocket.cpp src/client.cpp src/lib/PracticalSocket/common.cpp
OBJ1 = $(SRC1:.cpp = .o)
SRC2 = src/grec.cpp src/filehandler.cpp src/crypt.cpp src/lib/PracticalSocket/PracticalSocket.cpp src/server.cpp src/lib/PracticalSocket/common.cpp
OBJ2 = $(SRC2:.cpp = .o)

all: gsend grec

gsend: $(OBJ1)
	$(CC) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -o gsend -lssl -lcrypto $(OBJ1)
grec: $(OBJ2)
	$(CC) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -o grec -lssl -lcrypto $(OBJ2)

clean:
	rm -f core *.o
