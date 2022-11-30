// binary search tree

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

    tree()
    {
        root = NULL;
    }
    node *createNode(int data)
    {
        node *temp = new node;
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    void insert(int data)
    {
        node *temp = createNode(data);
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            node *p = root;
            node *q = NULL;
            while (p != NULL)
            {
                q = p;
                if (data < p->data)
                    p = p->left;
                else
                    p = p->right;
            }
            if (data < q->data)
                q->left = temp;
            else
                q->right = temp;
        }
    }

    void deleteIterative(int data)
    {
        node *parent = NULL;
        node *current = root;
        while (current != NULL && current->data != data)
        {
            parent = current;
            if (data < current->data)
                current = current->left;
            else
                current = current->right;
        }
        if (current == NULL)
            return;
        if (current->left == NULL && current->right == NULL)
        {
            if (parent == NULL)
                root = NULL;
            else if (parent->left == current)
                parent->left = NULL;
            else
                parent->right = NULL;
            delete current;
        }
        else if (current->left == NULL)
        {
            if (parent == NULL)
                root = current->right;
            else if (parent->left == current)
                parent->left = current->right;
            else
                parent->right = current->right;
            delete current;
        }
        else if (current->right == NULL)
        {
            if (parent == NULL)
                root = current->left;
            else if (parent->left == current)
                parent->left = current->left;
            else
                parent->right = current->left;
            delete current;
        }
        else
        {
            node *temp = findMin(current->right);
            current->data = temp->data;
            deleteIterative(temp->data);
        }
    }
    node *deleteNode(node *root, int data)
    {
        if (root == NULL)
            return NULL;
        else if (data < root->data)
            root->left = deleteNode(root->left, data);
        else if (data > root->data)
            root->right = deleteNode(root->right, data);
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            else if (root->left == NULL)
            {
                node *temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == NULL)
            {
                node *temp = root;
                root = root->left;
                delete temp;
            }
            else
            {
                node *temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;
    }

    
    int search(node *root,int data)
    {
        if (root == NULL)
            return 0;
        else if (root->data == data)
            return 1;
        else if (data <= root->data)
            return search(root->left, data);
        else
            return search(root->right, data);
    }

    void display(node *root)
    {
        if (root != NULL)
        {
            display(root->left);
            cout << root->data << " ";
            display(root->right);
        }
    }
    
    node *findMin(node *root)
    {
        if (root == NULL)
            return NULL;
        else if (root->left == NULL)
            return root;
        else
            return findMin(root->left);
    }

    node *findMax(node *root)
    {
        if (root == NULL)
            return NULL;
        else if (root->right == NULL)
            return root;
        else
            return findMax(root->right);
    }

    node *getRoot()
    {
        return root;
    }
};

int main()
{
    tree t;
    int choice, data;
    while (1)
    {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            t.insert(data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            t.deleteNode(t.getRoot(), data);
            break;
        case 3:
            cout << "Enter data: ";
            cin >> data;
            if (t.search(t.getRoot(), data) == 1)
                cout << "Found" << endl;
            else
                cout << "Not Found" << endl;
            break;
        case 4:
            t.display(t.getRoot());
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}