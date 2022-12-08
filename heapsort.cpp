//heapsort algorithm
#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node *left;
    node *right;
};

class heap
{
    private:
    node *root;

    public:
    heap()
    {
        root = NULL;
    }


    

    

    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapify(int arr[], int size, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < size && arr[l] > arr[largest])
            largest = l;

        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
            heapify(arr, size, largest);
        }
    }

    void heapSort(int arr[], int size)
    {
        for (int i = size/2 - 1; i >=0; i--)
            heapify(arr, size, i);

        for (int i = size - 1; i >= 0; i--)
        {
            swap(&arr[0], &arr[i]);
            heapify(arr, i, 0);
        }

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
    
};

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
     
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    heap bt;

    bt.heapSort(arr, n);
 
    return 0;

}