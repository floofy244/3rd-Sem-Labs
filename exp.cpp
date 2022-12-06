//expression tree using postfix

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
        if(top == size-1)
            cout<<"Stack Overflow"<<endl;
        else
            s[++top] = x;
    }

    node *pop()
    {
        node *x = NULL;
        if(top == -1)
            cout<<"Stack Underflow"<<endl;
        else
            x = s[top--];
        return x;
    }

    void display()
    {
        for(int i=top;i>=0;i--)
            cout<<s[i]<<" ";
        cout<<endl;
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

    node *createNode(char data)
    {
        node *temp = new node;
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    void createTree(char postfix[])
    {
        stack st(100);
        node *t, *t1, *t2;
        for(int i=0;postfix[i]!='\0';i++)
        {
            if(isOperand(postfix[i]))
            {
                t = createNode(postfix[i]);
                st.push(t);
            }
            else
            {
                t = createNode(postfix[i]);
                t1 = st.pop();
                t2 = st.pop();
                t->right = t1;
                t->left = t2;
                st.push(t);
            }
        }
        root = st.pop();
    }

    bool isOperand(char x)
    {
        if(x == '+' || x == '-' || x == '*' || x == '/')
            return false;
        else
            return true;
    }

    void display()
    {
        display(root);
        cout<<endl;
    }

    void display(node *p)
    {
        if(p)
        {
            display(p->left);
            cout<<p->data<<" ";
            display(p->right);
        }
    }

    void preorder()
    {
        preorder(root);
        cout<<endl;
    }

    void preorder(node *p)
    {
        if(p)
        {
            cout<<p->data<<" ";
            preorder(p->left);
            preorder(p->right);
        }
    }

    void inorder()
    {
        inorder(root);
        cout<<endl;
    }

    void inorder(node *p)
    {
        if(p)
        {
            inorder(p->left);
            cout<<p->data<<" ";
            inorder(p->right);
        }
    }

    void postorder()
    {
        postorder(root);
        cout<<endl;
    }

    void postorder(node *p)
    {
        if(p)
        {
            postorder(p->left);
            postorder(p->right);
            cout<<p->data<<" ";
        }
    }

    int evaluate()
    {
        return evaluate(root);

    }

    int evaluate(node *p)
    {
        if(p)
        {
            if(isOperand(p->data))
                return p->data - '0';
            else
            {
                int x = evaluate(p->left);
                int y = evaluate(p->right);
                if(p->data == '+')
                    return x+y;
                else if(p->data == '-')
                    return x-y;
                else if(p->data == '*')
                    return x*y;
                else
                    return x/y;
            }
        }
    }

};

int main()
{
    tree t;
    char postfix[100];
    cout<<"Enter postfix expression: ";
    cin>>postfix;
    t.createTree(postfix);
    cout<<"Infix expression: ";
    t.inorder();
    cout<<"Prefix expression: ";
    t.preorder();
    cout<<"Postfix expression: ";
    t.postorder();
    cout<<"Result: "<<t.evaluate()<<endl;
    return 0;
}
