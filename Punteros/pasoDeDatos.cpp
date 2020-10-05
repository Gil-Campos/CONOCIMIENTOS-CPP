#include <iostream>

using namespace std;

struct Test {
    string name = "Tu Nombre";
    string lastName = "Apellido";
    int edad = 18;
};

struct ArregloN{
    string nombre = "Arreglo";
    int* arr;
};


typedef struct Test IdentificadortTest;

void pasarArr(int[], int*, int);
void pasar2DArr(int[][5], int*, int, int);
void doblePuntero(int*);
void pasarRegistros(Test, Test*);
void crearArregloN();

int main() {

    int arr1[5] = {1,2,3,4,5};
    int arr2D[2][5] = {{1,2,3,4,5}, {6,7,8,9,10}};
    int num = 2;
    struct Test test;
    IdentificadortTest prueba;

    //pasarArr(arr1, arr1, 5);

    //pasar2DArr(arr2D, *arr2D, 2, 5);

    //doblePuntero(&num);

    //pasarRegistros(test, &test);

    //pasarRegistros(prueba, &prueba);

    //crearArregloN();
} 

void pasarArr(int arreglo[], int *arrPuntero, int limit) {

    cout << endl;
    cout << "Imprimiendo arreglo forma comun: " << endl;

    for (int i = 0; i < limit; i++)
    {
        cout << arreglo[i] << endl;
    }

    cout << endl;
    cout << "Imprimiendo arreglo forma puntero: " << endl;
    for (int i = 0; i < limit; i++)
    {
        cout << *(arrPuntero + i) << endl;
    }
    cout << endl;
}

void pasar2DArr(int arr[][5], int *pArr, int firstL, int secondL) {

    cout << endl;
    cout << "Imprimiendo arreglo2D forma comun: " << endl;

    for (int i = 0; i < firstL; i++)
    {
        for (int j = 0; j < secondL; j++)
        {
            cout << arr[i][j] << endl;
        }
        
    }
    
    cout << endl;
    cout << "Imprimiendo arreglo2D forma puntero: " << endl;
    for (int i = 0; i < firstL; i++)
    {
        for (int j = 0; j < secondL; j++)
        {
            cout << *((pArr+i)+j) << endl;
        }
    }

    cout << endl;
    cout << "Imprimiendo arreglo2D forma puntero direccion de su segunda dimesion: " << endl;

    int *primerPuntero;

    *primerPuntero = arr[0][0];

    for (int i = 0; i < secondL; i++)
    {
        cout << *(primerPuntero + i) << endl;
    }
    
    
}

void doblePuntero(int *num) {

    //Se le pasa el primero la direccion del puntero que es el la direccion del argumento desde el main.
    int **segundoPuntero = &num;

    cout << endl;
    cout << "Leyendo segundo puntero (sera igual al valor del main)" << endl;
    cout << **segundoPuntero << endl;
    cout << endl; 
}

void pasarRegistros(Test datos, Test *datosP) {

    //Los registros como buena practica se deben pasar por punteros.
    cout << endl;
    cout << "Forma como no se debe de hacer: " << endl;
    cout << "Pon tu " << datos.name << " y tu " << datos.lastName << endl;
    cout << endl;

    //Como se debe pasar un registro.
    cout << "Forma extendia: " << endl; 
    cout << "Pon tu " << (*datosP).name << " y tu " << (*datosP).lastName << endl;
    cout << endl;

    cout << "Forma resumida: " << endl; 
    cout << "Pon tu " << datosP->name << " y tu " << datosP->lastName << endl;
    cout << endl;
}

void crearArregloN() {
    struct ArregloN arreglo[2];

    int *datos = new int[6];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            datos[j] = j;
        }

        arreglo[i].arr = datos;                        
    }

    cout << endl;
    cout << "Imprimiendo los datos: " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << arreglo[i].arr[j] << endl;
        }
        
        cout << endl;
    }
    cout << endl;
}
