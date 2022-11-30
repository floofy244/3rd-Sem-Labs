
#include <iostream>
using namespace std;

class node
{
public:
    char data;
    node *left;
    node *right;
};

class stack
{
private:
    node *s[100];
    int top;
    int size;

public:

    stack(int size)
    {
        this->size = size;
        top = -1;
    }

    void push(node *x)
    {
        if (top == size - 1)
            cout << "Stack Overflow" << endl;
        else
            s[++top] = x;
    }

    node *pop()
    {
        node *x = NULL;
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

    bool isEmpty()
    {
        return top == -1;
    }
};

class tree
{
private:

    node *root;
    stack *stk;

public: 

    tree(int size)
    {
        root = NULL;
        stk = new stack(size);
    }

    void createTree(char *postfix)
    {
        node *t, *t1, *t2;
        int i = 0;

        while (postfix[i] != '\0')
        {
            if (isOperand(postfix[i]))
            {
                t = new node;
                t->data = postfix[i];
                t->left = t->right = NULL;
                // cout << t -> data << " ";
                stk->push(t);
            }
            else
            {
                t = new node;
                t->data = postfix[i];
                // cout << t -> data << " ";
                t2 = stk->pop();
                t1 = stk->pop();
                t->right = t2;
                t->left = t1;
                stk->push(t);
            }
            i++;
        }
        root = stk->pop();
    }

    void preorder(node *p)
    {
        if (p)
        {
            cout << p->data << " ";
            preorder(p->left);
            preorder(p->right);
        }
    }

    void inorder(node *p)
    {
        if (p)
        {
            inorder(p->left);
            cout << p->data << " ";
            inorder(p->right);
        }
    }

    void postorder(node *p)
    {
        if (p)
        {
            postorder(p->left);
            postorder(p->right);
            cout << p->data << " ";
        }
    }

    void display()
    {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }

    bool isOperand(char x)
    {
        if (x == '+' || x == '-' || x == '*' || x == '/')
            return false;
        else
            return true;
    }
};

int main()
{
    tree t(100);
    char postfix[] = "ABC*+D/";
    t.createTree(postfix);
    t.display();
    return 0;
}
