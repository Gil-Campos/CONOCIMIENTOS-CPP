#include <iostream>
#include <string>

using namespace std;

//Tipo de dato que contendran los nodos de la Cola
typedef char T;
const T noValido = ' ';

//Registro: Nodo y cola
struct Nodo
{
    T elemento;
    struct Nodo* siguiente;
};

struct Cola
{
    Nodo* frente;
    Nodo* final;
};

//Prototipo de funciones
void initialize(Cola *q);
bool empty(Cola *q);
T front(Cola *q);
T back(Cola *q);
void enqueue(Cola *q, T x);
T dequeue(Cola *q);
int size(Cola *q);
void driver();

int main() 
{
    driver();

    return 0;
}

void driver()
{
    Cola unaCola;
    initialize(&unaCola);

    enqueue(&unaCola, 'A'); 
    enqueue(&unaCola, 'B'); 
    enqueue(&unaCola, 'C'); 
    enqueue(&unaCola, 'D'); 
    enqueue(&unaCola, 'E'); 
    
    cout << "Elementos: " << size(&unaCola) << endl;
    
    while (!empty(&unaCola)) {
        cout << "Frente: " << front(&unaCola) << '\t';
        cout << "Final: " << back(&unaCola) << endl;
        dequeue(&unaCola);
    }
}

//Implementacion de funciones
void initialize(Cola *q) 
{
    q->frente = NULL;
    q->final = NULL;
}

bool empty(Cola *q) 
{
    return (q->frente == NULL) ? true : false;
}

T front(Cola *q)
{
    if(empty(q))
    {
        cout << "Underflow!" << endl;
        return noValido;
    } 
    return (q->frente)->elemento;
}

T back(Cola *q)
{
    if (empty(q))
    {
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->final)->elemento;
}

void enqueue(Cola *q, T x)
{
    Nodo *unNodo = new Nodo;
    unNodo->elemento = x;
    unNodo->siguiente = NULL;

    if (q->final == NULL)
    {
        q->frente = unNodo;
    } 
    else
    {
        (q->final)->siguiente = unNodo;
    } 

    q->final = unNodo;
}

T dequeue(Cola *q)
{
    if (empty(q))
    {
        cout << "Underflow!" << endl;
        return noValido;
    }
    
    Nodo *unNodo = q->frente;
    T x = unNodo->elemento;
    q->frente = unNodo->siguiente;

    if (q->frente == NULL)
    {
        q->final == NULL;
    }
    
    delete(unNodo);
    return x;
}

int size(Cola *q)
{
    Cola colaTemporal;

    initialize(&colaTemporal);

    int contador = 0;

    //Transferiendo desde q  hasta colaTemporal
    while (!empty(q))
    {
        T elemento = dequeue(q);
        enqueue(&colaTemporal, elemento);
        contador++;
    }

    // Transfiriendo desde colaTemporal hasta q
    while(!empty(&colaTemporal)){
        T elemento = dequeue(&colaTemporal);
        enqueue(q, elemento);
    }

    return contador; 
}
