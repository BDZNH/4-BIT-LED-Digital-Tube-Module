#!/bin/bash
#HEADER_PATH = -I/usr/local/include/
#CCFLAG="-Wall -fexceptions -g -std=c++11 -lwiringPi -lpthread -DNDEBUG"

showtime: main.o mytime.o
	g++ -g -o showtime main.o mytime.o -lwiringPi -lpthread

main.o: main.cpp
	g++ -Wall -fexceptions -O2 -std=c++11 -lwiringPi -lpthread -g -c main.cpp

mytime.o: mytime.cpp
	g++ -Wall -fexceptions -O2 -std=c++11 -lwiringPi -lpthread -g -c mytime.cpp

clean:
	rm -rf *.o
	rm -rf showtime