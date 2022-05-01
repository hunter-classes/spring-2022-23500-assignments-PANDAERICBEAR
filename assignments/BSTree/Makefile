main: main.o Node.o BSTree.o
	g++ -o main main.o Node.o BSTree.o

tests: tests.o Node.o BSTree.o
	g++ -o tests tests.o Node.o BSTree.o

main.o: main.cpp Node.h
	g++ -c main.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

BSTree.o: BSTree.cpp BSTree.h
	g++ -c BSTree.cpp

tests.o: tests.cpp doctest.h Node.h BSTree.h
	g++ -c tests.cpp

clean:
	rm -f main tests *.o *.gch
