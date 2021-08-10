#include "Util.h"
#include "Graph.h"

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
    cin >> u;
    while (u != cin.eof())
    {
        checkInput(u, n);
        cin >> v;
        if (v != cin.eof())
        {
            checkInput(v, n);
        }

        g.addEdge(u, v);

        cout << u << "," << v << endl;
        cin >> u;
    }

    Graph* gt = Graph::getGTranspose(g);
    cout << "this is G: " << endl << g << endl;
    cout << "this is G transpose: " << endl << *(gt);
}