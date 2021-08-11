#include "Util.h"
#include "Graph.h"
#include "Queue.h"

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

    Queue q;
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

        q.enqueue(v);
        g.addEdge(u, v);

    }
    cout.flush();

    //Graph* gt = Graph::getGTranspose(g);
    cout << "this is G: " << endl << g << endl;
    //cout << "this is G transpose: " << endl << *(gt) << endl;

    try {
        cout << "this is Queue q: " << endl;
        while (!(q.isEmpty())) {
            int temp = q.dequeue();
            cout << temp << ", ";
        }
        cout << endl;
    }
    catch (out_of_range e) {
        cout << "queue is empty" << endl;
    }

    Vertex sVertex(s);
    int* d = g.BFS(sVertex);

    Graph* Gs = Graph::getGs(g, d);
    cout << "this is Gs: " << endl << *(Gs) << endl;
}