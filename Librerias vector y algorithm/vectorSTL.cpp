/*
Los vectores son lo mismo que arreglos dinamicos con la habilidad que ellos pueden cambiar su tamaño
cuando se les agrega o quita un elemento, su almacenamiento es manejado automaticamente por el contenedor.

Operaciones que se pueden realizar:
-Inicializar: Crear un arreglo de longitud variable con cero o n casillas, vacias o con valores predeterminados.
-Acceder a algun elemento: En cualquier lugar del arreglo.
-Insertar: Ya sea al principio o al final.
-Eliminar: Al principio, al final o todos (vaciar el arreglo).
-Encoger: liberar espacio reservado sin utilizar.
-Consultar: el tama˜no y la capacidad del arreglo.
*/

#include <iostream>
#include <vector>

using namespace std;

//Prototipo de funciones
void driver();
void insertarDatos(vector<int> *vect01, vector<float> *vect02);
void eleminarVaciarDatos(vector<int> *vect01, vector<float> *vect02);
void mostrarDatos(vector<int> *vect01, vector<float> *vect02);

int main()
{
    driver();

    return 0;
}

void driver()
{
    //Inicializar con cero casillas
    vector<int> vector01;
    //Inicializar con valores predeterminados
    vector<float> vector02 = {1.2, 4.5, 6.6, 8.9, 10};

    //Recorder - acceder a los elementos
    cout << "Contenido vecto02: ";
    for (int i = 0; i < vector02.size (); i++)
    {
      cout << vector02[i] << " ";
    }
    cout << endl;

    //insertarDatos(&vector01, &vector02);

    //Recorrer - acceder a los elementos
    //mostrarDatos(&vector01, &vector02);

    eleminarVaciarDatos(&vector01, &vector02);

    //Recorrer - mostrando cambio de los elementos
    cout << "-Mostrar cambios de vectores:" << endl;
    //mostrarDatos(&vector01, &vector02);

    //consultarEncoger(&vector01, &vector02);
}

void mostrarDatos(vector<int> *vect01, vector<float> *vect02)
{
    cout << endl;
    cout << "Contenido vector01: ";

    if ((*vect01).empty())
    {
        cout << "El vector01 no tiene ningun dato" << endl;
        cout << endl;
    } 
    else 
    {
        for (int i = 0; i < (*vect01).size (); i++)
        {
            cout << (*vect01)[i] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    cout << "Contenido vector02: ";

    if ((*vect02).empty())
    {
        cout << "El vector02 no tiene ningun dato" << endl;
        cout << endl;
    } 
    else
    {
        for (int i = 0; i < (*vect02).size(); i++)
        {
            cout << (*vect02)[i] << " ";
        }
        cout << endl;
    } 
}

void insertarDatos(vector<int> *vect01, vector<float> *vect02) 
{
    //Insertar al inicio
    (*vect01).insert((*vect01).begin(), 3);
    (*vect01).insert((*vect01).begin(), 2);
    (*vect01).insert((*vect01).begin(), 9);

    (*vect02).insert((*vect02).begin(), 5.5);
    (*vect02).insert((*vect02).begin(), 7.6);

    //Insertar al final
    (*vect01).insert((*vect01).end(), 0);
    (*vect01).insert((*vect01).end(), 1);

    (*vect02).insert((*vect02).end(), 3.14);
}

void eleminarVaciarDatos(vector<int> *vect01, vector<float> *vect02)
{
    //Eliminar elementos del inicio
    (*vect01).erase((*vect01).begin());

    //Eliminar elementos del final
    (*vect01).erase((*vect01).end()-1);

    //Vaciar vector
    (*vect02).clear();
}

void consultarEncoger(vector<int> *vect01, vector<float> *vect02)
{
    //Consultar tamaño y capacidad
    cout << "Size vector 1: " << (*vect01).size() << " cap: " << (*vect01).capacity() << endl;
    cout << "Size vector 2: " << (*vect02).size() << " cap: " << (*vect02).capacity() << endl;
    cout << endl;

    cout << endl;
    cout << "Agregando datos a vector 02..." << endl;
    for (int i = 0; i < 3; i++) {
        (*vect02).insert((*vect02).begin(), 2);
        cout << "size: " << (*vect02).size() << " cap: " << (*vect02).capacity() << endl;
    }
    cout << endl;

    cout << "Encogiendo... ";
    (*vect02).shrink_to_fit();
    cout << "size vector 02: " << (*vect02).size() << " cap: " << (*vect02).capacity() << endl;
    cout << endl;
}
