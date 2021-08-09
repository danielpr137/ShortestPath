#include "Util.h"

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

    cin >> u;
    while (u != cin.eof())
    {
        checkInput(u, n);
        cin >> v;
        if (v != cin.eof())
        {
            checkInput(v, n);
        }
        cout << u << "," << v << endl;
        cin >> u;
    }
}