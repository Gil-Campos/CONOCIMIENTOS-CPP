#include <iostream>
#include <string>

using namespace std;

//Funciones que dependen del tipo de dato de los nodos
int solicitarDato()
{
    int unDato = 0;
    cin >> unDato;
    cin.ignore();
    return unDato;
}

void mostrarDato(int unDato)
{
    cout << unDato;
}

enum comparacion
{
    menorQue,
    mayorQue,
    igualQue
};

bool comparar(int a, comparacion operador, int b)
{
    bool resultado = false;

    switch (operador)
    {
    case menorQue:
        resultado = a < b;
        break;
    case mayorQue:
        resultado = a > b;
        break;
    case igualQue:
        resultado = a == b;
        break;
    default:
        break;
    }

    return resultado;
}

//Creacion de nodo y de arbol
typedef int T;

struct Nodo
{
    T info;
    struct Nodo *izq;
    struct Nodo *der;
};

typedef struct Nodo *Arbol;

Arbol crearArbol(T x);

//Agregar nodos a un arbol
void asignarIzq(Arbol a, T unDato);
void asignarDer(Arbol a, T unDato);
void agregarNodo(Arbol a);

//Recorrer un arbol (in, pre y post orden)
void preorden(Arbol a);
void inorden(Arbol a);
void postorden(Arbol a);
void recorrerArbol(Arbol a);

int main()
{
    cout << "Inicializando arbol... \nValor contenido en la raiz: ";

    Arbol arbol = crearArbol(solicitarDato());

    bool continuar = true;

    do
    {
        int opcion = 0;
        cout << "\nMenu: \n";
        cout << "\t1) Agregar\n";
        cout << "\t2) Recorrer\n";
        cout << "\t3) Salir\n";
        cout << "\tOpcion elegida: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            agregarNodo(arbol);
            break;
        case 2:
            recorrerArbol(arbol);
            break;
        case 3:
            continuar = false;
            break;
        default:
            break;
        }
    } while (continuar);
    
    return 0;
}

//Implementacion de funciones de arboles
Arbol crearArbol(T x)
{
    Arbol p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;

    return p;
}

//Agregar nodos al arbol
void asignarIzq(Arbol a, T unDato)
{
    if (a == NULL)
    {
        cout << "Error: arbol vacio" << endl;
    }
    else if (a->izq != NULL)
    {
        cout << "Error: subarbol IZQ ya existe" << endl;
    }
    else
    {
        a->izq = crearArbol(unDato);
    }
}

void asignarDer(Arbol a, T unDato)
{
    if (a == NULL)
    {
        cout << "Error: arbol vacio" << endl;
    }
    else if (a->der != NULL)
    {
        cout << "Error: subarbol DER ya existe" << endl;
    }
    else
    {
        a->der = crearArbol(unDato);
    }
}

void agregarNodo(Arbol a)
{
    //Solicitar informacion (dato a agregar)
    cout << "Dato a ingresar: ";
    T unDato = solicitarDato();

    Arbol p = a;

    //Desplazarse hasta el lugar adecuado
    while (true)
    {
        if (comparar(unDato, igualQue, p->info))
        {
            cout << "Error: dato ya existe!" << endl;
            return;
        }
        else if (comparar(unDato, menorQue, p->info)) //Ir a la  izquierda
        {
            if (p->izq == NULL)
            {
                break;
            }
            else
            {
                p = p->izq;
            }
        }
        else //Ir a la derecha
        {
            if (p->der == NULL)
            {
                break;
            }
            else
            {
                p = p->der;
            }   
        }
    }

    //Agregar el nuevo nodo
    if (comparar(unDato, menorQue, p->info))
    {
        asignarIzq(p, unDato);
    }
    else
    {
        asignarDer(p, unDato);
    }
}

//Recorrer un arbol (in, pre y post orden)
void preOrden(Arbol a)
{
    if (a != NULL)
    {
        cout << " ";
        mostrarDato(a->info);
        preorden(a->izq);
        preorden(a->der);
    }
}

void inorden(Arbol a)
{
    if (a != NULL)
    {
        inorden(a->izq);
        cout << " ";
        mostrarDato(a->info);
        inorden(a->der);
    }
}

void recorrerArbol(Arbol a)
{
    cout << "Recorrido PRE orden";
    preorden(a);
    cout << endl;

    cout << "Recorrido IN orden";
    inorden(a);
    cout << endl;

    cout << "Recorrido POST orden:";
    postorden(a);
    cout << endl;
}