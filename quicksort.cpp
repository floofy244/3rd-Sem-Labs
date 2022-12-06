#include <iostream>
using namespace std;


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int h)
{
    int pi = arr[h];
    int i = l - 1;

    for (int j = l; j < h; j++)
    {
        if (arr[j] < pi)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);

    return i + 1;
}

void quicksort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        quicksort(arr, l, p - 1);
        quicksort(arr, p + 1, h);


    }
}



int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements: ";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quicksort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}