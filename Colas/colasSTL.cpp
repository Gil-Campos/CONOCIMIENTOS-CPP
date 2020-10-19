/*
Operaciones a conocer de la libreria de colas o queue:

1. Crear (initialize) - crea una cola vacía.
2. Insert (push, enqueue) - añade un elemento al final de la cola.
3. Remove (pop, dequeue) - lee y retira el elemento al frente de la cola.
4. Front (peek) - lee el elemento al frente de la cola sin retirarlo.
5. Back - lee el elemento al fondo de la cola sin retirarlo.
6. Empty - devuelve true si la cola está sin elementos o false en caso de que contenga alguno.
7. queue::swap() in C++ STL - intercambia el contenido de dos colas mismo tipo de dato y sus tamaños pueden variar.
8. queue::emplace() in C++ STL - añade un nuevo elemento a la cola pero al final de ella.
*/

#include <iostream>
#include <string>
#include <queue>

struct agenda 
{
    string titulo;
    string hora;
    int duracion;
    string descripcion;
};

typedef struct agenda Agenda;

//Prototipo de funciones
Agenda insertarActividad();
void driver();

using namespace std;

int main() {

    driver();

    return 0;
}

void driver() {

    queue<Agenda> datos;
    Agenda input;
    int opcion = 0;

    cout << endl;
    cout << "Hola elige el numero que deseas utilizar:" << endl;
    cout << endl;

    cout << "1. Insertar actividad." << endl;
    cout << "2. Borrar actividad." << endl,
    cout << "3. Borrar todas las actividades." << endl;
    cout << "4. Mostar actidades del dia." << endl;
    cout << endl;

    cout << "Opcion seleccionada: ";
    cin >> opcion;

    input = insertarActividad();

    datos.push(input);

    
}


Agenda insertarActividad() {
    Agenda datos;

    cout << endl;
    cout << "Por favor pon la informacion necesaria para crear una actividad en tu agenda." << endl;
    cout << endl;

    cout << "Titulo de la actividad: ";
    getline(cin, datos.titulo);
    cout << endl;

    cout << "Hora de la actividad: ";
    getline(cin, datos.hora);
    cout << endl;

    cout << "Descripcion de la actividad: ";
    getline(cin, datos.descripcion);
    cout << endl;

    cin.ignore(1000, '\n');
    cout << "Duracion de la actividad: ";
    cin >> datos.duracion;
    cout << endl;

    return datos;
}

