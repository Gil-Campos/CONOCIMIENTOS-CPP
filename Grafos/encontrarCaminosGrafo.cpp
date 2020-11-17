#include <iostream>
#include <list>

using namespace std;

int V = 0; //Numero de vertices
list<int>* adj; //Puntero al arreglo de la lista de adyacencia

//Prototipo de funciones
void agregarBorde(int u, int v);
void imprimirTodosLosCaminos(int s, int d);
void imprimirTodosLosCaminosUtil(int, int, bool[], int[], int&); //Funcion recursiva utilizada por imprimitTodosLosCaminos

int main()
{
    V = 4;
    adj = new list<int>[V];

    agregarBorde(0, 1); 
    agregarBorde(0, 2); 
    agregarBorde(0, 3); 
    agregarBorde(2, 0); 
    agregarBorde(2, 1); 
    agregarBorde(1, 3); 

    int s = 2, d = 3; 
    cout << "Los siguientes son todos caminos diferentes de " << s << " a " << d << endl; 
    imprimirTodosLosCaminos(s, d);

    return 0;
}

void agregarBorde(int u, int v)
{
    //Agregar v a la lista de u
    adj[u].push_back(v);
}

//Imprime todos los caminos de 's' a 'd'
void imprimirTodosLosCaminos(int s, int d)
{
    //Marcar todos los vertices como no visitados
    bool* visited = new bool[V];

    //Crear arreglo para guardar los caminos
    int* path = new int[V];
    
    //Inicializa path[] como vacio
    int path_index = 0;

    //Inicializa todos los vertices como no visitados
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    
    //Llama la funcion recursiva auxiliar para imprimir todos las rutas
    imprimirTodosLosCaminosUtil(s, d, visited, path, path_index);
}

void imprimirTodosLosCaminosUtil(int u, int d, bool visited[], int path[], int& path_index)
{
    //Marca el nodo actual y lo almacena en path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    //Si el actual vertice es el mismo que el destino, entonces imprime el path[] actual
    if (u == d)
    {
        for (int i = 0; i < path_index; i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    } 
    else //Si el actual vertice no es el destino 
    {
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            if (!visited[*i])
            {
                imprimirTodosLosCaminosUtil(*i, d, visited, path, path_index);
            } 
        }
    }

    //Remover el actual vertice de path[] y marcarlo como visitado
    path_index--;
    visited[u] = false;
}