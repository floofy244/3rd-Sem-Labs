#include <iostream>
using namespace std;

class node
{   public:
    int data;
    node *next;
};

class csll
{
    private:
    node *head;

    public:
    csll()
    {
        head = NULL;
    }

    void create(int data)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            temp->next = head;
        }
        else
        {
            node *p = head;
            while (p->next != head)
                p = p->next;
            p->next = temp;
            temp->next = head;
        }
    }

    void insertBeginning(int data)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            temp->next = head;
        }
        else
        {
            node *p = head;
            while (p->next != head)
                p = p->next;
            p->next = temp;
            temp->next = head;
            head = temp;
        }
    }

    void display()
    {
        node *p = head;
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
        cout << endl;
    }

};

int main()
{
    int choice, data;
    csll c;
    while (1)
    {
        cout << "1. Create" << endl;
        cout << "2. Insert at beginning" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            c.create(data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            c.insertBeginning(data);
            break;
        case 3:
            c.display();
        default:
            cout << "Invalid choice" << endl;
        }
    }
}

