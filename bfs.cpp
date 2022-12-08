void breadthFirstSearch()
{
    if (root == NULL)
        return;
    node *p = root;
    node *s[] = new node[100];
    int front = -1;
    int rear = -1;
    s[++rear] = p;
    while (front != rear)
    {
        p = s[++front];
        cout<<p->data<<" ";
        if (p->left)
            s[++rear] = p->left;
        if (p->right)
            s[++rear] = p->right;
    }
}

void depthFirstSearch()
{
    if (root == NULL)
        return;
    node *p = root;
    node *s[] = new node[100];
    int top = -1;
    s[++top] = NULL;
    while (p || s[top] != NULL)
    {
        cout<<p->data<<" ";
        if (p)
        {
            s[++top] = p;
            p = p->left;
        }
        else
        {
            p = s[top--];
            p = p->right;
        }
    }
}