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
void mostar();
void ordenar();
void driver();

int main()
{
    driver();

    return 0;
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
