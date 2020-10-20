/*
La libreria de algorithm nos brinda varias funciones que pueden ser usadas de diferente manera como por ejemplo buscar,
clasificar, contar, manipular y muchas otras.

Operaciones que se pueden realizar:
-Buscar: Algun elemento en especifico (secuencial).
-Insertar: En medio (antes de otro elemento en especifico).
-Eliminar: Algun elemento en especifico.
-Ordenar: Los elementos de un arreglo.
-Buscar: Utilizando busqueda binaria.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Persona 
{
    string nombre;
    int edad;
};

//Prototipo de funciones
void funcFind();
void ordenarDatos();
bool compEdad(Persona a, Persona b);
void ordenarRegistros();
void driver();

int main()
{
    driver();
}

void driver()
{
    //funcFind();
    //ordenarDatos();
    //ordenarRegistros();
}

void funcFind()
{
    vector<int> v1 = {2, 6, 4, 8};

    //Buscar  el numero 3 en el vector
    if (find(v1.begin(), v1.end(), 3)!=v1.end())
    {
        cout << endl;
        cout << "El numero 3 si esta en el vector" << endl;
        cout << endl;
    }
    else
    {
         cout << endl;
        cout << "El numero 3 no esta en el vector" << endl;
        cout << endl;
    }
    
    //Insertar antes de:
    cout << "Insertando el 5 ANTES del 6..." << endl;
    v1.insert(find(v1.begin(), v1.end(), 6), 5);

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
    
    //Insertar despues de:
    cout << endl;
    cout << "Insertando el 7 DESPUES del 4... " << endl;
    v1.insert(find(v1.begin(), v1.end(), 4) + 1, 7);

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    //Eliminar el numero 5
    cout << endl;
    cout << "Eliminando el 5... " << endl;
    v1.erase(find(v1.begin(), v1.end(), 5));

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
    
}

void ordenarDatos()
{
    vector<int> v1 = { 10, 9, 8, 6, 7, 2, 5, 1 };

    cout << endl;
    cout << "Ordenando..." << endl;

    // Ordenar vector ascendentemente
    sort(v1.begin(), v1.end());

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    // Utilizar busqueda binaria
    if (binary_search(v1.begin(), v1.end(), 6))
    {
        cout << "El numero 6 si se encuentra" << endl;
        cout << endl;
    }
    else
    {
        cout << "El numero 6 no se encuentra" << endl;
        cout << endl;
    }
    
    if (binary_search(v1.begin(), v1.end(), 3))
    {
        cout << "El numero 3 si se encuentra" << endl;
        cout << endl;
    }
    else
    {
        cout << "El numero 3 no se encuentra" << endl;
        cout << endl;
    }
    
    cout << "Ordenando..." << endl;

    // Ordenar vector descendentemente
    sort(v1.begin(), v1.end(), greater<int>());

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    
}

bool compEdad(Persona a, Persona b)
{
    return a.edad < b.edad;
}

void ordenarRegistros()
{
    vector<Persona> estudiantes;
    
    char letra = 's';
    while(letra == 's'){
        Persona unaPersona;
        cout << "Nombre: "; 
        getline(cin, unaPersona.nombre);
        cout << "Edad: "; cin >> unaPersona.edad; 
        cin.ignore();
        estudiantes.insert(estudiantes.end(), unaPersona);
        
        cout << "\nDesea agregar alguien mas? (s/n): ";
        cin >> letra; cin.ignore();
    }
    
    // Ordenando estudiantes por edad
    sort(estudiantes.begin(), estudiantes.end(), compEdad);
    
    // Mostrando estudiantes ya ordenados
    for (int i = 0; i < estudiantes.size(); i++) {
        cout << estudiantes[i].nombre << " tiene ";
        cout << estudiantes[i].edad << " anios.";
    }
    cout << endl;
}
