OPTS = -Wall -std=c++11 -g -pthread

all: readGraph.o readGraph_TEST shortestPath.o shortestPath_TEST matrixDijkstra BinaryHeap_TEST listDijkstra bellmanFord currency parallelDijkstra mapqueue

readGraph.o: readGraph.cpp readGraph.hpp
	g++ ${OPTS} -c readGraph.cpp

readGraph_TEST: readGraph_TEST.cpp readGraph.o catch.hpp
	g++ ${OPTS} -o readGraph_TEST readGraph_TEST.cpp readGraph.cpp

shortestPath.o: shortestPath.cpp shortestPath.hpp BinaryHeap.o
	g++ ${OPTS} -c shortestPath.cpp

shortestPath_TEST: shortestPath_TEST.cpp shortestPath.o catch.hpp readGraph.o BinaryHeap.o
	g++ ${OPTS} -o shortestPath_TEST shortestPath_TEST.cpp shortestPath.cpp readGraph.o BinaryHeap.o

matrixDijkstra: matrixDijkstra.cpp readGraph.o shortestPath.o BinaryHeap.o
	g++ ${OPTS} -o matrixDijkstra matrixDijkstra.cpp readGraph.o shortestPath.o BinaryHeap.o

BinaryHeap.o: BinaryHeap.hpp BinaryHeap.cpp
	g++ ${OPTS} -c BinaryHeap.cpp

BinaryHeap_TEST: BinaryHeap_TEST.cpp BinaryHeap.o catch.hpp 
	g++ ${OPTS} -o BinaryHeap_TEST BinaryHeap_TEST.cpp BinaryHeap.cpp

listDijkstra: listDijkstra.cpp readGraph.o shortestPath.o BinaryHeap.o
	g++ ${OPTS} -o listDijkstra listDijkstra.cpp readGraph.o shortestPath.o BinaryHeap.o

bellmanFord: bellmanFord.cpp readGraph.o shortestPath.o BinaryHeap.o
	g++ ${OPTS} -o bellmanFord bellmanFord.cpp readGraph.o shortestPath.o BinaryHeap.o

currency: currency.cpp readGraph.o shortestPath.o BinaryHeap.o
	g++ ${OPTS} -o currency currency.cpp readGraph.o shortestPath.o BinaryHeap.o

parallelDijkstra: parallelDijkstra.cpp readGraph.o shortestPath.o BinaryHeap.o
	g++ ${OPTS} -o parallelDijkstra parallelDijkstra.cpp readGraph.o shortestPath.o BinaryHeap.o

mapqueue: mapqueue.cpp
	g++ ${OPTS} -o mapqueue mapqueue.cpp
