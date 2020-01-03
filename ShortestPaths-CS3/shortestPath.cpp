

#include "shortestPath.hpp"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <limits>
#include <algorithm>
#include "BinaryHeap.hpp"
#include <thread>
#include <cmath>

using namespace std;

void dijkstra(const double* const * matrix, int numVertices, int source, double*& dist, int*& prev)
{
    dist = new double[numVertices];
    prev = new int[numVertices];
    bool* tree = new bool[numVertices];
    
    double inf = numeric_limits<double>::infinity();
    
    for(int i = 0; i<numVertices; i++)
    {
        dist[i] = inf;
        tree[i] = false;
    }
    
    dist[source] = 0;
    prev[source] = source;
    tree[source] = true;
    
    int node = source;
    
    for(int i = 0; i<numVertices; i++)
    {
        int j;
        for(j = 0; j<numVertices; j++)
        {
            int adjNode = j;

            if(tree[adjNode] == false && dist[node] + matrix[node][adjNode] < dist[adjNode])
            {
                dist[adjNode] = dist[node] + matrix[node][adjNode];
                prev[adjNode] = node;
            }
        }
        
        double min = inf;
        
        for(int k = 0; k < numVertices; k++)
        {
            if(tree[k] == false && dist[k] < min)
            {
                node = k;
                min = dist[k];
            }
        }
        
        tree[node] = true;
       
    }
}

int getPath(int source, int dest, const int* prev, int*& path)
{
    int prevIdx = dest;
    int i = 1;
    while(prevIdx != source)
    {
        prevIdx = prev[prevIdx];
        i++;
    }
    path = new int[i];
    int size = i;
    
    prevIdx = dest;
    for(int i = size-1; i>=0; i--)
    {
        path[i] = prevIdx;
        prevIdx = prev[prevIdx];
    }
    
    return size;
}

void dijkstra(const int* const * adj, const double* const * weights, const int* lengths, int numVertices, int source, double*& dist, int*& prev)

{

    dist = new double[numVertices];
    prev = new int[numVertices];
    
    double inf = numeric_limits<double>::infinity();
    
    
    for(int i = 0; i<numVertices; i++)
    {
        dist[i] = inf;
    }
    BinaryHeap* bh = new BinaryHeap(dist, numVertices);

    bh->decreasePriority(source, 0);
    
    int n = bh->getMin();
    bh->popMin();
    
    dist[n] = 0;

    for(int i = 0; i < numVertices; i++)
    {
        for(int j = 0; j < lengths[n]; j++)
        {
            int adjacent = adj[n][j];
            if(bh->contains(adjacent) && dist[n] + weights[n][j] < bh->getPriority(adjacent))
            {
                bh->decreasePriority(adjacent, dist[n] + weights[n][j]);
                prev[adjacent] = n;
            }
        }
        n = bh->getMin();
        dist[n] = bh->getPriority(n);
        bh->popMin();
    }
}

int bellmanFord(const int* const * edges, const double* weights, int numVertices, int numEdges, int source, double*& dist, int*& prev)
{
    dist = new double[numVertices];
    prev = new int[numVertices];
    
    double inf = numeric_limits<double>::infinity();
    
    for(int i = 0; i<numVertices; i++)
    {
        dist[i] = inf;
        prev[i] = -1;
    }
    
    dist[source] = 0;

    for(int i = 0; i < numVertices; i++)
    {
        for(int j = 0; j < numEdges; j++)
        {
            int v1 = edges[j][0];
            int v2 = edges[j][1];
            
            if((dist[v1] + weights[j]) < dist[v2])
            {
                dist[v2] = dist[v1] + weights[j];
                prev[v2] = v1;
            }
        }
    }
    
    double* distC = new double[numVertices];
    int* prevC = new int[numVertices];
    
    for(int i = 0; i < numVertices; i++)
    {

        distC[i] = dist[i];
        prevC[i] = prev[i];
    }
    
    int returnV = -1;
    for(int j = 0; j < numEdges; j++)
    {

        int v1C = edges[j][0];
        int v2C = edges[j][1];
        
        if(dist[v1C] + weights[j] < dist[v2C])
        {
            dist[v2C] = distC[v1C] + weights[j];
            prev[v2C] = v1C;
            
            returnV = v2C;
        }
        
    }
    return returnV;

}

