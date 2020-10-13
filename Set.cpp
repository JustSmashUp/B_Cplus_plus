#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node * left;
  Node * right;
};
class BST
{
    private:
        int size;
        Node * root;

        //utility
        Node * createNode(int data)
        {
            Node * newNode = new Node;
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }

        void traverseAsc(Node * head, int * container, int &i)
        {
            if (head == NULL)
                return ;

            traverseAsc(head->left, container, i);
            *(container + i) = head->data;
            i++;
            traverseAsc(head->right, container,i);
        }

        void traverseDsc(Node * head, int * container, int &i)
        {
            if (head == NULL)
                return;

            traverseDsc(head->right, container, i);
            *(container + i) = head->data;
            i++;
            traverseDsc(head->left, container, i);
        }

        Node * deleteHelper(Node * &head, int data)
        {
            if (head == NULL)
                return NULL;
            if (head->data == data)
            {
                if (head->left != NULL && head->right != NULL)
                {
                    Node * tmp = head->right;

                    if (tmp->left == NULL)
                    {
                        tmp->left = head->left;
                        delete head;
                        head = tmp;
                        size--;
                        return head;
                    }

                    while (tmp->left == NULL && tmp->right == NULL)
                    {
                        if (tmp->left == NULL)
                            tmp = tmp->right;
                        else
                            tmp = tmp->right;
                    }
                    head->data = tmp->data;
                    delete tmp;
                    size--;
                    return head;

                }

                else if (head->left == NULL)
                {
                    Node * tmp = head;
                    head = head->right;
                    delete tmp;
                    size--;
                    return head;
                }
                else if (head->right == NULL)
                {
                    Node * tmp = head;
                    head = head->left;
                    delete tmp;
                    size--;
                    return head;
                }
                else
                {
                    delete head;
                    head = NULL;
                    size--;
                    return head;
                }
            }

            else if (head->data > data)
            {
                head->left = deleteHelper(head->left, data);
                return head;
            }
            else
            {
                head->right = deleteHelper(head->right, data);
                return head;
            }
        }


    public:

        int sizeOf ()
        {
            return size;
        }
        void deletion(int data)
        {
           root = deleteHelper(root, data);
        }
        void insert(int data)
        {
            if (root == NULL)
            {
                root = createNode(data);
                size++;
                return;
            }

            Node * tmp = root;
            while (true)
            {
                if (tmp->data == data)
                {
                    break;
                }

                if (tmp->data > data)
                {
                    if (tmp->left != NULL)
                        tmp = tmp->left;
                    else
                    {
                        tmp->left = createNode(data);
                        size++;
                        return;
                    }
                }
                else
                {
                    if(tmp->right != NULL)
                        tmp = tmp->right;
                    else
                    {
                        tmp->right = createNode (data);
                        size++;
                        return;
                    }
                }
            }
        }

        int * traverse(int choice)
        {
            int * mem = new int[size];
            if (choice == 0)
            {

                 int i = 0;
                 traverseAsc(root, mem, i);
            }
            else
            {
                int i = 0;
                traverseDsc(root, mem, i);
            }
            return mem;
        }

        int max()
        {
            Node * head = root;

            while (true)
            {
                if (head->right == NULL)
                    return head->data;
                else
                    head = head->right;
            }

        }

        int min()
        {
            Node * head = root;

            while (true)
            {
                if (head->left == NULL)
                    return head->data;
                else
                    head = head->left;
            }

        }

        BST()
        {
            root = NULL;
            size = 0;
        }
};

class Set
{
    private :
        BST mem;
        int type;

    public :
        int sizeOf()
        {
            return mem.sizeOf();
        }
        void pop (int data)
        {
            mem.deletion(data);

        }
        void insert(int data)
        {
            mem.insert(data);

        }

        int * traverse()
        {
            return mem.traverse(type);
        }

        int top()
        {
            if (type == 0)
                return mem.min();
            else
                return mem.max();
        }

        Set(int choice)
        {

            type = choice;
        }
};

int main()
{
    Set t(1);
    t.insert(5);
    t.insert(20);
    t.insert(3);
    t.insert(5);
    t.insert(220);
    t.insert(3);
    t.pop(5);


    int * ptr = t.traverse();
    int size = t.sizeOf();

    for (int i = 0; i < size; i++)
    {
        cout << *(ptr+i) << " ";
    }
}
