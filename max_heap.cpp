/*#include <iostream>

using namespace std;

int * heap()
{
    static int arr[1000];
    return arr;
}

void check_parent(int * arr, int child)
{
    if (child == 1)
        return;
    int parent = child / 2;
    while (*(arr+parent) < *(arr+child))
    {
        int tmp = *(arr+parent);
        *(arr+parent) = *(arr+child);
        *(arr+child) = tmp;

        child = parent;
        parent = child/2;
        if (child == 1)
        break;
    }
}
void insert(int *arr, int data)
{
    int i = 1;
    while(*(arr+i) != NULL)
        i++;
    *(arr+i) = data;
    check_parent(arr, i);
}

void traverse(int *p, int i)
{
    int child = i*2;
    if (*(p+child) == NULL && *(p+child-1) == NULL)
    {
        cout << (*p) <<endl;
        return;
    }

    if (*(p+child-1) == NULL)
    {
        cout << *(p+child) <<endl;
        traverse(p, child-1);
    }
    else if (*(p+child) ==  NULL)
    {
        cout << *(p+child-1) <<endl;
        traverse(p, child);
    }
    else if (*(p+child-1) != NULL && *(p+child) != NULL)
    {
        if (*(p+child-1) > *(p+child))
        {
            cout << *(p+child-1) <<endl;
            traverse(p, child);
        }
    }
}
int main()
{
    int * h = heap();

    insert(h, 5);
    insert(h, 8);
     insert(h, 6);
    insert(h, 9);
    insert(h, 4);
    insert(h, 3);
    cout << *(h+3);
}
*/



#include <iostream>

using namespace std;

struct heap
{
    int size;
    int mem[1000];
};


heap * createHeap()
{
    heap * new_heap = new heap;
    new_heap->size = 1;
    return new_heap;
}
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//helper
void check_parent(heap * &root, int child)
{

    int parent = child / 2;
    int tmp;



    while (root->mem[parent] < root->mem[child])
    {
        if (parent == 0)
            return;
        swap (root->mem[parent], root->mem[child]);
        tmp = parent;
        parent = parent / 2;
        child = tmp;

    }
}
void insert(heap * &root, int data)
{
    root->mem[root->size] = data;
    check_parent(root, root->size);
    root->size++;
}

//helper
void check_child(heap * &heap, int parent, int range)
{
    int child = parent * 2;

    if (heap->mem[child] > heap->mem[child+1])
        child = child;
    else
        child = child + 1;



    while (heap->mem[parent] < heap->mem[child])
    {
        if (child > range)
            return;
        swap(heap->mem[parent], heap->mem[child]);
        parent = child;

        child = parent * 2;
        if (heap->mem[child] > heap->mem[child+1])
            child = child;
        else
            child = child + 1;
    }

}
void traverse(heap * heap)
{
    int i = heap->size - 1;
    while (i >= 1)
    {
        cout << heap->mem[1] << endl;
        heap->mem[1] = heap->mem[i];
        check_child(heap, 1, i-1);
        i--;
    }
}

void deletion (heap * &root, int data)
{
    int parent;
    for ( int i = 1; i < root->size; i++)
    {
        if (root->mem[i] == data)
        {

            root->mem[i] = root->mem[root->size -1];
            root->mem[root->size - 1] = NULL;
            check_child(root, i, root->size - 2);
            root->size --;
            break;
        }
        parent = i / 2;

        if (parent > 0 && root->mem[parent] < data)
            break;

    }
}
int main()
{
    heap * t = createHeap();
    insert(t, 5);
    insert(t, 5);
    insert(t, 5);
    insert(t, 5);
    insert(t, 10);
    insert(t, 5);



   // deletion(t, 10);

    traverse (t);



}





























