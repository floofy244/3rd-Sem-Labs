
#include <iostream>
using namespace std;

class Stack
{
    char *arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new char[size];
        top = -1;
    }

    void push(char x)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    char pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    char peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

bool isMatchingPair(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return true;
    else if (character1 == '{' && character2 == '}')
        return true;
    else if (character1 == '[' && character2 == ']')
        return true;
    else
        return false;
}

bool areBracketsBalanced(char exp[])
{
    int i = 0;

    Stack *stack = new Stack(100);

    while (exp[i])
    {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            stack->push(exp[i]);
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {
            if (stack->isEmpty())
                return false;
            else if (!isMatchingPair(stack->pop(), exp[i]))
                return false;
        }
        i++;
    }

    if (stack->isEmpty())
        return true;
    else
        return false;
}  


int main()
{
    char exp[100];
    cout << "Enter the expression: ";
    cin >> exp;
    if (areBracketsBalanced(exp))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
    return 0;
}