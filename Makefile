CC=g++
CFLAGS=-c -std=c++0x

run: RoutingGraph.o geo_utils.o main.o
	$(CC) bin/RoutingGraph.o bin/geo_utils.o bin/main.o -o main

RoutingGraph.o: datastructures/RoutingGraph.cpp
	$(CC) $(CFLAGS) datastructures/RoutingGraph.cpp -o bin/RoutingGraph.o

geo_utils.o: utilities/geo_utils.cpp
	$(CC) $(CFLAGS) utilities/geo_utils.cpp -o bin/geo_utils.o

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o bin/main.o

clean:
	rm bin/* main