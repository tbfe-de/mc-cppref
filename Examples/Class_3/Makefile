main: main.o minmax.o average.o value.o
	g++ main.o minmax.o average.o value.o -o $@

main.run: main
	@./main

test-main.run: test-main
	@./test-main

test-main: test-main.o minmax.o average.o
	g++ test-main.o value.o minmax.o average.o -o $@

test-main.o main.o minmax.o: minmax.h value.h
test-main.o main.o average.o: average.h value.h

value.o: value.cpp
	g++ -c value.cpp

minmax.o: minmax.cpp
	g++ -c minmax.cpp

average.o: average.cpp
	g++ -c average.cpp

clean:
	rm -f a.out core *.o main
