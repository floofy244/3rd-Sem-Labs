#include <iostream>
using namespace std;

class node
{
public:
    int data;
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

public:

    tree()
    {
        root = NULL;
    }

    void create()
    {
        node *p, *t;
        int x;
        stack stk(100);

        cout << "Enter root value: ";
        cin >> x;
        root = new node;
        root->data = x;
        root->left = root->right = NULL;
        stk.push(root);

        while (!stk.isEmpty())
        {
            p = stk.pop();
            cout << "Enter left child of " << p->data << ": ";
            cin >> x;
            if (x != -1)
            {
                t = new node;
                t->data = x;
                t->left = t->right = NULL;
                p->left = t;
                stk.push(t);
            }
            cout << "Enter right child of " << p->data << ": ";
            cin >> x;
            if (x != -1)
            {
                t = new node;
                t->data = x;
                t->left = t->right = NULL;
                p->right = t;
                stk.push(t);
            }
        }
    }

    void preorderIterative()
    {
        stack stk(100);
        node *p = root;

        while (p || !stk.isEmpty())
        {
            if (p)
            {
                cout << p->data << " ";
                stk.push(p);
                p = p->left;
            }
            else
            {
                p = stk.pop();
                p = p->right;
            }
        }
        cout << endl;
    }

    void inorderIterative()
    {
        stack stk(100);
        node *p = root;

        while (p || !stk.isEmpty())
        {
            if (p)
            {
                stk.push(p);
                p = p->left;
            }
            else
            {
                p = stk.pop();
                cout << p->data << " ";
                p = p->right;
            }
        }
        cout << endl;
    }

    void postorderIterative()
    {
        stack stk(100);
        node *p = root;
        node *last = NULL;

        while (p || !stk.isEmpty())
        {
            if (p)
            {
                stk.push(p);
                p = p->left;
            }
            else
            {
                p = stk.pop();
                if (p->right && p->right != last)
                {
                    stk.push(p);
                    p = p->right;
                }
                else
                {
                    cout << p->data << " ";
                    last = p;
                    p = NULL;
                }
            }
        }
        cout << endl;
    }

    void parent(int key)
    {
        stack stk(100);
        node *p = root;

        while (p || !stk.isEmpty())
        {
            if (p)
            {
                if (p->data == key)
                {
                    cout << "Parent of " << key << " is " << stk.pop()->data << endl;
                    return;
                }
                stk.push(p);
                p = p->left;
            }
            else
            {
                p = stk.pop();
                p = p->right;
            }
        }
        cout << "Element not found" << endl;
    }

    int depth(node *p)
    {
        int x = 0, y = 0;
        if (p == NULL)
            return 0;
        x = depth(p->left);
        y = depth(p->right);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }

    void depth()
    {
        cout << "Depth of the tree is " << depth(root) << endl;
    }

    void ancestors(int key)
    {
        stack stk(100);
        node *p = root;

        while (p || !stk.isEmpty())
        {
            if (p)
            {
                if (p->data == key)
                {
                    cout << "Ancestors of " << key << " are: ";
                    while (!stk.isEmpty())
                        cout << stk.pop()->data << " ";
                    cout << endl;
                    return;
                }
                stk.push(p);
                p = p->left;
            }
            else
            {
                p = stk.pop();
                p = p->right;
            }
        }
        cout << "Element not found" << endl;
    }

    void leafNodes()
    {
        stack stk(100);
        node *p = root;

        while (p || !stk.isEmpty())
        {
            if (p)
            {
                if (p->left == NULL && p->right == NULL)
                    cout << p->data << " ";
                stk.push(p);
                p = p->left;
            }
            else
            {
                p = stk.pop();
                p = p->right;
            }
        }
        cout << endl;
    }

};

int main()
{
    tree t; 
    t.create();
    t.preorderIterative();
    t.inorderIterative();
    t.postorderIterative();
    t.parent(1);
    t.depth();
    t.ancestors(50);
    t.leafNodes();
    return 0;
}