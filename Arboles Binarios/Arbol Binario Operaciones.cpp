#include <iostream>
#include <string>

using namespace std;

//Creacion del nodo y del arbol
typedef int T;

struct Nodo
{
    T info;
    struct Nodo *izq;
    struct Nodo *der;
};

typedef struct Nodo *Arbol;

Arbol crearArbol(T x);

//Prototipo de funciones que dependen del tipo de dato de los nodos
enum comparacion 
{
    menorque,
    mayorque,
    igualque
};

int solicitarDato();
void mostrarDato(int unDato);
bool comparar(int a, comparacion operador, int b);

//Agregar nodos a un arbol
void asignarIzq(Arbol a, T unDato);
void aignarDer(Arbol a, T unDato);
void agregarNodo(Arbol a);

//Recorrer un arbol (in, pre y post orden)
void preorden(Arbol a);
void inorden(Arbol a);
void postOrden(Arbol a);
void recorrerArbol(Arbol a);

//Funcion principal
void driver();

int main()
{
    driver();

    return 0;
}

void driver()
{
    cout << endl;
    cout<<"Inicializando arbol... " << endl;
    cout << "Valor contenido en la raiz:" << endl;
    Arbol arbol = crearArbol(solicitarDato());
    
    bool continuar = true;

    do{
        int opcion = 0;
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1) Agregar" << endl;
        cout << "2) Recorrer" << endl;
        cout << "3) Salir" << endl;
        cout << "Opcion elegida: ";
        cin >> opcion;
        switch(opcion){
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
            cout << "Opcion erronea!" << endl; 
            break;
        }
    }while(continuar);
}

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

bool comparar(int a, comparacion operador, int b)
{
    bool resultado = false;

    switch (operador)
    {
    case menorque:
        resultado = a < b;
        break;
    case mayorque:
        resultado = a > b;
        break;
    case igualque:
        a == b;
        break;
    default:
        break;
    }

    return resultado;
}

//Implementacion de funciones de arboles
Arbol crearArbol(T x)
{
    Arbol p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;
}

//Agregar nodos a un arbol
void asignarIzq(Arbol a, T unDato)
{
    if (a == NULL)
    {
        cout << endl;
        cout << "Error: arbol vacio" << endl;
        cout << endl;
    }
    else if (a->izq != NULL)
    {
        cout << endl;
        cout << "Error: subArbol IZQ ya existe" << endl;
        cout << endl;
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
        cout << endl;
        cout << "Error: arbol vacio" << endl;
        cout << endl;
    }
    else if (a->der != NULL)
    {
        cout << endl;
        cout << "Error: subArbol DER ya existe" << endl;
        cout << endl;
    }
    else
    {
        a->der = crearArbol(unDato);
    }   
}

void agregarNodo(Arbol a)
{
    //Solicitar informacion (dato o agregar)
    cout << endl;
    cout << "Dato a agregar: ";
    T unDato = solicitarDato();

    Arbol p = a;

    //desplazarse hasta el lugar adecuado
    while (true)
    {
        if (comparar(unDato, igualque, p->info))
        {
            cout << endl;
            cout << "Error: dato ya no existe!" << endl;
            cout << endl;
            return;
        }
        //ir a la izquierda
        else if (comparar(unDato, menorque, p->info)) 
        {
            if (p->izq == NULL)
            {
                break;
            } else
            {
                p = p->izq;
            }
            
        }
        //Ir a la derecha
        else
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
    if (comparar(unDato, menorque, p->info))
    {
        asignarIzq(p, unDato);
    }
    else
    {
        asignarDer(p, unDato);
    } 
}

//Recorrer el arbol (in, pre y post orden)
void preorden(Arbol a)
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
    if(a != NULL){
        inorden(a->izq);
        cout << " "; 
        mostrarDato(a->info);
        inorden(a->der);
    }
}

void postorden(Arbol a)
{
    if(a != NULL)
    {
        postorden(a->izq);
        postorden(a->der);
        cout << " "; 
        mostrarDato(a->info);
    }
}

void recorrerArbol(Arbol a){
    cout << "Recorrido PRE orden:"; 
    preorden(a); 
    cout << endl;

    cout << "Recorrido IN orden:"; 
    inorden(a); 
    cout << endl;

    cout << "Recorrido POST orden:"; 
    postorden(a); 
    cout << endl;
}