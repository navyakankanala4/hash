 a program for storing of all five tupples (source ip,destination ip,source port,destinaton port,protovol)is implemented based on 
seperate chaining hash technique.here the hash key is generated by adding all the source ip destination ip and source port and destination port.

here the API's used are insert_packet,delete_packet,update_packet.

in the insertion first check for the index if it is null,then store the data in that index.if the index is not  empty then add a node at the end and store the data.

in the lookup function first we will compare ip addresses if the ip is already present then update the packet and timestamp at which it arrived.

in the delete function enter an ip address and then search for the ip address and if it is present then delete it else print deletion is failed.

server has been implemented based on select and there is a seperate logic for the tcp and udp packets.if the received packet is udp it stores information in protocol as udp else tcp