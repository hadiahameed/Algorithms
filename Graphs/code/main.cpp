
#include "graph.h"

int main()
{
    /*
        BFS TEST CASE
    */

   //BFS Book Example
    Graph* bfs_graph;
    int bfs_nodes = 8;
    cout<<"---------------------"<<endl;
    cout<<"Using Constructor 1: BFS"<<endl;
    cout<<"---------------------"<<endl;
    int **bfs_matrix = new int*[bfs_nodes];;
    for (int i = 0; i < bfs_nodes; i++){
        bfs_matrix[i] = new int[bfs_nodes];
        for (int j = 0; j < bfs_nodes; j++)
        {
            bfs_matrix[i][j] = 0;
        }
    }
    bfs_matrix[0][1] = 1;
    bfs_matrix[0][2] = 1;
    bfs_matrix[1][0] = 1;
    bfs_matrix[1][3] = 1;
    bfs_matrix[1][4] = 1;
    bfs_matrix[2][0] = 1;
    bfs_matrix[2][5] = 1;
    bfs_matrix[3][1] = 1;
    bfs_matrix[3][4] = 1;
    bfs_matrix[3][6] = 1;
    bfs_matrix[4][1] = 1;
    bfs_matrix[4][3] = 1;
    bfs_matrix[4][6] = 1;
    bfs_matrix[4][7] = 1;
    bfs_matrix[5][2] = 1;
    bfs_matrix[6][3] = 1;
    bfs_matrix[6][4] = 1;
    bfs_matrix[6][7] = 1;
    bfs_matrix[7][4] = 1;
    bfs_matrix[7][6] = 1;

    bfs_graph = new Graph(bfs_matrix,bfs_nodes);
    bfs_graph->bfs(0);
    for (int i = 0; i < bfs_nodes; i++)
        delete[] bfs_matrix[i];
    delete[] bfs_matrix;
    delete bfs_graph;
    
    cout<<"---------------------"<<endl;
    cout<<"Using Constructor 2: BFS"<<endl;
    cout<<"---------------------"<<endl;

    bfs_graph = new Graph(bfs_nodes);
    
    //s-w
    bfs_graph->set_edge(0,1,1);
    bfs_graph->set_edge(1,0,1);
    //s-r
    bfs_graph->set_edge(0,2,1);
    bfs_graph->set_edge(2,0,1);
    //r-v
    bfs_graph->set_edge(2,5,1);
    bfs_graph->set_edge(5,2,1);
    //w-t
    bfs_graph->set_edge(1,3,1);
    bfs_graph->set_edge(3,1,1);
    //t-x
    bfs_graph->set_edge(3,4,1);
    bfs_graph->set_edge(4,3,1);
    //w-x
    bfs_graph->set_edge(1,4,1);
    bfs_graph->set_edge(4,1,1);
    //t-u
    bfs_graph->set_edge(3,6,1);
    bfs_graph->set_edge(6,3,1);
    //x-u
    bfs_graph->set_edge(4,6,1);
    bfs_graph->set_edge(6,4,1);
    //u-y
    bfs_graph->set_edge(6,7,1);
    bfs_graph->set_edge(7,6,1);
    //x-y
    bfs_graph->set_edge(4,7,1);
    bfs_graph->set_edge(7,4,1);

    bfs_graph->bfs(0);
    delete bfs_graph;

    /*
        DFS TEST CASE
    */

    //DFS Book Example

    Graph* dfs_graph;
    int dfs_nodes = 6;

    cout<<"---------------------"<<endl;
    cout<<"Using Constructor 1: DFS"<<endl;
    cout<<"---------------------"<<endl;
    int **dfs_matrix = new int*[dfs_nodes];;
    for (int i = 0; i < dfs_nodes; i++){
        dfs_matrix[i] = new int[dfs_nodes];
        for (int j = 0; j < dfs_nodes; j++)
        {
            dfs_matrix[i][j] = 0;
        }
    }
    dfs_matrix[0][3] = 1;
    dfs_matrix[1][3] = 1;
    dfs_matrix[1][5] = 1;
    dfs_matrix[2][0] = 1;
    dfs_matrix[3][2] = 1;
    dfs_matrix[4][0] = 1;
    dfs_matrix[4][2] = 1;
    dfs_matrix[5][5] = 1;

    //Creating a graph for DFS using constructor 1
    dfs_graph = new Graph(dfs_matrix,dfs_nodes);

    //Calling DFS using constructor 1
    dfs_graph->dfs(4);

    //Deleting dynamically created elements
    for (int i = 0; i < dfs_nodes; i++)
        delete[] dfs_matrix[i];
    delete[] dfs_matrix;
    delete dfs_graph;

    cout<<"---------------------"<<endl;
    cout<<"Using Constructor 2: DFS"<<endl;
    cout<<"---------------------"<<endl;
    dfs_graph = new Graph(dfs_nodes);
    dfs_graph->set_edge(0,3,1);
    dfs_graph->set_edge(1,3,1);
    dfs_graph->set_edge(1,5,1);
    dfs_graph->set_edge(2,0,1);
    dfs_graph->set_edge(3,2,1);
    dfs_graph->set_edge(4,0,1);
    dfs_graph->set_edge(4,2,1);
    dfs_graph->set_edge(5,5,1);

    //Calling DFS using constructor 2
    dfs_graph->dfs(4);

    //Deleting dynamically created elements
    delete dfs_graph;

    return 0;
}
