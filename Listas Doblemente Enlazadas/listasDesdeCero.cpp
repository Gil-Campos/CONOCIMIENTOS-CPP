/*
Este ejemplo fue sacado de https://www.geeksforgeeks.org/doubly-linked-list/ y https://www.geeksforgeeks.org/delete-a-node-in-a-doubly-linked-list/
*/

#include <iostream>

using namespace std;

//Nodo lista 
struct Node
{
    int data;
    Node* next;
    Node* prev;
};

//Prototipo de funciones
void push(Node** head_ref, int new_data);
void insertAfter(Node* prev_node, int new_data);
void append(Node** head_ref, int new_data);
void deleteNode(Node** head_ref, Node* del);
void printList(Node* node);
void driver();

int main()
{
    driver();

    return 0;
}

void driver()
{
    //Iniciar con la lista vacia
    Node* head = NULL;

    //Insertar 6 al inicio. La lista enlazada sera 6->NULL
    append(&head, 6);

    //Insertar 7 al inicio. La lista enlazada sera 7->6->NULL
    push(&head, 7);

    //Insertar 1 al inicio. La lista enlazada sera 1->7->6->NULL
    push(&head, 1);

    //Insertar 4 al inicio. La lista enlazada sera 4->1->7->6->NULL
    append(&head,4);

    // Insertar 8, despues de 7.  La lista enlazada sera 1->7->8->6->4->NULL
    insertAfter(head->next, 8);

    cout << endl;
    cout << "Mostrar DLL: ";
    printList(head);
    cout << endl;

    //Borrar 7.  La lista enlazada sera 1->8->6->4->NULL
    deleteNode(&head, head->next);

    cout << endl;
    cout << "Mostrar DLL con datos borrados: ";
    printList(head);
    cout << endl;
}

/* Dada una referencia (puntero a puntero) a la cabeza de la lista y un entero,
insertar un nuevo nodo en el frente de la lista.*/
void push(Node** head_ref, int new_data)
{
    // 1.Asignar el nuevo nodo
    Node* new_node = new Node;

    // 2.Metemos los datos
    new_node->data = new_data;

    // 3.Hacemos el nuevo nodo la cabeza y el anterior como NULL
    new_node->next = (*head_ref);  
    new_node->prev = NULL;

    // 4.Cambiar el previo de la cabeza del nodo para el nuevo nodo
    if ((*head_ref) != NULL)
    {
        (*head_ref)->prev = new_node;
    }

    // 5.Mover la cabeza para que apunte al nuevo nodo
    (*head_ref) = new_node;   
}

/*
Pasar un nodo como prev_node, insertar un nuevo nodo despues del nodo pasado
a la funcion.*/
void insertAfter(Node* prev_node, int new_data)
{
    // 1.Verificar el nodo es NULL
    if (prev_node == NULL)
    {
        cout << endl;
        cout << "El nodo pasado a la funcion no puede estar vacio.";
        cout << endl;
    }

    // 2. Asignar el nuevo nodo
    Node* new_node = new Node; 

    // 3. Metemos los datos
    new_node->data = new_data;

    // 4.Hacer que el nuevo nodo como el siguiente de prev-node
    new_node->next = prev_node->next; 

    // 5. Hacer el siguiente de prev_node como new_node
    prev_node->next = new_node;  

    // 6.Hacer prev_node como el anteriod de new_node
    new_node->prev = prev_node;  

    // 7.Cambiar el anterior del siguiente nodo de new_node 
    if (new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
}

/*Pasar una referencia (puntero a puntero) a la cabeza de un DLL y un int,
añadir un nuevo nodo al final*/
void append(Node** head_ref, int new_data)
{
    // 1. Asigar el nuevo nodo 
    Node* new_node = new Node;

    // Se utiliza en el paso 5
    Node* last = *head_ref;

    // 2.Metemos los datos
    new_node->data = new_data;

    // 3.Este nuevo nodo va a ser el ultimo nodo, asi que se hacemos el siguiente del nodo como NULL
    new_node->next = NULL;

    // 4.Si la lista esta vacia, hacemos el nuevo nodo como la cabeza
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;  
        *head_ref = new_node;  
        return;
    }

    // 5.De lo contrario, atraviesa hasta el ultimo nodo
    while (last->next != NULL)
    {
        last = last->next;  
    }
    
    // 6.Cambiar el siguiente del ultimo nodo
    last->next = new_node;

    // 7.Hacer el ultimo nodo como el anterior del nuevo nodo
    new_node->prev = last; 

    return;
}

/*Borrar un nodo de la lista. head_ref --> puntero al puntero del nodo cabeza.
del --> puntero al nodo que se desea borrar.*/
void deleteNode(Node** head_ref, Node* del) 
{
    // 1.Chequear que el nodo no sea NULL
    if (*head_ref == NULL || del == NULL)
    {
        cout << endl;
        cout << "El nodo pasado a la funcion esta vacio.";
        cout << endl;
    }

    // 2.Si el nodo a borrar es el nodo cabeza
    if (*head_ref == del)
    {
        *head_ref = del->next;
    }
    
    // 3.Cambiar el siguiente solo si el nodo que se borra no el ultimo
    if (del->next != NULL)
    {
        del->next->prev = del->prev;
    }
    
    // 4.Cambiar el prev solo si el nodo a borrar no es el el nodo cabeza
    if (del->prev != NULL)
    {
        del->prev->next = del->next;
    }
    
    // 5.Limpiar memoria usada por el puntero borrado
    delete(del);
}

/*Esta funcion imprime los contenidos de una lista doblemente enlazada iniciando
desde un nodo en especifico*/
void printList(Node* node)
{
    Node* last;
    cout << endl;
    cout << "Recorrer de la cabeza al final";
    cout << endl;

    while (node != NULL)  
    {  
        cout<<" "<< node->data <<" ";  
        last = node;  
        node = node->next;  
    }  
    
    cout << endl;
    cout << "Recorrer de el final a la cabeza";
    cout << endl;

    while (last != NULL)  
    {  
        cout<<" "<< last->data <<" ";  
        last = last->prev;  
    } 
}


