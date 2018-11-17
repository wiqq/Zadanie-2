CC=g++ 
CXX=g++ 
CPPFLAGS= -Wall -pedantic 
OBJS=zad2.o main.o 
all:	$(OBJS) clean
zad2:	$(OBJS)
main.o:	main.cpp
zad2.o:	zad2.cpp
run:	zad2
	./zad2
clean:
	rm -f *o zad2