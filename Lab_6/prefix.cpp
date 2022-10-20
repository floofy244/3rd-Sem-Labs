// Write  a  program  to  input  an  infix  expression  and  convert  into  its  equivalent  prefix form and display. Operands can be single character.

#include <iostream>
using namespace std;


class stk
{
public:
    int top;
    char stack[20];

    stk()
    {
        top = -1;
    }
    void push(char);
    char pop();
    int  priority(char);
};

void stk::push(char x)
{
    if (top == 19)
    {
        cout << "Stack overflow";
        return;
    }
    top++;
    stack[top] = x;
}

char stk::pop()
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

int stk::priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    stk s;
    char infix[20], prefix[20], x, token;
    int i = 0, j = 0;
    cout << "Enter infix expression: ";
    cin >> infix;
    while ((token = infix[i++]) != '\0')
    {
        if (token == '(')
            s.push(token);
        else if (isalnum(token))
            prefix[j++] = token;
        else if (token == ')')
        {
            while ((x = s.pop()) != '(')
                prefix[j++] = x;
        }
        else
        {
            while (s.priority(s.stack[s.top]) >= s.priority(token))
                prefix[j++] = s.pop();
            s.push(token);
        }
    }
    while (s.top != -1)
        prefix[j++] = s.pop();
    prefix[j] = '\0';
    cout << "Prefix expression: " << prefix;
    return 0;
}