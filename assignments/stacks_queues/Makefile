main: main.o Node.o List.o Stack.o Queue.o
	g++ -o main main.o Node.o List.o Stack.o Queue.o

tests: tests.o Node.o List.o Stack.o Queue.o
	g++ -o tests tests.o Node.o List.o Stack.o Queue.o

main.o: main.cpp Node.h List.h Stack.h Queue.h
	g++ -c main.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

List.o: List.cpp List.h Node.h
	g++ -c List.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp

tests.o: tests.cpp doctest.h Node.h List.h Stack.h Queue.h
	g++ -c tests.cpp

clean:
	rm -f main tests *.o *.gch
