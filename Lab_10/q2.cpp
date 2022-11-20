// Write a recursive function to i) Create a binary tree and ii) print a binary tree

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
};


class tree
{
private:

    node *root;
public:

    tree(int size)
    {
        root = NULL;
    }

    void createRecursive()
    {
        root = createRecursive(root);
    }

    node *createRecursive(node *p)
    {
        int x;
        cout << "Enter data (0 for no node): ";
        cin >> x;
        if (x == 0)
            return NULL;
        p = new node;
        p->data = x;
        cout << "Enter left child of " << x << endl;
        p->left = createRecursive(p->left);
        cout << "Enter right child of " << x << endl;
        p->right = createRecursive(p->right);
        return p;
    }

    void displayRecursive()
    {
        displayRecursive(root);
        cout << endl;
    }

    void displayRecursive(node *p)
    {
        if (p)
        {
            cout << p->data << " ";
            displayRecursive(p->left);
            displayRecursive(p->right);
        }
    }

};

int main()
{
    tree t(100);
    t.createRecursive();
    t.displayRecursive();
    return 0;
}