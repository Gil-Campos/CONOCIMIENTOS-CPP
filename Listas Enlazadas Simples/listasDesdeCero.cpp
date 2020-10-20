/*
Para los siguientes ejercicios pueden realizarse ocupando la librería o realizando listas
simples enlazadas desde 0.

1) Realice un programa que muestre un menú que permita administrar una lista simple con
datos acerca de personas. Deberá desplegar un menú.

Para cada persona se deberá considerar que posee los siguientes datos: carnet, nombre,
apellido, edad, número de teléfono y correo electrónico.
*/

#include <iostream>
#include <string>

using namespace std;

// Definicion del registro Libro
struct persona 
{
    int carnet;
    string nombre;
    string apellido;
    int edad;
    int telefono;
    string email;
};

typedef struct persona Persona;

typedef Persona T;
const T noValido = {-1, " ", " ", -1, -1, " "};

// Definicion de la lista simplemente enlazada
struct Nodo 
{
    T dato;
    struct Nodo *sig;
};

typedef struct Nodo *Lista;

//Prototipo de funciones
void crearLista(Lista *p);
bool empty(Lista *p);
void insertarInicio(Lista *p, T x);
void insertarFinal(Lista *p, T x);
void insertarDespuesDe(Lista *p, T x);
void insertarAntesDe(Lista *p, T x);
void mostrarDatos(Persona p);
void mostrar(Lista *p);
void agregar(Lista *p);
void eliminar(Lista *p);
void buscar(Lista *p);
void invertir(Lista* p);
void vaciar(Lista *p);
int contarOcurrencias(Lista *p);
int cantidadDatos(Lista *p);
T acceder(Lista *p);
int solicitarCarnet();
Persona solicitarDatos();
void driver();

int main()
{
    driver();

    return 0;
}

//Implementacion de funciones
void driver()
{
    Lista unaLista;

    crearLista(&unaLista);

    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar\t2) Mostrar todos\n";
        cout << "\t3) Eliminar\t4) Buscar\n";
        cout << "\t5) Invertir\t6) Vaciar\n";
        cout << "\t7) Cantidad\t8) Contar ocurrencias\n";
        cout << "\t9) Acceder\t10) Salir\n";
        cout << "\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: agregar(&unaLista); break;
            case 2: mostrar(&unaLista); break;
            case 3: eliminar(&unaLista); break;
            case 4: buscar(&unaLista); break;
            case 5: invertir(&unaLista); break;
            case 6: vaciar(&unaLista); break;
            case 7: cout << "Hay " << cantidadDatos(&unaLista) << " datos.\n"; break;
            case 8: cout << "Esta " << contarOcurrencias(&unaLista) << " veces.\n"; break;
            case 9: acceder(&unaLista); break;
            case 10: continuar = false; break;
            default: cout << "Opcion erronea!" << endl; break;
        }
    }while(continuar);
}

int solicitarCarnet() 
{
    cout << endl;
    int num = 0;
    cout << "Introduce el carnet del estudiante: ";
    cin >> num;
    cout << endl;

    return num;
}

Persona solicitarDatos() 
{
    Persona input;
    cout << "Inicializando..." << endl;

    cout << endl;
    cout << "Ingresa el nombre: ";
    cin.ignore();
    getline(cin, input.nombre);
    cout << "Ingresa el apellido: ";
    getline(cin, input.apellido);
    cout << "Ingresa email: ";
    getline(cin, input.email);
    cout << "Ingresa el carnet: ";
    cin >> input.carnet;
    cout << "Ingresa el edad: ";
    cin >> input.edad;
    cout << "Ingresa el telefono: ";
    cin >> input.telefono;

    return input;
}

bool comparar(Persona a, int b)
{
    return a.carnet == b ? true : false;
}

void crearLista(Lista *p)
{
    *p = NULL;
}

bool empty(Lista *p)
{
    return *p == NULL;
}

void insertarInicio(Lista *p, T x) 
{
    Nodo *nuevo = new Nodo;
    nuevo->dato = x;
    nuevo->sig = *p;

    *p = nuevo;
}

void insertarFinal(Lista *p, T x) 
{
    Nodo *nuevo = new Nodo;
    nuevo->dato = x;
    nuevo->sig = NULL;    

    if (p == NULL)
    {
        *p = nuevo;
    }
    else
    {
        Nodo *unNodo = *p;
        Nodo *aux = NULL;

        while (unNodo != NULL)
        {
            aux = unNodo;
            unNodo = unNodo->sig;
        }
        aux->sig = nuevo;
    }
}

void insertarDespuesDe(Lista *p, T x)
{
    cout << endl;
    cout << "Dato de referencia: ";
    int ref = solicitarCarnet();

    Nodo *s = *p;

    while (s != NULL && !comparar(s->dato, ref))
    {
        s = s->sig;
    }
    
    if (s == NULL)
    {   
        cout << endl;
        cout << "Dato de referencia NO existe" << endl;
        cout << endl;
        return;
    } 
    else
    {
        Nodo *nuevo = new Nodo;
        nuevo->dato = x;
        nuevo->sig = s->sig;

        s->sig = nuevo;
        cout << endl;
        cout << "Dato insertado con exito" << endl;
        cout << endl;
    } 
}

