/*
Algoritma dan Struktur Data
Muhammad Imam Fahrudin
065121077
*/

#include <iostream>
#include <list>

using namespace std;

/*
Vertex or Vertices == node or nodes
based on linked list
*/

class Graph{
    int vertex; 
    list<int> *adjL;
    bool *visited;



public:
    Graph(int vertices){
        vertex = vertices;
        adjL = new list<int>[vertices];
        visited = new bool[vertices];

        for(int i = 0; i < vertices; i++){
            visited[i] = false;
        }
    }

    void addEdge(int source, int dest){
    adjL[source].push_back(dest);
    adjL[dest].push_back(source);
}


void DFS(int vertex){
    visited[vertex] = true;

    list<int> adjList = adjL[vertex];

    cout << vertex << " ";


    for(auto i = adjList.begin(); i != adjList.end(); i++){
        if(visited[*i]){
            continue;
        }
        DFS(*i);
    }
}
};
int main(){
    Graph g(6);

 //vertex 0 can be reached from vertex 1, vertex 2, vertex 5
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,5);

//vertex 1 can be reached from vertex 0, vertex 5, vertex 4
    g.addEdge(1,0);
    g.addEdge(1,5);
    g.addEdge(1,4);


//vertex 2 can be reached from vertex 0, vertex 3, vertex 5
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(2,5);

//vertex 3 can be reached from vertex 2, vertex 5, vertex 4
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.addEdge(3,5);
    

//vertex 4 can be reached from vertex 1, vertex 3, vertex 5
    g.addEdge(4,1);
    g.addEdge(4,3);
    g.addEdge(4,5);

//vertex 5 can be reached from vertex 0, vertex 1, vertex 2, vertex 3, vertex 4

    g.addEdge(5,0);
    g.addEdge(5,1);
    g.addEdge(5,2);
    g.addEdge(5,3);
    g.addEdge(5,4);


    cout << "Depth First Search: ";

    g.DFS(5);
    



}