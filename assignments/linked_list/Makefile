main: main.o Node.o List.o
	g++ -o main main.o Node.o List.o

main.o: main.cpp Node.h List.h
	g++ -c main.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

List.o: List.cpp List.h
	g++ -c List.cpp

clean:
	rm -f a.out *.o *.gch
