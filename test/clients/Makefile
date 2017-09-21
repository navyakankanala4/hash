CC=gcc
FLAGS= -I ../../include -g
EXECPATH= ../../

default: tcp_client udp_client client_lookup client_delete clean

tcp_client: tcp_client.o 
	$(CC) -o $(EXECPATH)tcp_client tcp_client.o -g

udp_client: udp_client.o
	$(CC) -o $(EXECPATH)udp_client udp_client.o -g


clean:
	rm -rf *.o
