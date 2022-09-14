#include <bits/stdc++.h>
using namespace std;

class sparseMatrix
{
    int row, col, value;
    int **arr;

    public:

    sparseMatrix(int r, int c, int v)
    {
        row = r;
        col = c;
        value = v;
        arr = new int*[row];
        for(int i = 0; i < row; i++)
        {
            arr[i] = new int[col];
        }
    } 

    void input()
    {
        cout << "Enter the elements of the matrix: " << endl;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cin >> arr[i][j];
            }
        }
    }

    void display()
    {
        cout << "The matrix is: " << endl;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    void sparse()
    {
        int count = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(arr[i][j] != 0)
                {
                    count++;
                }
            }
        }
        cout << "The number of non-zero elements are: " << count << endl;
        sparseMatrix s(row, col, count);
        int k = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(arr[i][j] != 0)
                {
                    s.arr[k][0] = i;
                    s.arr[k][1] = j;
                    s.arr[k][2] = arr[i][j];
                    k++;
                }
            }
        }
        cout << "The sparse matrix is: " << endl;
        for(int i = 0; i < count; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << s.arr[i][j] << " ";
            }
            cout << endl;
        }
    }


};

int main()
{
    int r, c;
    cout << "Enter the number of rows: ";
    cin >> r;
    cout << "Enter the number of columns: ";
    cin >> c;
    sparseMatrix m(r, c, 0);
    m.input();
    m.display();
    m.sparse();
    return 0;
}