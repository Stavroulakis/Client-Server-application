CC=gcc
CFLAGS=-lpthread
LDFLAGS=
SOURCES=server.c  shared_memory.c socket.c server_functions.c client.c 
OBJECTS= $(SOURCES:.c=.o)

all: client server

client:
	$(CC)  client.c  -lpthread -o client

server: 
	$(CC) server.c  shared_memory.c socket.c server_functions.c -lpthread -o server
clean:
	rm -rf server client eisitiria_Theatrikiis_parastashs.socket