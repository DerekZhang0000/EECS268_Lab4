Exercise1: main.o Node.o Stack.o Queue.o CeoOfElevator.o
	g++ -std=c++11 -g -Wall main.o Node.o Stack.o Queue.o CeoOfElevator.o -o Exercise1
main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
Stack.o: Stack.h Stack.cpp
	g++ -std=c++11 -g -Wall -c Stack.cpp
Queue.o: Queue.h Queue.cpp
	g++ -std=c++11 -g -Wall -c Queue.cpp
CeoOfElevator.o: CeoOfElevator.h CeoOfElevator.cpp
	g++ -std=c++11 -g -Wall -c CeoOfElevator.cpp
clean:
	rm*.o Exercise1