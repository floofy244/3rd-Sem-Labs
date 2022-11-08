// represent polynomials using linked lists and perform the following operations on them:
// addition, subtraction, multiplication.

#include <iostream>
using namespace std;

class node
{
public:
    int coeff;
    int exp;
    node *next;
    node *prev;
};

class DLL
{
private:
    node *head;
    node *tail;

public:

    DLL()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int coeff, int exp)
    {
        node *temp = new node;
        temp->coeff = coeff;
        temp->exp = exp;
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->coeff << "x^" << temp->exp << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse()
    {
        node *temp = tail;
        while (temp != NULL)
        {
            cout << temp->coeff << "x^" << temp->exp << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void add(DLL p1, DLL p2)
    {
        node *temp1 = p1.head;
        node *temp2 = p2.head;

        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->exp == temp2->exp)
            {
                insert(temp1->coeff + temp2->coeff, temp1->exp);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if (temp1->exp > temp2->exp)
            {
                insert(temp1->coeff, temp1->exp);
                temp1 = temp1->next;
            }
            else
            {
                insert(temp2->coeff, temp2->exp);
                temp2 = temp2->next;
            }
        }

        while (temp1 != NULL)
        {
            insert(temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        }

        while (temp2 != NULL)
        {
            insert(temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    }

    void subtract(DLL p1, DLL p2)
    {
        node *temp1 = p1.head;
        node *temp2 = p2.head;

        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->exp == temp2->exp)
            {
                insert(temp1->coeff - temp2->coeff, temp1->exp);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if (temp1->exp > temp2->exp)
            {
                insert(temp1->coeff, temp1->exp);
                temp1 = temp1->next;
            }
            else
            {
                insert(-temp2->coeff, temp2->exp);
                temp2 = temp2->next;
            }
        }
    }

    void multiply(DLL p1, DLL p2)
    {
        node *temp1 = p1.head;
        node *temp2 = p2.head;

        while (temp1 != NULL)
        {
            while (temp2 != NULL)
            {
                insert(temp1->coeff * temp2->coeff, temp1->exp + temp2->exp);
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
            temp2 = p2.head;
        }
    }
};

int main()
{
    DLL p1, p2, p3, p4, p5;

    p1.insert(2, 3);
    p1.insert(3, 2);
    p1.insert(4, 1);
    p1.insert(5, 0);

    p2.insert(1, 2);
    p2.insert(2, 1);
    p2.insert(3, 0);

    p3.add(p1, p2);
    p4.subtract(p1, p2);
    p5.multiply(p1, p2);

    p1.display();
    p2.display();
    p3.display();
    p4.display();
    p5.display();

    return 0;
}