

#include <stdio.h>
#include <iostream>
#include <fstream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "shortestPath.hpp"
#include "readGraph.hpp"
#include "BinaryHeap.hpp"

TEST_CASE("Testing shortest path functions")
{
    SECTION("Testing dijkstra with matrix")
    {
        ifstream fin("graph.txt");
        double** matrix;
        string* vLabels;
        string** eLabels;
        
        int vert = readGraph(fin, matrix, vLabels, eLabels);
        
        double* dist;
        int* prev;
        dijkstra(matrix, vert, 0, dist, prev);
        
        
        cout<<"---------dist-----------"<<endl;
        for(int i = 0; i<vert;i++)
        {
            cout<<dist[i]<<" ";
        }
        cout<<endl<<"---------prev-----------"<<endl;
        for(int i = 0; i<vert;i++)
        {
            cout<<prev[i]<<" ";
        }
        cout<<endl;
    }
    SECTION("Testing getPath for 0")
    {
        ifstream fin("graph.txt");
        double** matrix;
        string* vLabels;
        string** eLabels;

        int vert = readGraph(fin, matrix, vLabels, eLabels);
        
        double* dist;
        int* prev;

        dijkstra(matrix, vert, 0, dist, prev);
        
        int* path;
        int* path2;
        int* path3;


        int size = getPath(0, 1, prev, path);
        int size2 = getPath(0, 2, prev, path2);
        int size3 = getPath(0, 3, prev, path3);


        cout<<endl<<"--------- path from 0-1 -----------"<<endl;
        for(int i= 0; i<size; i++)
        {
            cout<<path[i]<<" ";
        }
        
        cout<<endl<<"--------- path from 0-2 -----------"<<endl;
        for(int i= 0; i<size2; i++)
        {
            cout<<path2[i]<<" ";
        }
        
        cout<<endl<<"--------- path from 0-3 -----------"<<endl;
        for(int i= 0; i<size3; i++)
        {
            cout<<path3[i]<<" ";
            
        }
        cout<<endl;
        
        cout<<"size for 0-1: "<<size<<endl;
        cout<<"size for 0-2: "<<size2<<endl;
        cout<<"size for 0-3: "<<size3<<endl;
        
    }
    SECTION("Testing getPath for 1")
    {
        ifstream fin("graph.txt");
        double** matrix;
        string* vLabels;
        string** eLabels;
        
        int vert = readGraph(fin, matrix, vLabels, eLabels);
        
        double* dist;
        int* prev;
       
        dijkstra(matrix, vert, 1, dist, prev);
        
        cout<<"---------dist for 1-----------"<<endl;
        for(int i = 0; i<vert;i++)
        {
            cout<<dist[i]<<" ";
        }
        cout<<endl<<"---------prev for 1-----------"<<endl;
        for(int i = 0; i<vert;i++)
        {
            cout<<prev[i]<<" ";
        }
        cout<<endl;
        
        int* path;
        int* path2;
        int* path3;
        
        
        int size = getPath(1, 0, prev, path);
        int size2 = getPath(1, 2, prev, path2);
        int size3 = getPath(1, 3, prev, path3);
        
       
        
        cout<<endl<<"--------- path from 1-0 -----------"<<endl;
        for(int i= 0; i<size; i++)
        {
            cout<<path[i]<<" ";
        }
        
        cout<<endl<<"--------- path from 1-2 -----------"<<endl;
        for(int i= 0; i<size2; i++)
        {
            cout<<path2[i]<<" ";
        }
        
        cout<<endl<<"--------- path from 1-3 -----------"<<endl;
        for(int i= 0; i<size3; i++)
        {
            cout<<path3[i]<<" ";
            
        }
        cout<<endl;
        
        cout<<"size for 1-0: "<<size<<endl;
        cout<<"size for 1-2: "<<size2<<endl;
        cout<<"size for 1-3: "<<size3<<endl;
        
    }
    SECTION("Testing dijkstra with list")
    {
        ifstream fin("graph.txt");
        int** adj;
        double** weights;
        int* lengths;
        string* vLabels;
        string** eLabels;
        
        int vert = readGraph(fin, adj, weights, lengths, vLabels, eLabels);
        
        double* dist;
        int* prev;
        
        dijkstra(adj, weights, lengths, vert, 0, dist, prev);
        
        cout<<"---------dist for 0 (adj list)-----------"<<endl;
        for(int i = 0; i<vert;i++)
        {
            cout<<dist[i]<<" ";
        }
        cout<<endl<<"---------prev for 0-----------"<<endl;
        for(int i = 0; i<vert;i++)
        {
            cout<<prev[i]<<" ";
        }
        cout<<endl;
    }
    SECTION("Testing Bellman-Ford")
    {
        ifstream fin("graph2.txt");
        int** edgeList;
        double* weights;
        int numEdges;
        string* vLabels;
        string* eLabels;
        
        int vert = readGraph(fin, edgeList, weights, numEdges, vLabels, eLabels);
        
        double* dist;
        int* prev;
        
        int negCycleDet = bellmanFord(edgeList, weights, vert, numEdges, 0, dist, prev);
        
        cout<<"---------dist for 0 (B-F)-----------"<<endl;
        for(int i = 0; i<vert;i++)
        {
            cout<<dist[i]<<" ";
        }
        cout<<endl<<"---------prev for 0 (B-F)-----------"<<endl;
        for(int i = 0; i<vert;i++)
        {
            cout<<prev[i]<<" ";
        }
        cout<<endl;
        
        cout<<negCycleDet<<endl;
    }
    SECTION("Testing getCycle")
    {
        ifstream fin("graph2.txt");
        int** edgeList;
        double* weights;
        int numEdges;
        string* vLabels;
        string* eLabels;
        
        int vert = readGraph(fin, edgeList, weights, numEdges, vLabels, eLabels);
        
        double* dist;
        int* prev;
        
        int negCycleDet = bellmanFord(edgeList, weights, vert, numEdges, 0, dist, prev);
        
        int* cycle;
        
        getCycle(negCycleDet, prev, vert, cycle);
    }
    SECTION("Testing initalize")
    {
        int numVertices = 10;

        double* dist = new double[numVertices];
        int* prev = new int[numVertices];
        bool* tree = new bool[numVertices];
        int high = 10;
        int low = 0;
        int numThreads = 5;
        
        initialize(dist, prev, tree, numThreads, low, high);
        
        for(int i = 0; i < numVertices; i++)
        {
            cout<<dist[i]<<" ";
        }
        cout<<endl;
        
        for(int i = 0; i < numVertices; i++)
        {
            cout<<prev[i]<<" ";
        }
        cout<<endl;
        
        for(int i = 0; i < numVertices; i++)
        {
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }
    SECTION("Testing getMinVertex")
    {
        int numVertices = 5;
        
        double* dist = new double[numVertices];
        dist[0] = 10;
        dist[1] = 12;
        dist[2] = 4;
        dist[3] = 7;
        dist[4] = 3;


        bool* tree = new bool[numVertices];
        tree[0] = false;
        tree[1] = true;
        tree[2] = false;
        tree[3] = false;
        tree[4] = true;

        int high = 5;
        int low = 0;
        int numThreads = 3;
        double** graph;
        
        int vertex;
      
        getMinVertex(dist, tree, low, high, numThreads, &vertex);
        
        cout<<"GMV vertex: "<<vertex<<endl;
    }
    
    SECTION("Testing updateDistances")
    {
        ifstream fin("graph.txt");
        double** matrix;
        string* vLabels;
        string** eLabels;
        
        int vert = readGraph(fin, matrix, vLabels, eLabels);

        double* dist = new double[vert];
        bool* tree = new bool[vert];
        int* prev = new int[vert];

        int vertex = 0;
        
        double inf = numeric_limits<double>::infinity();
        
        for(int i = 0; i < vert; i++)
        {
            dist[i] = inf;
            prev[i] = -1;
            tree[i] = false;
        }
        
        for(int i = 0; i < vert; i++)
        {
            cout<<"[";
            for(int j = 0; j < vert; j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<"]"<<endl;
        }
        
        dist[2] = 0;
        
        updateDistances(matrix, dist, prev, tree, 2, 0, 4, 2);

        for(int i = 0; i < vert; i++)
        {
            cout<<dist[i]<<" ";
        }
        cout<<endl;
        for(int i = 0; i < vert; i++)
        {
            cout<<prev[i]<<" ";
        }
        cout<<endl;
        for(int i = 0; i < vert; i++)
        {
            cout<<tree[i]<<" ";
        }
        cout<<endl;
        
    }
    
    SECTION("Testing dijkstra with parallel helper functions")
    {
        ifstream fin("graph.txt");
        double** matrix;
        string* vLabels;
        string** eLabels;
        
        int vert = readGraph(fin, matrix, vLabels, eLabels);
        
        cout<<"vert: "<<vert<<endl;
        double* dist;
        int* prev;
        
        dijkstra(matrix, vert, 0, dist, prev, 2);
        
        for(int i = 0; i < vert; i++)
        {
            cout<<dist[i]<<" ";
        }
        cout<<endl;
        for(int i = 0; i < vert; i++)
        {
            cout<<prev[i]<<" ";
        }
        cout<<endl;
    }
}
