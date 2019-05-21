#include "limits.h"
#include "graph.h"
#include <list>
#include <iostream>

using namespace std;

/*
 * constructor 1
 */
graph::graph(int n, int m, int w)
{ /*<<<*/
  if (n < 2)
  {
    cout << "No. of vertices should be more than 1" << endl;
    return;
  }
  else
  {
    no_vert = n;
  }

  int max_edges = n * n - n;
  if (m < 1)
  {
    cout << "No. of edges cannot be less than 1" << endl;
    return;
  }
  if (m > (max_edges))
  {
    cout << "No. of edges cannot be more than (n*n - n) : " << max_edges << endl;
    return;
  }
  else
  {
    no_edges = m;
  }
  weights = w;

  /*
 * allocate adjacency matrix
 */
  m_edge = new int *[no_vert];

  for (int i = 0; i < no_vert; i++)
    m_edge[i] = new int[no_vert];

  initialize();

  dist = new int[no_vert];
  parent = new int[no_vert];
} /*>>>*/

/*
 * constructor 2
 */
graph::graph(int n)
{ /*<<<*/
  if (n < 1)
  {
    cout << "Please enter 1 or more number of nodes." << endl;
    return;
  }
  no_vert = n; //number of nodes in the graph
  m_edge = new int *[no_vert];

  //Initializing the adjacency matrix with zeros
  for (int i = 0; i < no_vert; i++)
  {
    m_edge[i] = new int[no_vert];
  }

  initialize();
  dist = new int[no_vert];
  parent = new int[no_vert];
} /*>>>*/

/*
 * destructor
 */

graph::~graph()
{ /*<<<*/
  /*
 * delete nil element and all other allocated nodes
 */
  for (int i = 0; i < no_vert; i++)
  {
    delete[] m_edge[i];
  }
  delete[] m_edge;

  delete[] dist;
  delete[] parent;

} /*>>>*/

/*
 * initialize adjacency matrix
 */
void graph::initialize()
{ /*<<<*/
  /*
 * initialize adjacency matrix
 * -> use infinity to allow 0 weight edges
 */
  for (int i = 0; i < no_vert; i++)
  {
    for (int j = 0; j < no_vert; j++)
    {
      m_edge[i][j] = INT_MAX;
    }
  }

} /*>>>*/

/*
 * set edges in case of static graph
 */
bool graph::set_edge(int u, int v, int w)
{ /*<<<*/
  if (u > no_vert - 1 || v > no_vert - 1 || u < 0 || v < 0)
  {
    cout << "Please enter valid nodes." << endl;
    return false;
  }
  else
  {
    m_edge[u][v] = w;
    return true;
  }
} /*>>>*/

/*
 * initialization for Bellman-Ford
 */

void graph::init_single_source(int s)
{ /*<<<*/
  if (s > no_vert - 1 || s < 0)
  {
    cout << "Invalid source node." << endl;
    return;
  }
  for (int i = 0; i < no_vert; i++)
  {
    dist[i] = INT_MAX;
    parent[i] = INT_MAX;
  }
  dist[s] = 0;
} /*>>>*/

/*
 * relax edges for for Bellman-Ford
 */
void graph::relax(int u, int v, int w)
{ /*<<<*/
  if (u > no_vert - 1 || v > no_vert - 1 || u < 0 || v < 0)
  {
    cout << "Invalid nodes." << endl;
    return;
  }
  if (dist[u] != INT_MAX)
  {
    if (dist[v] > (dist[u] + w))
    {
      cout << "-------------------------" << endl;
      cout << "Relaxing Edge (" << u << "," << v << "):" << endl;
      dist[v] = dist[u] + w;
      cout << "Changing distance of Vertex[" << v << "] to : " << dist[v] << endl;
      parent[v] = u;
    }
  }
} /*>>>*/

/*
 * Bellman-Ford Algorithm for single-source shortest path
 */

//RUNNING TIME = O(VE)
bool graph::bellmanFord(int s)
{ /*<<<*/
  if (s > no_vert - 1 || s < 0)
  {
    cout << "Please enter a valid source node." << endl;
    return false;
  }
  //Takes O(V) time (Big O of E)
  init_single_source(s);

  //Takes O(VE) time (Big O of VE)
  for (int k = 0; k < no_vert - 1; k++)
  {
    cout << endl;
    cout << "Pass : " << k << endl;
    int i = s + 1;
    int count = 0;
    while (count < no_vert)
    {
      i = i % no_vert;
      //Takes ~O~(E) (theta of E)
      for (int j = 0; j < no_vert; j++)
      {
        if (m_edge[i][j] != INT_MAX)
        {
          relax(i, j, m_edge[i][j]);
        }
      }
      i = i + 1;
      count = count + 1;
    }
  }

  //Takes ~O~(E) (theta of E)
  for (int i = 0; i < no_vert; i++)
  {
    for (int j = 0; j < no_vert; j++)
    {
      if (m_edge[i][j] != INT_MAX)
      {
        if (dist[j] > dist[i] + (m_edge[i][j]))
        {
          return false;
        }
      }
    }
  }
  return true;
} /*>>>*/

