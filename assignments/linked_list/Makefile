main: main.o Node.o List.o OList.o
	g++ -o main main.o Node.o List.o OList.o

main.o: main.cpp Node.h List.h
	g++ -c main.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

List.o: List.cpp List.h Node.h
	g++ -c List.cpp

OList.o: OList.cpp OList.h List.h
	g++ -c OList.cpp

clean:
	rm -f main *.o *.gch
