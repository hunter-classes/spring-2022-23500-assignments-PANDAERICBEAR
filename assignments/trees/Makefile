main: main.o Node.o Tree.o
	g++ -o main main.o Node.o Tree.o

tests: tests.o Node.o Tree.o
	g++ -o tests tests.o Node.o Tree.o

main.o: main.cpp Node.h
	g++ -c main.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

Tree.o: Tree.cpp Tree.h
	g++ -c Tree.cpp

tests.o: tests.cpp doctest.h Node.h Tree.h
	g++ -c tests.cpp

clean:
	rm -f main tests *.o *.gch
