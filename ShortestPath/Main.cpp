#include "Util.h"
#include "Graph.h"
#include "Queue.h"

Graph& shortestPathsGraph(int s, int t, Graph& g);

void main()
{

    int n;  //number of vertexes in G
    int s;  //start vertex for shortest path algorithm
    int t;  //target vertex for shortest path algorithm 
    int u;  //origin vertex
    int v;  //destination vertex
    cin >> n; 
    checkN(n);  //check if valid input
    cin >> s;
    checkInput(s, n);   //check if start vertex in G
    cin >> t;           
    checkInput(t, n);   //check if target vertex in G

    Graph g(n);         //create G graph
    
    while (cin >> u)    //check if input is eof (^Z)
    {
        checkInput(u, n);
        if (cin >> v)   
        {
            checkInput(v, n);
        }
        else
        {
            cout << "invalid input" << endl;
            exit(1);
        }

        g.addEdge(u, v);
    }

    Graph h = shortestPathsGraph(s, t, g);
    cout << h;      //print shortest path graph
    printRunTimeToFile(shortestPathsGraph,"shortestPathsGraph", s, t, g);
}


Graph& shortestPathsGraph(int s, int t, Graph& g) {

    int* d = g.BFS(Vertex(s));      //create bfs array
    Graph* gs = Graph::getGs(g, d); //create Gs graph
    Graph* gst = Graph::getGTranspose(*gs); //create Gs transpose
    int* d_gst = gst->BFS(Vertex(t));       //create bfs array for Gst
    Graph* ht = Graph::getGs(*(gst), d_gst); //create Gs for Gst
    Graph* h = Graph::getGTranspose(*ht);    //create shortest paths graph
    delete gs;
    delete gst;
    delete ht;
    delete[] d;
    delete[] d_gst;
    return *h;
}