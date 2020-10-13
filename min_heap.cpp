#include <iostream>

using namespace std;

class MinHeap
{
    private:
        int mem[1000];
        int index;

        //helper method
        void swap (int &a, int &b)
        {
            int tmp = a;
            a = b;
            b = tmp;
        }
        void check_parent(int child)
        {
            int parent = child / 2;

            while (mem[child] < mem[parent])
            {
                if (parent < 1)
                    break;
                swap(mem[child], mem[parent]);

                child = parent;
                parent = parent / 2;
            }
        }

        void check_child(int parent, int range)
        {
            int child = parent * 2;

            if (mem[child] > mem[child + 1])
                child = child + 1;


            while (mem[child] < mem[parent])
            {
                if (child > range)
                    break;
                swap(mem[child], mem[parent]);
                parent = child;
                child = child * 2;
                if (mem[child] > mem[child + 1])
                    child = child + 1;


            }

        }

    public:




        //main method
        void insert(int data)
        {
            mem[index] = data;
            check_parent(index);
            index++;
        }

        void traverse()
        {
            int i = index - 1;

            while (i > 0)
            {
                cout << mem[1] <<endl;
                mem[1] = mem[i];
                check_child(1, i - 1);
                i--;
            }


        }

        void print()
        {
            for (int i = 1; i < index; i++)
                cout << mem[i] << " ";

            cout << endl;
        }

        void deletion(int data)
        {
            int parent;
            for (int i = 1; i < index; i++)
            {
                cout << "loop" << endl;
                if (mem[i] == data)
                {
                    mem[i] = index - 1;
                    mem[index - 1] = NULL;
                    check_child(i, index - 2);

                    index--;
                    break;
                }

                parent = i / 2;

                //optimization
                if (parent != 0 &&  data < mem[parent])
                {
                    if (i % 2 == 0)
                    {
                        i ++;
                    }
                }
            }
        }
        MinHeap()
        {
            int index = 1;
        }
};

int main()
{
    MinHeap r;
    r.insert(5);
    r.insert(2);
    r.insert(1);
    r.insert(5);
    r.insert(6);
    r.insert(4);
    r.insert(7);
    r.deletion(3);
    r.print();
   // r.print();
    r.traverse();
}
