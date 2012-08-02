SRC=*.cpp

all:
	g++ -Wall $(SRC) -o main

clean:
	rm *.o *.gch main
