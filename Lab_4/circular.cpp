#include <bits/stdc++.h>

using namespace std;

class qu
{
    int front, rear;
    int q[100];
    int size;
    
    public:
    qu()
    {
        front = 0;
        rear = -1;
    }

    int dequeue()
    {
        if (front > rear) {return -1;}

        return q[front++];
    }

    int insertq(int a, int size)
    {
        if (rear == size-1) { cout << "queue overflow"; return -1;}
        q[++rear] = a;
    }
};

int main()
{
    qu q;
    int size;
    cout << "Enter size of queue: ";
    cin >> size;
    int a[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element: ";
        cin >> a[i];
    }
    for (int i = 0; i < size; i++)
    {
        q.insertq(a[i], size);
    }
    
    cout <<"removed element: "<< q.dequeue() << " ";
    return 0;
}