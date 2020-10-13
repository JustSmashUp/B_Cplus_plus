#include <iostream>

using namespace std;

typedef struct node
{
    struct node * prev;
    struct node * next;
    int data;
}node;

class linkedList
{
    private:
        int size; //size of the list
        node * head; // point the first node of the list
        node * tail; // point the last node of the list

        node * createNode()
        {
            node * new_node;
            new_node = (node *) malloc(sizeof(node)); //allocate memory inside heap
            new_node->prev = NULL;
            new_node->next = NULL;
            return new_node;
        }

    public:
        void insertFront(int data)
        {
            node * new_node = createNode();
            new_node->data = data;

            if (size == 0)
            {
                head = new_node;
                tail = head; //first inserted node will be the tail, tail will be changed when insertEnd will be called;
            }
            else
            {
                node * tmp = head;
                head = new_node;
                head->next = tmp;
                tmp->prev = head;
            }
            size++;
        }

        void show()
        {
            node * tmp;
            tmp = head;

            while (tmp != NULL)
            {

                cout << tmp->data <<" "; //forward print
                if (tmp->next == NULL)
                {
                    cout <<endl<< "reverse "<< endl;
                    while (tmp != NULL)
                    {
                        cout <<tmp->data << " "; //reverse print
                        tmp = tmp->prev;
                    }
                    break;
                }
                tmp = tmp->next;
            }
        }

        void deleteFront()
        {
            if (size != 0)
            {
                node * tmp = head;
                head = head->next;
                head->prev = NULL;
                free(tmp);
                size--;
            }
        }
        void deleteEnd()
        {
            if(size != 0 )
            {
                node * tmp = tail;
                tail = tail->prev;
                tail->next = NULL;
                free(tmp);
                size--;
            }
        }
        void insertEnd(int data)
        {
            if(size != 0)
            {
                node * new_node = createNode();
                new_node->data = data;

                new_node->prev = tail;
                tail->next = new_node;
                tail = new_node;
                size++;
            }
            else
            {
                insertFront(data);
            }
        }
        linkedList()
        {
            size = 0;
            head = NULL;
        }

        void insertN(int data, int n)
        {
            node * tmp = head;
            node * new_node = createNode();
            new_node->data = data;

            if (n == 1)
                insertFront(data);
            if (n == size + 1)
                insertEnd(data);
            else
            {
                for (int i = 2; i < n; i++)
                {
                    tmp = tmp->next;
                }


                tmp->next->prev = new_node;
                new_node->next = tmp->next;

                new_node->prev = tmp;
                tmp->next = new_node;

            }
            size++;
        }

        void deleteN(int n)
        {
            if ( n== 1 )
                deleteFront();
            else if (n == size)
                deleteEnd();
            else
            {
                node *tmp = head;
                node *tmp_2 = tmp->next;
                for (int i = 2; i < n; i++)
                    tmp = tmp->next;

                tmp->next = tmp->next->next;

                if(tmp->next != NULL)
                    tmp->next->prev = tmp;

                free(tmp_2);
            }
        }

        int get_front ()
        {
            return head->data;
        }

        int get_end()
        {
            return tail->data;
        }

};

class Stack
{
    private:
        int size;
        linkedList mem;

    public:
        void push(int data)
        {
            mem.insertFront(data);
            size++;
        }

        void pop()
        {
            mem.deleteFront();
            size--;
        }

        int peek()
        {
            return mem.get_front();
        }

        bool isEmpty()
        {
            if (size == 0)
                return true;
            return false;

        }

        Stack()
        {
            size = 0;
        }

};

class Queue
{
    private:
        int size;
        linkedList mem;

    public:
        void enque(int data)
        {
            mem.insertEnd(data);
            size++;
        }


        void deque()
        {
            mem.deleteFront();
            size--;
        }

        int peek()
        {
            return mem.get_front();
        }

        bool isEmpty()
        {
            if (size == 0)
                return true;
            return false;
        }
};

int main(void)
{
    Queue m;

    m.enque(3);
    m.enque(8);
    m.enque(43);

    while (!m.isEmpty())
    {
        cout << m.peek() << endl;
        m.deque();
    }

}
