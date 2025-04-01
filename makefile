PP1: main.o operation.o
	g++ -o PP1 main.o  operation.o -g

main.o: operation.h main.cpp
	g++ -c main.cpp -g

operation.o: operation.h operation.cpp
	g++ -c operation.cpp -g

clean:
	rm *o PP1