

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include "readGraph.hpp"
#include "shortestPath.hpp"
#include <chrono>
#include <ctime>

using namespace std;

int main(int argc, char** argv)
{
    string inFile = argv[1];
    string outFile = argv[2];
    string sourceVertex = argv[3];
    string destVertex = argv[4];
    int numThreads = atoi(argv[5]);

    
    ifstream fin(inFile);
    double** matrix;
    string* vLabels;
    string** eLabels;
    
    int vert = readGraph(fin, matrix, vLabels, eLabels);
    
    int source = 0;
    int dest = 0;
    
    for(int i = 0; i<vert; i++)
    {
        string vertexName = vLabels[i];
        if(vertexName == sourceVertex)
        {
            source = i;
        }
        else if(vertexName == destVertex)
        {
            dest = i;
        }
        
    }
    
    double* dist;
    int* prev;
    
    auto t1 = chrono::system_clock::now();
    clock_t start = clock();
    
    dijkstra(matrix, vert, source, dist, prev, numThreads);
    
    clock_t end = clock();
    clock_t dur2 = end-start;
    double cputime = (dur2 * 1000000) / CLOCKS_PER_SEC;
    
    auto t2 = chrono::system_clock::now();
    auto dur = t2 - t1;
    auto durNS = chrono::duration_cast<chrono::microseconds>(dur);
    
    int* path;
    
    int size = getPath(source, dest, prev, path);
    
    
    ofstream fout(outFile);
    
    fout << vert << " " << size-1<<endl;
    
    for(int i = 0; i < vert; i++)
    {
        fout<<vLabels[i]<<endl;
        
    }
    for(int i = 0; i<size-1; i++)
    {
        fout<<path[i]<<" "<<path[i+1]<<" "<< matrix[path[i]][path[i+1]] << " "<< eLabels[path[i]][path[i+1]] <<endl;
    }
    
    double edgeTotal = dist[dest];
    
    cout<<"Dijkstra using Parallel Functions Takes: "<< cputime << " microseconds in CPU Time"<<endl;
    cout<<"Dijkstra using Parallel Functions Takes: " <<durNS.count() << " microseconds in Wall Clock Time"<<endl;
    cout<<"The shortest path has a weight of " << edgeTotal << endl;
    
    for(int i = 0; i < vert; i++)
    {
        delete[] matrix[i];
        delete[] eLabels[i];
    }
    
    delete[] vLabels;
    delete[] eLabels;
    delete[] dist;
    delete[] prev;
    delete[] path;
    delete[] matrix;
}

