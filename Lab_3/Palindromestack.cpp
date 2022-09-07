#include <iostream>

using namespace std;

class stk
{
    char s[100];
    int top;

    public:

    stk()
    {
        top = -1;
    };

    void push(char a)
    {
        if (top == sizeof(s) - 1) { cout << "Stack Overflow"; return;}

        s[++top] = a;
    }

    char pop()
    {
        if (top == -1) { cout << "stack underflow";}

        return(s[top--]);
    }

    void palindrome(char str1[])
    {
        for (int i = 0; str1[i] != '\0'; i++) { push(str1[i]);}

        for (int i = 0; str1[i] != '\0'; i++)
        {
            if ( pop() != str1[i]) 
            {
                cout << "Not a Palindrome";
                return;
            }
        }

        cout << "It is a palidrome";
        return;
    }
};


int main()
{
    stk s1;
    char str[100];

    cout << "Enter a string: ";
    cin.get(str, 100);
    

    s1.palindrome(str);

}