FLAGS = -Wall -std=gnu99
DEPENDENCIES = hash.h ftree.h

all: fcopy

fcopy: fcopy.o ftree.o hash_functions.o
	gcc ${FLAGS} -o $@ $^

%.o: %.c ${DEPENDENCIES}
	gcc ${FLAGS} -c $<

clean:
	rm *.o fcopy