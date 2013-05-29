C++ = g++
CFLAGS = -c -g

all: final service

final:		final.o ML_hash.o random_op.o
		$(C++) -o final final.o ML_hash.o random_op.o MLH_Node.h MLH.h

service:	service.o ML_hash.o random_op.o Vehicle.o Car.o Hybrid.o Bus.o Motorcycle.o
		$(C++) -o service service.o ML_hash.o random_op.o Vehicle.o Car.o Hybrid.o Bus.o Motorcycle.o

clean:
		rm -f *.o 

%.o:	%.cpp
		$(C++) $(CFLAGS) $*.cpp

