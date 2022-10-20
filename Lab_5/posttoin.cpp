// postfix to infix

#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int top;
    char stack[20];

public:
    Stack()
    {
        top = -1;
    }
    void push(char);
    char pop();
    char eval(char);
};

void Stack::push(char x)
{
    if (top == 19)
    {
        cout << "Stack overflow";
        return;
    }
    top++;
    stack[top] = x;
}

char Stack::pop()
{
    if (top == -1)
    {
        cout << "Stack underflow";
        return 0;
    }
    char x = stack[top];
    top--;
    return x;
}

char Stack::eval(char ch)
{
    char x, y;
    switch (ch)
    {
    case '+':
        x = pop();
        y = pop();
        return y + x;
    case '-':
        x = pop();
        y = pop();
        return y - x;
    case '*':
        x = pop();
        y = pop();
        return y * x;
    case '/':
        x = pop();
        y = pop();
        return y / x;
    }
}

int main()
{
    Stack s;
    char exp[20], *e, x;
    cout << "Enter the postfix expression: ";
    cin >> exp;
    e = exp;
    while (*e != '\0')
    {
        if (isalnum(*e))
            s.push(*e);
        else
        {
            x = s.eval(*e);
            s.push(x);
        }
        e++;
    }
    cout << "The infix expression is: " << s.pop();
    return 0;
}
