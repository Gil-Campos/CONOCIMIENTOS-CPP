/*
Este codigo es sacado de las clases del Lic. Rondaldo Chinchilla de PED de la UCA.
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Definicion de nodo ------------------------
struct nodo{
    float elemento;
    struct nodo *siguiente;
};
typedef struct nodo *Pila;

// Prototipos de funciones ------------------------
void initialize(Pila *s);
bool empty(Pila *s);
void push(Pila *s, float e);
float pop(Pila *s);
float top(Pila *s);

// Otras funciones a utilizar ---------------------
bool operand(char symb);
float oper(char symb, float a, float b);

// Programa principal ------------------------
int main(){
    string postfija;
    cout << "Digite alguna expresion postfija: ";
    getline(cin, postfija);
    
    Pila s;
    initialize(&s);
    for (int i = 0; i < postfija.length(); i++) {
        char symb = postfija[i];
        
        if(operand(symb)){
            int digito = symb  - '0';
            push(&s, digito);
        }
        else{
            float oper2 = pop(&s);
            float oper1 = pop(&s);
            float value = oper(symb, oper1, oper2);
            push(&s, value);
        }
    }
    
    cout << "Resultado: " << pop(&s) << endl;

    return 0;
}

// Implementacion de funciones ------------------------
bool operand(char c){
    return (c=='0' || c=='1' || c=='2' || c=='3' || c=='4' ||
    c=='5' || c=='6' || c=='7' || c=='8' || c=='9');
}

float oper(char symb, float a, float b){
    if(symb=='+') return a + b;
    else if(symb=='-') return a - b;
    else if(symb=='*') return a * b;
    else if(symb=='/') return a / b;
    else if(symb=='$') return pow(a, b);
    else return -1;
}

void initialize(Pila *s){
    *s = NULL;
}

bool empty(Pila *s){
    return *s == NULL;
}

void push(Pila *s, float e){
    struct nodo *unNodo = new struct nodo;
    unNodo->elemento = e;
    unNodo->siguiente = *s;
    
    *s = unNodo;
}

float pop(Pila *s){
    if(!empty(s)){
        struct nodo *unNodo = *s;
        float e = (*s)->elemento;
        *s = (*s)->siguiente;
        delete(unNodo);
        return e;
    }
    else // Underflow!
        return -1;
}

float top(Pila *s){
    if(!empty(s))
        return (*s)->elemento;
    else // Underflow!
        return -1;
}

