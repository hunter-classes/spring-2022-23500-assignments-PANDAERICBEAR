main: main.o Node.o List.o Dictionary.o Person.o
	g++ -o main main.o Node.o List.o Dictionary.o Person.o

tests: tests.o Node.o List.o Dictionary.o Person.o
	g++ -o tests tests.o Node.o List.o Dictionary.o Person.o

main.o: main.cpp Node.h List.h
	g++ -c main.cpp

Node.o: Node.cpp Node.h Person.h
	g++ -c Node.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp

List.o: List.cpp List.h Node.h
	g++ -c List.cpp

Dictionary.o: Dictionary.cpp Dictionary.h List.h
	g++ -c Dictionary.cpp

tests.o: tests.cpp doctest.h Dictionary.h
	g++ -c tests.cpp

clean:
	rm -f main tests *.o *.gch