/*
 * Floyd-Warshall Algorithm for all-pairs shortest path
 */

void graph::floyd_warshall()
{ /*<<<*/
  int **D = new int *[no_vert];
  int **P = new int *[no_vert];

  for (int i = 0; i < no_vert; i++)
  {
    D[i] = new int[no_vert];
    P[i] = new int[no_vert];
  }

  for (int i = 0; i < no_vert; i++)
    for (int j = 0; j < no_vert; j++)
    {
      if (i != j && m_edge[i][j] < INT_MAX)
      {
        P[i][j] = i;
      }
      else
      {
        P[i][j] = INT_MAX;
      }
    }

  for (int i = 0; i < no_vert; i++)
    for (int j = 0; j < no_vert; j++)
      if (i != j)
        D[i][j] = m_edge[i][j];
      else
        D[i][j] = 0;

  for (int k = 0; k < no_vert; k++)
  {
    for (int i = 0; i < no_vert; i++)
    {
      for (int j = 0; j < no_vert; j++)
      {
        if (D[i][k] != INT_MAX && D[k][j] != INT_MAX)
        {
          if (D[i][k] + D[k][j] < D[i][j])
          {
            D[i][j] = D[i][k] + D[k][j];
            P[i][j] = P[k][j];
          }
        }
      }
    }
  }

  //Print the shortest path matrix D^(n)
  cout << "Floyd-Warshall: Shortest Distance Matrix:" << endl;
  output_matrix(D);
  cout << "Floyd-Warshall: Predecessor Matrix:" << endl;
  output_matrix(P);

  //Deallocating memory
  for (int i = 0; i < no_vert; i++)
  {
    delete[] D[i];
    delete[] P[i];
  }
  delete[] D;
  delete[] P;

} /*>>>*/

/*
 * generate a random graph
 */
void graph::random_graph()
{ /*<<<*/
  /*
 * creates a random graph with n vertices and m edges
 */
  random_generator rg;
  int *perm = new int(no_vert);
  while (!edges_complete())
  {
    permutation(perm, no_vert);
    int i = 0;
    while (i < (no_vert - 2) && !edges_complete())
    {
      int v1 = perm[i];
      int v2 = perm[i + 1];
      if (m_edge[v1][v2] == INT_MAX)
      {
        random_generator rg;
        int randomWeight = 0;
        rg >> randomWeight;
        int w = weights;
        randomWeight = randomWeight % (2 * w + 1) + (-w);

        //randomWeight = (-1 * w) + (randomWeight % (2 * w + 1));
        m_edge[v1][v2] = randomWeight;
      }
      i = i + 1;
    }
  }
  delete perm;
} /*>>>*/

/*
 * check if all paths add up to m edges
 */
bool graph::edges_complete()
{ /*<<<*/
  int count = 0;
  for (int i = 0; i < no_vert; i++)
    for (int j = 0; j < no_vert; j++)
      if (m_edge[i][j] != INT_MAX)
        count = count + 1;

  if (count == no_edges)
    return true;
  else
    return false;
} /*>>>*/

/*
 * for creating random paths
 */
void graph::permutation(int *perm, int n)
{ /*<<<*/
  random_generator rg;
  int p_tmp, p_pos;

  for (int i = 0; i < n; i++)
    perm[i] = i;

  for (int i = 0; i < n; i++)
  {
    rg >> p_pos;
    p_pos = (p_pos % (n - i)) + i;

    p_tmp = perm[i];
    perm[i] = perm[p_pos];
    perm[p_pos] = p_tmp;
  }
} /*>>>*/

/*
 * display the adjacency matrix
 */
void graph::output()
{ /*<<<*/
  cout << endl;
  cout << "[";
  for (int i = 0; i < no_vert; i++)
  {
    cout << "[\t";
    for (int j = 0; j < no_vert; j++)
      if (m_edge[i][j] == INT_MAX)
        cout << "Inf\t";
      else
        cout << m_edge[i][j] << "\t";
    cout << "]" << endl;
  }
  cout << "]" << endl;
  cout << endl;
} /*>>>*/

/*
 * display any nxn matrix
 */
void graph::output_matrix(int **D)
{ /*<<<*/
  cout << endl;
  cout << "[";
  for (int i = 0; i < no_vert; i++)
  {
    cout << "[\t";
    for (int j = 0; j < no_vert; j++)
      if (D[i][j] == INT_MAX)
        cout << "Inf\t";
      else
        cout << D[i][j] << "\t";
    cout << "]" << endl;
  }
  cout << "]" << endl;
  cout << endl;
} /*>>>*/
