main: main.o minmax.o average.o
	g++ main.o minmax.o average.o -o $@

main.run: main
	@./main

main.o minmax.o: minmax.h
main.o average.o: average.h

minmax.o: minmax.cpp
	g++ -c minmax.cpp

average.o: average.cpp
	g++ -c average.cpp

clean:
	rm -f a.out core *.o main
