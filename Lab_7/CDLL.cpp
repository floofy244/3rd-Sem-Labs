// circular doubly linked list

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
};

class CDLL
{
private:
    node *head;
    node *tail;

public:

    CDLL()
    {
        head = NULL;
        tail = NULL;
    }

    void append(int elem)
    {
        node *temp = new node;
        temp->data = elem;
        temp->next = head;
        temp->prev = tail;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            head->prev = temp;
            tail = temp;
        }
    }

    void insert_after(int elem, int value)
    {
        node *temp = new node;
        temp->data = elem;
        node *trav = head;
        bool found = false;
        while (trav != NULL)
        {
            if (trav->data == value)
            {
                temp->next = trav->next;
                temp->prev = trav;
                trav->next = temp;
                found = true;
                break;
            }
            trav = trav->next;
        }
        if (!found)
        {
            cout << "Element not found!" << endl;
        }
    }

    void insert_before(int elem, int value)
    {
        node *temp = new node;
        temp->data = elem;
        node *trav = head;
        bool found = false;

        if (trav->data == value)
        {
            head = temp;
            temp->next = trav;
            temp->prev = tail;
            return;
        }
        while (trav->next != NULL)
        {
            if (trav->next->data == value)
            {
                temp->next = trav->next;
                temp->prev = trav;
                trav->next = temp;
                found = true;
                break;
            }
            trav = trav->next;
        }
        if (!found)
        {
            cout << "Element not found!" << endl;
        }
    }

    void display()
    {
        node *trav = head;
        while (trav != NULL)
        {
            cout << trav->data << " ";
            trav = trav->next;
        }
        cout << endl;
    }
};
