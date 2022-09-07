#include <iostream>
using namespace std;

class student
{
    char name[20];
    int roll;
    char grade;

public:
    void read(student s[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter name: ";
            cin >> s[i].name;
            cout << "Enter roll: ";
            cin >> s[i].roll;
            cout << "Enter grade: ";
            cin >> s[i].grade;
        }
    }

    void display(student s[], int n)
    {

        cout << endl << endl << endl << endl << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Name: " << s[i].name << " " << s[i].roll << " "<< s[i].grade << " "<< endl;
        }
    }

    void sort(student s[], int n)
    {
        student temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (s[j].roll > s[j + 1].roll)
                {
                    temp = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = temp;
                }
            }
        }
    }
};

int main()
{
    student s[10];
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    s[0].read(s, n);
    s[0].sort(s, n);
    s[0].display(s, n);
    return 0;
}