int getCycle(int vertex, const int* prev, int numVertices, int*& cycle)
{
    
    bool* checked = new bool[numVertices];
    int* flippedCycle = new int[numVertices];
    
    for(int i = 0; i < numVertices; i++)
    {
        checked[i] = false;
    }
    
    int v1 = prev[vertex];
    int repeatVert = 0;
    int i = 0;
    
    while(checked[v1] != true)
    {
        flippedCycle[i] = v1;
        i++;
        checked[v1] = true;
        v1 = prev[v1];
        repeatVert = v1;
    }
    int size = i;
    flippedCycle[size] = repeatVert;
    size++;
    
    cycle = new int[size];
    
    for(int i = 0; i < size; i++)
    {
        cycle[i] = flippedCycle[size-i-1];
    }
    
    return size;
}

void dijkstra(const double* const * graph, int numVertices, int source, double*& dist, int*& prev, int numThreads)
{
    dist = new double[numVertices];
    prev = new int[numVertices];
    bool* tree = new bool[numVertices];
    
    initialize(dist, prev, tree, numThreads, 0, numVertices);

    dist[source] = 0;
    
    for(int i = 0; i < numVertices; i++)
    {
        int x;
        getMinVertex(dist, tree, 0, numVertices, numThreads, &x);
        tree[x] = true;
        updateDistances(graph, dist, prev, tree, numThreads, 0, numVertices, x);
    }
}

void initialize(double* dist, int* prev, bool* tree, int numThreads, int low, int high)
{
    
    double inf = numeric_limits<double>::infinity();

    if(numThreads == 1)
    {
        for(int i = low; i < high; i++)
        {
            dist[i] = inf;
            prev[i] = -1;
            tree[i] = false;
        }
    }
    else
    {
        int halfThreads = numThreads/2;
        
        int mid = low + halfThreads*((high - low)/numThreads);

        thread init1(initialize, dist, prev, tree, halfThreads, low, mid);
        initialize(dist, prev, tree, numThreads - halfThreads, mid, high);
            
        init1.join();

    }
}

void getMinVertex(double* dist, bool* tree, int start, int end, int numThreads, int* vertex)
{
    if(numThreads == 1)
    {
        double inf = numeric_limits<double>::infinity();
        
        double minDist = inf;
        int minVertex = -1;
        
        for(int i = start; i < end; i++)
        {
            if(dist[i] < minDist && tree[i] == false)
            {
                minDist = dist[i];
                minVertex = i;
            }
        }
        *vertex = minVertex;
    }
    else
    {
        int leftMin;
        int rightMin;
        
        int halfNumThreads = numThreads/2;
            
        int mid = start + halfNumThreads*((end - start)/numThreads);
            
        thread leftThread(getMinVertex, dist, tree, start, mid, halfNumThreads, &leftMin);
        getMinVertex(dist, tree, mid, end, numThreads - halfNumThreads, &rightMin);
            
        leftThread.join();
    
        if(leftMin == -1 && rightMin != -1)
        {
            *vertex = rightMin;
        }
        else if(rightMin == -1 && leftMin != -1)
        {
            *vertex = leftMin;
        }
        else
        {
            *vertex = leftMin;
            if(dist[rightMin] < dist[leftMin])/// && tree[rightMin] == false)
            {
                *vertex = rightMin;
            }
        }
    }
}

void updateDistances(const double* const * graph, double* dist, int* prev, bool* tree, int numThreads, int low, int high, int vertex)
{
    if(numThreads == 1)
    {
        for(int i = low; i < high; i++)
        {
            if(tree[i] == false && dist[i] > dist[vertex] + graph[vertex][i])
            {
                dist[i] = dist[vertex] + graph[vertex][i];
                prev[i] = vertex;
            }
        }
    }
    else
    {
        int halfThreads = numThreads/2;
        
        int mid = low + halfThreads*((high - low)/numThreads);
        
        thread upDist(updateDistances, graph, dist, prev, tree, halfThreads, low, mid, vertex);
        updateDistances(graph, dist, prev, tree, numThreads - halfThreads, mid, high, vertex);
        
        upDist.join();
        
    }
}


