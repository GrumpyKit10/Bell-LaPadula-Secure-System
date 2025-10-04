#Name:			Matthew Wilson
#Email:			mlw0420@unt.edu
#Course:		CSCE 3550.001
#Date:			3-2-22
#Description:	Makefile for project 1.

secureblp: subject.o object.o instruction.o refmon.o secureblp.o
	g++ -o secureblp subject.o object.o instruction.o refmon.o secureblp.o

subject.o: subject.cpp subject.h
	g++ -c -g -std=c++0x -Wall	-c -o subject.o subject.cpp

object.o: object.cpp object.h
	g++ -c -g -std=c++0x -Wall	-c -o object.o object.cpp

instruction.o: instruction.cpp instruction.h
	g++ -c -g -std=c++0x -Wall	-c -o instruction.o instruction.cpp

refmon.o: refmon.cpp refmon.h
	g++ -c -g -std=c++0x -Wall	-c -o refmon.o refmon.cpp

secureblp.o: secureblp.cpp refmon.h
	g++ -c -g -std=c++0x -Wall	-c -o secureblp.o secureblp.cpp

clean:
	rm *.o secureblp
