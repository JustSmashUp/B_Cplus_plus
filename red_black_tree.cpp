#include <iostream>

using namespace std;

struct Node
{
    int data, color;
    Node * left;
    Node * right;
    Node * parent;
};
Node * mem[100];

Node * createNode(int data)
{
    Node * new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = new_node->parent = NULL;
    new_node->color = 1;
    return new_node;
}



void recolor(Node * root)
{
    if (root->color == 0)
        root->color = 1;
    else
        root->color = 0;

}
//rotation

Node * leftRotation(Node * root);
Node * rightRotation(Node * root);


Node * rotation( int i)
{

    Node * root = mem[0];

    while(true)
    {
        if(i > 1 && mem[i-1]->color == 1)
        {
            Node * current = mem[i];
            Node * parent = mem[i-1];
            Node * g_parent = mem[i-2];

            if (g_parent->left == parent)
            {
                if (g_parent->right == NULL || g_parent->right->color == 0)
                {

                    if (parent->left == current)
                    {
                        if (i-2 == 0)
                        {
                            root = rightRotation(g_parent);
                        }
                        else
                        {
                            if(mem[i-3]->left == g_parent)
                            {
                                mem[i-3]->left = rightRotation(g_parent);
                            }
                            else
                            {
                                mem[i-3]->right = rightRotation(g_parent);
                            }
                        }
                    }
                    else
                    {
                        g_parent->left = leftRotation(parent);

                        if (i-2 == 0)
                        {
                            root = rightRotation(g_parent);
                        }
                        else
                        {
                            if(mem[i-3]->left == g_parent)
                            {
                                mem[i-3]->left = rightRotation(g_parent);
                            }
                            else
                            {
                                mem[i-3]->right = rightRotation(g_parent);
                           }
                        }
                    }
                    recolor (g_parent);
                    recolor (parent);
                    break;
                }
                else
                {
                    recolor(g_parent->right);
                    recolor(parent);
                    if (i - 2 != 0)
                    {
                        recolor(g_parent);
                        i = i - 2;
                        continue;
                    }
                    break;
                }
            }
            else
            {
                if (g_parent->left == NULL || g_parent->left->color == 0)
                {
                    if (parent->right == current)
                    {
                        if (i - 2 == 0)
                        {
                            root = leftRotation(g_parent);
                        }
                        else
                        {
                            if (mem[i-3]->left == g_parent)
                            {
                                mem[i-3]->left = leftRotation(g_parent);
                            }
                            else
                            {
                                mem[i-3]->right = leftRotation(g_parent);
                            }
                        }

                        recolor(g_parent);
                        recolor(parent);
                    }
                }
                else
                {

                    recolor(parent);
                    recolor(g_parent->left);
                    if (i - 2 == 0)
                    {
                        break;
                    }
                    else
                    {
                        recolor(g_parent);
                        i = i - 2;
                        continue;
                    }

                }
            }
        }
        else
            return root;
    }

    return root;

}



Node * insert(Node * root, int data)
{

    Node * target = root;
    if (root == NULL)
    {
        root = createNode(data);
        root->color = 0;
        return root;
    }

    int i = 0;
    while (target != NULL)
    {
        if (target->data > data)
        {
            if (target->left != NULL)
            {
                mem[i] = target;
                target = target->left;

            }
            else
            {
                target->left = createNode(data);

                mem[i] = target;
                i++;
                mem[i] = target->left;

                break;
            }
        }
        else
        {
            if (target->right != NULL)
            {
                mem[i] = target;
                target = target->right;
            }
            else
            {
                mem[i] = target;
                target->right = createNode(data);

                i++;
                mem[i] = target->right;

                break;
            }
        }

        i++;

    }

    root = rotation(i);
    return root;

}



int leaf(Node * root)
{
    while (root->left != NULL)
    {
        root == root->left;
    }
    return root->data;
}

void black(int i)
{
    while (true)
    {
        if (i - 2 >= 0)
        {
            Node * parent = mem[i-1];
            Node * g_parent = mem[i-2]
        }
        else
            break;
    }
}

Node * deletion(Node * root, int data)
{
     Node * base_root = root;
     int i = 0;
     while (root != NULL)
     {
         mem[i] = root;
         if (root->data == data)
         {
            if (i > 0)
            {
                if (mem[i-1]->data > data)
                {
                    mem[i-1]->left =
                }
            }
            else
            {
                base_root =
            }
         }
         else if (root->data > data)
         {
            root = root->left;
         }
         else
         {
             root = root->right;
         }
         i++;
     }

    return base_root;
}

Node * inOrder(Node * root)
{
    if (root == NULL)
        return NULL;

    inOrder(root->left);
    cout << root->data <<" ";
    inOrder(root->right);
}
int main()
{

    Node * root = NULL;

    root = insert(root, 5);

    root = insert(root, 10);
    root = insert(root, 15);

    root = insert(root, 20);
    root = insert(root, 4);
    deletion(root, 15);


    //inOrder(root);





    return 0;
}


//rotation body

Node * leftRotation(Node * root)
{
    Node * right = root->right;

    root->right = right->left;
    right->left = root;
    root = right;
    right = NULL;
    return root;
}

Node * rightRotation(Node * root)
{
    Node * left = root->left;

    root->left = left->right;
    left->right = root;
    root = left;
    left = NULL;
    return root;
}








