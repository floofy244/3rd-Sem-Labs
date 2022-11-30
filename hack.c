#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int coach_no;
    char name[20];
    long int mob_no;
    char food;
    int vacant_seats;
    struct node *next;
};

struct node *head = NULL;

void create()
{
    struct node *new_node, *temp;
    int i, j, k, n, m;
    char ch;
    printf("Enter the number of CC coaches: ");
    scanf("%d", &n);
    printf("Enter the number of EC coaches: ");
    scanf("%d", &m);
    for (i = 1; i <= n; i++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->coach_no = i;
        new_node->vacant_seats = 10;
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
            temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }
    for (j = 1; j <= m; j++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->coach_no = j;
        new_node->vacant_seats = 5;
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
            temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->vacant_seats == 10)
        {
            printf("Enter the details of the passengers in CC coach %d (10 seats): ", temp->coach_no);
            for (k = 1; k <= 10; k++)
            {
                printf("Enter the name of the passenger: ");
                scanf("%s", temp->name);
                printf("Enter the mobile number of the passenger: ");
                scanf("%ld", &temp->mob_no);
                temp->vacant_seats--;
                temp = temp->next;
            }
        }
        else
        {
            printf("Enter the details of the passengers in EC coach %d (5 seats): ", temp->coach_no);
            for (k = 1; k <= 5; k++)
            {
                printf("Enter the name of the passenger: ");
                scanf("%s", temp->name);
                printf("Enter the mobile number of the passenger: ");
                scanf("%ld", &temp->mob_no);
                printf("Enter the food option of the passenger (V/N): ");
                scanf(" %c", &temp->food);
                temp->vacant_seats--;
                temp = temp->next;
            }
        }
    }
}

void booking()
{
    struct node *new_node, *temp;
    int i, j, k, n, m;
    char ch;
    printf("Enter the number of CC coaches: ");
    scanf("%d", &n);
    printf("Enter the number of EC coaches: ");
    scanf("%d", &m);
    for (i = 1; i <= n; i++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->coach_no = i;
        new_node->vacant_seats = 10;
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
            temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }
    for (j = 1; j <= m; j++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->coach_no = j;
        new_node->vacant_seats = 5;
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
            temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->vacant_seats == 10)
        {
            printf("Enter the details of the passengers in CC coach %d (10 seats): ", temp->coach_no);
            for (k = 1; k <= 10; k++)
            {
                printf("Enter the name of the passenger: ");
                scanf("%s", temp->name);
                printf("Enter the mobile number of the passenger: ");
                scanf("%ld", &temp->mob_no);
                temp->vacant_seats--;
                temp = temp->next;
            }
        }
        else
        {
            printf("Enter the details of the passengers in EC coach %d (5 seats): ", temp->coach_no);
            for (k = 1; k <= 5; k++)
            {
                printf("Enter the name of the passenger: ");
                scanf("%s", temp->name);
                printf("Enter the mobile number of the passenger: ");
                scanf("%ld", &temp->mob_no);
                printf("Enter the food option of the passenger (V/N): ");
                scanf(" %c", &temp->food);
                temp->vacant_seats--;
                temp = temp->next;
            }
        }
    }
}

void display()
{
    struct node *temp;
    temp = head;
    printf("Coach No.\tPassenger Name\tMobile No.\tFood Option (EC only)\tVacant Seats (CC only) \t \t");
    while (temp != NULL)
    {
        if (temp->vacant_seats == 10)
        {
            printf("%d\t\t%s\t\t%ld\t\t\t\t%d \t\t\t\t", temp->coach_no, temp->name, temp->mob_no, temp->vacant_seats);
            temp = temp->next;
        }
        else
        {
            printf("%d\t\t%s\t\t%ld\t\t\t%c \t\t\t\t", temp->coach_no, temp->name, temp->mob_no, temp->food);
            temp = temp->next;
        }
    }
}

void cancel()
{
    struct node *temp;
    int i, j, k, n, m;
    char ch;
    printf("Enter the number of CC coaches: ");
    scanf("%d", &n);
    printf("Enter the number of EC coaches: ");
    scanf("%d", &m);
    for (i = 1; i <= n; i++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->coach_no = i;
        new_node->vacant_seats = 10;
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
            temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }
    for (j = 1; j <= m; j++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->coach_no = j;
        new_node->vacant_seats = 5;
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
            temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->vacant_seats == 10)
        {
            printf("Enter the details of the passengers in CC coach %d (10 seats): ", temp->coach_no);
            for (k = 1; k <= 10; k++)
            {
                printf("Enter the name of the passenger: ");
                scanf("%s", temp->name);
                printf("Enter the mobile number of the passenger: ");
                scanf("%ld", &temp->mob_no);
                temp->vacant_seats--;
                temp = temp->next;
            }
        }
        else
        {
            printf("Enter the details of the passengers in EC coach %d (5 seats): ", temp->coach_no);
            for (k = 1; k <= 5; k++)
            {
                printf("Enter the name of the passenger: ");
                scanf("%s", temp->name);
                printf("Enter the mobile number of the passenger: ");
                scanf("%ld", &temp->mob_no);
                printf("Enter the food option of the passenger (V/N): ");
                scanf(" %c", &temp->food);
                temp->vacant_seats--;
                temp = temp->next;
            }
        }
    }
    temp = head;
    printf("Enter the coach number of the coach in which the passenger is travelling: ");
    scanf("%d", &n);
    printf("Enter the name of the passenger: ");
    scanf("%s", &ch);
    while (temp != NULL)
    {
        if (temp->coach_no == n)
        {
            if (temp->vacant_seats == 10)
            {
                if (strcmp(temp->name, ch) == 0)
                {
                    printf("Enter the name of the passenger: ");
                    scanf("%s", temp->name);
                    printf("Enter the mobile number of the passenger: ");
                    scanf("%ld", &temp->mob_no);
                    temp->vacant_seats++;
                    temp = temp->next;
                }
                else
                {
                    printf("Passenger not found!");
                    temp = temp->next;
                }
            }
            else
            {
                if (strcmp(temp->name, ch) == 0)
                {
                    printf("Enter the name of the passenger: ");
                    scanf("%s", temp->name);
                    printf("Enter the mobile number of the passenger: ");
                    scanf("%ld", &temp->mob_no);
                    printf("Enter the food option of the passenger (V/N): ");
                    scanf(" %c", &temp->food);
                    temp->vacant_seats++;
                    temp = temp->next;
                }
                else
                {
                    printf("Passenger not found!");
                    temp = temp->next;
                }
            }
        }
        else
        {
            temp = temp->next;
        }
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("Enter your choice: ");
        printf(" 1. Book a ticket \t 2. Display the details of the passengers \t 3. Cancel a ticket \t 4. Exit \t");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            booking();
            break;
        case 2:
            display();
            break;
        case 3:
            cancel();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!");
        }
    }
}
