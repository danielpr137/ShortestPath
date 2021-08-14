/*
This Program creates the shortest paths graph from an input graph. 
It gets the number of vertexes, starting and target vertexes, and the edges from the user.
    1) First, the user will enter the number of vertexes of the requested graph (a positive integer).
    2) After pressing 'space' or 'Enter' the next input will be the starting vertex, and the target vertex for the requested path.
    3) The next input will be the edges in the garph - pairs of integers, an origin vertex and destination vartex seperated with space or enter.
The program will check the input and create the shortest paths graph (explanation documented in the algorithm).
*/
#include "Util.h"
#include "Graph.h"
#include "Queue.h"

Graph& shortestPathsGraph(int s, int t, Graph& g);

int main()
{
    int n;  //number of vertexes in G
    int s;  //start vertex for shortest path algorithm
    int t;  //target vertex for shortest path algorithm 

    cin >> n; 
    checkN(n);  //check if valid input
    cin >> s;
    checkInput(s, n);   //check if start vertex in G
    cin >> t;           
    checkInput(t, n);   //check if target vertex in G

    Graph g;            //create G graph
    g.readGraph(n);

    Graph h = shortestPathsGraph(s, t, g);
    cout << h;      //print shortest path graph
    printRunTimeToFile(shortestPathsGraph,"shortestPathsGraph", s, t, g);
    return 0;
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