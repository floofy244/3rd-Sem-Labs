// A binary search tree is represented by struct TreeNode
// {
// int data;
// struct TreeNlode* left;
// struct TreeNlode* right;
// y
// Implement the following function:
// int CountOfSubtrees (struct TreeNode* root, int low, int high)


#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isInRange(int data, int low, int high)
{
    return (data >= low && data <= high);
}

bool getCountUtil(struct TreeNode* root, int low, int high, int& count)
{
    if (root == NULL)
        return true;
    
    bool left = getCountUtil(root->left, low, high, count);
    bool right = getCountUtil(root->right, low, high, count);
    
    if (left && right && isInRange(root->data, low, high))
    {
        count++;
        return true;
    }
    
    return false;
}

int getCount(struct TreeNode* root, int low, int high)
{
    int count = 0;
    getCountUtil(root, low, high, count);
    return count;
}

struct TreeNode* newNode(int data)
{
    struct TreeNode* temp = new struct TreeNode;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main()
{
    struct TreeNode* root = newNode(6);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->right->right = newNode(9);
    
    int low = 5, high = 17;
    cout << "Count of subtrees in [" << low << ", " << high << "] is "
    << getCount(root, low, high);
    return 0;
}