all: run

run: BSTree_main.o BSTree.o
	c++ -std=c++11 BSTree_main.o BSTree.o -o run

BSTree_main.o: BSTree_main.cpp BSTree.h
	c++ -std=c++11 -c BSTree_main.cpp

BSTree.o: BSTree.cpp BSTree.h
	c++ -std=c++11 -c BSTree.cpp

clean:
	rm *.o run