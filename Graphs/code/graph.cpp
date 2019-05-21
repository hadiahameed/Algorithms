#include <iostream>
#include <queue>
#include <set>
#include "graph.h"

//constructor 1: Build graph with "number of nodes" given as an input 
Graph::Graph(int n)
{
    if ( n < 1){
        cout<<"Please enter 1 or more number of nodes."<<endl;
        return;
    }
    this->nodes = n; //number of nodes in the graph
    this->matrix = new int*[nodes];

    //Initializing the adjacency matrix with zeros
    for (int i = 0; i < nodes; i++){
        matrix[i] = new int[nodes];
        for (int j = 0; j < nodes; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

//constructor 2: Build graph with "adjacency matrix" and "number of nodes" given as an input 
Graph::Graph(int** adj, int n)
{
    if ( n < 1){
        cout<<"Please enter 1 or more number of nodes."<<endl;
        return;
    }
    this->nodes = n;
    this->matrix = new int*[nodes];
    for (int i = 0; i < nodes; i++){
        matrix[i] = new int[nodes];
        for (int j = 0; j < nodes; j++)
        {
            matrix[i][j] = adj[i][j];
        }
    }
}

Graph::~Graph()
{
  for (int i = 0; i < nodes; i++)
    delete[] matrix[i];
  delete[] matrix;

}

bool Graph::set_edge(int u, int v, int w) 
{
    if ( u > nodes-1 || v > nodes-1 || u < 0 || v < 0){
        cout<<"Please enter valid nodes."<<endl;
        return false;
    }
    else {
        matrix[u][v] = w;
        return true;
    }

}

void Graph::bfs(int s)
{ 
    if ( s > nodes - 1 || s < 0 ){
        cout<<"Please enter a valid start node for BFS."<<endl;
        return;
    }
    set <int>* visited;
    bfs(s,visited);

}

void Graph::bfs(int s, set<int>* visited) {
    visited = new set<int>;
    queue <int> Q;
    visited->insert(s);
    cout<<endl;
    cout<<"*********************"<<endl;
    cout<<"Breadth First Tree:"<<endl;
    cout<<"*********************"<<endl;
    cout<<"Order in which the nodes are visited: "<<endl;
    cout<<s<<"->";
    Q.push(s);
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < nodes; i++){
            if (matrix[u][i] > 0 && visited->count(i)==0) {
                visited->insert(i);
                if(i==nodes-1) cout<<i;
                else cout<<i<<"->";
                Q.push(i);
            }
        }
    }
    cout<<endl;
    cout<<"--------------------------"<<endl;
    delete visited;
}

void Graph::dfs(int s)
{ 
    if ( s > nodes - 1 || s < 0 ){
        cout<<"Please enter a valid start node for DFS."<<endl;
        return;
    }
    set <int>* visited;
    visited = new set<int>;
    cout<<endl;
    cout<<"*********************"<<endl;
    cout<<"Depth First Tree"<<endl;
    cout<<"*********************"<<endl;
    cout<<"Order in which the nodes are visited: "<<endl;
    dfs(s,visited);
    for (int u = 0; u < nodes; u++){
        if (visited->count(u)==0) {
            dfs(u,visited);
        }
    }
    cout<<endl;
    cout<<"--------------------------"<<endl;
    delete visited;
    
}

void Graph::dfs(int s, set<int>* visited) {
    cout<<s<<endl;
    visited->insert(s);
    for (int i = 0; i < nodes; i++){
        if (matrix[s][i] > 0 && visited->count(i)==0) {
            dfs(i,visited);
        }
    }
}


