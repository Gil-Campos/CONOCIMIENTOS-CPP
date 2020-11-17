/**
-Recorido Inorder:
inorder(root -> left)
display(root -> data)
inorder(root -> right)

-Recorrido Preorder:
display(root -> data)
preorder(root -> left)
preorder(root -> right)

-Recorrido Postoder:
postorder(root -> left)
postorder(root -> right)
display(root -> data)
*/

#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;
};

//Prototipo de funciones
void recorridoPreorder(struct Node* node);
void recorridoPostOrder(struct Node* node);
void recorridoInorder(struct Node* node);

int main()
{
    return 0;
}

void recorridoPreorder(struct Node* node)
{
    if(node == NULL)
    {
        return;
    }

    cout << node->data << "->";
    recorridoPreorder(node->left);
    recorridoPreorder(node->right);
}

