// Singly Circular Linked List

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

void InsertFirst(PPNODE Head, PPNODE Tail, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL && *Tail == NULL)
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        newn->next = *Head;
        (*Tail)->next = newn;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, PPNODE Tail, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL && *Tail == NULL)
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        (*Tail)->next = newn;
        *Tail = newn;
        (*Tail)->next = *Head;
    }
}

void InsertAtPos(PPNODE Head, PPNODE Tail, int No, int iPos)
{
    int iSize = 0;
    iSize = Count(*Head, *Tail);
    if((iPos < 1) || (iPos > (iSize + 1)))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head, Tail, No);
    }
    else if(iPos == (iSize + 1))
    {
        InsertLast(Head, Tail, No);
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

void DeleteFirst(PPNODE Head, PPNODE Tail)
{
    if((*Head == NULL) && (*Tail == NULL))
    {
        return;
    }
    else if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        (*Tail)->next = (*Tail)->next->next;
        free(*Head);
        *Head = (*Tail)->next;
    }
}

void DeleteLast(PPNODE Head, PPNODE Tail)
{
    if((*Head == NULL) && (*Tail == NULL))
    {
        return;
    }
    else if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        PNODE temp = *Head;
        while(temp->next != *Tail)
        {
            temp = temp->next;
        }
        free(*Tail);
        *Tail = temp;
        (*Tail)->next = *Head;
    }
}

void DeleteAtPos(PPNODE Head, PPNODE Tail, int iPos)
{
    int iSize = 0;
    iSize = Count(*Head, *Tail);
    if((iPos < 1) || (iPos > (iSize)))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head, Tail);
    }
    else if(iPos == (iSize))
    {
        DeleteLast(Head, Tail);
    }
    else
    {
        PNODE temp = *Head;
        PNODE deltemp = NULL;
        int iCnt = 0;
        for (iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp->next;
        }
        deltemp = temp->next;
        temp->next = deltemp->next;
        free(deltemp);
    }
}

void Display(PNODE Head, PNODE Tail)
{
    if((Head == NULL) && (Tail == NULL))
    {
        return;
    }

    do
    {
        printf("|%d|-> ", Head->data);
        Head = Head->next;
    } while (Head != Tail->next);
    printf("\n");
}

int Count(PNODE Head, PNODE Tail)
{
    int iCnt = 0;

    if((Head == NULL) && (Tail == NULL))
    {
        return;
    }

    do
    {
        iCnt++;
        Head = Head->next;
    } while (Head != Tail->next);
    
    return iCnt;
}

int main()
{
    PNODE first = NULL;
    PNODE last = NULL;

    printf("Insert First : \n");
    InsertFirst(&first, &last, 101);
    InsertFirst(&first, &last, 51);
    InsertFirst(&first, &last, 21);
    Display(first, last);
    printf("Number of nodes : %d\n", Count(first, last));

    printf("\nInsert Last : \n");
    InsertLast(&first, &last, 111);
    InsertLast(&first, &last, 121);
    Display(first, last);
    printf("Number of nodes : %d\n", Count(first, last));

    printf("\nInsert At Position : \n");
    InsertAtPos(&first, &last, 110, 4);
    Display(first, last);
    printf("Number of nodes : %d\n", Count(first, last));

    printf("\nDelete First : \n");
    DeleteFirst(&first, &last);
    Display(first, last);
    printf("Number of nodes : %d\n", Count(first, last));

    printf("\nDelete Last : \n");
    DeleteLast(&first, &last);
    Display(first, last);
    printf("Number of nodes : %d\n", Count(first, last));

    printf("\nDelete At Position : \n");
    DeleteAtPos(&first, &last, 4);
    Display(first, last);
    printf("Number of nodes : %d\n", Count(first, last));

    return 0;
}