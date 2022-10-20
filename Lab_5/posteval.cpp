// program to evaluate a postfix expression

#include <iostream>
using namespace std;

class stk
{
private:
    int top;
    int stack[20];
public:
    stk()
    {
        top = -1;
    }
    void push(int);
    int pop();
    int eval(char);
};

void stk::push(int x)
{
    if (top == 19)
    {
        cout << "Stack overflow";
        return;
    }
    top++;
    stack[top] = x;
}

int stk::pop()
{
    if (top == -1)
    {
        cout << "Stack underflow";
        return 0;
    }
    int x = stack[top];
    top--;
    return x;
}

int stk::eval(char ch)
{
    int x, y;
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
    case '%':
        x = pop();
        y = pop();
        return y % x;
    default:
        return ch - '0';
    }
}

int main()
{
    stk s;
    char exp[20];
    int i, x;
    cout << "Enter the postfix expression: ";
    cin >> exp;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit(exp[i]))
            s.push(exp[i] - '0');
        else
        {
            x = s.eval(exp[i]);
            s.push(x);
        }
    }
    cout << "The result is: " << s.pop();
    return 0;
}
