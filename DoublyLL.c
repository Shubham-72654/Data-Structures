// Doubly Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE head,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        newn->next = *head;
        (*head)->prev = newn;
        *head = newn;
    }
}

void InsertLast(PPNODE head,int no)
{
    PNODE temp = *head;
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }   
}

void InsertAtPos(PPNODE head, int no, int ipos)
{
    int iSize = 0;
    iSize = Count(*head);

    if((ipos < 1) || (ipos > (iSize + 1)))
    {
        printf("invalid position\n");
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(head, no);
    }
    else if(ipos == (iSize + 1))
    {
        InsertLast(head, no);
    }
    else
    {
        PNODE temp = *head;
        PNODE newn = NULL;
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        int iCnt = 0;

        for (iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        newn->next->prev = newn;
        newn->prev = temp;
    }
}

void DeleteFirst(PPNODE head)
{
    if(*head == NULL)
    {
        return;
    }
    else if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        *head = (*head)->next;
        free((*head)->prev);
        (*head)->prev = NULL;
    }
}

void DeleteLast(PPNODE head)
{
    if(*head == NULL)
    {
        return;
    }
    else if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        PNODE temp = *head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }   
}

void DeleteAtPos(PPNODE head,int ipos)
{
    int iSize = 0;
    iSize = Count(*head);

    if((ipos < 1) || (ipos > (iSize)))
    {
        printf("invalid position\n");
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst(head);
    }
    else if(ipos == (iSize))
    {
        DeleteLast(head);
    }
    else
    {
        PNODE temp = *head;
        int iCnt = 0;

        for (iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}

void Display(PNODE head)
{
    PNODE temp = head;
    while(temp != NULL)
    {
        printf("|%d|-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int Count(PNODE head)
{
    int iCnt = 0;
    PNODE temp = head;
    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

int main()
{
    PNODE first = NULL;

    printf("Insert First :\n");
    InsertFirst(&first, 101);
    InsertFirst(&first, 51);
    InsertFirst(&first, 21);
    InsertFirst(&first, 11);
    Display(first);
    printf("Number of nodes : %d\n", Count(first));

    printf("\nInsert Last :\n");
    InsertLast(&first, 111);
    InsertLast(&first, 121);
    Display(first);
    printf("Number of nodes : %d\n", Count(first));

    printf("\nInsert At Position :\n");
    InsertAtPos(&first, 105, 5);
    InsertAtPos(&first, 115, 7);
    Display(first);
    printf("Number of nodes : %d\n", Count(first));

    printf("Delete First :\n");
    DeleteFirst(&first);
    Display(first);
    printf("Number of nodes : %d\n", Count(first));

    printf("Delete Last :\n");
    DeleteLast(&first);
    Display(first);
    printf("Number of nodes : %d\n", Count(first));

    printf("\nDelete At Position :\n");
    DeleteAtPos(&first, 4);
    DeleteAtPos(&first, 5);
    Display(first);
    printf("Number of nodes : %d\n", Count(first));

    return 0;
}