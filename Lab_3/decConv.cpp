#include <iostream>
using namespace std;

class stk
{
    int s[100];
    int top;

    public:

    stk()
    {
        top = -1;
    };

    void push(int a)
    {
        if (top == sizeof(s) - 1) { cout << "Stack Overflow"; return;}

        s[++top] = a;
    }

    int pop()
    {
        if (top == -1) { cout << "stack underflow";}

        return(s[top--]);
    }

    void decConv(int num, int base)
    {
        int rem;
        while (num != 0)
        {
            rem = num % base;
            push(rem);
            num = num / base;
        }

        while (top != -1)
        {
            cout << pop();
        }
    }
};

int main()
{
    stk s1;
    int num, base;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Enter the base: ";
    cin >> base;

    s1.decConv(num, base);

    return 0;
}