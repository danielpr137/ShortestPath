#include "Util.h"
#include "Graph.h"
#include "Queue.h"

Graph& shortestPathsGraph(int s, int t, Graph& g);

void main()
{

    int n;  //number of vertexes in G
    int s;  //start vertex for shortest path algorithm
    int t;  //target vertex for shortest path algorithm 
    int u;  //
    int v;
    cin >> n;
    checkN(n);
    cin >> s;
    checkInput(s, n);
    cin >> t;
    checkInput(t, n);

    Graph g(n);
    
    while (cin >> u)
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
    //cout.flush();

    Graph h = shortestPathsGraph(s, t, g);

    cout << "this is H:" << endl;
    cout << h;
}


Graph& shortestPathsGraph(int s, int t, Graph& g) {

    int* d = g.BFS(Vertex(s));
    Graph* gs = Graph::getGs(g, d);
    Graph* gst = Graph::getGTranspose(*gs);
    int* d_gst = gst->BFS(Vertex(t));
    Graph* ht = Graph::getGs(*(gst), d_gst);
    Graph* h = Graph::getGTranspose(*ht);    
    delete gs;
    delete gst;
    delete ht;
    delete[] d;
    delete[] d_gst;
    return *h;
}