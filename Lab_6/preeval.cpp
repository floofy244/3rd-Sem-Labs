//Program to evaluate a Prefix Expression using character array

#include <iostream>
using namespace std;

class Stack
{
    int top;
    char *s;
    int size;
public:

    Stack(int size)
    {
        this->size = size;
        top = -1;
        s = new char[size];
    }

    void push(char x);
    char pop();
    int isFull();
    int isEmpty();
    char stackTop();
};

void Stack::push(char x)
{
    if (isFull())
        cout << "Stack Overflow" << endl;
    else
    {
        top++;
        s[top] = x;
    }
}

char Stack::pop()
{
    char x = -1;
    if (isEmpty())
        cout << "Stack Underflow" << endl;
    else
    {
        x = s[top];
        top--;
    }
    return x;
}

int Stack::isFull()
{
    if (top == size - 1)
        return 1;
    return 0;
}

int Stack::isEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}

char Stack::stackTop()
{
    if (isEmpty())
        return -1;
    return s[top];
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int preEval(char *prefix)
{
    Stack stk(strlen(prefix));
    int i = strlen(prefix) - 1;
    int x1, x2, r;

    while (i >= 0)
    {
        if (isOperand(prefix[i]))
            stk.push(prefix[i] - '0');
        else
        {
            x1 = stk.pop();
            x2 = stk.pop();
            switch (prefix[i])
            {
            case '+':
                r = x1 + x2;
                stk.push(r);
                break;
            case '-':
                r = x1 - x2;
                stk.push(r);
                break;
            case '*':
                r = x1 * x2;
                stk.push(r);
                break;
            case '/':
                r = x1 / x2;
                stk.push(r);
                break;
            }
        }
        i--;
    }
    return stk.pop();
}

int main()
{
    char *prefix = "-+7*45+20";
    cout << "Result is " << preEval(prefix) << endl;
    return 0;
}
