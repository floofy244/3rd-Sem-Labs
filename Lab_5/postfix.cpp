// Write a program to input an infix expression and convert into its equivalent post fix form and display. Operands can be single character.

#include <iostream>
using namespace std;

class stack
{
    public:
    
    char s[20];
    int top;


    stack()
    {
        top = -1;
    }

    void push(char x)
    {
        s[++top] = x;
    }

    char pop()
    {
        return s[top--];
    }

    int priority(char x)
    {
        if (x == '(')
            return 0;
        if (x == '+' || x == '-')
            return 1;
        if (x == '*' || x == '/')
            return 2;
        return 0;
    }
};

int main()
{
    stack s;
    char infix[20], postfix[20], x, token;
    int i = 0, j = 0;
    cout << "Enter infix expression: ";
    cin >> infix;
    while ((token = infix[i++]) != '\0')
    {
        if (token == '(')
            s.push(token);
        else if (isalnum(token))
            postfix[j++] = token;
        else if (token == ')')
        {
            while ((x = s.pop()) != '(')
                postfix[j++] = x;
        }
        else
        {
            while (s.priority(s.s[s.top]) >= s.priority(token))
                postfix[j++] = s.pop();
            s.push(token);
        }
    }
    while (s.top != -1)
        postfix[j++] = s.pop();
    postfix[j] = '\0';
    cout << "Postfix expression: " << postfix;
}
