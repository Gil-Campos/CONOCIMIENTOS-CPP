#include <iostream>
#include <string>

using namespace std;

void entradaDeString();
void entradaDeMultiplesDatos();
void entradaDeDatosWhile();
void entradaDeDatosYCondicionales();

int main() {

    //entradaDeString();
    //entradaDeMultiplesDatos();
    //entradaDeDatosWhile();
    entradaDeDatosYCondicionales();

    return 0;
}

void entradaDeString() {
    string nombre;

    cout << "Por favor pon tu nombre y apellido: ";
    getline(cin, nombre);

    cout << "Tu nombre y apellido es: " << nombre;
}

void entradaDeMultiplesDatos() {
    int edad = 0;
    string nombre;

    cout << endl;
    cout << "Ingresa tu edad: ";
    cin >> edad;
    cout << endl;

    cin.ignore(1000,'\n');

    cout << "Ingresa tu nombre y tu apellido: ";
    getline(cin, nombre);
    cout << endl;

    cout << "Tu nombre y apellido es: " << nombre << " y tu edad " << edad;
    cout << endl;
}

void entradaDeDatosWhile() {
    int edad = 0;
    cout << "Ingresa tu edad por favor: ";

    cin >> edad;

    while(cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl;
        cout << "Tipo de dato equivocado." << endl;
        cout << endl;
        cout << "Ingresa tu edad otra vez: ";
        cin >> edad;
        cout << endl;
    }
}

void entradaDeDatosYCondicionales() {
    int num = 0;
    cout << "Ingresa un numero entre 19 y 64 por favor: ";

    cin >> num;

    while(num < 18 || num > 65) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl;
        cout << "Rango de datos equivocado." << endl;
        cout << endl;
        cout << "Ingresa un numero otra vez: ";
        cin >> num;
        cout << endl;
    }
}
