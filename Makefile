


all:
	$(MAKE) -C test
	$(MAKE) -C test/clients

clean:
	rm -f server  client_tcp client_udp
