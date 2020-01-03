
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include "readGraph.hpp"
#include "shortestPath.hpp"
#include <chrono>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
    string inFile = argv[1];
    string outFile = argv[2];
    string sourceVertex = argv[3];
    string destVertex = argv[4];
    
    ifstream fin(inFile);
    int** edgeList;
    double* weights;
    int numEdges;
    string* vLabels;
    string* eLabels;
    
    int vert = readGraph(fin, edgeList, weights, numEdges, vLabels, eLabels);
    
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
    
    int detector = bellmanFord(edgeList, weights, vert, numEdges, source, dist, prev);
    
    auto t2 = chrono::system_clock::now();
    auto dur = t2 - t1;
    auto durNS = chrono::duration_cast<chrono::microseconds>(dur);
    
    int* path;
    
    ofstream fout(outFile);
    
    double edgeTotal = 0;
    
    if(detector == -1)
    {
        int size = getPath(source, dest, prev, path);
        
        fout << vert << " " << size-1 <<endl;
        
        for(int i = 0; i < vert; i++)
        {
            fout<<vLabels[i]<<endl;
        }
        
        for(int i = 0; i<size-1; i++)
        {
            int firstVert = path[i];
            int secVert = path[i+1];
            int weightIdx = 0;
            for(int j = 0; j < numEdges; j++)
            {
                int v1 = edgeList[j][0];
                int v2 = edgeList[j][1];
                
                if(v1 == firstVert && v2 == secVert)
                {
                    weightIdx = j;
                    j = numEdges-1;
                }
            }
            fout << firstVert<<" " << secVert<<" " << weights[weightIdx]<<" " << eLabels[weightIdx]<<" " << endl;
            edgeTotal = dist[dest];
        }
        cout<<"Bellman Ford Takes: " <<durNS.count() << " microseconds"<<endl;
        cout<<"The shortest path has a weight of " << edgeTotal << endl;
        
        delete[] path;

    }
    else
    {
        int* cycle;
        int cycleSize = getCycle(source, prev, vert, cycle);

        fout << vert << " " << cycleSize-1 <<endl;
        
        for(int i = 0; i < vert; i++)
        {
            fout<<vLabels[i]<<endl;
        }
        
        
        for(int i = 0; i<cycleSize-1; i++)
        {
            int firstVert = cycle[i];
            int secVert = cycle[i+1];
            int weightIdx = 0;
            for(int j = 0; j < numEdges; j++)
            {
                int v1 = edgeList[j][0];
                int v2 = edgeList[j][1];
                
                
                if(v1 == firstVert && v2 == secVert)
                {
                    weightIdx = j;
                    j = numEdges-1;
                    edgeTotal += weights[weightIdx];
                }
            }
            fout << firstVert<<" " << secVert<<" " << weights[weightIdx]<<" " << eLabels[weightIdx]<<" " << endl;
        }
        
        cout<<"ERROR: Negative Cycle Detected Within Graph"<<endl;
        cout<<"Total weight: " << edgeTotal << endl;
        cout<<"Runtime: " <<durNS.count() << " microseconds"<<endl;
        
        delete[] cycle;
    }
    
    for(int i = 0; i < vert; i++)
    {
        delete[] edgeList[i];
    }
    
    delete[] edgeList;
    delete[] weights;
    delete[] vLabels;
    delete[] eLabels;
    delete[] dist;
    delete[] prev;
    
    return 0;
    

}
