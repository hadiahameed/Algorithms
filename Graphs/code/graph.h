#include <iostream>
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <set>

using namespace std;

class Graph
{
    private:
        // Total number of nodes
        int nodes;
        // [nodes x nodes] adjacency matrix
        int **matrix;
        // Helper funciton for dfs, takes a start node and a set of visited nodes as args
        void dfs(int, set<int>*);
        // Helper funciton for bfs, takes a start node and a set of visited nodes as args
        void bfs(int, set<int>*);

    public:
        // Creates a graph of size param1
        Graph(int);

        // Creates a graph from an adjacency matrix of size param2
        Graph(int**, int);
        ~Graph();

        // Sets the value of the edge (param1, param2) to param3
        bool set_edge(int, int, int);

        // Runs a dfs from the starting vertex
        void dfs(int);

        // Runs a bfs from the starting vertex
        void bfs(int);

        //Display the Adjacency Matrix
        void display() {
            for (int i = 0; i < nodes; i++){
                for (int j = 0; j < nodes; j++){
                    cout<<matrix[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};

#endif
