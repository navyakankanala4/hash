In this program , hash table is implemented based on seperate chaining  and hash key is generated based on ip tupple parameters like source ip,destination ip,source port,destination port and protocol.
Based on the hash key and  maximum size hash index is generated.Depending upon the index the all the tupple parameters are stored in the hash table .while insertion of packet if the ip is already present it updates and increment the count .while searching it searches for a ip address or a particular port which was entered by the user and if it finds it returns the search element is found .while deletion it searches for the particular element entered by the user and deletes the specified element and update the count by decrementing and a makefile is created for the particular program depending upon the files which were used
Steps to compile and run:
compiling the main program buy linking the files both hash.h hash.c with server.c
compilation:gcc -o server server.c hash.c
To run the makefile:make
after running make file it creates .o files and library.then execute the program
execution:./server
now execute the client based on the requirement if the client is TCP
compilation of TCP_client is :gcc -o tcp_client tcp_client.c
execution:./tcp_client
Now to execute UDP_client the compilition to be done as
compilation of UDP_client is:gcc -o udp_client udp_client.c
execution:./udp_client

