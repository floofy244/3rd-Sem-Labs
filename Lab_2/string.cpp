#include <iostream>
using namespace std;



int str_length(char s[])
{
    int i;
    for (i = 0; s[i]; i++);



   return i;



}



void str_concat()
{
    int i = 0, j = 0;
    char s1[50], s2[50], s3[100];
    fflush(stdin);
    cout << "Enter a string: ";
    cin.get(s1, 50);
    fflush(stdin);
    cout << "Enter string to be appended: ";
    cin.get(s2, 50);
    fflush(stdin);



   while (s1[i] != '\0')
    {
        s3[j] = s1[i];
        j++; i++;
    }
    i = 0;



    while (s2[i] != '\0')
    {
        s3[j] = s2[i];
        j++; i++;
    }
    s3[j] = '\0';
    cout << "Concatenated string: " << s3 << endl;



}



void str_comp()
{
    int i = 0, flag = 0;
    char s1[50], s2[50];
    fflush(stdin);
    cout << "Enter a string: ";
    cin.get(s1, 50);
    fflush(stdin);
    cout << "Enter string to be compared: ";
    cin.get(s2, 50);
    fflush(stdin);



   while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            flag = 1;
            break;
        }
        i++;
    }
    if (flag == 0)
        cout << "Strings are the same" << endl;
    else
        cout << "Strings are not the same" << endl;



}




void str_sub()
{
    int i = 0, p = 0, r = 0;
    int t = 0;
    int x, g, s, n, o;
    fflush(stdin);
    char s1[50], s2[50], s3[50];
    cout << "Enter a string: ";
    cin.get(s1, 50);
    fflush(stdin);
    cout << "Enter string to be added: ";
    cin.get(s2, 50);
    fflush(stdin);
    cout << "Enter position: ";
    cin >> p;



   r = str_length(s1);
    n = str_length(s2);



   while (i <= r)
    {
        s3[i] = s1[i];
        i++;
    }
    s = n + r;
    o = p + n;



   for (i = p; i < s; i++)
    {
        x = s3[i];
        if (t < n)
        {
            s1[i] = s2[t];
            t += 1;
        }
        s1[o] = x;
        o += 1;
    }



   cout << "Final string: " << s1 << endl;



}



void str_del()
{
   char s1[100], subs1[20];
   int i, j, ls, lw, temp, chk=0;
   fflush(stdin);
   cout << "Enter the String: ";
   cin.get(s1,100);
   fflush(stdin);
   cout << "Enter a Word: ";
   cin.get(subs1,20);
   fflush(stdin);
   ls = str_length(s1);
   lw = str_length(subs1);
   for(i=0; i<ls; i++)
   {
      temp = i;
      for(j=0; j<lw; j++)
      {
         if(s1[i]==subs1[j])
            i++;
      }
      chk = i-temp;
      if(chk==lw)
      {
         i = temp;
         for(j=i; j<(ls-lw); j++)
            s1[j] = s1[j+lw];
         ls = ls-lw;
         s1[j]='\0';
      }
   }
   cout << "New string is : " << s1;
}




int main()
{
    //menu driven
    float result;
    int choice, num;
    cout << "Press 1 to find length\n";
    cout << "Press 2 to concantenate\n";
    cout << "Press 3 to compare strings\n";
    cout << "Press 4 to add substring\n";
    cout << "Press 5 to delete substring\n";
    cout << "Enter your choice:\n";
    cin >> choice;



   switch (choice) {
    case 1: {
        char s1[50];
        fflush(stdin);
        cout << "Enter a string: ";
        cin.get(s1, 50);
        fflush(stdin);
        cout << str_length(s1)<< endl;
        break;
    }
    case 2: {
        str_concat();
        break;
    }
    case 3: {
        str_comp();
        break;
    }
    case 4:{
        str_sub();
        break;
    }
    case 5:{
        str_del();
        break;
    }
    default:
        cout << "wrong Input\n";
    }



   return 0;
}