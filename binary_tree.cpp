#include <iostream>
#include <stack>

using namespace std;

typedef struct Node
{
    int data;
    Node * left;
    Node * right;
} Node;


/*================procedural method*/
Node * createNode(int data)
{
    Node * new_node =(Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

Node * insert(Node * &root, int data)
{
    if ( root == NULL )
    {
        root = createNode(data);
    }
    else if (root->data >= data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

bool search(Node * root,int data)
{
    // iterative method
   /* while (root != NULL)
    {
        if (root->data == data)
        {
            return true;
        }

        if (root->data > data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
    */

    //recursion

    if ( root == NULL )
        return false;
    if ( root->data = data )
        return true;

    if ( root ->data > data )
        return search( root->left, data );
    else
        return search( root->right, data );
}

/*===========OOP Model ==========*/
class BST
{
    private:
        Node * root;
        int size;

    public:
        Node * createNode(int data)
        {
            Node * new_node;
            new_node = new Node;
            new_node->data = data;
            new_node->left = NULL;
            new_node->right = NULL;
            return new_node;
        }

        void insert(int data)
        {
            if (root == NULL)
                root = createNode(data);
            else
            {
                Node * tmp = root;

                while (tmp != NULL)
                {
                    if (tmp->data >= data)
                    {
                        if (tmp->left != NULL)
                            tmp = tmp->left;
                        else
                        {
                            tmp->left = createNode(data);
                            break;
                        }
                    }
                    else
                    {
                        if (tmp->right != NULL)
                            tmp = tmp->right;
                        else
                        {
                            tmp->right = createNode(data);
                            break;
                        }
                    }
                }
            }
        }

        //in-order traversal (ascending order)
        Node * inorder(Node * root)
        {
            if (root == NULL)
                return NULL;

            inorder(root->left);
            cout << root->data <<endl;
            inorder(root->right);

        }

        //pre-order traversal (descending order)
        Node * preorder(Node * root)
        {
            if (root == NULL)
                return NULL;

            preorder(root->right);
            cout << root->data<<endl;
            preorder(root->left);
        }

        //post-order traversal (leaf by leaf)


        void traverse(int value)
        {
            switch(value)
            {
                case 0:
                    inorder(root);
                case 1:
                    preorder(root);
            }
        }
        BST()
        {
            root = NULL;
            size = 0;
        }
};
int main()
{
    Node * root = NULL;
    BST o;
    o.insert(5);
    o.insert(8);
    o.insert(3);
    o.traverse(0);


}
