#include <iostream>

#include "graph.h"
#include "random_generator.h"

using namespace std;

int main(int argc, char *argv[])
{
    int n, m, w;
  
  if (argc == 4)
    { 
      n = atoi(argv[1]);
      if (n<2) {
          cout<<"No. of vertices should be more than 1"<<endl;
          return 0;
      }
      int max_edges = n*n - n;
      m = atoi(argv[2]);
      if (m<1) {
          cout<<"No. of edges cannot be less than 1"<<endl;
          return 0;
      }
      if (m>(max_edges)) {
          cout<<"No. of edges cannot be more than (n*n - n) = "<<max_edges<<" to avoid self-directed cycles"<<endl;
          return 0;
      }

      w = atoi(argv[3]);

    }
  else
    {
      cout << "hw7: [n] [m] [w]" << endl;
      cout << "[n]              no. of vertices in the graph" << endl;
      cout << "[m]              no. of edges in the graph" << endl;
      cout << "[w]              interval [-w,w] for weights" << endl;
      cout << endl;
      return 0;
    }

    graph* rm_graph = new graph(n,m,w);
    rm_graph->random_graph();
    rm_graph->output();


    delete rm_graph;


    /*
        Bellman-Ford TEST CASE
    */

   //BF Book Example
    graph* bf_graph;
    int bf_nodes = 5;
    bf_graph = new graph(bf_nodes);
    

    bf_graph->set_edge(0,1,6);
    bf_graph->set_edge(0,3,7);

    bf_graph->set_edge(1,2,5);
    bf_graph->set_edge(1,3,8);
    bf_graph->set_edge(1,4,-4);
   
    bf_graph->set_edge(2,1,-2);

    bf_graph->set_edge(3,2,-3);
    bf_graph->set_edge(3,4,9);
    
    bf_graph->set_edge(4,0,2);
    bf_graph->set_edge(4,2,7);

    cout<<"----------------------------"<<endl;
    cout<<"BELLMAN-FORD ALGORITHM"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"Input Graph"<<endl;
    bf_graph->output();
    bool neg_cycle = bf_graph->bellmanFord(0);

    if(neg_cycle){
        cout<<"-------------------------------"<<endl;
        cout<<"Negative Cycle Doesn't Exist."<<endl;
        cout<<"-------------------------------"<<endl;
    }
    else {
        cout<<"-------------------------------"<<endl;
        cout<<"Negative Cycle Exists."<<endl;
        cout<<"-------------------------------"<<endl;
    }
    delete bf_graph;

    /*
        Floyd-Warshall TEST CASE
    */

   //FW Book Example
    graph* fw_graph;
    int fw_nodes = 5;
    fw_graph = new graph(fw_nodes);
    
    fw_graph->set_edge(0,1,3);
    fw_graph->set_edge(0,2,8);
    fw_graph->set_edge(0,4,-4);

    fw_graph->set_edge(1,4,7);
    fw_graph->set_edge(1,3,1);
   
    fw_graph->set_edge(2,1,4);

    fw_graph->set_edge(3,2,-5);
    fw_graph->set_edge(3,0,2);
    
    fw_graph->set_edge(4,3,6);

    cout<<"----------------------------"<<endl;
    cout<<"FLOYD-WARSHALL ALGORITHM"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"Input Graph"<<endl;
    fw_graph->output();
    fw_graph->floyd_warshall();

    
    delete fw_graph;


    return 0;
}
