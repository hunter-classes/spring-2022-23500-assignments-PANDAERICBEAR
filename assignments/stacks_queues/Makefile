main: main.o Node.o List.o Stack.o
	g++ -o main main.o Node.o List.o Stack.o

tests: tests.o Node.o List.o Stack.o
	g++ -o tests tests.o Node.o List.o Stack.o

main.o: main.cpp Node.h List.h Stack.h
	g++ -c main.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

List.o: List.cpp List.h Node.h
	g++ -c List.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp

tests.o: tests.cpp doctest.h Node.h List.h Stack.h
	g++ -c tests.cpp

clean:
	rm -f main tests *.o *.gch
