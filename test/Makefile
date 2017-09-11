CC=gcc
CFLAGS=-c -Wall
LDFLAGS= - L Home/Downloads/Task1/hash.h
SOURCES= server.c  hash.c
OBJECTS=$(SOURCES:.c=.o)
LIB_NAME=hashing

all: $(SOURCES) $(LIB_NAME)
	    
$(LIB_NAME): $(OBJECTS)
	ar rcs $(LIB_NAME) $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(LIB_NAME)
