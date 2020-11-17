#include <iostream>

using namespace std;

//Almacena los elementos de la lista de adyacencia
struct adjNode
{
    int val;
    int cost;
    adjNode* next;
};

//Almacena las esquinas
struct grapEdge
{
    int start_ver;
    int en_ver;
    int weight;
};

//Lista de adyacencia como arreglo de punteros
adjNode **head;

//Prototipo de funciones
adjNode* getAdjListNode(int value, int weight, adjNode* head);
void diaGraph(grapEdge edges[], int n, int N);
void displayAdjList(adjNode* ptr, int i);

int main()
{
    //Arreglo de aristas del grafo
    //(x, y, w) -> borde de x a y con peso w
    grapEdge edges[] = {{0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}};

    //Numero de vertices en el grafo
    int verNum = 6;

    //Calcular numero de bordes
    int n = sizeof(edges)/sizeof(edges[0]);

    //Construir el grafo
    diaGraph(edges, n, verNum);

    //Imprimir lista de adyacencia representando el grafo
    cout << "Lista de adyacencia del grafo" << endl << "(vertice_inicio, vertice_fin, peso):"<<endl;
    for (int i = 0; i < verNum; i++)
    {
        //Mostrar vertices adyacentes del vertice i
        displayAdjList(head[i], i);
    }
    
    return 0;
}

//Inserta nuevos nodos en la lista de adyacencia de un grafo
adjNode* getAdjListNode(int value, int weight, adjNode* head)
{
    adjNode* newNode = new adjNode;
    newNode->val = value;
    newNode->cost = weight;

    //Apuntar nuevo nodo a la actual cabeza
    newNode->next = head;
    
    return newNode;
}

void diaGraph(grapEdge edges[], int n, int N)
{
    //Asignar nuevo nodo
    head = new adjNode*[N];

    //Inicializar el puntero cabeza para todo los vertices
    for (int i = 0; i < N; i++)
    {
        head[i] = NULL;
    }

    //Construir grafo dirigido añadiendole aristas
    for (int i = 0; i < n; i++)
    {
        int start_ver = edges[i].start_ver;
        int end_ver = edges[i].en_ver;
        int weight = edges[i].weight;

        //Insertar al inicio
        adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);

        //Apunta el puntero de la cabeza al nuevo nodo
        head[start_ver] = newNode;
    }
}

void displayAdjList(adjNode* ptr, int i)
{
    while (ptr != NULL)
    {
        cout << "(" << i << ", " << ptr->val << ", " << ptr->cost << ") ";
        ptr = ptr->next;
    }
    cout << endl;
}
