/*
Este codigo es sacado de las clases del Lic. Rondaldo Chinchilla de PED de la UCA.
*/

#include <iostream>
#include <string>
using namespace std;

// Definicion de nodo ------------------------
struct nodo{
    char elemento;
    struct nodo *siguiente;
};
typedef struct nodo *Pila;

// Prototipos de funciones ------------------------
void initialize(Pila *s);
bool empty(Pila *s);
void push(Pila *s, char e);
char pop(Pila *s);
char top(Pila *s);

// Otras funciones a utilizar ---------------------
bool operand(char symb);
bool prcd(char a, char b);

// Programa principal ------------------------
int main(){
    string infija, postfija = "";
    cout << "Digite alguna expresion infija: ";
    getline(cin, infija);
    
    Pila s;
    initialize(&s);
    for (int i = 0; i < infija.length(); i++) {
        char symb = infija[i];
        
        if(operand(symb))
            postfija += symb;
        else{
            while(!empty(&s) && prcd(top(&s), symb)){
                char topsymb = pop(&s);
                postfija += topsymb;
            }
            if(empty(&s) || symb!=')')
                push(&s, symb);
            else
                char topsymb = pop(&s);
        }
    }
    while(!empty(&s)){
        char topsymb = pop(&s);
        postfija += topsymb;
    }
    
    cout << "Infija: " << infija << endl;
    cout << "Postfija: " << postfija << endl;

    return 0;
}

// Implementacion de funciones ------------------------
bool operand(char c){
    return (c=='0' || c=='1' || c=='2' || c=='3' || c=='4' ||
    c=='5' || c=='6' || c=='7' || c=='8' || c=='9') || 
    (c>='a' && c<='z') || (c>='A' && c<='Z');
}

bool prcd(char a, char b){
    if((a=='*'||a=='/') && (b=='+'||b=='-')) return true;
    else if((a=='+'||a=='-') && (b=='+'||b=='-')) return true;
    else if((a=='+'||a=='-') && (b=='*'||b=='/')) return false;
    else if(a=='(') return false;
    else if(b=='(') return false;
    else if(b==')') return true;
    else if(a=='$') return true;
    else return false;
}

void initialize(Pila *s){
    *s = NULL;
}

bool empty(Pila *s){
    return *s == NULL;
}

void push(Pila *s, char e){
    struct nodo *unNodo = new struct nodo;
    unNodo->elemento = e;
    unNodo->siguiente = *s;
    
    *s = unNodo;
}

char pop(Pila *s){
    if(!empty(s)){
        struct nodo *unNodo = *s;
        char e = (*s)->elemento;
        *s = (*s)->siguiente;
        delete(unNodo);
        return e;
    }
    else // Underflow!
        return ' ';
}

char top(Pila *s){
    if(!empty(s))
        return (*s)->elemento;
    else // Underflow!
        return ' ';
}


