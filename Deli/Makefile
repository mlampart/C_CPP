C++ = g++
CFLAGS = -c -g

all: project4

project4:       project4.o Customer.o Product.o Price_List.o Cart.o Scale.o Deli.o
		$(C++) -o project4 project4.o Customer.o Product.o Price_List.o  Cart.o Scale.o Deli.o

clean:
	rm -f *.o

%.o:    %.cpp
		$(C++) $(CFLAGS) $*.cpp

