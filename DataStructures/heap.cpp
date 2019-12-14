#include <iostream>
using namespace std;

class MinHeap
{
    int *arr;
    int capacity;
    int heap_size;
public:
    MinHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        arr = new int[cap];
    }

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int parent(int i)
{
    return (i-1)/2;
}

int left(int i)
{
    return (2*i + 1);
}

int right(int i)
{
    return (2*i + 2);
}

int getMin()
{
    return arr[0];
}

void insertKey(int key)
{
    if (heap_size == capacity)
    {
        cout << "Overflow" << endl;
    }

    heap_size++;
    int i = heap_size - 1;
    arr[i] = key;

    while (i != 0 && arr[parent(i)] > arr[i])
    {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}

void decreaseKey(int i, int new_val)
{
    arr[i] = new_val;
    while (i != 0 && arr[parent(i)] > arr[i])
    {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}

void minHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && arr[l] < arr[i])
        smallest = l;
    if (r <heap_size && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        minHeapify(smallest);
    }
}

int extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return arr[0];
    }
    int root = arr[0];
    arr[0] = arr[heap_size - 1];
    heap_size--;
    minHeapify(0);

    return root;
}

void deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

};

int main()
{
    MinHeap myHeap(10);
    myHeap.insertKey(3);
    myHeap.insertKey(2);
    myHeap.deleteKey(1);
    myHeap.insertKey(15);
    myHeap.insertKey(4);
    myHeap.insertKey(44);
    cout << myHeap.extractMin() << endl;
    cout << myHeap.getMin() << endl;
    myHeap.decreaseKey(2, 1);
    cout << myHeap.getMin() << endl;
    return 0;
}
