/*
Implemente en C++ un programa que simule el almacenamiento de
articulos en una bodega, se debe utilizar un registro con los campos:

-Nombre del articulo.
-Peso en gramos.
-Precio del paquete.

Se deben de poder realizar las siguientes operaciones:
-Agregar articulos a la bodega.
-Buscar articulos.
-Eliminar articulos.
-Mostrar todo lo que contenga la bodega.
-Ordenar por peso, precio y alfabeticamente.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Articulo
{
    string nombre;
    int peso;
    float precio;
};

vector<Articulo> bodega;

//Prototipo de funciones
bool compNombre(Articulo a, Articulo b);
bool compPeso(Articulo a, Articulo b);
bool compPrecio(Articulo a, Articulo b);
void agregar();
void buscar();
void eliminar();
void mostrar();
void ordenar();
void driver();

int main()
{
    driver();

    return 0;
}

void driver()
{
    bool continuar = true;

    while (continuar)
    {
        int opcion = 0;
        cout << "\n1) Agregar articulos a la bodega.\n";
        cout << "2) Buscar articulos.\n";
        cout << "3) Eliminar articulos.\n";
        cout << "4) Mostrar todo lo que contenga la bodega.\n";
        cout << "5) Ordenar.\n";
        cout << "6) Salir.\n";
        cout << "Opcion: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: agregar(); break;
            case 2: buscar(); break;
            case 3: eliminar(); break;
            case 4: mostrar(); break;
            case 5: ordenar(); break;
            case 6: continuar = false;
            default: cout << "Opcion no valida.\n"; break;
        }
    }
    
}

bool compNombre(Articulo a, Articulo b){
    return a.nombre < b.nombre;
}

bool compPeso(Articulo a, Articulo b){
    return a.peso < b.peso;
}

bool compPrecio(Articulo a, Articulo b){
    return a.precio < b.precio;
}

void agregar()
{
    Articulo unArticulo; 
    cout << "Nombre: "; 
    getline(cin, unArticulo.nombre);
    cout << "Peso: "; cin >> unArticulo.peso; 
    cin.ignore();
    cout << "Precio: "; cin >> unArticulo.precio; 
    cin.ignore();
    bodega.insert(bodega.end(), unArticulo);
    cout << "Articulo ingresado exitosamente!\n";
}

void buscar(){
    string unNombre;
    cout << "Nombre del articulo que buscar: ";
    getline(cin, unNombre);
    
    bool encontrado = false;
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].nombre == unNombre){
            encontrado = true;
            break;
        }
    }
    
    if(encontrado)
        cout << "Articulo si se encuentra en la bodega.\n";
    else
        cout << "Articulo no se encuentra en la bodega.\n";
}

void eliminar(){
    string unNombre;
    cout << "Nombre del articulo que buscar: ";
    getline(cin, unNombre);
    
    for(auto iter = bodega.begin(); iter != bodega.end(); ++iter){
        if(iter->nombre == unNombre){
            iter = bodega.erase(iter);
            cout << "Articulo eliminado exitosamente.\n";
            break;
        }
    }
}

void mostrar(){
    for (int i = 0; i < bodega.size(); i++) {
        cout << bodega[i].nombre << " pesa " << bodega[i].peso;
        cout << " gramos y vale $" << bodega[i].precio << "\n";
    }
}

void ordenar(){
    int opcion = 0;
    cout << "Criterio de ordenamiento:\n";
    cout << "1) Alfabetico\n";
    cout << "2) Peso\n3)Precio\n";
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    
    if(opcion == 1)
        sort(bodega.begin(), bodega.end(), compNombre);
    else if(opcion == 2)
        sort(bodega.begin(), bodega.end(), compPeso);
    else if(opcion == 3)
        sort(bodega.begin(), bodega.end(), compPrecio);
        
    cout << "Bodega ordenada exitosamente\n";
}