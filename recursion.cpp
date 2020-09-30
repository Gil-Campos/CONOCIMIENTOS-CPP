#include <iostream>
#include <string>

using namespace std;

int numFctorial = 1;
int factorialRecursionExample(int);
int RecursionLineal_NoFinal(int);
float RecursionLineal_Final(int, int);
int RecursionMultiple(int);
string par(int);
string impar(int);

int main() {
    int numOne= 6;
    int numTwo = 4;

    cout << endl;

    /* IMPORTANTE: NO CORRER TODAS LAS FUNCIONES A LA VEZ PUEDE CAUSAR PROBLEMAS */ 

    //cout << factorialRecursionExample(numOne) << endl;
    //cout << RecursionLineal_Final(numOne, numTwo) << endl;
    //cout << RecursionMultiple(numOne) << endl;
    //cout << par(numOne) << endl;

    cout << endl;
}

//RECURSION

int factorialRecursionExample(int num) {

    /*
    Se necesita un caso base el cual se usa para terminar la recursion o si la respuesta al problema no necesita llamar
    a la funcion y el caso recursivo que se utiliza para que la funcion se llame a si misma hasta llegar al caso base y
    no generar un stack overflow.
    */

    if (num == 1)
    {
        return numFctorial;
    } else {
        numFctorial = num * factorialRecursionExample(num - 1);
    }
    
}

//TIPOS DE RECURSION

int RecursionLineal_NoFinal(int num) {

    if (num > 1)
    {
        /*
        Recursion lineal no final: el resultado de la llamada recursiva se combina en una expresión para
        dar lugar al resultado de la función que llama. Ejemplo para demostrar factorial de un numero.
        */

        return (num * RecursionLineal_NoFinal(num - 1));

    } else {

       return 1;
    }
    
} 

float RecursionLineal_Final(int firstNum, int secondNum) {
    
    if (secondNum != 0)
    {
        /*
        Recursion lineal final: El resultado que es devuelto es el resultado de ejecución de la última llamada 
        recursiva. Ejemplo para demostrar calculo maximo comun divisor.
        */

        return RecursionLineal_Final(firstNum, firstNum % secondNum);

    } else
    {
        return firstNum;
    }
         
}

int RecursionMultiple(int num) {

    /*
    Recursion Multiple: Alguna llamada recursiva puede generar más de una llamada a la función. Ejemplo para demostrar secuencia
    de Fibonacci.
    */

    if (num == 1 || num == 2)
    {
        return 1;
    }
    else
    {
        return (RecursionMultiple(num - 1) + RecursionMultiple(num - 2));
    }
    
}

/*
Recursion mutua: Implica más de una función que se llaman mutuamente. Ejemplo para demostrar funciones par e impar.
*/

string par(int num){
    if(num == 0) {
        return "Par";
    } 
    else
    {
        return impar(num - 1);    
    }
}

string impar(int num) {
    if (num == 0)
    {
        return "Impar";
    }
    else
    {
        return par(num - 1); 
    } 
}





