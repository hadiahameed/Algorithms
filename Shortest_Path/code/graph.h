#ifndef __AM_GRAPH_H__
#define __AM_GRAPH_H__

#include <limits.h>
#include "random_generator.h"

#include <iostream>

using namespace std;
    
class graph
{
  protected:

    // Total number of nodes
    int		no_vert;
    // [nodes x nodes] adjacency matrix
    int**	m_edge;
    // Total number of edges
    int no_edges;
    // value for the weight interval [-w,w]
    int weights;
    //Shortest distances for each node from the source node
    int *dist;
    //parent of each node
    int *parent;


  public:
  // Creates a graph of size param1
     graph(int);
  // Creates a graph of size param1, edges param2, and weights between [-param3, param3]
    graph(int, int, int);
    ~graph();

  // Sets the value of the edge (param1, param2) to param3
    bool set_edge(int, int, int);


    int get_no_of_vertices()
      { return no_vert; }

    void output();
  /*Computes single-source shortest paths from source node param1
    Prints the edges that are relaxed and distances that are updated*/
    bool bellmanFord(int);

  /*Computes all-pairs shortest paths
    Prints the shortest path and predecessor matrix*/
    void floyd_warshall();

  //Generates a random graph
    void random_graph();


  protected:
    void initialize();
    void permutation(int*, int);
    bool edges_complete();

    void init_single_source(int);
    void relax(int, int, int);
    void output_matrix(int**);
};

#endif
