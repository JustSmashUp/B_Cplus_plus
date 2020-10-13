#include <iostream>
#include <queue>
using namespace std;


struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};

//utility

void swap(int &a, int &b);
int max (int a, int b);
int height (Node * root);
int getfactor(Node * root);
//rotation type
Node * leftRotation(Node * root);
Node * rightRotation(Node * root);

//rotation

Node * rotation(Node * root)
{
    int factor = getfactor(root);
    if (factor > 1 && getfactor(root->left) >= 0 )
        root = leftRotation(root);
    else if (factor > 1 && getfactor(root->left) < 0)
    {
        root->left = rightRotation(root->left);
        root = leftRotation(root);
    }
    else if (factor < -1 && getfactor(root->right) < 0)
        root = rightRotation(root);
    else if (factor < -1 && getfactor(root->right) >= 0)
    {
        root->right = leftRotation(root->right);
        root = rightRotation(root);
    }

    return root;
}

//creating newNode
Node * createNode(int data)
{
    Node * new_node = new Node;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;

}

Node * insert(Node * root, int data)
{
    if (root == NULL)
        root = createNode(data);

    if (root->data > data)
        root->left = insert(root->left, data);
    else if (root->data < data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = 1 + max (height(root->left), height(root->right));

    int factor = getfactor(root);


    if (factor > 1 || factor < -1)
    {
        root = rotation(root);
    }

    return root;
}

void traverse ( queue <Node *> &mem)
{

    if(mem.front() == NULL)
        return ;
    while (!mem.empty())
    {
        Node * root = mem.front();
        if (root->left != NULL)
            mem.push(root->left);

        if (root->right != NULL)
            mem.push(root->right);

        cout << root->data << " ";
        mem.pop();
    }

}

void traverse (Node * root)
{
    if (root == NULL)
        return ;

    traverse(root->left);
    cout << root->data << " ";
    traverse(root->right);
}


Node * minValue(Node * root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}
Node * deletion(Node * root, int data)
{
    if (root == NULL)
        return NULL;



    if (root->data == data)
    {

        if (root->left == NULL || root->right == NULL)
        {
            Node * tmp = root->left ? root->left : root->right;
            if (tmp == NULL)
            {
                root = NULL;
            }
            else
            {
                *root = *tmp;
                delete tmp;
            }
        }
        else
        {
            Node * tmp = minValue(root->right);
            root->data = tmp->data;
            root->right = deletion(root->right, tmp->data);
        }
    }

    else if (root->data > data)
    {
        root->left = deletion(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = deletion(root->right, data);
    }

    if (root != NULL)
    {
        root->height = 1 + max(height(root->left), height(root->right));
        root = rotation(root);
    }

    return root;
}
int main()
{
    Node * root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 16);
    root = insert(root, 17);
    root = insert(root, 5);
    root = insert(root, 13);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 14);
    root = insert(root, 11);
    root = deletion (root, 15);
    root = deletion (root, 10);
    root = deletion (root, 5);
    root = deletion (root, 16);
  //   root = deletion (root, 4);
    root = insert(root, 9);




    queue <Node *> mem;
    mem.push(root);
    traverse(root);

}

//Rotation

Node * leftRotation(Node * root)
{

    Node * head = root;
    Node * left = root->left;


    head->left = left->right;
    left->right = head;

    root = left;

    root->right->height = 1 + max(height(root->right->left), height(root->right->right));
    root->height = 1 + max(height(root->left), height(root->right));

    return root;
}


Node * rightRotation(Node * root)
{
     Node * head = root;
     Node * right = root->right;


     head->right = right->left;
     right->left = head;
     root = right;
     root->left->height = 1 + max(height(root->left->left), height(root->left->right));
     root->height = 1 + max(height(root->left), height(root->right));
     return root;
}



//utility

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int max (int a, int b)
{
    return a > b ? a : b;
}

int height (Node * root)
{
    if (root == NULL)
        return 0;

    return root->height;
}

int getfactor(Node * root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

