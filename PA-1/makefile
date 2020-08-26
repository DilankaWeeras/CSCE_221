all: test

##JN: Jeans.o Jean_test.o
##c++ -std=c++11 Jeans.o Jean_test.o -o test

##SB: Stress_ball.o Stress_ball_test.o
##c++ -std=c++11 Stress_ball.o Stress_ball_test.o -o test

test: Stress_ball.o Jeans.o collection_test_2.o
	c++ -std=c++11 Stress_ball.o Jeans.o collection_test_2.o -o test

Stress_ball.o: Stress_ball.cpp Stress_ball.h
	c++ -std=c++11 -c Stress_ball.cpp

Stress_ball_test: Stress_ball_test.cpp
	c++ -std=c++11 -c Stress_ball_test.cpp

Jeans.o: Jeans.cpp Jeans.h
	c++ -std=c++11 -c Jeans.cpp

Jeans_test.o: Jeans_test.cpp
	c++ -std=c++11 -c Jean_test.cpp

Collection_template.o: Collection_template_2.cpp Collection_template_2.h
	c++ -std=c++11 -c Collection_template_2.cpp
	
collection_test_2.o: collection_test_2.cpp
	c++ -std=c++11 -c collection_test_2.cpp

clean:
	rm -f *.o test
