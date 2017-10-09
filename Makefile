CPPFLAGS = -Wall -Wno-sign-compare -Wno-reorder -Wno-unused-variable -lssh2

OBJECTS = main.o \
          Connection.o \

C++ = g++

all: $(OBJECTS)
	$(C++) -o main $(CPPFLAGS) $(OBJECTS)

.PHONY: clean all

$(OBJECTS) :
	$(C++) -c -o $(@) $(CPPFLAGS) $(<)

GLOBALS = 

main.o: main.cpp                            $(GLOBALS)

Connection.o: Connection.cpp Connection.h   $(GLOBALS)

clean:
	rm -rf *.o
