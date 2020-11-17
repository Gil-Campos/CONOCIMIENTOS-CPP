#include <iostream>
#include <vector>

using namespace std;

//Funcion para agregar una esquina en un grafo no dirigido
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//Lista de adyacencia para representar el grado
void printGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; ++i)
    {
        cout << endl;
        cout << "Lista de adyacencia del vertice " << v << endl;
        cout << "head";
        for (auto x : adj[i]) 
        {
            cout << "-> " << x;
        }
        cout << endl;
    }
    
}

int main()
{
    int V = 5; 
    vector<int> adj[V]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    printGraph(adj, V); 

    return 0;
}