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
    cin >> u;
    while (u != cin.eof())
    {
        checkInput(u, n);
        cin >> v;
        if (v != cin.eof())
        {
            checkInput(v, n);
        }

        q.enqueue(v);
        g.addEdge(u, v);

        cout << u << "," << v << endl;
        cin >> u;
    }

    Graph* gt = Graph::getGTranspose(g);
    cout << "this is G: " << endl << g << endl;
    cout << "this is G transpose: " << endl << *(gt) << endl;

    try {
        cout << "this is Queue q: " << endl;
        while (!(q.isEmpty())) {
            int temp = q.dequeue();
            cout << temp << ", ";
        }
    }
    catch (out_of_range e) {
        cout << "queue is empty";
    }
}