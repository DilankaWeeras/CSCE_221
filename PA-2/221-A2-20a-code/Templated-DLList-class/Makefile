all: run-tdll MinQueue

run-tdll: TDLList-main.o 
	c++ -std=c++11 TDLList-main.o -o run-tdll

MinQueue: MinQueue-main.o
	c++ -std=c++11 MinQueue-main.o -o MinQueue

TDLList-main.o: TDLList-main.cpp TemplatedDLList.h
	c++ -std=c++11 -c TDLList-main.cpp

MinQueue-main.o: MinQueue-main.cpp MinQueue.h TemplatedDLList.h
	c++ -std=c++11 -c MinQueue-main.cpp

clean:
	rm *.o run-tdll
