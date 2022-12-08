#include<iostream>
#include<string.h>
#include <stdio.h>
using namespace std;
class bt
{
    private:
    char data;
    bt* lc;
    bt* rc;
    public:
    bt *root;
    bt()
    {
        root=NULL;
    }
   
    bt* crtbt()
    {
        // bt* temp=new bt;
        // temp=NULL;
        bt* s[10];
        int i=0;
        int top=-1;
        s[++top]=NULL;
        char e[50];
        cout<<"Enter an Expression"<<endl;
        gets(e);
        for (i = 0; e[i] != '\0'; i++)
        {
            cout<<i;
            bt* temp=new bt;
            temp->lc = NULL;
            temp->rc = NULL;
            temp->data=e[i];
            cout<<i;
            if(e[i]>='0' || e[i]<='9')
            {
                cout<<i;
                s[++top]=temp;
            }
            else
            {
                cout<<i;
                temp->rc=s[top--];
                temp->lc=s[top--];
                s[++top]=temp;
            }
            
        }
        cout<<"Hello";
        root=s[top];
        
        return root;
    }
    void inorder()
    {
        bt* curr = new bt;
        curr=root;
        bt* s[10];
        int top=-1;
        s[++top]=NULL;
        while(curr || s[top]!=NULL)
        {
            if(curr)
            {
                s[++top]=curr;
                curr=curr->lc;
            }
            else
            {
                curr=s[top--];
                cout<<curr->data<<" ";
                curr=curr->rc;
            }
        }
        cout<<endl;
    }
};
int main()
{
    bt b;
    b.crtbt();
    b.inorder();
    return 0;
}