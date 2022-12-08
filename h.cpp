void preorderiterative()
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