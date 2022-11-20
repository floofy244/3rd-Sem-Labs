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

    node *insert(node *root, int data)
    {
        if (root == NULL)
            root = createNode(data);
        else if (data < root->data)
            root->left = insert(root->left, data);
        else if (data > root->data)
            root->right = insert(root->right, data);
        return root;
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
            t.insert(t.getRoot(), data);
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