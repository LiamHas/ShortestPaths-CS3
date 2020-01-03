

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include "readGraph.hpp"
#include "shortestPath.hpp"
#include <chrono>

using namespace std;

int main(int argc, char** argv)
{

    string inFile = argv[1];
    string outFile = argv[2];
    string sourceVertex = argv[3];
    string destVertex = argv[4];
    
    ifstream fin(inFile);
    int** adj;
    double** weights;
    int* lengths;
    string* vLabels;
    string** eLabels;
    
    int vert = readGraph(fin, adj, weights, lengths, vLabels, eLabels);

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
    
    dijkstra(adj, weights, lengths, vert, source, dist, prev);

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

    for(int i = 0; i < vert; i++)
    {
        cout<<path[i]<<endl;
    }
    
    int weightIdx = 0;
    double edgeTotal = 0;
    for(int i = 0; i<size-1; i++)
    {
        int firstVert = path[i];
        int secVert = path[i+1];
        for(int j = 0; j < lengths[firstVert]; j++)
        {
            int v1 = adj[firstVert][j];
            if(v1 == secVert)
            {
                weightIdx = j;
                j = lengths[firstVert];
                edgeTotal += weights[path[i]][weightIdx];
            }
        }
        fout<<firstVert<<" "<<secVert<<" "<< weights[path[i]][weightIdx] << " "<< eLabels[path[i]][weightIdx] <<endl;
    }
    
    //double edgeTotal = dist[dest];
    
    cout<<"Dijkstra with Adjacency List Takes: " <<durNS.count() << " microseconds"<<endl;
    cout<<"The shortest path has a weight of " << edgeTotal << endl;
    
    for(int i = 0; i < vert; i++)
    {
        delete[] eLabels[i];
        delete[] adj[i];
        delete[] weights[i];
    }
    
    delete[] vLabels;
    delete[] eLabels;
    delete[] dist;
    delete[] prev;
    delete[] path;
}

