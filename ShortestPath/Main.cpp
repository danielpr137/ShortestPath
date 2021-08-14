#include "Util.h"
#include "Graph.h"
#include "Queue.h"

Graph& shortestPathsGraph(int s, int t, Graph& g);

void main()
{

    int n;
    int s;
    int t;
   // int input;
    int u;
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

    //Graph* gt = Graph::getGTranspose(g);
    //cout << "this is G: " << endl << g << endl;
    ////cout << "this is G transpose: " << endl << *(gt) << endl;

    //try {
    //    cout << "this is Queue q: " << endl;
    //    while (!(q.isEmpty())) {
    //        int temp = q.dequeue();
    //        cout << temp << ", ";
    //    }
    //    cout << endl;
    //}
    //catch (out_of_range e) {
    //    cout << "queue is empty" << endl;
    //}

    //Vertex sVertex(s);
    //int* d = g.BFS(sVertex);

    //Graph* Gs = Graph::getGs(g, d);
    //cout << "this is Gs: " << endl << Gs << endl;


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