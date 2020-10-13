#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef struct Node
{
    int data;
    Node * left;
    Node * right;
} Node;



/*================procedural method*/
/*
Node * createNode(int data)
{
    Node * new_node =new Node;
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
/*
    if ( root == NULL )
        return false;
    if ( root->data = data )
        return true;

    if ( root ->data > data )
        return search( root->left, data );
    else
        return search( root->right, data );
}

void traverse(Node * root)
{
    //method 1: using recursion

    if (root == NULL)
        return;

    traverse(root->right);

    cout << root->data <<endl;
    traverse(root->left);




    //method 2: using queue

    /*queue <Node *> mem;
    mem.push(root);
    Node * tmp;
    while (!mem.empty())
    {
        tmp = mem.front();
        if (tmp->left != NULL)
            mem.push(tmp->left);

        if (tmp->right !=NULL )
            mem.push(tmp->right);

        cout << tmp->data << endl;
        mem.pop();

    }
}
*/
/*
Node * delNode(Node * &root, int data)
{
    if (root == NULL)
        return NULL;
    if (root->data  == data )
    {
        //case 1
        if (root->left == NULL && root->right == NULL )
        {
            free(root);
            root = NULL;
            return root;
        }

        //case 2
        if (root->left != NULL && root->right != NULL )
        {
            Node * tmp = root->right;

            if (tmp->left == NULL)
            {
                tmp->left = root->left;
                Node * tmp2 = root; //for free up the memory
                root = tmp;
                free(tmp2);
                return root;
            }


            while (tmp ->left != NULL && tmp->right != NULL)
            {
                if (tmp->left == NULL)
                    tmp = tmp->right;
                else
                    tmp = tmp->left;
            }
            root->data = tmp->data;
            return root;
        }

        //case 3
        if (root->right != NULL )
        {
            Node * tmp = root;
            root = root->right;
            free(tmp);
            return root;
        }

        //case 4
        if (root->left != NULL )
        {
            Node * tmp = root;
            root = root->left;
            free(tmp);
            return root;
        }
    }
    if (root->data > data)
    {
        root->left = delNode(root->left, data);
        return root;
    }

    else
    {
        root->right = delNode(root->right, data);
        return root;
    }
}


/*===========OOP Model ==========*/
class BST
{
    private:
        Node * root;
        int size;
        //helping function for deleting
        Node * remove_leaf_get(Node * head, Node * &storage)
        {
            if (head->left == NULL && head->right == NULL)
            {
                storage->data = head->data;
                delete head;
                head = NULL;

            }

            else if (head->left == NULL)
                head->right = remove_leaf_get(head->right, storage);
            else
                head->left = remove_leaf_get(head->left, storage);

            return head;
        }
        Node * deleteNode(Node * &root, int data)
        {

            if (root == NULL)
                return NULL;
            if (root->data == data)
            {
                if (root->left == NULL && root->right == NULL)
                {
                    delete root;
                    root = NULL;
                    return root;
                }

                if (root->left == NULL)
                {
                    Node * tmp = root;
                    root = root->right;
                    delete tmp;
                    tmp = NULL;
                    return root;
                }
                if (root->right == NULL)
                {
                    Node * tmp = root;
                    root = root->left;
                    delete tmp;
                    return root;
                }
                else
                {
                    Node * tmp = root->right;
                    Node * tmp2 = root;
                    if (tmp->left == NULL)
                    {
                        tmp->left = root->left;
                        root = tmp;
                        delete tmp2;
                        return root;
                    }
                    else
                    {

                    //method 1:
                    /*
                       while (tmp->left != NULL || tmp->right != NULL)
                       {
                           if (tmp->left == NULL)
                            tmp = tmp->right;
                           else
                            tmp = tmp->left;
                       }

                       int a= tmp->data;
                       deleteNode(root, tmp->data);
                       root->data = a;
                       return root;
                       */

                       //method 2: with the help of remove_leaf_ge
                        root->right->left = remove_leaf_get(root->right->left, root);
                        return root;
                    }
                }
            }
            else if (root->data > data)
            {
                root->left = deleteNode(root->left, data);
                return root;
            }
            else
            {
                root->right = deleteNode(root->right, data);
                return root;
            }
        }

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

        Node * postorder(Node * root)
        {
            if (root == NULL)
                return NULL;

            postorder(root->left);
            postorder(root->right);
            cout << root->data <<endl;
        }

        void unique_insert(int data)
        {
            Node * tmp = root;

            while (tmp != NULL)
            {
                if (tmp->data == data)
                    break;

                if (tmp->data > data)
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
        void traverse(int value)
        {
            switch(value)
            {
                case 0:
                    inorder(root);
                    break;
                case 1:
                    preorder(root);
                    break;
                case 2:
                    postorder(root);
                    break;
                default:
                    inorder(root);


            }
        }


        void deleteItem(int data)
        {
            deleteNode (root, data);
        }
        BST()
        {
            root = NULL;
            size = 0;
        }
};


int main()
{

   /* BST o;*/

 Node * root = NULL;
/*
    cout << "procedural" <<endl;
    insert(root,5);
    insert(root,10);
    insert(root, 6);
    insert(root, 11);
    traverse(root);
    delNode(root,1);


    cout << "oop" <<endl;
*/
    BST o;
    o.insert(5);
    o.insert(10);
    o.insert(6);
    o.insert(11);
    o.insert(7);
    o.insert(12);

    o.deleteItem(10);
    o.traverse(2);

}
