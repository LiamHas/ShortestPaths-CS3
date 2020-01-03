

#include <stdio.h>
#include <iostream>
#include <fstream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "readGraph.hpp"

TEST_CASE("Testing readGraph for matrix")
{
    SECTION("Testing readGraph with graph.txt")
    {
        ifstream fin("graph.txt");
        double** matrix;
        string* vLabels;
        string** eLabels;

        int vert = readGraph(fin, matrix, vLabels, eLabels);
        
        cout<<"-----------matrix---------------"<<endl;
        
        for(int i = 0; i<vert;i++)
        {
            for(int j = 0; j<vert;j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"---------eLabels-----------"<<endl;
        for(int i = 0; i<vert;i++)
        {
            for(int j = 0; j<vert;j++)
            {
                if(eLabels[i][j] != "")
                {
                    cout<<i<<" "<<j<<" ";
                    cout<<eLabels[i][j]<<" ";

                }
            }
            cout<<endl;
        }
        cout<<"---------vLabels-----------"<<endl;
        for(int i = 0; i<vert;i++)
        {
            cout<<vLabels[i]<<" ";
        }
        cout<<endl;

    }
}

TEST_CASE("Testing readGraph for adjList")
{
    SECTION("Testing readGraph with graph.txt")
    {
        ifstream fin("graph.txt");
        int** adj;
        double** weights;
        int* lengths;
        string* vLabels;
        string** eLabels;
        
        int vert = readGraph(fin, adj, weights, lengths, vLabels, eLabels);
        
        vert = 4;
        
        cout<<"-----------adj---------------"<<endl;
        for(int i = 0; i<vert;i++)
        {
            for(int j = 0; j<lengths[i];j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"-----------weights---------------"<<endl;
        for(int i = 0; i<vert;i++)
        {
            for(int j = 0; j<lengths[i];j++)
            {
                cout<<weights[i][j]<<" ";
            }
            cout<<endl;
        }
        
        cout<<"---------eLabels-----------"<<endl;
        for(int i = 0; i<vert;i++)
        {
            for(int j = 0; j<lengths[i];j++)
            {
                if(eLabels[i][j] != "")
                {
                    cout<<eLabels[i][j]<<" ";
                    
                }
            }
            cout<<endl;
        }
        
        cout<<"---------lengths-----------"<<endl;
        for(int i = 0; i<vert;i++)
        {
            cout<<lengths[i]<<" ";
        }
        cout<<endl;
        cout<<"---------vLabels-----------"<<endl;
        for(int i = 0; i<vert;i++)
        {
            cout<<vLabels[i]<<" ";
        }
    }
    cout<<endl;
}

TEST_CASE("Testing readGraph for Edge List")
{
    ifstream fin("graph.txt");
    int** edgeList;
    double* weights;
    int numEdges;
    string* vLabels;
    string* eLabels;
    
    int vert = readGraph(fin, edgeList, weights, numEdges, vLabels, eLabels);
    
    cout<<"numEdges: "<<numEdges<<endl;
    cout<<"vert: "<<vert<<endl;
    cout<<"-----------edgeList---------------"<<endl;
    for(int i = 0; i<numEdges;i++)
    {
        cout<<"edgeList[" << i << "] ";
        for(int j = 0; j<2;j++)
        {
            cout<<edgeList[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"---------weights-----------"<<endl;
    for(int i = 0; i<numEdges;i++)
    {
        cout<<weights[i]<<" ";
    }
    cout<<endl;
    
    cout<<"---------vLabels-----------"<<endl;
    for(int i = 0; i<vert;i++)
    {
        cout<<vLabels[i]<<" ";
    }
    cout<<endl;
    
    cout<<"---------eLabels-----------"<<endl;
    for(int i = 0; i<numEdges;i++)
    {
        cout<<eLabels[i]<<" ";
    }
    cout<<endl;
    
  

}