void insertarAntesDe(Lista *p, T x)
{
    cout << "Dato de referencia: ";
    int ref = solicitarCarnet();

    Nodo *s = *p, *q = NULL;

    while (s != NULL && !comparar(s->dato, ref))
    {
        q = s;
        s = s->sig;
    }

    if (s == NULL)
    {
        cout << endl;
        cout << "Dato de referencia NO existe" << endl;
        cout << endl;
        return;
    } 

    Nodo *nuevo = new Nodo;
    nuevo->dato = x;
    nuevo->sig = s;

    if (q == NULL)
    {
        *p = nuevo;
    } 
    else 
    {
        q->sig = nuevo;
        cout << endl;
        cout << "Dato insertado con exito" << endl;
        cout << endl;
    }
    
}

void agregar(Lista *p)
{
    T datos = solicitarDatos();

    bool continuar = true;
    do
    {
        int opcion = 0;
        cout << "\t1) Al principio\n";
        cout << "\t2) Al final\n";
        cout << "\t3) Despues de\n";
        cout << "\t4) Antes de\n";
        cout << "\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: insertarInicio(p, datos); continuar = false; break;
            case 2: insertarFinal(p, datos); continuar = false; break;
            case 3: insertarDespuesDe(p, datos); continuar = false; break;
            case 4: insertarAntesDe(p, datos); continuar = false; break;
            default: cout << "Opcion erronea!" << endl; break;
        }
    } while(continuar);
    
}

int cantidadDatos(Lista *p) {
    Nodo *s = *p;

    int contador = 0;
    while (s != NULL) {
        s = s->sig;
        contador++;
    }
    
    return contador;
}

void mostrar(Lista *p)
{
    Nodo *s = *p;

    while (s != NULL) {
        mostrarDatos(s->dato);
        s = s->sig;
    }   
}

void mostrarDatos(Persona p)
{
    cout << endl;

    cout << "Nombre: " << p.nombre << endl;
    cout << "Apellido: " << p.apellido << endl;
    cout << "Edad: " << p.edad << endl;
    cout << "Carnet: " << p.carnet << endl;
    cout << "Email: " << p.email << endl;
    cout << "Telefono: " << p.telefono << endl;
    cout << endl;

}

void eliminar(Lista *p)
{
    cout << endl;
    cout << "Dato a eliminar" << endl;
    int  ref = solicitarCarnet();

    Nodo *q = *p, *s = NULL;

    while (q != NULL && !comparar(q->dato, ref))
    {
        s = q;
        q = q->sig;
    }
    
    if (q == NULL)
    {
        cout << endl;
        cout << "Dato a borrar NO existe" << endl;
        cout << endl;
        return;
    }
    
    if(s == NULL)
    {
        *p = q->sig;
    }
    else 
    {
        s->sig = q->sig;
    }

    delete(q);
    cout << endl;
    cout << "Dato borrado!" << endl;
    cout << endl;
}

void buscar(Lista *p)
{
    cout << "Dato a buscar";
    int  ref = solicitarCarnet();

    Nodo *s = *p;

    while (s != NULL && !comparar(s->dato, ref))
    {
        s = s->sig;
    }

    if (s != NULL)
    {
        cout << endl;
        cout << "El dato SI se encuentra" << endl;
        cout << endl;
    }
    else
    {
        cout << endl;
        cout << "El dato NO se encuentra" << endl;
        cout << endl;
    }
}

void invertir(Lista* p)
{
    Nodo *resultante = NULL;
    Nodo *actual = *p;
    Nodo *siguiente;

    while(actual != nullptr){
        siguiente = actual->sig;

        actual->sig = resultante;
        resultante = actual;
        actual = siguiente;
    }
    *p = resultante;

    cout << endl << "Lista invertida con exito" << endl;
}

void vaciar(Lista *p)
{
    Nodo* actual = *p;
    Nodo* siguiente;
    
    while(siguiente != NULL){
        siguiente = actual->sig;
        delete(actual);
        actual = siguiente;
    }

    *p = NULL;
}

int contarOcurrencias(Lista *p)
{
    cout << "Dato de referencia: ";
    int ref = solicitarCarnet();

    Nodo* actual = *p;
    int contador = 0;
    
    while(actual != NULL){
        if(comparar(actual->dato, ref)) contador++;
        actual = actual->sig;
    }

    return contador;
}

T acceder(Lista *p) {
    int indice = 0;
    cout << "Indice a acceder: ";
    cin >> indice; cin.ignore();
    
    if(indice>=0 && indice<cantidadDatos(p)){
        Nodo *s = *p;
        for (int i = 0; i < indice; i++) {
            s = s->sig;
        }
        mostrarDatos(s->dato);
        return s->dato;
    }
    else{
        cout << "Error, indice no valido\n";
        return noValido;
    }
}
