// Define  a  class timewith  data  members  hour,  min,  sec  .Write  the  user  defined functions  to  (i)  Add  (ii)  To  find  difference  between  two  objects  of  class  time. Functions take two time objects as argument and  return time object. Also write the display and read function.

#include <iostream>
using namespace std;

class time
{
    int hour;
    int min;
    int sec;

public:

    void read(time t[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter hour: ";
            cin >> t[i].hour;
            cout << "Enter min: ";
            cin >> t[i].min;
            cout << "Enter sec: ";
            cin >> t[i].sec;
        }
    }

    void display(time t[], int n)
    {
        cout << endl << endl << endl << endl << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Time: " << t[i].hour << ":" << t[i].min << ":" << t[i].sec<< endl;
        }
    }

    void add(time t[], int n)
    {
        time temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (t[j].hour > t[j + 1].hour)
                {
                    temp = t[j];
                    t[j] = t[j + 1];
                    t[j + 1] = temp;
                }
            }
        }
    }
};

int main()
{
    time t[10];
    int n;
    cout << "Enter number of times: ";
    cin >> n;
    t[0].read(t, n);
    t[0].add(t, n);
    t[0].display(t, n);
}