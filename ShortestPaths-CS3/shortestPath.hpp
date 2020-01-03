

#ifndef shortestPath_hpp
#define shortestPath_hpp

#include <stdio.h>

void dijkstra(const double* const * matrix, int numVertices, int source, double*& dist, int*& prev);
int getPath(int source, int dest, const int* prev, int*& path);
void dijkstra(const int* const * adj, const double* const * weights, const int* lengths, int numVertices, int source, double*& dist, int*& prev);
int bellmanFord(const int* const * edges, const double* weights, int numVertices, int numEdges, int source, double*& dist, int*& prev);
int getCycle(int vertex, const int* prev, int numVertices, int*& cycle);
void dijkstra(const double* const * graph, int numVertices, int source, double*& dist, int*& prev, int numThreads);
void initialize(double* dist, int* prev, bool* tree, int numThreads, int low, int high);
void getMinVertex(double* dist, bool* tree, int start, int end, int numThreads, int* vertex);
void updateDistances(const double* const * graph, double* dist, int* prev, bool* tree, int numThreads, int low, int high, int vertex);// int vert);

#endif /* shortestPath_hpp */
