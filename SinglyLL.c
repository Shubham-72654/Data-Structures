// Singly Linear Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE Head, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        PNODE temp = *Head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void InsertAtPos(PPNODE Head, int No, int iPos)
{
    int iSize = 0;
    iSize = Count(*Head);

    if((iPos < 1) || (iPos > iSize+1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head, No);
    }
    else if(iPos == (iSize + 1))
    {
        InsertLast(Head, No);
    }
    else
    {
        PNODE temp = *Head;
        PNODE newn = NULL;
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = No;
        newn->next = NULL;

        int iCnt = 0;

        for (iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;

    if(temp == NULL)
    {
        return;
    }
    else if(temp->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        *Head = temp->next;
        free(temp);
    }

}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if(temp == NULL)
    {
        return;
    }
    else if(temp->next == NULL)
    {
        free(temp);
        temp = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void DeleteAtPos(PPNODE Head, int iPos)
{
    int iSize = 0;
    iSize = Count(*Head);

    if((iPos < 1) || (iPos > iSize))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if(iPos == iSize)
    {
        DeleteLast(Head);
    }
    else
    {
        PNODE temp = *Head;
        PNODE Deltemp = NULL;
        int iCnt = 0;

        for (iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp->next;
        }
        Deltemp = temp->next;
        temp->next = Deltemp->next;
        free(Deltemp);
    }
}

void Display(PNODE Head)
{
    PNODE temp = Head;
    while(temp != NULL)
    {
        printf("|%d|-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int Count(PNODE Head)
{
    PNODE temp = Head;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

// Entry Point Function
int main()
{
    PNODE first = NULL;

    printf("Insert First : \n");
    InsertFirst(&first, 101);
    InsertFirst(&first, 51);
    InsertFirst(&first, 21);
    InsertFirst(&first, 11);
    Display(first);
    printf("Number of nodes : %d\n",Count(first));

    printf("\nInsert Last : \n");
    InsertLast(&first, 121);
    InsertLast(&first, 151);
    Display(first);
    printf("Number of nodes : %d\n",Count(first));

    printf("\nInsert At Position : \n");
    InsertAtPos(&first, 111, 5);
    Display(first);
    printf("Number of nodes : %d\n",Count(first));

    printf("\nDelete First : \n");
    DeleteFirst(&first);
    Display(first);
    printf("Number of nodes : %d\n",Count(first));

    printf("\nDelete Last : \n");
    DeleteLast(&first);
    Display(first);
    printf("Number of nodes : %d\n",Count(first));

    printf("\nDelete At Position : \n");
    DeleteAtPos(&first, 4);
    Display(first);
    printf("Number of nodes : %d\n",Count(first));

    return 0;
}