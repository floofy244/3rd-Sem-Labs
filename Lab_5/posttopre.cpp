// convert postfix to prefix

#include <iostream>
#include <string>
using namespace std;

class stack
{
private:
    char *s;
    int top;
    int size;

public:

    stack(int size)
    {
        this->size = size;
        s = new char[size];
        top = -1;
    }

    void push(char x)
    {
        if (top == size - 1)
            cout << "Stack Overflow" << endl;
        else
            s[++top] = x;
    }

    char pop()
    {
        char x = -1;
        if (top == -1)
            cout << "Stack Underflow" << endl;
        else
            x = s[top--];
        return x;
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
            cout << s[i] << " ";
        cout << endl;
    }

    bool isOperand(char x)
    {
        if (x == '+' || x == '-' || x == '*' || x == '/')
            return false;
        else
            return true;
    }

    int reverse(char *postfix)
    {
        int i = 0, x = 0;
        while (postfix[i] != '\0')
        {
            if (isOperand(postfix[i]))
                push(postfix[i]);
            else
            {
                x = pop();
                push(postfix[i]);
                push(x);
            }
            i++;
        }
        return top;
    }

    void convert(char *postfix)
    {
        int i = 0, j = 0;
        char *prefix = new char[size];
        int index = reverse(postfix);
        while (index != -1)
        {
            prefix[j++] = pop();
            index--;
        }
        prefix[j] = '\0';
        cout << "Prefix: " << prefix << endl;
    }
    
};

int main()
{
    char postfix[] = "ab*c+";
    int size = sizeof(postfix) / sizeof(postfix[0]);                    
    stack stk(size);
    stk.convert(postfix);
    return 0;
}