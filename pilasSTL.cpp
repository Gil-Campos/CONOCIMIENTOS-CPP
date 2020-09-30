#include <iostream>
#include <string>
#include <stack>

using namespace std;

void stacks();

int main() {

    stacks();

    return 0;
}

/*
Antes de ver la siguiente funcion es necesario entender que son las pilas o stacks son estructuras dinamicas de datos lineales que siguen un orden
en que las operaciones son realizadas, el orden de ellas puede ser LIFO (Last In First Out) o FIFO (First In First Out) y las operaciones a realizar son
las siguientes push, pop, peek o top y isEmpty. Ejemplo para demostrar el uso de las operaciones es la navegacion de Instagram (Android) con ayuda de la libreria stack
de c++ para su facil comprension.  
*/

void stacks() {

    //Crear (initialize): crea la pila vac´ıa.
    stack<string> screens;

    cout << endl;
    cout << "-Inicio de Insta";
    cout << endl;

    //Vacía (empty): devuelve cierto si la pila está sin elementos o falso en caso de que contenga alguno.
    if (screens.empty())
    {
        cout << endl;
        cout << "-No se a navegado nada en instagram" << endl;
        cout << endl; 
    } else
    {
        //Tamaño (size): devuelve la cantidad de elementos en la pila.
        cout << "-Cantidad de taps en Insta " << screens.size() << endl;
        cout << endl;
    }

    cout << "-Navegando en Inta..." << endl;
    cout << endl;
    
    //Apilar (push): añade un elemento a la pila.
    screens.push("Tap a Insta de Juan");
    screens.push("Tap a post 3 del Insta de Juan");
    screens.push("Tap al like 5 (perfil de Melissa) del post 3 de Juan");
    screens.push("Perfil de Melissa");
    screens.push("Tap post 7 del perfil de Melissa");

    if (screens.empty())
    {
        cout << "-No se a navegado nada en instagram" << endl;
        cout << endl; 
    } else
    {
        cout << "-Cantidad de taps en Insta " << screens.size() << endl;
        cout << endl;
    }

    cout << "-Regresando a home de Insta" << endl;
    cout << endl;

    while (screens.empty() != true)
    {
        //Leer último (top o peek): lee el elemento superior de la pila sin retirarlo.
        cout << "back button " << screens.top() << endl;

        //Desapilar (pop): lee y retira el elemento superior de la pila.
        screens.pop();
    }

    if (screens.empty())
    {
        cout << endl;
        cout << "-Home de Insta" << endl;
        cout << endl; 
    } else
    {
        cout << "Cantidad de taps en Insta" << screens.size() << endl;
        cout << endl;
    }

}