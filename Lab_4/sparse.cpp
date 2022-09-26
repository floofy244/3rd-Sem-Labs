#include <bits/stdc++.h>
using namespace std;



class SPM
{
    public:
    int row, col, val;
    SPM*input(SPM arr[],int r,int c);
    void display(int r,int c,SPM arr[100]);
    SPM*transpose(int r,int c,SPM arr[100],SPM transp[100]);
};



SPM*SPM::input(SPM arr[100],int r,int c)
    {
        cout << "Enter the elements of the matrix: " << endl;
        int k=1;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                int e;
                cin>>e;
                if(e!=0)
                {
                   arr[k].row=i;
                   arr[k].col=j;
                   arr[k].val=e;
                   k++;
                }
            }
        }
        arr[0].row=r;
        arr[0].col=c;
        arr[0].val=k;
        return arr;
    }



   void SPM::display(int r,int c,SPM a[100])
    {
        cout << "The sparse matrix is: " << endl;
        int k=1;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(a[k].row==i && a[k].col==j)
                {cout<< a[k].row << " " << a[k].col << " " << a[k].val << endl;k++;}
            }
        }



   }
    SPM*SPM::transpose(int r,int c,SPM arr[100],SPM transp[100])
    {
        cout<<"entered"<<endl;
        int sp[100]={0};int mp[100];
        transp[0].row=arr[0].col;transp[0].col=arr[0].row;transp[0].val=arr[0].val;
        for(int i=1;i<=arr[0].val;i++)
        {
           mp[i]=0;
        }
        cout<<"entered"<<endl;
        for(int i=1;i<=arr[0].val;i++)
        {
            mp[arr[i].col]++;
        }
        cout<<"entered"<<endl;
        sp[0]=1;
        for(int i=1;i<=arr[0].col;i++)
        {
            sp[i]=sp[i-1]+mp[i-1];
        }
        cout<<"entered"<<endl;
        int j;
        for(int i=1;i<arr[0].val;i++)
        {cout<<"entered"<<endl;
            j=sp[arr[i].col]++;
            transp[j].row=arr[i].col;
            transp[j].col=arr[i].row;
            transp[j].val=arr[i].val;
        }
         cout<<"entered"<<endl;
         cout << "The transpose matrix is: " << endl;
        int k=1;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(transp[k].row==i && transp[k].col==j)
                {cout<<transp[k].val<<" ";k++;}
                else
                {cout<<0<<" ";}
            }
            cout << endl;
        }
        return transp;
    }
int main()
{
    cout << "Enter the dimensions of matrix:" << endl;
    int r,c;
    cin>>r>>c;
    SPM m;char ch;
    SPM a[100];
    m.input(a,r,c);
    m.display(r,c,a);
    cout<<"enter y if you want to take transpose:"<<endl;
    cin>>ch;
    if(ch=='y')
    {
        SPM transp[100];
        m.transpose(r,c,a,transp);



   }
    return 0;
}