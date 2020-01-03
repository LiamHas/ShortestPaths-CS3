

#include "readGraph.hpp"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <limits>
#include <vector>

using namespace std;

int readGraph(ifstream& fin, double**& matrix, string*& vLabels,string**& eLabels)
{
    int numVert;
    int numEdge;
    
    fin >> numVert;
    fin >> numEdge;
    
    matrix = new double*[numVert];
    vLabels = new string[numVert];
    eLabels = new string*[numEdge];
    
    
    string vertName;
    for(int i = 0; i<numVert; i++)
    {
        fin >> vertName;
        vLabels[i] = vertName;
    }
    
    

    double inf = numeric_limits<double>::infinity();
    for(int i = 0; i < numVert; i++)
    {
        double* matrixList = new double[numVert];
        string* eLabelList = new string[numVert];
        
        for(int j = 0; j<numVert; j++)
        {
            eLabelList[j] = "";
            matrixList[j] = inf;

            if(j == i)
            {
                matrixList[j] = 0;
            }

            
        }
        matrix[i] = matrixList;
        eLabels[i] = eLabelList;
    }
    
    
    int firstVert;
    int secVert;
    double edgeWeight;
    string edgeName;

    for(int i = 0; i<numEdge; i++)
    {
        fin >> firstVert;
        fin >> secVert;
        fin >> edgeWeight;
        fin >> edgeName;

        matrix[firstVert][secVert] = edgeWeight;
        eLabels[firstVert][secVert] = edgeName;

    }
    
    return numVert;
}

int readGraph(ifstream& fin, int**& adj, double**& weights, int*& lengths, string*& vLabels, string**& eLabels)
{
    int numVert;
    int numEdge;
    
    fin >> numVert;
    fin >> numEdge;
    
    adj = new int*[numVert];
    weights = new double*[numVert];
    lengths = new int[numVert];
    vLabels = new string[numVert];
    eLabels = new string*[numVert];
    
    
    
    string vertName;
    for(int i = 0; i<numVert; i++)
    {
        lengths[i] = 0;
        fin >> vertName;
        vLabels[i] = vertName;
    }
    
    int firstVert;
    int secVert;
    double edgeWeight;
    string edgeName;
    
    for(int i = 0; i<numEdge; i++)
    {
        fin >> firstVert;
        fin >> secVert;
        fin >> edgeWeight;
        fin >> edgeName;
        
        lengths[firstVert] += 1;
    }
  
    fin.seekg(0, ios::beg ); 
    
    int holder;
    string holderStr;
    
    fin >> holder;
    fin >> holder;
    
    for(int i = 0; i<numVert; i++)
    {
        fin >> holderStr;
    }
    
    for(int i = 0; i < numVert; i++)
    {
        int size = lengths[i];
        
        int* adjArray = new int[size];
        double* weightArray = new double[size];
        string* nameArray = new string[size];
        
        for(int j = 0; j < size; j++)
        {
            fin >> firstVert;
            fin >> secVert;
            fin >> edgeWeight;
            fin >> edgeName;
            
            adjArray[j] = secVert;
            weightArray[j] = edgeWeight;
            nameArray[j] = edgeName;
        }
        
        adj[i] = adjArray;
        weights[i] = weightArray;
        eLabels[i] = nameArray;
    }
   
    return numVert;
    
}

int readGraph(ifstream& fin, int**& edgeList, double*& weights, int& numEdges, string*& vLabels, string*& eLabels)
{
    int numVert;
    
    fin >> numVert;
    fin >> numEdges;
    
    edgeList = new int*[numEdges];
    weights = new double[numEdges];
    vLabels = new string[numVert];
    eLabels = new string[numEdges];
    
    string vertName;
    for(int i = 0; i<numVert; i++)
    {
        fin >> vertName;
        vLabels[i] = vertName;
    }
    
    for(int i = 0; i < numEdges; i++)
    {
        int* edgeArr = new int[2];
        int s;
        int d;
        fin>>s;
        fin>>d;
        edgeArr[0] = s;
        edgeArr[1] = d;
        edgeList[i] = edgeArr;
        
        double w;
        fin >> w;
        weights[i] = w;

        string l;
        fin>>l;
        eLabels[i] = l;
    }
    
    return numVert;
    
}
