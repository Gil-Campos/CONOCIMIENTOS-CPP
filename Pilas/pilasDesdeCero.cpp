#include <iostream>
#include <string>

using namespace std;

/* PALABRAS A CONOCER 

1. new: El operador new pide una asignicacion de memoria. Si hay suficiente memoria disponible, el new operador inicializa y devuelce la direccion de memoria
recien asignada e inicializada a la variable puntero.

2. delete: El operador delete sirve para limpiar la memoria que fue asignada por el operador new pues queda hasta que el programador la borra (usando delete) o el programa
termina.

3. Underflow: Ocurre cuando se trata de hacer la operacion de pop sobre una pila que esta vacia.

4. Overflow: Esto sucede cuando queremos hacer push a la pila de la que puede soportar.

*/

//Definicion de nodo
struct nodo
{
    string elemento;
    struct nodo *siguiente;
};

typedef struct nodo *Pila;

//Prototipo de funciones
void initialize(Pila *s);
bool empty(Pila *s);
void push(Pila *s, string e);
string pop(Pila *s);
string top(Pila *s);
void test();

int main() {
    test();
    return 0;
}

void test() {
    Pila s;
    initialize(&s);

    cout << endl;
    cout << "-Inicio de Insta";
    cout << endl;
    cout << "-Navegando en Inta..." << endl;
    cout << endl;

    push(&s, "Tap a Insta de Juan");
    push(&s, "Tap a post 3 del Insta de Juan");
    push(&s, "Tap al like 5 (perfil de Melissa) del post 3 de Juan");
    push(&s, "Perfil de Melissa");
    push(&s, "Tap post 7 del perfil de Melissa");

    while (!empty(&s))
    {
        cout << "Retroceder desde: " << top(&s) << endl;
        pop(&s);
    }
    
    cout << endl;
    cout << "-Home de Insta" << endl;
    cout << endl; 
}

//Implementacion de funciones
void initialize(Pila *s) {
    *s = NULL;
}

bool empty(Pila *s) {
    return *s == NULL;
}

void push(Pila *s, string e) {
    struct nodo *unNodo = new struct nodo;
    unNodo->elemento = e;
    unNodo->siguiente = *s;

    *s = unNodo;
}

string pop(Pila *s) {
    if (!empty(s))
    {
        struct nodo *unNodo = *s;
        string e = (*s)->elemento;
        *s = (*s)->siguiente;
        delete(unNodo);
        return e;
    }
    else
    {
        //Underflow
        return "Underflow";
    }
    
}

string top(Pila *s) {
    if(!empty(s)) {
        return (*s)->elemento;
    } else {
        //Underflow
        return "Underflow";
    }
}