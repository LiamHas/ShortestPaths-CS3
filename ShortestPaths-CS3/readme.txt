Liam Hasandjekaj
CPS 222 Project 3

Files Submitted: 
catch.hpp
readGraph.hpp
readGraph.cpp
shortestPath.hpp
shortestPath.cpp
matrixDijkstra.cpp
listDijkstra.cpp
bellmanFord.cpp
currency.cpp
parallelDijkstra.cpp
mapqueue.cpp
readGraph_TEST.cpp
shortestPath_TEST.cpp
BinaryHeap_TEST.cpp
Malefile
mapqueuefix.txt
analysis.pdf
readme.txt
Project 3 Coversheet

This project contains six executable files related to finding shortest paths in given situations. The project also contains several related files for testing and building relevant data structures and algorithms. Using the command "make all" will compile all files in the project. You can also compile according to the directions below.

---matrixDijkstra---
To compile: make matrixDijkstra
To run: ./matrixDijkstra <input file> <output file> <source vertex> <destination vertex>
Description:

The matrixDijkstra program utilizes an adjacency matrix structure to perform Dijkstra's algorithm which finds the shortest path between two vertices. The program reads the relevant graph through an <input file> which contains the vertices, edges, and other graph qualities. By reading the graph the program creates an adjacency matrix which is then passed to a dijkstra implementation which finds the shortest path from the given <source vertex> to the given <destination vertex>. The shortest path and its data are then written to the given <output file>. The wall clock duration of the algorithm is outputted to the terminal in microseconds. The total weight of the shortest path is also outputted to the terminal. 

---listDijkstra---
To compile: make listDijkstra
To run: ./listDijkstra <input file> <output file> <source vertex> <destination vertex>

Description:
The listDijkstra program utilizes an adjacency list structure to perform Dijkstra's algorithm which finds the shortest path between two vertices. The program reads the relevant graph through an <input file> which contains the vertices, edges, and other graph qualities. By reading the graph the program creates an adjacency list which is represented by three separate structures. This is passed to a dijkstra implementation which finds the shortest path from the given <source vertex> to the given <destination vertex>. The shortest path and its data are then written to the given <output file>. The wall clock duration of the algorithm is outputted to the terminal in microseconds. The total weight of the shortest path is also outputted to the terminal.

---bellmanFord---
To compile: make bellmanFord
To run: ./bellmanFord <input file> <output file> <source vertex> <destination vertex>

Description: 
The bellmanFord program utilizes an adjacency list structure to perform Dijkstra's algorithm which finds the shortest path between two vertices. The program reads the relevant graph through an <input file> which contains the vertices, edges, and other graph qualities. By reading the graph the program creates an adjacency list which is represented by three separate structures. This is passed to a dijkstra implementation which finds the shortest path from the given <source vertex> to the given <destination vertex>. Dijkstra's does this by utilizing a min binary heap class which is able to hold, priorities, items, and positions of items for the relevant graph. The shortest path and its data are then written to the given <output file>. The wall clock duration of the algorithm is outputted to the terminal in microseconds. The total weight of the shortest path is also outputted to the terminal.

---currency---
To compile: make currency
To run: ./currency <input file> <output file> <source vertex> <destination vertex> <transaction cost>

Description:
The currency program utilizes an edge list and weights array to perform Bellman-Ford's algorithm which then finds the best conversion rate given a file of currency exchange rates. Bellman-Ford differs from dijkstra because it takes into account negative cycles. The program reads the relevant graph through an <input file> which contains the vertices, edges, and other graph qualities. Bellman-Ford then outputs an indicator that tells currency whether or not there is a cycle. Depending on that output currency then writes to the <output file> with either the cycle or the path that finds the given conversion rate. In this case, the <source vertex> is the currency you want to start with and the <destination vertex> is the currency you want to convert to. The <transaction cost> is used to compute the exchange rate. The wall clock duration of the algorithm is outputted to the terminal in microseconds. The exchange rate and an indication of an arbitrage opportunity (cycle) is also outputted to the terminal.


---parallelDijkstra---
To compile: make parallelDijkstra
To run: ./parallelDijkstra <input file> <output file> <source vertex> <destination vertex> <number of threads(consumers)>

Description:

The parallelDijkstra program utilizes an adjacency matrix structure and threading to perform Dijkstra's algorithm which finds the shortest path between two vertices. The program reads the relevant graph through an <input file> which contains the vertices, edges, and other graph qualities. By reading the graph the program creates an adjacency matrix which is then passed to a dijkstra implementation which finds the shortest path from the given <source vertex> to the given <destination vertex> utilizing three different parallelized algorithms. These algorithms are then called within dijkstra to create a parallelized version of the shorter path algorithm. The shortest path and its data are then written to the given <output file>. The wall clock duration and CPU duration of the algorithm is outputted to the terminal in microseconds. The total weight of the shortest path is also outputted to the terminal. 


---mapqueue---
To compile: make mapqueue
To run: ./mapqueue <number of servers>
Description:
The mapqueue program implements a simulation of queue of jobs that simultaneously being created, taken, and performed, using threads. The consumer threads take jobs off of the queue and perform them for the given allotment of seconds. The producer threads make jobs and push them onto the queue. The <number of servers> input determines the number of consumer threads that can pull jobs off of the queue. The program utilizes mutexes locks and unlocks to keep threads from entering in race conditions, which would crash the output.  




